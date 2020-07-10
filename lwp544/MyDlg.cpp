// MyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "lwp544.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog


CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_Num1 = 0;
	m_Num2 = 0;
	m_Num3 = 0;
	//}}AFX_DATA_INIT
}


void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Num1);
	DDX_Text(pDX, IDC_EDIT2, m_Num2);
	DDX_Text(pDX, IDC_EDIT3, m_Num3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_NUM1, OnNum1)
	ON_BN_CLICKED(IDC_NUM2, OnNum2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

void CMyDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
//MFC的DDX数据交换——控件和整型变量关联	
/*
	UpdateData();    //成员变量从对话框控件中获取数据
	m_Num3 = m_Num1 + m_Num2;
	UpdateData(FALSE);    //以成员变量的值初始化对话框控件
*/
/*
	int num1, num2, num3;
	char c1[10], c2[10], c3[10];
	m_Edit1.GetWindowText(c1, 10);
	m_Edit2.GetWindowText(c2, 10);
	num1 = atoi(c1);
	num2 = atoi(c2);
	num3 = num1 + num2;
	itoa(num3,c3,10);
	m_Edit3.SetWindowText(c3);
*/
//GetDlgItem + Get/SetWindowText
	int num1, num2, num3;
	char c1[10], c2[10], c3[10];
	GetDlgItem(IDC_EDIT1)->GetWindowText(c1, 10);
	GetDlgItem(IDC_EDIT2)->GetWindowText(c2, 10);	
    num1 = atoi(c1);
	num2 = atoi(c2);
	num3 = num1 + num2;
	itoa(num3,c3,10);
	GetDlgItem(IDC_EDIT3)->SetWindowText(c3);
}

void CMyDlg::OnNum1() 
{
	// TODO: Add your control notification handler code here
//利用GetDlgItem改变控件文本内容
	CString str;
	GetDlgItem(IDC_NUM1)->GetWindowText(str);
	if (str == "Number1:")
		GetDlgItem(IDC_NUM1)->SetWindowText("数值1：");
	else
		GetDlgItem(IDC_NUM1)->SetWindowText("Number1:");
}

//利用GetDlgItem在控件中绘图
void CMyDlg::OnNum2() 
{
	// TODO: Add your control notification handler code here
	CWnd* pWnd = GetDlgItem(IDC_NUM2);

	CRect rc;
	pWnd->GetClientRect(&rc);
	CBrush brush(RGB(255,0,0));

	CDC* pDC = pWnd->GetDC();
	pDC->FillRect(&rc,&brush);
	pDC->SetBkMode(TRANSPARENT);
	pDC->TextOut(13,5,"李炜鹏");	
	ReleaseDC(pDC);	
}

BOOL CMyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	CRect rc;
	GetClientRect(rc);
	CRgn rgn;
	rgn.CreateEllipticRgn(0, 0, rc.Width(), rc.Height());
	SetWindowRgn((HRGN) rgn.m_hObject, TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
