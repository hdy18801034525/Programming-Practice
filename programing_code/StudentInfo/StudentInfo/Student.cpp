// Student.h : CStudent ���ʵ��



// CStudent ʵ��

// ���������� 2018��6��5��, 20:41

#include "stdafx.h"
#include "Student.h"
IMPLEMENT_DYNAMIC(CStudent, CRecordset)

CStudent::CStudent(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Sno = "";
	m_Sname = "";
	m_Ssex = "";
	m_ClassNo = "";
	m_Sbirth;
	m_Status = "";
	m_Hometown = "";
	m_Enrollment;
	m_Telephone = "";
	m_Resume = "";
	m_nFields = 10;
	m_nDefaultType = dynaset;
}

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CStudent::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CStudent::GetDefaultSQL()
{
	return _T("[dbo].[Student]");
}

void CStudent::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[Sno]"), m_Sno);
	RFX_Text(pFX, _T("[Sname]"), m_Sname);
	RFX_Text(pFX, _T("[Ssex]"), m_Ssex);
	RFX_Text(pFX, _T("[ClassNo]"), m_ClassNo);
	RFX_Date(pFX, _T("[Sbirth]"), m_Sbirth);
	RFX_Text(pFX, _T("[Status]"), m_Status);
	RFX_Text(pFX, _T("[Hometown]"), m_Hometown);
	RFX_Date(pFX, _T("[Enrollment]"), m_Enrollment);
	RFX_Text(pFX, _T("[Telephone]"), m_Telephone);
	RFX_Text(pFX, _T("[Resume]"), m_Resume);

}
/////////////////////////////////////////////////////////////////////////////
// CStudent ���

#ifdef _DEBUG
void CStudent::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudent::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


