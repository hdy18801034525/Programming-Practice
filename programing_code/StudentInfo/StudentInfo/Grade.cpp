// Grade.h : Grade ���ʵ��



// Grade ʵ��

// ���������� 2018��6��17��, 23:26

#include "stdafx.h"
#include "Grade.h"
IMPLEMENT_DYNAMIC(Grade, CRecordset)

Grade::Grade(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_dboChoiceSNo = "";
	m_dboChoiceCourseNO = "";
	m_dboChoiceSscore = 0;
	m_dboCourseCourseName = "";
	m_dboCourseCourseNO = "";
	m_dboCStudentSName = "";
	m_dboCStudentSNo = "";
	m_dboCStudentSMajor = "";
	m_dboCStudentSSex = "";
	m_dboCStudentSBirthDate = "";
	m_dboCStudentSSchoolDate = "";
	m_nFields = 12;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Grade::GetDefaultConnect()
{
	return _T("DSN=StudentInfoDB;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=StudentInfoDB");
}

CString Grade::GetDefaultSQL()
{
	return _T("[dbo].[Choice],[dbo].[Course],[dbo].[CStudent]");
}

void Grade::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[dbo].[Choice].[SNo]"), m_dboChoiceSNo);
	RFX_Text(pFX, _T("[dbo].[Choice].[CourseNO]"), m_dboChoiceCourseNO);
	RFX_Long(pFX, _T("[dbo].[Choice].[Sscore]"), m_dboChoiceSscore);
	RFX_Text(pFX, _T("[dbo].[Course].[CourseName]"), m_dboCourseCourseName);
	RFX_Text(pFX, _T("[dbo].[Course].[CourseNO]"), m_dboCourseCourseNO);
	RFX_Long(pFX, _T("[dbo].[Course].[CourseCredit]"), m_dboCourseCourseCredit);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SName]"), m_dboCStudentSName);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SNo]"), m_dboCStudentSNo);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SMajor]"), m_dboCStudentSMajor);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SSex]"), m_dboCStudentSSex);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SBirthDate]"), m_dboCStudentSBirthDate);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SSchoolDate]"), m_dboCStudentSSchoolDate);

}
/////////////////////////////////////////////////////////////////////////////
// Grade ���

#ifdef _DEBUG
void Grade::AssertValid() const
{
	CRecordset::AssertValid();
}

void Grade::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


