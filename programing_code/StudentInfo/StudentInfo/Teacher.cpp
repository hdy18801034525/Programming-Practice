// Teacher.h : CTeacher ���ʵ��



// CTeacher ʵ��

// ���������� 2018��6��5��, 20:59

#include "stdafx.h"
#include "Teacher.h"
IMPLEMENT_DYNAMIC(CTeacher, CRecordset)

CTeacher::CTeacher(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Tno = "";
	m_Dno = "";
	m_Tname = "";
	m_Tsex = "";
	m_Tage = 0;
	m_Tworking;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CTeacher::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CTeacher::GetDefaultSQL()
{
	return _T("[dbo].[Teacher]");
}

void CTeacher::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[Tno]"), m_Tno);
	RFX_Text(pFX, _T("[Dno]"), m_Dno);
	RFX_Text(pFX, _T("[Tname]"), m_Tname);
	RFX_Text(pFX, _T("[Tsex]"), m_Tsex);
	RFX_Int(pFX, _T("[Tage]"), m_Tage);
	RFX_Date(pFX, _T("[Tworking]"), m_Tworking);

}
/////////////////////////////////////////////////////////////////////////////
// CTeacher ���

#ifdef _DEBUG
void CTeacher::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTeacher::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


