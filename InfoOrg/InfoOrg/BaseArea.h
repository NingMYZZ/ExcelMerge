#pragma once

#include <string>
#include <vector>
// BaseArea 对话框

class BaseArea : public CDialog
{
	DECLARE_DYNAMIC(BaseArea)

public:
	BaseArea(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BaseArea();


	void GetAllFormatFiles( std::string path, std::vector<std::string>& files,std::string format);


	void ReadExcelField(CString sFile,std::vector<CString>&FieldName);
	void CreaTable(CString sFile,std::vector<CString>&FieldName);

	void ReadExcel(CString sFile,std::vector<CString> &sItem);
	void WriteExcel(CString sFile,std::vector<CString> sItem);
	CString BaseArea::GetExcelDriver();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();           //确定
	afx_msg void OnBnClickedCancel();		//返回
	afx_msg void OnBnClickedButton1();      //选择文件夹
public:
	// 文件路径
	CString FilePath;
public:
	CString FileName;
	CString resFilePath;
};
