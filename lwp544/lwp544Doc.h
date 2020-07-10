// lwp544Doc.h : interface of the CLwp544Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LWP544DOC_H__224EF8C0_B7DB_4D73_9707_AA0711297C9B__INCLUDED_)
#define AFX_LWP544DOC_H__224EF8C0_B7DB_4D73_9707_AA0711297C9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLwp544Doc : public CDocument
{
protected: // create from serialization only
	CLwp544Doc();
	DECLARE_DYNCREATE(CLwp544Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLwp544Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLwp544Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLwp544Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LWP544DOC_H__224EF8C0_B7DB_4D73_9707_AA0711297C9B__INCLUDED_)
