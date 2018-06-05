// Course.h : CCourse ������

#pragma once

// ���������� 2018��6��5��, 20:44

class CCourse : public CRecordset
{
public:
	CCourse(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCourse)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringA	m_CourseNo;
	CStringA	m_CourseName;
	CStringA	m_Category;
	CStringA	m_Major;
	CStringA	m_Grade;
	CStringA	m_StartTM;
	float		m_Credits;
	CStringA	m_WeekHours;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���
	virtual CString GetDefaultSQL(); 		// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

