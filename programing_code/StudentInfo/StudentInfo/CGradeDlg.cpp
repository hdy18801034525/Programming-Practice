// CGradeDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CGradeDlg.h"
#include "afxdialogex.h"


// CGradeDlg 对话框

IMPLEMENT_DYNAMIC(CGradeDlg, CDialogEx)

CGradeDlg::CGradeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CGRADE, pParent)
{

}

CGradeDlg::~CGradeDlg()
{
}

void CGradeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGradeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BN_EXIT, &CGradeDlg::OnBnClickedBnExit)
END_MESSAGE_MAP()


// CGradeDlg 消息处理程序


void CGradeDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}
