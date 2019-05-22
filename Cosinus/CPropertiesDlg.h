#pragma once


// CPropertiesDlg dialog

class CPropertiesDlg : public CDialog
{
	DECLARE_DYNAMIC(CPropertiesDlg)

public:
	CPropertiesDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPropertiesDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_edit1;
};
