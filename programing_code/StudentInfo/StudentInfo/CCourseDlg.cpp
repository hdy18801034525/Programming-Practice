// CCourseDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CCourseDlg.h"
#include "afxdialogex.h"


// CCourseDlg 对话框

IMPLEMENT_DYNAMIC(CCourseDlg, CDialogEx)

CCourseDlg::CCourseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COURSE, pParent)
	, m_strCNAME_Q(_T(""))
	, m_strCNo(_T(""))
	, m_strCName(_T(""))
{

}

CCourseDlg::~CCourseDlg()
{
}

void CCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	/*
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CNO_q, m_strCNo_Q);
	DDX_Control(pDX, IDC_EDIT_CNNAME_q, m_strCNAME_Q);
	DDX_Control(pDX, IDC_CNO, m_strCNo);
	DDX_Control(pDX, IDC_EDIT_CNAME, m_strCName);
	DDX_Control(pDX, IDC_CREDIT, m_strCRedit);
	*/
}


BEGIN_MESSAGE_MAP(CCourseDlg, CDialogEx)
	
	ON_BN_CLICKED(IDC_BN_EXIT, &CCourseDlg::OnBnClickedBnExit)
END_MESSAGE_MAP()


// CCourseDlg 消息处理程序








void CCourseDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}
