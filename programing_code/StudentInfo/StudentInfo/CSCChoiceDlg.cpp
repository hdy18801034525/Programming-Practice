// CSCChoiceDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CSCChoiceDlg.h"
#include "afxdialogex.h"


// CSCChoiceDlg 对话框

IMPLEMENT_DYNAMIC(CSCChoiceDlg, CDialogEx)

CSCChoiceDlg::CSCChoiceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SCCHOICE, pParent)
	, m_strCNo_q(_T(""))
	, m_strCNAME_Q(_T(""))
	, m_strCNo(_T(""))
	, m_strCName(_T(""))
	, m_strCRedit(_T(""))
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CSCChoiceDlg::~CSCChoiceDlg()
{
}

void CSCChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	/*
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CNO_q, m_strCNo_q);
	DDX_Control(pDX, IDC_EDIT_CNNAME_q, m_strCNAME_Q);
	DDX_Control(pDX, IDC_CNO, m_strCNo);
	DDX_Control(pDX, IDC_EDIT_CNAME, m_strCName);
	DDX_Control(pDX, IDC_CREDIT, m_strCRedit);
	*/
}


BEGIN_MESSAGE_MAP(CSCChoiceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BN_EXIT, &CSCChoiceDlg::OnBnClickedBnExit)
END_MESSAGE_MAP()


// CSCChoiceDlg 消息处理程序


void CSCChoiceDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}
