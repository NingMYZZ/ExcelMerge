// InfoOrgView.h : CInfoOrgView 类的接口
//


#pragma once


class CInfoOrgView : public CView
{
protected: // 仅从序列化创建
	CInfoOrgView();
	DECLARE_DYNCREATE(CInfoOrgView)

// 属性
public:
	CInfoOrgDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CInfoOrgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // InfoOrgView.cpp 中的调试版本
inline CInfoOrgDoc* CInfoOrgView::GetDocument() const
   { return reinterpret_cast<CInfoOrgDoc*>(m_pDocument); }
#endif

