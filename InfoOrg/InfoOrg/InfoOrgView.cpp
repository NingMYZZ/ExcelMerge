// InfoOrgView.cpp : CInfoOrgView ���ʵ��
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

// CInfoOrgView ����/����

CInfoOrgView::CInfoOrgView()
{
	// TODO: �ڴ˴���ӹ������

}

CInfoOrgView::~CInfoOrgView()
{
}

BOOL CInfoOrgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CInfoOrgView ����

void CInfoOrgView::OnDraw(CDC* /*pDC*/)
{
	CInfoOrgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CInfoOrgView ���

#ifdef _DEBUG
void CInfoOrgView::AssertValid() const
{
	CView::AssertValid();
}

void CInfoOrgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CInfoOrgDoc* CInfoOrgView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInfoOrgDoc)));
	return (CInfoOrgDoc*)m_pDocument;
}
#endif //_DEBUG


// CInfoOrgView ��Ϣ�������
