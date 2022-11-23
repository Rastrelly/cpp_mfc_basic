
// cpp_mfc_basicDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CcppmfcbasicDlg
class CcppmfcbasicDlg : public CDialogEx
{
// Создание
public:
	CcppmfcbasicDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CPP_MFC_BASIC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	// edit for entering second value
	CEdit Edit3;
	// arithmetic ops
	CComboBox cbOpList;
	CEdit Edit1;
	CEdit Edit2;
	afx_msg void OnBnClickedButton2();
	CButton rb1_1;
	CButton rb1_2;
	CButton rb1_3;
	CButton rb2_1;
	CButton rb2_2;	
};
