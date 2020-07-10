// lwp544.h : main header file for the LWP544 application
//

#if !defined(AFX_LWP544_H__447C27C2_6729_4EE8_8D48_2A37651717D7__INCLUDED_)
#define AFX_LWP544_H__447C27C2_6729_4EE8_8D48_2A37651717D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLwp544App:
// See lwp544.cpp for the implementation of this class
//

class CLwp544App : public CWinApp
{
public:
	CLwp544App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLwp544App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLwp544App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LWP544_H__447C27C2_6729_4EE8_8D48_2A37651717D7__INCLUDED_)
