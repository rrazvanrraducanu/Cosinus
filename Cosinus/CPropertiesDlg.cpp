// CPropertiesDlg.cpp : implementation file
//

#include "pch.h"
#include "Cosinus.h"
#include "CPropertiesDlg.h"
#include "afxdialogex.h"


// CPropertiesDlg dialog

IMPLEMENT_DYNAMIC(CPropertiesDlg, CDialog)

CPropertiesDlg::CPropertiesDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_edit1(0)
{
	m_edit1 = 10;
}

CPropertiesDlg::~CPropertiesDlg()
{
}

void CPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
}


BEGIN_MESSAGE_MAP(CPropertiesDlg, CDialog)
END_MESSAGE_MAP()


// CPropertiesDlg message handlers
