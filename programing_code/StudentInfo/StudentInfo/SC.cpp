// SC.h : CSC ���ʵ��



// CSC ʵ��

// ���������� 2018��6��5��, 20:53

#include "stdafx.h"
#include "SC.h"
IMPLEMENT_DYNAMIC(CSC, CRecordset)

CSC::CSC(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Sno = "";
	m_CourseNo = "";
	m_Score = 0.0;
	m_nFields = 3;
	m_nDefaultType = dynaset;
}

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CSC::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CSC::GetDefaultSQL()
{
	return _T("[dbo].[SC]");
}

void CSC::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[Sno]"), m_Sno);
	RFX_Text(pFX, _T("[CourseNo]"), m_CourseNo);
	RFX_Single(pFX, _T("[Score]"), m_Score);

}
/////////////////////////////////////////////////////////////////////////////
// CSC ���

#ifdef _DEBUG
void CSC::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSC::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


