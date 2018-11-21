// BaseArea.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "InfoOrg.h"
#include "BaseArea.h"
#include <io.h>
using namespace std;

// BaseArea �Ի���

IMPLEMENT_DYNAMIC(BaseArea, CDialog)

BaseArea::BaseArea(CWnd* pParent /*=NULL*/)
	: CDialog(BaseArea::IDD, pParent)
	, FilePath(_T(""))
	, FileName(_T(""))
{

}

BaseArea::~BaseArea()
{
}

void BaseArea::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILE_PATH, FilePath);
	DDV_MaxChars(pDX, FilePath, 256);
	DDX_Text(pDX, IDC_EDIT_FILE_NAME, FileName);
}


BEGIN_MESSAGE_MAP(BaseArea, CDialog)
	ON_BN_CLICKED(IDOK, &BaseArea::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &BaseArea::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &BaseArea::OnBnClickedButton1)
END_MESSAGE_MAP()


// BaseArea ��Ϣ�������

void BaseArea::CreaTable(CString sFile,std::vector<CString>&FieldName)
{

	CDatabase database_w;
	CString sDriver="MICROSOFT EXCEL DRIVER (*.XLS)";


	CString sSQL;
	TRY 
	{	
		sSQL.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, sFile,sFile);
		if( database_w.OpenEx(sSQL,CDatabase::noOdbcDialog) )
		{
			sSQL="CREATE TABLE Sheet1(";

			for (int i=0;i<FieldName.size()-1;++i)
			{
				sSQL=sSQL+" "+FieldName[i]+" TEXT "+", ";
			}

			sSQL=sSQL+FieldName[FieldName.size()-1]+" TEXT "+" )";
			database_w.ExecuteSQL(sSQL);
		}
		database_w.Close();

	}
	CATCH (CMemoryException, e)
	{
		TRACE1("Excel����û�а�װ: %s",sDriver);
	}
	END_CATCH



}


void BaseArea::OnBnClickedOk()
{
	UpdateData(TRUE);
	vector<string>FileNameFolder;

	this->GetAllFormatFiles((LPCTSTR)(this->FilePath) ,FileNameFolder,".xls");
	vector<CString> item;

	CString buf=FileNameFolder[0].c_str();
	this->ReadExcelField(buf,item);     //(CString)FileNameFolder.at(0).c_str()    "C://Users//2018YZZ//Desktop//�༶��Ϣ//��ҵ��������Ϣ����-��Т��.xls"

	CString sExceFile =this->FilePath+"\\"+this->FileName+".xls";
	this->resFilePath=sExceFile;
	CString sSQL;


	this->CreaTable(sExceFile,item);

	for (int i=0;i<FileNameFolder.size();++i)
	{
		vector<CString> databuf;
		buf=FileNameFolder[i].c_str();
		this->ReadExcel(buf,databuf);
		this->WriteExcel(sExceFile,databuf);
	}






	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}



void BaseArea::ReadExcelField(CString sFile,std::vector<CString>&FieldName)
{
	CDatabase database;
	CString sSql;
	CString sDriver;
	CString sDsn;

	sDriver = GetExcelDriver();						// �����Ƿ�װ��Excel���� "Microsoft Excel Driver (*.xls)"
	if (sDriver.IsEmpty())
	{										
		AfxMessageBox("û�а�װ����");				// û�з���Excel����
		return;
	}

	// �������д�ȡ���ַ���
	sDsn.Format("ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, sFile);

	TRY
	{
		database.Open(NULL, false, false, sDsn);	// �����ݿ�(��Excel�ļ�)

		CRecordset recset(&database);

		sSql = sSql+ "SELECT *  FROM  [Sheet1$] ";

		// ִ�в�ѯ���
		recset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);

		//database.ExecuteSQL(sSql);


		short a=recset.GetODBCFieldCount();
		// �Ƶ���һ��
		//recset.MoveNext();
		for (int i=0;i<recset.GetODBCFieldCount();++i)
		{
			CODBCFieldInfo buffer;
			recset.GetODBCFieldInfo(i, buffer);
			FieldName.push_back(buffer.m_strName);
		}


		// �ر����ݿ�
		database.Close();

	}
	CATCH(CDBException, e)
	{
		// ���ݿ���������쳣ʱ...
		AfxMessageBox("���ݿ����: " + e->m_strError);
	}
	END_CATCH;

}




void BaseArea::ReadExcel(CString sFile,vector<CString> &sItem)
{
	CDatabase database;
	CString sSql;
	CString sDriver;
	CString sDsn;
	
	sDriver = GetExcelDriver();						// �����Ƿ�װ��Excel���� "Microsoft Excel Driver (*.xls)"
	if (sDriver.IsEmpty())
	{										
		AfxMessageBox("û�а�װ����");				// û�з���Excel����
		return;
	}


	//char drive[256];
	//char dir[256];
	//char fname[256];
	//char ext[256];
	//_splitpath( (char *)(LPCTSTR)sFile , drive, dir, fname, ext);

	// �������д�ȡ���ַ���
	sDsn.Format("ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, sFile);

	TRY
	{
		database.Open(NULL, false, false, sDsn);	// �����ݿ�(��Excel�ļ�)

		CRecordset recset(&database);

		sSql = sSql+ "SELECT *  FROM  [Sheet1$] ";

		// ִ�в�ѯ���
		recset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);
		
		//database.ExecuteSQL(sSql);


		short a=recset.GetODBCFieldCount();
		// �Ƶ���һ��
		//recset.MoveNext();
		for (int i=0;i<recset.GetODBCFieldCount();++i)
		{
				
			CString buffer;
			recset.GetFieldValue(i, buffer);
			sItem.push_back(buffer);
		}
		
		
		// �ر����ݿ�
		database.Close();

	}
	CATCH(CDBException, e)
	{
		// ���ݿ���������쳣ʱ...
		AfxMessageBox("���ݿ����: " + e->m_strError);
	}
	END_CATCH;
}





void BaseArea::WriteExcel(CString sFile,vector<CString> sItem)
{

	CDatabase database;
	CString sDriver = "Microsoft Excel Driver (*.xls)"; // Excel��װ����
	CString sSql;


	//char drive[256];
	//char dir[256];
	//char fname[256];
	//char ext[256];

	//_splitpath( (char*)(LPCTSTR)sItem[0] , drive, dir, fname, ext);

	TRY
	{
		// �������д�ȡ���ַ���
		sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, sFile, sFile);

		// �������ݿ� (��Excel����ļ�)
		if (database.OpenEx(sSql,CDatabase::noOdbcDialog))
		{
			sSql="";
			sSql =sSql+ " INSERT INTO " +"Sheet1" +" VALUES(";
			for (int i=0;i<sItem.size()-1;++i)
			{
				sSql+=	sItem[i]+", " ;
			}

			sSql=sSql+sItem[sItem.size()-1]+")";
			database.ExecuteSQL(sSql);

		}

		// �ر����ݿ�
		database.Close();
	}
	CATCH_ALL(e)
	{
		AfxMessageBox("����ʧ��");
	}
	END_CATCH_ALL;
}












CString BaseArea::GetExcelDriver()
{
	char szBuf[2001];
	WORD cbBufMax = 2000;
	WORD cbBufOut;
	char *pszBuf = szBuf;
	CString sDriver;

	// ��ȡ�Ѱ�װ����������(������odbcinst.h��)
	if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))
		return "";

	// �����Ѱ�װ�������Ƿ���Excel...
	do
	{
		if (strstr(pszBuf, "Excel") != 0)
		{
			//���� !
			sDriver = CString(pszBuf);
			break;
		}
		pszBuf = strchr(pszBuf, '\0') + 1;
	} while (pszBuf[1] != '\0');

	return sDriver;
}


void BaseArea::GetAllFormatFiles( string path, vector<string>& files,string format)    
{    
	//�ļ����    
	long   hFile   =   0;    
	//�ļ���Ϣ    
	struct _finddata_t fileinfo; 
	string p;    
	if((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(),&fileinfo)) !=  -1)		 //��path��ֵ����p��"\\*" + format�ӵ�p����
	{    
		do    
		{      
			if((fileinfo.attrib &  _A_SUBDIR))														//������ļ���
			{    
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)				//�����Ϊ0
				{           
					GetAllFormatFiles( p.assign(path).append("\\").append(fileinfo.name), files,format);   
				}  
			}    
			else    
			{    
				files.push_back(p.assign(path).append("\\").append(fileinfo.name) );				//��vertor�м��� ���Ŀ¼ 
			}

		}while(_findnext(hFile, &fileinfo)  == 0);    

		_findclose(hFile);   
	}   
}  






void BaseArea::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}


int CALLBACK BrowseCallbackProc(HWND hwnd,UINT uMsg,LPARAM lParam,LPARAM lpData)
{
	switch(uMsg)
	{
	case BFFM_INITIALIZED:
		::SendMessage(hwnd,BFFM_SETSELECTION,TRUE,lpData);
		break;
	}

	return 0;
}


void BaseArea::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char       szDir[MAX_PATH]="";
	BROWSEINFO bi; 

	bi.hwndOwner = this ? this->GetSafeHwnd() : NULL;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szDir;
	bi.lpszTitle = "��ѡ���ļ�����Ŀ¼:";
	bi.iImage = 0;
	bi.ulFlags = BIF_USENEWUI | BIF_RETURNONLYFSDIRS;
	bi.lpfn = BrowseCallbackProc;
	bi.lParam = 0;

	LPITEMIDLIST lp = SHBrowseForFolder(&bi);
	if (lp && SHGetPathFromIDList(lp,szDir))
	{
		FilePath = szDir;
	}
	else
	{
		FilePath="";
	}
	UpdateData(FALSE);


}
