// Dex文件解析.h : main header file for the DEX文件解析 application
//

#if !defined(AFX_DEX_H__65E208D5_8266_4063_AD6E_FD6D692A9705__INCLUDED_)
#define AFX_DEX_H__65E208D5_8266_4063_AD6E_FD6D692A9705__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "dex.h"
/////////////////////////////////////////////////////////////////////////////
// CDexApp:
// See Dex文件解析.cpp for the implementation of this class
//

class CDexApp : public CWinApp
{
public:
	CDexApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDexApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDexApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEX_H__65E208D5_8266_4063_AD6E_FD6D692A9705__INCLUDED_)
