// Dex�ļ�����Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dex�ļ�����.h"
#include "Dex�ļ�����Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDexDlg dialog

CDexDlg::CDexDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDexDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDexDlg)
	m_DexFilePath = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDexDlg)
	DDX_Control(pDX, IDC_EDIT2, m_edit);
	DDX_Text(pDX, IDC_EDIT1, m_DexFilePath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDexDlg, CDialog)
	//{{AFX_MSG_MAP(CDexDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnLook)
	ON_BN_CLICKED(IDC_BUTTON2, OnAnalysis)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDexDlg message handlers

BOOL CDexDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDexDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDexDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDexDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDexDlg::OnLook() 
{
	// ��ѡ���ļ�
	CString FilePath;
	char szFilter[] = {"Dex Files(*.dex)|*.dex||"};  
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);
	if(dlg.DoModal() == IDOK)  
    {  
        FilePath = dlg.GetPathName();  
        m_DexFilePath = (LPCTSTR)FilePath;  //lpszFileName��һ��ȫ�ֱ���  
		UpdateData(FALSE);
    }  
}
//
byte charBuffer[0x70];


//���ȷ���� ����dex�ļ�
void CDexDlg::OnAnalysis() 
{
	CFile pFile; 
	
	 m_DexFilePath= "D:\\dextest\\test.dex";
	if (!pFile.Open(m_DexFilePath,CFile::modeRead))
	{
		AfxMessageBox("��dex�ļ�ʧ��!");
	}
	pFile.Read(charBuffer,0x70);
	dex.Pdexheader =(DexHeader *)charBuffer;
	pFile.Close();

//	ReadStrings(dex);
//	ReadTypes(dex);
//	ReadProtos(dex);
//	ReadFields(dex);
	ReadClassDefs(dex);
//	ReadMethods(dex);


//	ReadClassDefs(dex);
}




//����ָ���������ַ���
CString CDexDlg::ReadStrings(Class_dex dex,UINT32 n)
{
	UINT32 offset;
	UINT32 Count =dex.Pdexheader->string_ids_size;
	UINT32 Address;

	ReadNbyte((byte*)&offset, dex.Pdexheader->string_ids_off,4);

	if (n<Count)
	{
		ReadNbyte((byte*)&Address, dex.Pdexheader->string_ids_off + n*4, 4);
	}
	 return GetLeb128String(Address);
}


//��ʾ�����ַ���
void CDexDlg::ReadStrings(Class_dex dex)
{
	UINT32 offset;
	UINT32 Count =dex.Pdexheader->string_ids_size;
	UINT32 *StringAddressTable = new UINT32[Count];
	
	ReadNbyte((byte*)&offset, dex.Pdexheader->string_ids_off,4);	
	//��ȡ��������String�ĵ�ַ
	for (UINT32 i=0; i < Count; i++)
		ReadNbyte((byte*)&StringAddressTable[i], dex.Pdexheader->string_ids_off + i*4, 4);
	CString str;
	//  �������ַ���	
	for (i=0; i<Count; i++)
	{
		str = GetLeb128String(StringAddressTable[i]);
		AddTextToEdit(str);
	}
	delete []StringAddressTable;
}

//��ʾ��������
void CDexDlg::ReadTypes(Class_dex dex)
{
	UINT32 Count =dex.Pdexheader->type_ids_size;
	UINT32 *TypeIndexTable = new UINT32[Count];
	
	AddTextToEdit("Start read Types......");
	
	//��ȡ��������Type�ĵ�ַ
	for (UINT32 i=0; i < Count; i++)
	{
		ReadNbyte((byte*)&TypeIndexTable[i], dex.Pdexheader->type_ids_off + i*4, 4);
	}
	
	for (i=0;i<Count; i++)
	{
		AddTextToEdit(ReadStrings(dex,TypeIndexTable[i])); 
	}
	delete []TypeIndexTable;
}

CString CDexDlg::ReadTypes(Class_dex dex,int n)
{
	UINT32 Count =dex.Pdexheader->type_ids_size;
	UINT32 TypeIndex ;
	
	ReadNbyte((byte*)&TypeIndex, dex.Pdexheader->type_ids_off + n*4, 4);

	return	ReadStrings(dex,TypeIndex);

}

//��ʾ���к���ԭ��
void CDexDlg::ReadProtos(Class_dex dex)
{
	UINT32 Count =dex.Pdexheader->proto_ids_size;
	proto_id_item *Pproto_id_items = new proto_id_item[Count];
	
	AddTextToEdit("Start read Protos......");
	//��ȡ��������Type�ĵ�ַ
	for (UINT32 i=0; i < Count; i++)
	{
		ReadNbyte((byte*)&Pproto_id_items[i], dex.Pdexheader->proto_ids_off + i*(sizeof(proto_id_item)), sizeof(proto_id_item));
	}
	CString str;
	
	for ( i=0; i < Count; i++)
	{	
		str.Empty();
		str += "short-form: ";
		//��short-form descriptor string of this prototype.
		str += ReadStrings(dex,Pproto_id_items[i].shorty_idx)+"  ";	
		str +="return_type: ";
		//����������
		str += ReadTypes(dex,Pproto_id_items[i].return_type_idx)+"  ";
		str +="parameters: ";
		//�������б�
		if (Pproto_id_items[i].parameters_offset == 0)
		{
			str+="NULL";
		}else
		{
			unsigned short count;	//���м�������
			ReadNbyte((byte*)&count,Pproto_id_items[i].parameters_offset,4);
			//ѭ��������������
			for (UINT32 j=0;j<count;j++)
			{
				UINT32 Type_Idx; memset((void*)&Type_Idx,0,sizeof(UINT32));
				//����j��������type_ids�е�����
				ReadNbyte((byte*)&Type_Idx,Pproto_id_items[i].parameters_offset+j*4+4,2);
				str += ReadTypes(dex,Type_Idx);
			}
		}
		AddTextToEdit(str);
	}	
	delete []Pproto_id_items;
}

//����ָ��idx�ĺ���ԭ��
CString CDexDlg::ReadProtos(Class_dex dex,UINT32 idx)
{
	CString str="";
	UINT32 Count =dex.Pdexheader->proto_ids_size;
	proto_id_item items;
	//��ȡ��������Type�ĵ�ַ

	if (idx<Count)
	{
		ReadNbyte((byte*)&items, dex.Pdexheader->proto_ids_off + idx*(sizeof(proto_id_item)), sizeof(proto_id_item));

		str += "short-form: ";
		//��short-form descriptor string of this prototype.
		str += ReadStrings(dex,items.shorty_idx)+"  ";	
		str +="return_type: ";
		//����������
		str += ReadTypes(dex,items.return_type_idx)+"  ";
		str +="parameters: ";
		//�������б�
		if (items.parameters_offset == 0)
		{
			str+="NULL";
		}else
		{
			unsigned short count;	//���м�������
			ReadNbyte((byte*)&count,items.parameters_offset,4);
			//ѭ��������������
			for (UINT32 j=0;j<count;j++)
			{
				UINT32 Type_Idx; memset((void*)&Type_Idx,0,sizeof(UINT32));
				//����j��������type_ids�е�����
				ReadNbyte((byte*)&Type_Idx,items.parameters_offset+j*4+4,2);
				str += ReadTypes(dex,Type_Idx);
			}
		}
		
	}else
		AfxMessageBox("ָ��Index����!");
	return str;
}


//��ȡ����Fields�ֶ�
void CDexDlg::ReadFields(Class_dex dex)
{
	UINT32 Count =dex.Pdexheader->field_ids_size;
	filed_id_item *items = new filed_id_item[Count];
	
	AddTextToEdit("Start read Fields......");
	//��ȡ��������Type�ĵ�ַ
	for (UINT32 i=0; i < Count; i++)
	{
		ReadNbyte((byte*)&items[i], dex.Pdexheader->field_ids_off + i*(sizeof(filed_id_item)), sizeof(filed_id_item));
	}
	CString str;
	
	for ( i=0; i < Count; i++)
	{	
		str.Empty();
		str += "class: ";
		//��short-form descriptor string of this prototype.
		str += ReadTypes(dex,items[i].class_idx)+"  ";	
		str +="type: ";
		//����������
		str += ReadTypes(dex,items[i].type_idx)+"  ";
		str +="name: ";
		//�������б�		
		str += ReadStrings(dex,items->name_idx);
		AddTextToEdit(str);
	}	
	delete []items;
}


void CDexDlg::ReadMethods(Class_dex dex)
{
	UINT32 Count =dex.Pdexheader->method_ids_size;
	method_id_item *items = new method_id_item[Count];
	
	AddTextToEdit("Start read Methods......");
	//��ȡ��������Type�ĵ�ַ
	for (UINT32 i=0; i < Count; i++)
	{
		ReadNbyte((byte*)&items[i], dex.Pdexheader->method_ids_off + i*(sizeof(method_id_item)), sizeof(method_id_item));
	}
	CString str;
	
	for ( i=0; i < Count; i++)
	{	
		str.Empty();
		str += "class: ";
		//��short-form descriptor string of this prototype.
		str += ReadTypes(dex,items[i].class_idx)+"  ";	
		str +="proto: ";
		//������ԭ��
		str += ReadProtos(dex,items[i].proto_idx)+"  ";
		str +="name: ";
		//������		
		str += ReadStrings(dex,items[i].name_idx);
		AddTextToEdit(str);
	}	
	delete []items;

}




void CDexDlg::ReadClassDefs(Class_dex dex)
{
	CString str;
	UINT32 Count =dex.Pdexheader->class_defs_size;
	class_def_item *Def_items = new class_def_item[Count];
	
	AddTextToEdit("Start read ClassDefs......");
	
	//������ȡ��ÿ��class_def_item�ṹ
	for (UINT32 i=0; i < Count; i++)
	{
		ReadNbyte((byte*)&Def_items[i], dex.Pdexheader->class_defs_off +i*(sizeof(class_def_item)), sizeof(class_def_item));
	}
	
	for (i=0; i < Count; i++)
	{
		AddTextToEdit("����:\t\t"+ReadTypes(dex,Def_items[i].class_idx));
		AddTextToEdit("����Ȩ��:\t"+GetAccess(Def_items[i].access_flags));
		AddTextToEdit("����:\t\t"+ReadTypes(dex,Def_items[i].superclass_idx));
		AddTextToEdit("�ӿ�:\t\t"+GetInterface(Def_items[i].interfaces_off));
		AddTextToEdit("Դ�ļ���:\t"+GetSourceName(Def_items[i].source_file_idx));
		AddTextToEdit("ע����Ϣ:\t"+GetAnnontation(Def_items[i].annotations_off));
		//static_values_off ��ʱû�ж�ȡ
		
	}
	
	delete []Def_items;
}




void CDexDlg::ReadNbyte(byte *buffer, UINT32 offset, UINT32 ByteNum)
{
	CFile pFile; 
	
	if (!pFile.Open(m_DexFilePath,CFile::modeRead))
	{
		AfxMessageBox("��dex�ļ�ʧ��!");
	}
	pFile.Seek(offset,CFile::begin);
	pFile.Read(buffer,ByteNum);
	pFile.Close();
}

//Leb128���ʹ��5�ֽڱ�ʾ�ַ�����С,����һ��Ĭ�ϴ���5��byte
//����ֵΪʹ���˶����ֽ���Ϊ����
CString CDexDlg::GetLeb128String(UINT32 StringAddress)
{
	UINT32 count=1;	//count ʹ���˶����ֽ���Ϊ����
	byte Leb128[5];
	ReadNbyte(Leb128,StringAddress,5);
	
	int result = Leb128[0];	//�����ַ�������

	//�����һ���ֽڵ����λ��1
	if (Leb128[0]> 0x7f) 
	{
	 //��ǰֵ�ǵ�һ���ֽڵ�7λ���ϵڶ����ֽڵ�7λ
		result = (result & 0x7f) | ((Leb128[1] & 0x7f) << 7);	
			
		//����ڶ����ֽڵ����λ��1
		if (Leb128[1] > 0x7f) 
		{	
			result |= (Leb128[2] & 0x7f) << 14;//��ǰֵ���ϵ������ֽڵ�7λ
			count++;
	
			//����������ֽڵ����λ��1
			if (Leb128[2] > 0x7f) 
			{	
				result |= (Leb128[3] & 0x7f) << 21;//��ǰֵ���ϵ��ĸ��ֽڵ�7λ
				count++;

				//������ĸ��ֽڵ����λ��1
				if (Leb128[3] > 0x7f) 
				{
					result |= Leb128[4] << 28;//��ǰֵ���ϵ�����ֽڵ�7λ
					count++;
				}
			}
		}
	}
	
	char * pStr = new char[result+1];	
	ReadNbyte((byte*)pStr,StringAddress+count,result+1);
	CString str = "";
	str.Format("%s",pStr);
	delete []pStr;
	return str;
}

//��༭�������һ��
void CDexDlg::AddTextToEdit(CString str)
{
	m_edit.SetSel(-1,-1);//����ƶ�����β��
	m_edit.ReplaceSel(str+_T("\r\n"));
}

CString CDexDlg::GetAccess(UINT32 value)
{
	switch (value)
	{
	case ACC_PUBLIC:return "public";
	case ACC_PRIVATE: return "public";
	case ACC_PROTECTED: return "protected";
	case ACC_STATIC: return "static";
	default: return "Null";
	}
	
}


CString CDexDlg::GetSourceName(UINT32 off)
{
	if (off==0)
	{
		return "Null";
	}else
		return ReadStrings(dex,off);
	
}





CString CDexDlg::GetInterface(UINT32 off)
{
	if (off==0)
	{
		return "Null";
	}else
		return "coding now!";
}




CString CDexDlg::GetAnnontation(UINT32 off)
{
	if (off== 0)
	{
		return "Null";
	}else
		return "coding now!";
}


