// CStudentDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CStudentDlg.h"
#include "afxdialogex.h"


// CStudentDlg 对话框

IMPLEMENT_DYNAMIC(CStudentDlg, CDialogEx)

CStudentDlg::CStudentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_STUDENT, pParent)
{

}

CStudentDlg::~CStudentDlg()
{
}

void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStudentDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BN_EXIT, &CStudentDlg::OnBnClickedBnExit)
END_MESSAGE_MAP()


// CStudentDlg 消息处理程序


void CStudentDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}
