// InfoOrgDoc.cpp : CInfoOrgDoc 类的实现
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


// CInfoOrgDoc 构造/析构

CInfoOrgDoc::CInfoOrgDoc()
{
	// TODO: 在此添加一次性构造代码

}

CInfoOrgDoc::~CInfoOrgDoc()
{
}

BOOL CInfoOrgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CInfoOrgDoc 序列化

void CInfoOrgDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CInfoOrgDoc 诊断

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


// CInfoOrgDoc 命令
