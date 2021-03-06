// CStudentDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CStudentDlg.h"
#include "afxdialogex.h"

// CStudentDlg 对话框

IMPLEMENT_DYNAMIC(CStudentDlg, CDialogEx)

CStudentDlg::CStudentDlg(CWnd *pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_STUDENT, pParent), m_strSNo_Q(_T("")), m_strSNAME_Q(_T("")), m_strSNo(_T("")), m_strSName(_T("")), m_strSSex(_T("")), m_strSMajor(_T("")), m_strSBDate(_T("")), m_strSSDate(_T("")), m_bAdd(false), m_bEdit(false), m_bEmpty(false), m_bFirst(false), m_bLast(false)
{
	SetBackgroundColor(RGB(255, 255, 255));
}

CStudentDlg::~CStudentDlg()
{
}

void CStudentDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SNo_Q, m_strSNo_Q);
	DDX_Text(pDX, IDC_SEDIT_NAME_Q, m_strSNAME_Q);
	DDX_Text(pDX, IDC_EDIT_SNo, m_strSNo);
	DDX_Text(pDX, IDC_EDIT_SSEX, m_strSSex);
	DDX_Text(pDX, IDC_EDIT_SBDATE, m_strSBDate);
	DDX_Text(pDX, IDC_SNAME, m_strSName);
	DDX_Text(pDX, IDC_EDIT_SMAJOR, m_strSMajor);
	DDX_Text(pDX, IDC_EDIT_SSDATE, m_strSSDate);
}

BEGIN_MESSAGE_MAP(CStudentDlg, CDialogEx)
ON_BN_CLICKED(IDC_BN_EXIT, &CStudentDlg::OnBnClickedBnExit)
ON_BN_CLICKED(IDC_ADD, &CStudentDlg::OnBnClickedAdd)
ON_BN_CLICKED(IDC_BN_EDIT, &CStudentDlg::OnBnClickedBnEdit)
ON_BN_CLICKED(IDC_BN_DELETE, &CStudentDlg::OnBnClickedBnDelete)
ON_BN_CLICKED(IDC_BN_SAVE, &CStudentDlg::OnBnClickedBnSave)
ON_BN_CLICKED(IDC_BN_QUERY, &CStudentDlg::OnBnClickedBnQuery)
ON_BN_CLICKED(IDC_BN_FIRST, &CStudentDlg::OnBnClickedBnFirst)
ON_BN_CLICKED(IDC_BN_PREV, &CStudentDlg::OnBnClickedBnPrev)
ON_BN_CLICKED(IDC_BN_NEXT, &CStudentDlg::OnBnClickedBnNext)
ON_BN_CLICKED(IDC_BN_LAST, &CStudentDlg::OnBnClickedBnLast)
ON_BN_CLICKED(IDC_BN_CANCEL, &CStudentDlg::OnBnClickedBnCancel)
END_MESSAGE_MAP()

// CStudentDlg 消息处理程序

void CStudentDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}

void CStudentDlg::ClearEditData(void)
{
	m_strSNo_Q = "";
	m_strSNAME_Q = "";
	m_strSNo = "";
	m_strSSex = "";
	m_strSBDate = "";
	m_strSName = "";
	m_strSMajor = "";
	m_strSSDate = "";

	UpdateData(FALSE);
	return;
}

void CStudentDlg::ReadRecord(void)
{
	m_strSNo = m_rsStudentSet.m_SNo;
	m_strSName = m_rsStudentSet.m_SName;
	m_strSSex = m_rsStudentSet.m_SSex;
	m_strSMajor = m_rsStudentSet.m_SMajor;
	m_strSBDate = m_rsStudentSet.m_SBirthDate;
	m_strSSDate = m_rsStudentSet.m_SSchoolDate;

	UpdateData(FALSE);
}

void CStudentDlg::WriteRecord(void)
{
	UpdateData(TRUE);

	m_rsStudentSet.m_SNo = m_strSNo;
	m_rsStudentSet.m_SName = m_strSName;
	m_rsStudentSet.m_SSex = m_strSSex;
	m_rsStudentSet.m_SMajor = m_strSMajor;
	m_rsStudentSet.m_SBirthDate = m_strSBDate;
	m_rsStudentSet.m_SSchoolDate = m_strSSDate;
	
}

void CStudentDlg::SetMoveBNState(void)
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

void CStudentDlg::SetEditState(void)
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

		pWnd = GetDlgItem(IDC_EDIT_SNo);
		if (m_bAdd)
			pWnd->EnableWindow(TRUE);
		else
			pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_EDIT_SNAME);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_EDIT_SSEX);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_EDIT_SMAJOR);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_EDIT_SBDATE);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_EDIT_SSDATE);
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

		pWnd = GetDlgItem(IDC_EDIT_SNo);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_EDIT_SNAME);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_EDIT_SSEX);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_EDIT_SMAJOR);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_EDIT_SBDATE);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_EDIT_SSDATE);
		pWnd->EnableWindow(FALSE);
	}
}

BOOL CStudentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_rsStudentSet.Open(AFX_DB_USE_DEFAULT_TYPE);
	ChoiceSet.Open(AFX_DB_USE_DEFAULT_TYPE);
	if (!m_rsStudentSet.IsOpen()&&!ChoiceSet.IsOpen())
	{
		AfxMessageBox("数据打开失败!");
		return TRUE;
	}

	else if (m_rsStudentSet.IsBOF())
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

	return TRUE; // return TRUE unless you set the focus to a control
				 // 异常: OCX 属性页应返回 FALSE
}

void CStudentDlg::OnBnClickedAdd()
{
	ClearEditData();
	m_bEdit = true;
	m_bAdd = true;
	SetMoveBNState();
	SetEditState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_EDIT_SNo);
	pWnd->SetFocus();
}

void CStudentDlg::OnBnClickedBnEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bEdit = true;
	m_bAdd = false;
	SetMoveBNState();
	SetEditState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_EDIT_SNAME);
	pWnd->SetFocus();
}

void CStudentDlg::OnBnClickedBnDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	//if (AfxMessageBox("震惊！是否要删除此条记录？"), MB_YESNO != IDYES)
		//return;
	if (AfxMessageBox("震惊！是否要删除该记录？", MB_YESNO | MB_ICONSTOP) == IDYES)
	{
		ChoiceSet.m_strFilter = "SNO='" + m_rsStudentSet.m_SNo + "'";
		ChoiceSet.Requery();
		ChoiceSet.MoveFirst();
		while (!ChoiceSet.IsEOF())
		{
			ChoiceSet.Delete();
			ChoiceSet.MoveNext();
		}
		
		m_rsStudentSet.Delete();
		m_rsStudentSet.Requery();
		if (m_rsStudentSet.IsBOF())
		{
			AfxMessageBox("什么？表中居然已经没有记录了！");
			ClearEditData();
			m_bEmpty = true;
			SetMoveBNState();
		}
		m_bFirst = true;
		m_bLast = false;
		ReadRecord();
		SetMoveBNState();
	}
}

void CStudentDlg::OnBnClickedBnSave()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_strSNo.IsEmpty() || m_strSName.IsEmpty())
	{
		AfxMessageBox("请输入相应数据！");
		CWnd *pWnd;
		pWnd = GetDlgItem(IDC_EDIT_SNo);
		pWnd->SetFocus();
		return;
	}
	if (m_bAdd)
	{
		m_rsStudentSet.AddNew();
	}
	else
	{
		m_rsStudentSet.Edit();
	}
	WriteRecord();
	m_rsStudentSet.Update();
	m_rsStudentSet.Requery();
	m_rsStudentSet.MoveFirst();
	m_bFirst = true;
	m_bLast = false;
	m_bAdd = false;
	m_bEdit = false;
	ReadRecord();
	SetMoveBNState();
	SetEditState();
}

void CStudentDlg::OnBnClickedBnQuery()
{
	UpdateData(TRUE);
	if (m_strSNo_Q.IsEmpty() && m_strSNAME_Q.IsEmpty())
	{
		m_rsStudentSet.m_strFilter = "";
		m_rsStudentSet.Requery();
		if (m_rsStudentSet.IsBOF())
		{
			AfxMessageBox("数据集空！");
			m_bEmpty = true;
			ClearEditData();
			SetMoveBNState();
		}
		else
		{
			m_bEmpty = false;
			m_rsStudentSet.MoveFirst();
			m_bFirst = true;
			m_bLast = false;
			ReadRecord();
			SetMoveBNState();
		}
		return;
	}
	BOOL mbSNoQInput = FALSE;
	if (!m_strSNo_Q.IsEmpty())
	{
		m_rsStudentSet.m_strFilter = "Sno='" + m_strSNo_Q;
		m_rsStudentSet.m_strFilter = m_rsStudentSet.m_strFilter + "'";

		mbSNoQInput = TRUE;
	}
	if (!m_strSNAME_Q.IsEmpty())
	{
		if (mbSNoQInput)
		{
			m_rsStudentSet.m_strFilter = m_rsStudentSet.m_strFilter + " AND Sname='";
			m_rsStudentSet.m_strFilter = m_rsStudentSet.m_strFilter + m_strSNAME_Q;
			m_rsStudentSet.m_strFilter = m_rsStudentSet.m_strFilter + "'";
		}
		else
		{
			m_rsStudentSet.m_strFilter = "Sname='" + m_strSNAME_Q;
			m_rsStudentSet.m_strFilter = m_rsStudentSet.m_strFilter + "'";
		}
	}
	m_rsStudentSet.Requery();
	if (m_rsStudentSet.IsEOF())
	{
		AfxMessageBox("没有查到相关记录！");
		m_bEmpty = true;
		ClearEditData();
		SetMoveBNState();
	}
	else
	{
		m_bEmpty = false;
		m_rsStudentSet.MoveFirst();
		m_bFirst = true;
		ReadRecord();
		SetMoveBNState();
	}
}

void CStudentDlg::OnBnClickedBnFirst()
{
	// TODO: 在此添加控件通知处理程序代码
	m_rsStudentSet.MoveFirst();
	m_bFirst = true;
	m_bLast = false;
	SetMoveBNState();
	ReadRecord();
}

void CStudentDlg::OnBnClickedBnPrev()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bFirst = false;
	m_bLast = false;
	m_rsStudentSet.MovePrev();
	if (m_rsStudentSet.IsBOF())
	{
		m_rsStudentSet.MoveFirst();
		m_bFirst = TRUE;
	}
	SetMoveBNState();
	ReadRecord();
}

void CStudentDlg::OnBnClickedBnNext()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bFirst = false;
	m_bLast = false;
	m_rsStudentSet.MoveNext();
	if (m_rsStudentSet.IsEOF())
	{
		m_rsStudentSet.MoveLast();
		m_bLast = true;
	}
	SetMoveBNState();
	ReadRecord();
}

void CStudentDlg::OnBnClickedBnLast()
{
	// TODO: 在此添加控件通知处理程序代码
	m_rsStudentSet.MoveLast();
	m_bFirst = false;
	m_bLast = true;
	SetMoveBNState();
	ReadRecord();
}

void CStudentDlg::OnBnClickedBnCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bAdd = false;
	m_bEdit = false;
	ReadRecord();
	SetMoveBNState();
	SetEditState();
}
