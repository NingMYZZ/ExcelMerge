// InfoOrg.cpp : ����Ӧ�ó��������Ϊ��
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


// CInfoOrgApp ����

CInfoOrgApp::CInfoOrgApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CInfoOrgApp ����

CInfoOrgApp theApp;


// CInfoOrgApp ��ʼ��

BOOL CInfoOrgApp::InitInstance()
{
	CWinApp::InitInstance();


	pBaseArea.DoModal();


	return TRUE;
}

