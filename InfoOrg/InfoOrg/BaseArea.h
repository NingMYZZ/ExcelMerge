#pragma once

#include <string>
#include <vector>
// BaseArea �Ի���

class BaseArea : public CDialog
{
	DECLARE_DYNAMIC(BaseArea)

public:
	BaseArea(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BaseArea();


	void GetAllFormatFiles( std::string path, std::vector<std::string>& files,std::string format);


	void ReadExcelField(CString sFile,std::vector<CString>&FieldName);
	void CreaTable(CString sFile,std::vector<CString>&FieldName);

	void ReadExcel(CString sFile,std::vector<CString> &sItem);
	void WriteExcel(CString sFile,std::vector<CString> sItem);
	CString BaseArea::GetExcelDriver();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();           //ȷ��
	afx_msg void OnBnClickedCancel();		//����
	afx_msg void OnBnClickedButton1();      //ѡ���ļ���
public:
	// �ļ�·��
	CString FilePath;
public:
	CString FileName;
	CString resFilePath;
};
