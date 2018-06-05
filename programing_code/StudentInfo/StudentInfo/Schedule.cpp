// Schedule.h : CSchedule ���ʵ��



// CSchedule ʵ��

// ���������� 2018��6��5��, 20:54

#include "stdafx.h"
#include "Schedule.h"
IMPLEMENT_DYNAMIC(CSchedule, CRecordset)

CSchedule::CSchedule(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_CourseNo = "";
	m_StartYear;
	m_ClassNo = "";
	m_Teacher = "";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CSchedule::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CSchedule::GetDefaultSQL()
{
	return _T("[dbo].[Schedule]");
}

void CSchedule::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[CourseNo]"), m_CourseNo);
	RFX_Date(pFX, _T("[StartYear]"), m_StartYear);
	RFX_Text(pFX, _T("[ClassNo]"), m_ClassNo);
	RFX_Text(pFX, _T("[Teacher]"), m_Teacher);

}
/////////////////////////////////////////////////////////////////////////////
// CSchedule ���

#ifdef _DEBUG
void CSchedule::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSchedule::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


