// Department.h : CDepartment ���ʵ��



// CDepartment ʵ��

// ���������� 2018��6��5��, 20:52

#include "stdafx.h"
#include "Department.h"
IMPLEMENT_DYNAMIC(CDepartment, CRecordset)

CDepartment::CDepartment(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Dno = "";
	m_Tno = "";
	m_Dname = "";
	m_nFields = 3;
	m_nDefaultType = dynaset;
}

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDepartment::GetDefaultConnect()
{
	return _T("DSN=teaching;UID=sa;PWD=zy228830;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CDepartment::GetDefaultSQL()
{
	return _T("[dbo].[Department]");
}

void CDepartment::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[Dno]"), m_Dno);
	RFX_Text(pFX, _T("[Tno]"), m_Tno);
	RFX_Text(pFX, _T("[Dname]"), m_Dname);

}
/////////////////////////////////////////////////////////////////////////////
// CDepartment ���

#ifdef _DEBUG
void CDepartment::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDepartment::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


