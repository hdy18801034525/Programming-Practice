// Course.h : CCourse ���ʵ��



// CCourse ʵ��

// ���������� 2018��6��11��, 22:50

#include "stdafx.h"
#include "Course.h"
IMPLEMENT_DYNAMIC(CCourse, CRecordset)

CCourse::CCourse(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_CourseName = "";
	m_CourseNO = "";
	
	m_nFields = 3;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CCourse::GetDefaultConnect()
{
	return _T("DSN=StudentInfoDB;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=StudentInfoDB");
}

CString CCourse::GetDefaultSQL()
{
	return _T("[dbo].[Course]");
}

void CCourse::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[CourseName]"), m_CourseName);
	RFX_Text(pFX, _T("[CourseNO]"), m_CourseNO);
	RFX_Long(pFX, _T("[CourseCredit]"), m_CourseCredit);

}
/////////////////////////////////////////////////////////////////////////////
// CCourse ���

#ifdef _DEBUG
void CCourse::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCourse::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


