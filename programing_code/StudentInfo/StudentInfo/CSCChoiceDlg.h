#pragma once


// CSCChoiceDlg 对话框

class CSCChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSCChoiceDlg)

public:
	CSCChoiceDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSCChoiceDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SCCHOICE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCNo_q = NULL;
	CString m_strCNAME_Q = NULL;
	CString m_strCNo = NULL;
	CString m_strCName = NULL;
	CString m_strCRedit = NULL;
	afx_msg void OnBnClickedBnExit();
};
