
// CosinusView.h : interface of the CCosinusView class
//

#pragma once


class CCosinusView : public CView
{
protected: // create from serialization only
	CCosinusView() noexcept;
	DECLARE_DYNCREATE(CCosinusView)

// Attributes
public:
	CCosinusDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCosinusView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int m_pasi;
	afx_msg void OnFunctionsCosinus();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in CosinusView.cpp
inline CCosinusDoc* CCosinusView::GetDocument() const
   { return reinterpret_cast<CCosinusDoc*>(m_pDocument); }
#endif

