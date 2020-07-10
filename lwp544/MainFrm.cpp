// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "lwp544.h"
#include "MyDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_MYDLG, OnMydlg)
	ON_WM_TIMER()
	ON_COMMAND(ID_A, OnA)
	ON_UPDATE_COMMAND_UI(ID_A, OnUpdateA)
	//}}AFX_MSG_MAP
	ON_COMMAND(888, OnHello)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

extern CLwp544App theApp;
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_newToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_newToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
//	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
//	EnableDocking(CBRS_ALIGN_ANY);
//	DockControlBar(&m_wndToolBar);

//标记菜单（在菜单项前面打上勾）
//	GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED);
	GetMenu()->GetSubMenu(0)-> CheckMenuItem(ID_FILE_NEW, MF_CHECKED);
//图形标记菜单（在菜单项前面加上位图）
	CBitmap bmp3,bmp2;
	bmp3.LoadBitmap(IDB_BITMAP3);
	bmp2.LoadBitmap(IDB_BITMAP2);
	GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(0, MF_BYPOSITION, &bmp3, &bmp2);
//解除资源与C++的绑定关系
	bmp3.Detach();
	bmp2.Detach();
//禁用菜单项
	GetMenu()->GetSubMenu(0)->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED | MF_DISABLED);
//移除菜单
	SetMenu(NULL);
//加载菜单
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);
	SetMenu(&menu);
	menu.Detach();
//动态菜单操作
//添加菜单项目（AppendMenu）
	CMenu my_menu;
	my_menu.CreateMenu();
	GetMenu()->AppendMenu( MF_POPUP,  (UINT) my_menu.m_hMenu, "my_menu");
	GetMenu()->InsertMenu(2, MF_BYPOSITION | MF_POPUP, (UINT)my_menu.m_hMenu,"my_menu");
	my_menu.Detach();

//需要依葫芦画瓢，更改MainFrm.cpp的开头ON_COMMAND(888, OnHello)和结尾void CMainFrame::OnHello()，还有MainFrm.h的void OnHello(); 
//	GetMenu()->GetSubMenu(5)->AppendMenu(MF_STRING, 888, "Hello");
	GetMenu()->GetSubMenu(0)->InsertMenu (0, MF_STRING | MF_BYPOSITION, 777, "Hello");


	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_newToolBar.EnableDocking(CBRS_ALIGN_ANY);

	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_newToolBar);

	m_hIcon[0] = ::LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	m_hIcon[1] = ::LoadIcon(theApp.m_hInstance, MAKEINTRESOURCE(IDI_ICON2));
	m_hIcon[2] = ::LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3));
	m_hIcon[3] = AfxGetApp()->LoadIcon(IDI_ICON4);
	SetClassLong(m_hWnd, GCL_HICON,(LONG)m_hIcon[0]);

	SetWindowLong(m_hWnd, GWL_STYLE, GetWindowLong(m_hWnd,GWL_STYLE) & ~WS_MAXIMIZEBOX);
	SetTimer(1,1000, NULL);	

	CTime t = CTime::GetCurrentTime();
	CString str = t.Format("%H:%M:%:%S");
	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
//	m_wndStatusBar.SetPaneInfo(1, IDS_TIMER,SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(1, str);

	//在提示行中显位图
	CRect rc(100,4,120,20);
	if (!m_bmp.Create("", WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, rc, &m_wndStatusBar, 789))
		return FALSE;
	if (!m_bmp.LoadBitmaps(IDB_BITMAP1, IDB_BITMAP2, NULL, NULL))
		return FALSE;

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
//	cs.cx = 300;
//	cs.cy = 200;	
//	cs.lpszName = "暨南大学";
//	cs.style = cs.style & ~FWS_ADDTOTITLE;  

	WNDCLASS MyWnd;
	MyWnd.cbClsExtra = NULL; MyWnd.cbWndExtra = NULL;
	MyWnd.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	MyWnd.hCursor = LoadCursor(NULL, IDC_CROSS);
	MyWnd.hIcon = LoadIcon(NULL, IDI_WARNING);
	MyWnd.hInstance = AfxGetInstanceHandle();
	MyWnd.lpfnWndProc = ::DefWindowProc;
	MyWnd.lpszClassName = "Hello";
	MyWnd.lpszMenuName = NULL;
	MyWnd.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&MyWnd);
	cs.lpszClass = "hello";

//	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0, 0, LoadIcon(NULL, IDI_WARNING));
	
	SetClassLong(m_hWnd, GCL_HICON,(LONG)LoadIcon(NULL,IDI_WARNING));

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
	pCmdUI->SetCheck();
	pCmdUI->SetText("123");	
}

void CMainFrame::OnHello() 
{
	// TODO: Add your command handler code here
	MessageBox("hello");
}

void CMainFrame::OnMydlg() 
{
	// TODO: Add your command handler code here
//	CMyDlg Dlg;
//	Dlg.DoModal();
	
//	dlg.Create(IDD_DIALOG1, this);
//	dlg.ShowWindow(SW_SHOW);
//	dlg.Detach();//解除绑定，但造成程序崩溃了

	static BOOL bFlag = FALSE;
	if (FALSE == bFlag)
	{
		dlg.Create(IDD_DIALOG1, this);
		dlg.ShowWindow(SW_SHOW);
		bFlag = TRUE;
	}
	else
	{
		dlg.DestroyWindow();
		bFlag = FALSE;
	}


/*	CMyDlg* pDlg = new CMyDlg;
	pDlg->Create(IDD_DIALOG1, this);
	pDlg->ShowWindow(SW_SHOW);
*/
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
		static int index = 1;
	SetClassLong(m_hWnd, GCL_HICON,(LONG)m_hIcon[index]);
	index = ++index % 4;

	CTime t = CTime::GetCurrentTime();
	CString str = t.Format("%H:%M:%:%S");
	m_wndStatusBar.SetPaneText(1, str);
	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnA() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnUpdateA(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
