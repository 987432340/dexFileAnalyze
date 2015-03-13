// DexÎÄ¼þ½âÎöDlg.h : header file
//

#if !defined(AFX_DEXDLG_H__7EC419A3_0702_4497_81A2_379850380357__INCLUDED_)
#define AFX_DEXDLG_H__7EC419A3_0702_4497_81A2_379850380357__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDexDlg dialog

class CDexDlg : public CDialog
{
// Construction
public:
	CString GetAccess(UINT32);
	CString GetInterface(UINT32 off);
	CString GetSourceName(UINT32 off);
	CString GetAnnontation(UINT32 off);

	void ReadClassDefs(Class_dex dex);
	void ReadMethods(Class_dex dex);
	void ReadFields(Class_dex dex);

	void ReadProtos(Class_dex dex);
	CString CDexDlg::ReadProtos(Class_dex dex,UINT32 idx);

	CString ReadTypes(Class_dex dex,int n);
	void CDexDlg::ReadTypes(Class_dex dex);
	CString CDexDlg::GetLeb128String(UINT32 StringAddress);
	void ReadNbyte(byte *buffer, UINT32 offset, UINT32 ByteNum);
	CString CDexDlg::ReadStrings(Class_dex dex,UINT32 n);
	void CDexDlg::ReadStrings(Class_dex dex);
	void CDexDlg::AddTextToEdit(CString str);
	CDexDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDexDlg)
	enum { IDD = IDD_DEX_DIALOG };
	CEdit	m_edit;
	CString	m_DexFilePath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDexDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDexDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLook();
	afx_msg void OnAnalysis();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	Class_dex dex;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEXDLG_H__7EC419A3_0702_4497_81A2_379850380357__INCLUDED_)
