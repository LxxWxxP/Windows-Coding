// lwp544View.h : interface of the CLwp544View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LWP544VIEW_H__1CC5E420_6436_4243_8D41_FF4047810A70__INCLUDED_)
#define AFX_LWP544VIEW_H__1CC5E420_6436_4243_8D41_FF4047810A70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLwp544View : public CView
{
protected: // create from serialization only
	CLwp544View();
	DECLARE_DYNCREATE(CLwp544View)

// Attributes
public:
	CLwp544Doc* GetDocument();
	CPoint m_ptOrigin;
	CPoint m_ptEnd;
	CString m_strLine;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLwp544View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLwp544View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLwp544View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTest1();
	afx_msg void OnTest2();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lwp544View.cpp
inline CLwp544Doc* CLwp544View::GetDocument()
   { return (CLwp544Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LWP544VIEW_H__1CC5E420_6436_4243_8D41_FF4047810A70__INCLUDED_)
