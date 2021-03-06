// CCourseDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CCourseDlg.h"
#include "afxdialogex.h"

// CCourseDlg 对话框

IMPLEMENT_DYNAMIC(CCourseDlg, CDialogEx)

CCourseDlg::CCourseDlg(CWnd *pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COURSE, pParent)
	, CourseNO_Q(_T("")), CourseName_Q(_T(""))
	, CourseNO(_T(""))
	, CourseName(_T(""))
	, CourseCredit(_T(""))
{
	SetBackgroundColor(RGB(255, 255, 255));
}

CCourseDlg::~CCourseDlg()
{
}

void CCourseDlg::DoDataExchange(CDataExchange *pDX)
{

	DDX_Text(pDX, IDC_EDIT_CNO_q, CourseNO_Q);
	DDX_Text(pDX, IDC_EDIT_CNNAME_q, CourseName_Q);
	DDX_Text(pDX, IDC_CNO, CourseNO);
	DDX_Text(pDX, IDC_EDIT_CNAME, CourseName);
	DDX_Text(pDX, IDC_CREDIT, CourseCredit);
}

BEGIN_MESSAGE_MAP(CCourseDlg, CDialogEx)

ON_BN_CLICKED(IDC_BN_EXIT, &CCourseDlg::OnBnClickedBnExit)
ON_BN_CLICKED(IDC_BN_QUERY, &CCourseDlg::OnBnClickedBnQuery)
ON_BN_CLICKED(IDC_ADD, &CCourseDlg::OnBnClickedAdd)
ON_BN_CLICKED(IDC_BN_EDIT, &CCourseDlg::OnBnClickedBnEdit)
ON_BN_CLICKED(IDC_BN_DELETE, &CCourseDlg::OnBnClickedBnDelete)
ON_BN_CLICKED(IDC_BN_SAVE, &CCourseDlg::OnBnClickedBnSave)
ON_BN_CLICKED(IDC_BN_CANCEL, &CCourseDlg::OnBnClickedBnCancel)
ON_BN_CLICKED(IDC_BN_FIRST, &CCourseDlg::OnBnClickedBnFirst)
ON_BN_CLICKED(IDC_BN_PREV, &CCourseDlg::OnBnClickedBnPrev)
ON_BN_CLICKED(IDC_BN_NEXT, &CCourseDlg::OnBnClickedBnNext)
ON_BN_CLICKED(IDC_BN_LAST, &CCourseDlg::OnBnClickedBnLast)
END_MESSAGE_MAP()

// CCourseDlg 消息处理程序

void CCourseDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}

void CCourseDlg::OnBnClickedBnQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (CourseNO_Q.IsEmpty() && CourseName_Q.IsEmpty())
	{
		CourseSet.m_strFilter = "";
		CourseSet.Requery();
		if (CourseSet.IsBOF())
		{
			AfxMessageBox("数据集空！");
			m_bEmpty = true;
			ClearEditData();
			SetMoveBNState();
		}
		else
		{
			m_bEmpty = false;
			CourseSet.MoveFirst();
			m_bFirst = true;
			m_bLast = false;
			ReadRecord();
			SetMoveBNState();
		}
		return;
	}
	BOOL mbSNoQInput = FALSE;
	if (!CourseNO_Q.IsEmpty())
	{
		CourseSet.m_strFilter = "CourseNO='" + CourseNO_Q;
		CourseSet.m_strFilter = CourseSet.m_strFilter + "'";

		mbSNoQInput = TRUE;
	}
	if (!CourseName_Q.IsEmpty())
	{
		if (mbSNoQInput)
		{
			CourseSet.m_strFilter = CourseSet.m_strFilter + " AND CourseName='";
			CourseSet.m_strFilter = CourseSet.m_strFilter + CourseName_Q;
			CourseSet.m_strFilter = CourseSet.m_strFilter + "'";
		}
		else
		{
			CourseSet.m_strFilter = "CourseName='" + CourseName_Q;
			CourseSet.m_strFilter = CourseSet.m_strFilter + "'";
		}
	}
	CourseSet.Requery();
	if (CourseSet.IsEOF())
	{
		AfxMessageBox("没有查到相关记录！");
		m_bEmpty = true;
		ClearEditData();
		SetMoveBNState();
	}
	else
	{
		m_bEmpty = false;
		CourseSet.MoveFirst();
		m_bFirst = true;
		ReadRecord();
		SetMoveBNState();
	}
}


void CCourseDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	ClearEditData();
	m_bEdit = true;
	m_bAdd = true;
	SetMoveBNState();
	SetEditState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_EDIT_SNo);
}

void CCourseDlg::ClearEditData(void)
{
	CourseNO_Q = "";
	CourseName_Q = "";
	CourseNO = "";
	CourseName = "";
	CourseCredit = "";

	UpdateData(FALSE);
	return;
}

void CCourseDlg::WriteRecord(void)
{
	UpdateData(TRUE);
	CourseSet.m_CourseNO = CourseNO;
	CourseSet.m_CourseCredit = atoi(CourseCredit);
	CourseSet.m_CourseName = CourseName;
	
}

void CCourseDlg::ReadRecord(void)
{
	CourseNO = CourseSet.m_CourseNO;
	CString temp;
	CourseCredit.Format("%d", CourseSet.m_CourseCredit);
	CourseName = CourseSet.m_CourseName;

	UpdateData(FALSE);
}

void CCourseDlg::SetMoveBNState(void)
{
	{
		CWnd *pWnd;
		if (m_bEmpty || m_bEdit)
		{
			pWnd = GetDlgItem(IDC_BN_FIRST);
			pWnd->EnableWindow(FALSE);

			pWnd = GetDlgItem(IDC_BN_PREV);
			pWnd->EnableWindow(FALSE);

			pWnd = GetDlgItem(IDC_BN_NEXT);
			pWnd->EnableWindow(FALSE);
		}
		if (m_bFirst)
		{
			pWnd = GetDlgItem(IDC_BN_FIRST);
			pWnd->EnableWindow(FALSE);

			pWnd = GetDlgItem(IDC_BN_PREV);
			pWnd->EnableWindow(FALSE);

			pWnd = GetDlgItem(IDC_BN_LAST);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_NEXT);
			pWnd->EnableWindow(TRUE);
		}
		else if (m_bLast)
		{
			pWnd = GetDlgItem(IDC_BN_FIRST);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_PREV);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_LAST);
			pWnd->EnableWindow(FALSE);

			pWnd = GetDlgItem(IDC_BN_NEXT);
			pWnd->EnableWindow(FALSE);
		}
		else
		{
			pWnd = GetDlgItem(IDC_BN_FIRST);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_PREV);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_LAST);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_NEXT);
			pWnd->EnableWindow(TRUE);
		}
	}
}

void CCourseDlg::SetEditState(void)
{
	CWnd *pWnd;
	if (m_bEdit)
	{
		pWnd = GetDlgItem(IDC_ADD);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_BN_EDIT);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_BN_DELETE);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_BN_QUERY);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_BN_SAVE);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_CANCEL);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_CNO);
		pWnd->EnableWindow(TRUE);
		
		pWnd = GetDlgItem(IDC_EDIT_CNAME);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_CREDIT);
		pWnd->EnableWindow(TRUE);

	}
	else
	{
		pWnd = GetDlgItem(IDC_ADD);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_EDIT);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_DELETE);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_QUERY);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_QUERY);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_SAVE);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_BN_CANCEL);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_CNO);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_EDIT_CNAME);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_CREDIT);
		pWnd->EnableWindow(FALSE);
	}
}


BOOL CCourseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CourseSet.Open(AFX_DB_USE_DEFAULT_TYPE);
	ChoiceSet.Open(AFX_DB_USE_DEFAULT_TYPE);
	if (!CourseSet.IsOpen()&&!ChoiceSet.IsOpen())
	{
		AfxMessageBox("数据打开失败!");
		return TRUE;
	}
	else if (CourseSet.IsBOF())
	{
		AfxMessageBox("数据集空!");
		m_bEmpty = true;
		ClearEditData();
		SetMoveBNState();
		SetEditState();
	}
	else
	{
		m_bEmpty = false;
		m_bFirst = true;
		m_bLast = false;
		ReadRecord();
		SetMoveBNState();
		SetEditState();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CCourseDlg::OnBnClickedBnEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bEdit = true;
	m_bAdd = false;
	SetMoveBNState();
	SetEditState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_EDIT_SNAME);
}


void CCourseDlg::OnBnClickedBnDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	
	if (AfxMessageBox("震惊！是否要删除该记录？", MB_YESNO | MB_ICONSTOP) == IDYES)
	{
		ChoiceSet.m_strFilter = "CNO='" + CourseSet.m_CourseNO + "'";
		ChoiceSet.Requery();
		ChoiceSet.MoveFirst();
		while (!ChoiceSet.IsEOF())
		{
			ChoiceSet.Delete();
			ChoiceSet.MoveNext();
		}

		CourseSet.Delete();
		CourseSet.Requery();
		ClearEditData();
		if (CourseSet.IsBOF())
		{
			AfxMessageBox("什么？表中居然已经没有记录了！");
			ClearEditData();
			m_bEmpty = true;
			SetMoveBNState();
			return;
		}
		m_bFirst = true;
		m_bLast = false;
		ReadRecord();
		SetMoveBNState();
	}
}


void CCourseDlg::OnBnClickedBnSave()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (CourseNO.IsEmpty() || CourseName.IsEmpty())
	{
		AfxMessageBox("请输入相应数据！");
		CWnd *pWnd;
		pWnd = GetDlgItem(IDC_EDIT_SNo);
		pWnd->SetFocus();
		return;
	}
	if (m_bAdd)
	{
		CourseSet.AddNew();
	}
	else
	{
		CourseSet.Edit();
	}
	WriteRecord();
	CourseSet.Update();
	CourseSet.Requery();
	CourseSet.MoveFirst();
	m_bFirst = true;
	m_bLast = false;
	m_bAdd = false;
	m_bEdit = false;
	ReadRecord();
	SetMoveBNState();
	SetEditState();
}


void CCourseDlg::OnBnClickedBnCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bAdd = false;
	m_bEdit = false;
	ReadRecord();
	SetMoveBNState();
	SetEditState();
}


void CCourseDlg::OnBnClickedBnFirst()
{
	// TODO: 在此添加控件通知处理程序代码
	CourseSet.MoveFirst();
	m_bFirst = true;
	m_bLast = false;
	SetMoveBNState();
	ReadRecord();
}


void CCourseDlg::OnBnClickedBnPrev()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bFirst = false;
	m_bLast = false;
	CourseSet.MovePrev();
	if (CourseSet.IsBOF())
	{
		CourseSet.MoveFirst();
		m_bFirst = TRUE;
	}
	SetMoveBNState();
	ReadRecord();
}


void CCourseDlg::OnBnClickedBnNext()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bFirst = false;
	m_bLast = false;
	CourseSet.MoveNext();
	if (CourseSet.IsEOF())
	{
		CourseSet.MoveLast();
		m_bLast = true;
	}
	SetMoveBNState();
	ReadRecord();
}


void CCourseDlg::OnBnClickedBnLast()
{
	// TODO: 在此添加控件通知处理程序代码
	CourseSet.MoveLast();
	m_bFirst = false;
	m_bLast = true;
	SetMoveBNState();
	ReadRecord();
}