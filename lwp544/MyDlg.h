#if !defined(AFX_MYDLG_H__0F97A67B_69E8_452F_B58A_625672FA557E__INCLUDED_)
#define AFX_MYDLG_H__0F97A67B_69E8_452F_B58A_625672FA557E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_DIALOG1 };
	int		m_Num1;
	int		m_Num2;
	int		m_Num3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	afx_msg void OnButton1();
	afx_msg void OnNum1();
	afx_msg void OnNum2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDLG_H__0F97A67B_69E8_452F_B58A_625672FA557E__INCLUDED_)
