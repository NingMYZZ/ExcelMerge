// InfoOrgDoc.h : CInfoOrgDoc ��Ľӿ�
//


#pragma once


class CInfoOrgDoc : public CDocument
{
protected: // �������л�����
	CInfoOrgDoc();
	DECLARE_DYNCREATE(CInfoOrgDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CInfoOrgDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


