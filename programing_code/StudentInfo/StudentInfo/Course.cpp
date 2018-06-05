// Course.h : CCourse ���ʵ��



// CCourse ʵ��

// ���������� 2018��6��5��, 20:44

#include "stdafx.h"
#include "Course.h"
IMPLEMENT_DYNAMIC(CCourse, CRecordset)

CCourse::CCourse(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_CourseNo = "";
	m_CourseName = "";
	m_Category = "";
	m_Major = "";
	m_Grade = "";
	m_StartTM = "";
	m_Credits = 0.0;
	m_WeekHours = "";
	m_nFields = 8;
	m_nDefaultType = dynaset;
}

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CCourse::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
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
	RFX_Text(pFX, _T("[CourseNo]"), m_CourseNo);
	RFX_Text(pFX, _T("[CourseName]"), m_CourseName);
	RFX_Text(pFX, _T("[Category]"), m_Category);
	RFX_Text(pFX, _T("[Major]"), m_Major);
	RFX_Text(pFX, _T("[Grade]"), m_Grade);
	RFX_Text(pFX, _T("[StartTM]"), m_StartTM);
	RFX_Single(pFX, _T("[Credits]"), m_Credits);
	RFX_Text(pFX, _T("[WeekHours]"), m_WeekHours);

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


