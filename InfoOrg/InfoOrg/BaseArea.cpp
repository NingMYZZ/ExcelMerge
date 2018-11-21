// BaseArea.cpp : 实现文件
//

#include "stdafx.h"
#include "InfoOrg.h"
#include "BaseArea.h"
#include <io.h>
using namespace std;

// BaseArea 对话框

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


// BaseArea 消息处理程序

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
		TRACE1("Excel驱动没有安装: %s",sDriver);
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
	this->ReadExcelField(buf,item);     //(CString)FileNameFolder.at(0).c_str()    "C://Users//2018YZZ//Desktop//班级信息//毕业本科生信息报表-贾孝良.xls"

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






	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}



void BaseArea::ReadExcelField(CString sFile,std::vector<CString>&FieldName)
{
	CDatabase database;
	CString sSql;
	CString sDriver;
	CString sDsn;

	sDriver = GetExcelDriver();						// 检索是否安装有Excel驱动 "Microsoft Excel Driver (*.xls)"
	if (sDriver.IsEmpty())
	{										
		AfxMessageBox("没有安装驱动");				// 没有发现Excel驱动
		return;
	}

	// 创建进行存取的字符串
	sDsn.Format("ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, sFile);

	TRY
	{
		database.Open(NULL, false, false, sDsn);	// 打开数据库(既Excel文件)

		CRecordset recset(&database);

		sSql = sSql+ "SELECT *  FROM  [Sheet1$] ";

		// 执行查询语句
		recset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);

		//database.ExecuteSQL(sSql);


		short a=recset.GetODBCFieldCount();
		// 移到下一行
		//recset.MoveNext();
		for (int i=0;i<recset.GetODBCFieldCount();++i)
		{
			CODBCFieldInfo buffer;
			recset.GetODBCFieldInfo(i, buffer);
			FieldName.push_back(buffer.m_strName);
		}


		// 关闭数据库
		database.Close();

	}
	CATCH(CDBException, e)
	{
		// 数据库操作产生异常时...
		AfxMessageBox("数据库错误: " + e->m_strError);
	}
	END_CATCH;

}




void BaseArea::ReadExcel(CString sFile,vector<CString> &sItem)
{
	CDatabase database;
	CString sSql;
	CString sDriver;
	CString sDsn;
	
	sDriver = GetExcelDriver();						// 检索是否安装有Excel驱动 "Microsoft Excel Driver (*.xls)"
	if (sDriver.IsEmpty())
	{										
		AfxMessageBox("没有安装驱动");				// 没有发现Excel驱动
		return;
	}


	//char drive[256];
	//char dir[256];
	//char fname[256];
	//char ext[256];
	//_splitpath( (char *)(LPCTSTR)sFile , drive, dir, fname, ext);

	// 创建进行存取的字符串
	sDsn.Format("ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, sFile);

	TRY
	{
		database.Open(NULL, false, false, sDsn);	// 打开数据库(既Excel文件)

		CRecordset recset(&database);

		sSql = sSql+ "SELECT *  FROM  [Sheet1$] ";

		// 执行查询语句
		recset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);
		
		//database.ExecuteSQL(sSql);


		short a=recset.GetODBCFieldCount();
		// 移到下一行
		//recset.MoveNext();
		for (int i=0;i<recset.GetODBCFieldCount();++i)
		{
				
			CString buffer;
			recset.GetFieldValue(i, buffer);
			sItem.push_back(buffer);
		}
		
		
		// 关闭数据库
		database.Close();

	}
	CATCH(CDBException, e)
	{
		// 数据库操作产生异常时...
		AfxMessageBox("数据库错误: " + e->m_strError);
	}
	END_CATCH;
}





void BaseArea::WriteExcel(CString sFile,vector<CString> sItem)
{

	CDatabase database;
	CString sDriver = "Microsoft Excel Driver (*.xls)"; // Excel安装驱动
	CString sSql;


	//char drive[256];
	//char dir[256];
	//char fname[256];
	//char ext[256];

	//_splitpath( (char*)(LPCTSTR)sItem[0] , drive, dir, fname, ext);

	TRY
	{
		// 创建进行存取的字符串
		sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, sFile, sFile);

		// 创建数据库 (既Excel表格文件)
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

		// 关闭数据库
		database.Close();
	}
	CATCH_ALL(e)
	{
		AfxMessageBox("插入失败");
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

	// 获取已安装驱动的名称(涵数在odbcinst.h里)
	if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))
		return "";

	// 检索已安装的驱动是否有Excel...
	do
	{
		if (strstr(pszBuf, "Excel") != 0)
		{
			//发现 !
			sDriver = CString(pszBuf);
			break;
		}
		pszBuf = strchr(pszBuf, '\0') + 1;
	} while (pszBuf[1] != '\0');

	return sDriver;
}


void BaseArea::GetAllFormatFiles( string path, vector<string>& files,string format)    
{    
	//文件句柄    
	long   hFile   =   0;    
	//文件信息    
	struct _finddata_t fileinfo; 
	string p;    
	if((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(),&fileinfo)) !=  -1)		 //把path的值赋给p，"\\*" + format加到p后面
	{    
		do    
		{      
			if((fileinfo.attrib &  _A_SUBDIR))														//如果是文件夹
			{    
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)				//相等则为0
				{           
					GetAllFormatFiles( p.assign(path).append("\\").append(fileinfo.name), files,format);   
				}  
			}    
			else    
			{    
				files.push_back(p.assign(path).append("\\").append(fileinfo.name) );				//在vertor中加入 这个目录 
			}

		}while(_findnext(hFile, &fileinfo)  == 0);    

		_findclose(hFile);   
	}   
}  






void BaseArea::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	char       szDir[MAX_PATH]="";
	BROWSEINFO bi; 

	bi.hwndOwner = this ? this->GetSafeHwnd() : NULL;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szDir;
	bi.lpszTitle = "请选择文件所在目录:";
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
