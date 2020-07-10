// lwp544View.cpp : implementation of the CLwp544View class
//

#include "stdafx.h"
#include "lwp544.h"

#include "lwp544Doc.h"
#include "lwp544View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLwp544View

IMPLEMENT_DYNCREATE(CLwp544View, CView)

BEGIN_MESSAGE_MAP(CLwp544View, CView)
	//{{AFX_MSG_MAP(CLwp544View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_TEST1, OnTest1)
	ON_COMMAND(ID_TEST2, OnTest2)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLwp544View construction/destruction

CLwp544View::CLwp544View()
{
	// TODO: add construction code here

}

CLwp544View::~CLwp544View()
{
}

BOOL CLwp544View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs


	cs.lpszClass = "hello";
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLwp544View drawing

void CLwp544View::OnDraw(CDC* pDC)
{
	CLwp544Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
//在窗口输入文字——视类OnDraw函数
	//pDC->TextOut(100,100, "第四讲 文本编程");
//在窗口输入文字——CString类
	//CString str("第四讲 文本编程");	
	//pDC->TextOut(100,100, str);
//添加字符串资源
	CString str;
	str.LoadString(IDS_MYSTRING);
	pDC->TextOut(100,100, str);
}

/////////////////////////////////////////////////////////////////////////////
// CLwp544View printing

BOOL CLwp544View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLwp544View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLwp544View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLwp544View diagnostics

#ifdef _DEBUG
void CLwp544View::AssertValid() const
{
	CView::AssertValid();
}

void CLwp544View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLwp544Doc* CLwp544View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLwp544Doc)));
	return (CLwp544Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLwp544View message handlers

void CLwp544View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//m_ptOrigin = point;
	m_ptOrigin = m_ptEnd = point; 
//插入符位置随鼠标单击而移动
	SetCaretPos(point);
//字符输入
	m_strLine.Empty();
	m_ptOrigin = point;


	CView::OnLButtonDown(nFlags, point);
}

void CLwp544View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//利用API全局函数实现画线功能
/*	HDC hdc;
	hdc = ::GetDC(m_hWnd);
	::MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	::LineTo(hdc, point.x, point.y);
	::ReleaseDC(m_hWnd, hdc);
*/
//利用CDC类实现画线功能
/*	CDC* pDC = GetDC();
	pDC->MoveTo(m_ptOrigin);
	pDC->LineTo(point);
	ReleaseDC(pDC);
*/
//利用CClientDC类实现画线功能
/*	CClientDC dc(this); 
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);
*/
//利用CWindowDC类实现画线功能
/*	CWindowDC dc(this); 
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);
*/
//在桌面上绘图
/*	CWindowDC dc(NULL); 
    //CWindowDC dc(GetDesktopWindow());
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);
*/
//绘制彩色线条——使用CPen类
/*	CPen pen(PS_SOLID,5,RGB(255,0,0));
	CClientDC dc(this);
	CPen* pOldPen = dc.SelectObject(&pen);
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);
	dc.SelectObject(pOldPen);
*/
//绘制矩形填充块	
/**	CBrush brush(RGB(255,0,0));
	CClientDC dc(this);
	dc.FillRect(CRect(m_ptOrigin,point), &brush);
*/
//绘制位图填充块	
/*	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	CBrush brush(&bmp);
	CClientDC dc(this);
	dc.FillRect(CRect(m_ptOrigin,point), &brush);
*/
//绘制矩形框
/*	CPen pen(PS_SOLID,5,RGB(255,0,0));
	CClientDC dc(this);
	CPen* pOldPen = dc.SelectObject(&pen);
	//若要绘制空心的矩形框，需要在设备描述表中将默认画刷（填充白色）换成透明画刷
	CBrush* pOldBrush=(CBrush*)dc.SelectStockObject(HOLLOW_BRUSH);	
	dc.Rectangle(CRect(m_ptOrigin,point));
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
*/


	CView::OnLButtonUp(nFlags, point);
}

void CLwp544View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//绘制连续线条	
/*	CPen pen(PS_SOLID,5,RGB(255,0,0));
	CClientDC dc(this);
	CPen* pOldPen = dc.SelectObject(&pen);
	if (nFlags == MK_LBUTTON)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		m_ptOrigin = point;
	}
	dc.SelectObject(pOldPen);
*/
//橡皮筋技术
/*	CClientDC dc(this);
	if (nFlags == MK_LBUTTON)
	{
		 //通过取反的模式擦除旧线条
		dc.SetROP2(R2_NOT);
		dc.MoveTo(m_ptOrigin); dc.LineTo(m_ptEnd);
		//绘制新线条
		m_ptEnd = point;
		dc.MoveTo(m_ptOrigin); dc.LineTo(m_ptEnd);
	} 
*/
	CView::OnMouseMove(nFlags, point);
}

int CLwp544View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
//创建文本插入符	
	//CreateSolidCaret(20,200);
	//ShowCaret();
//根据当前所选字号设置插入符大小	
/*	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight);
	ShowCaret();
*/
//创建图形插入符
	CBitmap bmp; 
	bmp.LoadBitmap(IDB_BITMAP1);
	CreateCaret(&bmp);
	ShowCaret();
	bmp.Detach();

	SetTimer(1, 100, NULL);	
	return 0;
}

void CLwp544View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
//字符输入
	CClientDC dc(this);
//设置字体规格
	CFont font;
	font.CreatePointFont(200, "华文琥珀");
	CFont* pOldFont = dc.SelectObject(&font);
	dc.SetTextColor(RGB(255,0,0));
//字符输入——回车键的处理
	if (13 == nChar)     //回车键的ASCII码为13
	{
		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);
		m_strLine.Empty();
		m_ptOrigin.y += tm.tmHeight;
	}
//字符输入——退格键的处理
	else if (8 == nChar)     //退格键的ASCII码为8
	{
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
		m_strLine = m_strLine.Left(m_strLine.GetLength() - 1) ;
		dc.SetTextColor(clr);
	}
	else
		m_strLine += nChar;
//插入符的移动
	CSize sz = dc.GetTextExtent(m_strLine);
	CPoint pt;
	pt.x = m_ptOrigin.x + sz.cx;
	pt.y = m_ptOrigin.y;
	SetCaretPos(pt);

	dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);//输出
	dc.SelectObject(pOldFont);//改回原始字体规格	


	CView::OnChar(nChar, nRepCnt, nFlags);
}

int nWidth = 0;
void CLwp544View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
//卡拉OK功能
	nWidth += 5;
	CClientDC dc(this);
	//设置字体规格
	CFont font;
	font.CreatePointFont(200, "华文琥珀");
	CFont* pOldFont = dc.SelectObject(&font);

	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CRect rect;
	rect.left = 0;
	rect.top = 200;
	rect.right = rect.left + nWidth;
	rect.bottom = rect.top + tm.tmHeight;

	dc.SetTextColor(RGB(255, 0, 0));
	CString str;
	str.LoadString(IDS_MYSTRING);
	dc.DrawText(str, rect, DT_LEFT);
	CSize sz = dc.GetTextExtent(str);

	if (nWidth > sz.cx)
	{
		nWidth = 0;
		dc.SetTextColor(RGB(0,0,255));
		dc.TextOut(rect.left,rect.top,str);
	}
	
	CView::OnTimer(nIDEvent);
}

void CLwp544View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	ClientToScreen(&point);
	CMenu* pPopup = menu.GetSubMenu(0);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN, point.x ,point.y, this);
	
	CView::OnRButtonDown(nFlags, point);
}

void CLwp544View::OnTest1() 
{
	// TODO: Add your command handler code here
	MessageBox("View Test1");
}

void CLwp544View::OnTest2() 
{
	// TODO: Add your command handler code here
	MessageBox("View Test2");
}

BOOL CLwp544View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(&rect);

	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	CBrush brush(&bmp);
	CClientDC dc(this);
	dc.FillRect(rect, &brush);

//	return CView::OnEraseBkgnd(pDC);
	return CView::OnEraseBkgnd(pDC);
}
