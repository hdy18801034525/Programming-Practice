#pragma once


// CGradeDlg 对话框

class CGradeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGradeDlg)

public:
	CGradeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGradeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CGRADE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBnExit();
};
