// InfoOrgView.cpp : CInfoOrgView 类的实现
//

#include "stdafx.h"
#include "InfoOrg.h"

#include "InfoOrgDoc.h"
#include "InfoOrgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInfoOrgView

IMPLEMENT_DYNCREATE(CInfoOrgView, CView)

BEGIN_MESSAGE_MAP(CInfoOrgView, CView)
END_MESSAGE_MAP()

// CInfoOrgView 构造/析构

CInfoOrgView::CInfoOrgView()
{
	// TODO: 在此处添加构造代码

}

CInfoOrgView::~CInfoOrgView()
{
}

BOOL CInfoOrgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CInfoOrgView 绘制

void CInfoOrgView::OnDraw(CDC* /*pDC*/)
{
	CInfoOrgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CInfoOrgView 诊断

#ifdef _DEBUG
void CInfoOrgView::AssertValid() const
{
	CView::AssertValid();
}

void CInfoOrgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CInfoOrgDoc* CInfoOrgView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInfoOrgDoc)));
	return (CInfoOrgDoc*)m_pDocument;
}
#endif //_DEBUG


// CInfoOrgView 消息处理程序
