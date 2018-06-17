// Grade.h : Grade ������

#pragma once

// ���������� 2018��6��17��, 23:26

class Grade : public CRecordset
{
public:
	Grade(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Grade)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CString	m_dboChoiceSNo;
	CString	m_dboChoiceCourseNO;
	long	m_dboChoiceSscore;
	CString	m_dboCourseCourseName;
	CString	m_dboCourseCourseNO;
	long	m_dboCourseCourseCredit;
	CString	m_dboCStudentSName;
	CString	m_dboCStudentSNo;
	CString	m_dboCStudentSMajor;
	CString	m_dboCStudentSSex;
	CString	m_dboCStudentSBirthDate;
	CString	m_dboCStudentSSchoolDate;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


