// InfoOrg.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "InfoOrg.h"
#include "MainFrm.h"

#include "InfoOrgDoc.h"
#include "InfoOrgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInfoOrgApp

BEGIN_MESSAGE_MAP(CInfoOrgApp, CWinApp)

END_MESSAGE_MAP()


// CInfoOrgApp 构造

CInfoOrgApp::CInfoOrgApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CInfoOrgApp 对象

CInfoOrgApp theApp;


// CInfoOrgApp 初始化

BOOL CInfoOrgApp::InitInstance()
{
	CWinApp::InitInstance();


	pBaseArea.DoModal();


	return TRUE;
}

