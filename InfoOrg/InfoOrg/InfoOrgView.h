// InfoOrgView.h : CInfoOrgView ��Ľӿ�
//


#pragma once


class CInfoOrgView : public CView
{
protected: // �������л�����
	CInfoOrgView();
	DECLARE_DYNCREATE(CInfoOrgView)

// ����
public:
	CInfoOrgDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CInfoOrgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // InfoOrgView.cpp �еĵ��԰汾
inline CInfoOrgDoc* CInfoOrgView::GetDocument() const
   { return reinterpret_cast<CInfoOrgDoc*>(m_pDocument); }
#endif

