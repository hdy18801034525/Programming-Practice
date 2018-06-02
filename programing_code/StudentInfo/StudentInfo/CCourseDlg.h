#pragma once


// CCourseDlg 对话框

class CCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCourseDlg)

public:
	CCourseDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCourseDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COURSE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	
	CString m_strCNo_Q = NULL;
	CString m_strCNAME_Q = NULL;
	CString m_strCNo = NULL;
	CString m_strCName = NULL;
	CString m_strCRedit = NULL;
	afx_msg void OnBnClickedBnExit();
};
