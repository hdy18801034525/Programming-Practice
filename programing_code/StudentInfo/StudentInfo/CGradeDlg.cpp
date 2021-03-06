// CGradeDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CGradeDlg.h"
#include "afxdialogex.h"


// CGradeDlg 对话框

IMPLEMENT_DYNAMIC(CGradeDlg, CDialogEx)

CGradeDlg::CGradeDlg(CWnd *pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CGRADE, pParent), m_strSNo_Q(_T("")), m_strCCount(_T("")), m_strCReditS(_T(""))
	, m_strCAvg(_T(""))
{
	SetBackgroundColor(RGB(255, 255, 255));
}

CGradeDlg::~CGradeDlg()
{
}

void CGradeDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_SNo_Q, m_strSNo_Q);
	DDX_Text(pDX, IDC_EDIT_CCOUNT, m_strCCount);
	DDX_Text(pDX, IDC_CReditS, m_strCReditS);
	DDX_Text(pDX, IDC_CAVG, m_strCAvg);
	DDX_Control(pDX, IDC_LIST, ListDisp);
}

BEGIN_MESSAGE_MAP(CGradeDlg, CDialogEx)
ON_BN_CLICKED(IDC_BN_EXIT, &CGradeDlg::OnBnClickedBnExit)
ON_BN_CLICKED(IDC_BN_QUERY, &CGradeDlg::OnBnClickedBnQuery)
END_MESSAGE_MAP()

// CGradeDlg 消息处理程序

void CGradeDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}

BOOL CGradeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_strConnCondition = "CStudent.Sno=choice.Sno and Course.Courseno=Choice.Courseno";
	m_rsGradeSet.m_strFilter = m_strConnCondition;
	if (!m_rsGradeSet.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		AfxMessageBox("数据库打开失败！");
	}
	
	ListDisp.InsertColumn(0, "姓名", LVCFMT_LEFT, 150);
	ListDisp.InsertColumn(1, "课程号", LVCFMT_LEFT, 150);
	ListDisp.InsertColumn(2, "课程名", LVCFMT_LEFT, 150);
	ListDisp.InsertColumn(3, "学分", LVCFMT_LEFT, 150);
	ListDisp.InsertColumn(4, "成绩", LVCFMT_LEFT, 150);

	RECT rect;
	ListDisp.GetWindowRect(&rect);
	int wid = rect.right - rect.left;
	ListDisp.SetColumnWidth(0, wid / 5);
	ListDisp.SetColumnWidth(1, wid / 5);
	ListDisp.SetColumnWidth(2, wid / 5);
	ListDisp.SetColumnWidth(3, wid / 5);
	ListDisp.SetColumnWidth(4, wid / 5);

	ListDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT |
		LVS_EX_GRIDLINES);
	
	return TRUE; // return TRUE unless you set the focus to a control
				 // 异常: OCX 属性页应返回 FALSE
}


void CGradeDlg::OnBnClickedBnQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	
	if (m_strSNo_Q.IsEmpty())
	{
		AfxMessageBox("请输入学生的学号");
		m_strCCount = "";
		m_strCReditS = "";
		m_strCAvg = "";

		UpdateData(FALSE);
		return;
	}
	else
	{
		m_rsGradeSet.m_strFilter = m_strConnCondition +
			" and cstudent.SNO=" + m_strSNo_Q + " ";
		m_rsGradeSet.Requery();
		ListDisp.DeleteAllItems();
		ListDisp.SetRedraw(FALSE);
		UpdateData(TRUE);

		if (m_rsGradeSet.IsBOF())
		{
			AfxMessageBox("该学生没有选课！");
			m_strCCount = "";
			m_strCReditS = "";
			m_strCAvg = "";

			UpdateData(FALSE);
			return;
		}

		m_rsGradeSet.MoveFirst();
		int i = 0;
		int iCCount = 0;
		int iCReditS = 0;
		int iCSum = 0;
		CString strNum;
		while (!m_rsGradeSet.IsEOF())
		{
			ListDisp.InsertItem(i, m_rsGradeSet.m_dboCStudentSName);
			ListDisp.SetItemText(i, 1, m_rsGradeSet.m_dboCourseCourseNO);
			ListDisp.SetItemText(i, 2, m_rsGradeSet.m_dboCourseCourseName);

			strNum.Format("%d", m_rsGradeSet.m_dboCourseCourseCredit);
			ListDisp.SetItemText(i, 3, strNum);

			strNum.Format("%d", m_rsGradeSet.m_dboChoiceSscore);
			ListDisp.SetItemText(i, 4, strNum);

			iCCount++;
			iCReditS += m_rsGradeSet.m_dboCourseCourseCredit;

			iCSum += m_rsGradeSet.m_dboChoiceSscore;

			m_rsGradeSet.MoveNext();
		}
		ListDisp.SetRedraw(TRUE);
		m_strCCount.Format("%d", iCCount);
		m_strCCount.Format("%d", iCCount);
		m_strCReditS.Format("%d", iCReditS);
		m_strCAvg.Format("%.2f", (float)iCSum / iCCount);
		UpdateData(FALSE);
	}
}
