// InfoOrg.h : InfoOrg Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "BaseArea.h"

// CInfoOrgApp:
// �йش����ʵ�֣������ InfoOrg.cpp
//

class CInfoOrgApp : public CWinApp
{
public:
	CInfoOrgApp();

	BaseArea pBaseArea;
// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CInfoOrgApp theApp;