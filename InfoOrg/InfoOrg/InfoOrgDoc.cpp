// InfoOrgDoc.cpp : CInfoOrgDoc ���ʵ��
//

#include "stdafx.h"
#include "InfoOrg.h"

#include "InfoOrgDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInfoOrgDoc

IMPLEMENT_DYNCREATE(CInfoOrgDoc, CDocument)

BEGIN_MESSAGE_MAP(CInfoOrgDoc, CDocument)
END_MESSAGE_MAP()


// CInfoOrgDoc ����/����

CInfoOrgDoc::CInfoOrgDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CInfoOrgDoc::~CInfoOrgDoc()
{
}

BOOL CInfoOrgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CInfoOrgDoc ���л�

void CInfoOrgDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CInfoOrgDoc ���

#ifdef _DEBUG
void CInfoOrgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CInfoOrgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CInfoOrgDoc ����
