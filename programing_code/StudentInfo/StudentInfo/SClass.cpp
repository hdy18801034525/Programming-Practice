// SClass.h : CSClass ���ʵ��



// CSClass ʵ��

// ���������� 2018��6��5��, 20:57

#include "stdafx.h"
#include "SClass.h"
IMPLEMENT_DYNAMIC(CSClass, CRecordset)

CSClass::CSClass(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ClassNo = "";
	m_ClassName = "";
	m_Major = "";
	m_Grade = "";
	m_Number = 0;
	m_Advisor = "";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CSClass::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CSClass::GetDefaultSQL()
{
	return _T("[dbo].[SClass]");
}

void CSClass::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[ClassNo]"), m_ClassNo);
	RFX_Text(pFX, _T("[ClassName]"), m_ClassName);
	RFX_Text(pFX, _T("[Major]"), m_Major);
	RFX_Text(pFX, _T("[Grade]"), m_Grade);
	RFX_Int(pFX, _T("[Number]"), m_Number);
	RFX_Text(pFX, _T("[Advisor]"), m_Advisor);

}
/////////////////////////////////////////////////////////////////////////////
// CSClass ���

#ifdef _DEBUG
void CSClass::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSClass::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


