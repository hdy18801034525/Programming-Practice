// Choice.h : Choice ���ʵ��



// Choice ʵ��

// ���������� 2018��6��17��, 23:20

#include "stdafx.h"
#include "Choice.h"
IMPLEMENT_DYNAMIC(Choice, CRecordset)

Choice::Choice(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_SNo = "";
	m_CourseNO = "";
	m_Sscore = 0;
	m_nFields = 3;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Choice::GetDefaultConnect()
{
	return _T("DSN=StudentInfoDB;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=StudentInfoDB");
}

CString Choice::GetDefaultSQL()
{
	return _T("[dbo].[Choice]");
}

void Choice::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[SNo]"), m_SNo);
	RFX_Text(pFX, _T("[CourseNO]"), m_CourseNO);
	RFX_Long(pFX, _T("[Sscore]"), m_Sscore);

}
/////////////////////////////////////////////////////////////////////////////
// Choice ���

#ifdef _DEBUG
void Choice::AssertValid() const
{
	CRecordset::AssertValid();
}

void Choice::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


