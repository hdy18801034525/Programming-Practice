#pragma once
#include"Course.h"
#include"Choice.h"
// CCourseDlg 对话框

class CCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCourseDlg)

  public:
	CCourseDlg(CWnd *pParent = nullptr); // 标准构造函数
	virtual ~CCourseDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum
	{
		IDD = IDD_DIALOG_COURSE
	};
#endif

  protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
  public:
	
	CString CourseNO_Q;
	CString CourseName_Q;
	CString CourseNO;
	CString CourseName;
	CString CourseCredit;

	bool m_bEmpty;
	bool m_bFirst;
	bool m_bLast;
	bool m_bAdd;
	bool m_bEdit;

	CCourse CourseSet;
	Choice ChoiceSet;
	void ClearEditData(void);
	void WriteRecord(void);
	void ReadRecord(void);
	void SetMoveBNState(void);
	void SetEditState(void);
	
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedBnEdit();
	afx_msg void OnBnClickedBnDelete();
	afx_msg void OnBnClickedBnSave();
	afx_msg void OnBnClickedBnCancel();
	afx_msg void OnBnClickedBnFirst();
	afx_msg void OnBnClickedBnPrev();
	afx_msg void OnBnClickedBnNext();
	afx_msg void OnBnClickedBnLast();
	afx_msg void OnBnClickedBnExit();
	afx_msg void OnBnClickedBnQuery();
};