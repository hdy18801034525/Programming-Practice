// Student.h : CStudent ������

#pragma once

// ���������� 2018��6��5��, 20:41

class CStudent : public CRecordset
{
public:
	CStudent(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStudent)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringA	m_Sno;
	CStringA	m_Sname;
	CStringA	m_Ssex;
	CStringA	m_ClassNo;
	CTime		m_Sbirth;
	CStringA	m_Status;
	CStringA	m_Hometown;
	CTime		m_Enrollment;
	CStringA	m_Telephone;
	CStringA	m_Resume;

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


