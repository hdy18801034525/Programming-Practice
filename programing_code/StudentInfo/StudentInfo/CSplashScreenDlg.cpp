// CSplashScreenDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CSplashScreenDlg.h"
#include "afxdialogex.h"


// CSplashScreenDlg 对话框

IMPLEMENT_DYNAMIC(CSplashScreenDlg, CDialogEx)

CSplashScreenDlg::CSplashScreenDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SPLASHSCREEN_DIALOG, pParent)
{
	
}

CSplashScreenDlg::~CSplashScreenDlg()
{
}

void CSplashScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSplashScreenDlg, CDialogEx)
END_MESSAGE_MAP()


// CSplashScreenDlg 消息处理程序
