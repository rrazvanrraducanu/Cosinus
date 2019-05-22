
// CosinusView.cpp : implementation of the CCosinusView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Cosinus.h"
#endif

#include "CosinusDoc.h"
#include "CosinusView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CPropertiesDlg.h"
#include "math.h"


// CCosinusView

IMPLEMENT_DYNCREATE(CCosinusView, CView)

BEGIN_MESSAGE_MAP(CCosinusView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCosinusView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FUNCTIONS_COSINUS, &CCosinusView::OnFunctionsCosinus)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CCosinusView construction/destruction

CCosinusView::CCosinusView() noexcept
{
	// TODO: add construction code here

}

CCosinusView::~CCosinusView()
{
}

BOOL CCosinusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCosinusView drawing

void CCosinusView::OnDraw(CDC* /*pDC*/)
{
	CCosinusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCosinusView printing


void CCosinusView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCosinusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCosinusView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCosinusView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCosinusView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCosinusView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCosinusView diagnostics

#ifdef _DEBUG
void CCosinusView::AssertValid() const
{
	CView::AssertValid();
}

void CCosinusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCosinusDoc* CCosinusView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCosinusDoc)));
	return (CCosinusDoc*)m_pDocument;
}
#endif //_DEBUG


// CCosinusView message handlers


void CCosinusView::OnFunctionsCosinus()
{
	// TODO: Add your command handler code here
	CPropertiesDlg dlg;
	int res = dlg.DoModal();
	if (res == IDOK)
		m_pasi = dlg.m_edit1;
	CClientDC dc(this);
	CRect rc;
	GetClientRect(&rc);
	int nWidth = rc.Width();
	int nHeight = rc.Height();
	CPoint point[100];
	for (int i = 1; i < m_pasi; i++)
	{
		point[i].x = (i * nWidth) / m_pasi;
		point[i].y = int((nHeight / 2) * (1 - cos((2 * 3.14 * i) / m_pasi)));
	}
	dc.Polyline(point, m_pasi);
}


void CCosinusView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	RedrawWindow();
	CView::OnRButtonDown(nFlags, point); 
}
