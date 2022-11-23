
// cpp_mfc_basicDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "cpp_mfc_basic.h"
#include "cpp_mfc_basicDlg.h"
#include "afxdialogex.h"

#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CcppmfcbasicDlg



CcppmfcbasicDlg::CcppmfcbasicDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CPP_MFC_BASIC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcppmfcbasicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, Edit3);
	DDX_Control(pDX, IDC_COMBO1, cbOpList);
	DDX_Control(pDX, IDC_EDIT1, Edit1);
	DDX_Control(pDX, IDC_EDIT2, Edit2);
	DDX_Control(pDX, IDC_RADIO1_1, rb1_1);
	DDX_Control(pDX, IDC_RADIO1_2, rb1_2);
	DDX_Control(pDX, IDC_RADIO2_1, rb2_1);
	DDX_Control(pDX, IDC_RADIO2_2, rb2_2);
	DDX_Control(pDX, IDC_RADIO1_3, rb1_3);
}

BEGIN_MESSAGE_MAP(CcppmfcbasicDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CcppmfcbasicDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CcppmfcbasicDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CcppmfcbasicDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcppmfcbasicDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Обработчики сообщений CcppmfcbasicDlg

BOOL CcppmfcbasicDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// init component states
	Edit1.SetWindowTextW(L"10");
	Edit3.SetWindowTextW(L"2");

	cbOpList.AddString(L"+");
	cbOpList.AddString(L"-");
	cbOpList.AddString(L"*");
	cbOpList.AddString(L"/");
	cbOpList.SelectString(0,L"+");

	rb1_1.SetCheck(true);
	rb2_1.SetCheck(true);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CcppmfcbasicDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CcppmfcbasicDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CcppmfcbasicDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcppmfcbasicDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void CcppmfcbasicDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
	
}


void CcppmfcbasicDlg::OnBnClickedButton1()
{
	CString txt = L"";
	CWnd *edit1 = GetDlgItem(IDC_EDIT1);
	CWnd *edit2 = GetDlgItem(IDC_EDIT2);
	edit1->GetWindowTextW(txt);
	int a = _wtoi(txt);

	Edit3.GetWindowTextW(txt); //to get this create a variable
	//via right click menu on element
	int b = _wtoi(txt);

	cbOpList.GetWindowTextW(txt);

	int c = 0;

	if(txt==L"+") c = a + b;
	if (txt == L"-") c = a - b;
	if (txt == L"*") c = a * b;
	if (b != 0) if (txt == L"/") c = a / b;
	
	txt = std::to_wstring(c).c_str();
	//txt = (CString)std::to_string(b).c_str(); <- for ASCII
	edit2->SetWindowTextW(txt);
}


void CcppmfcbasicDlg::OnBnClickedButton2()
{
	int sel1 = rb1_1.GetCheck() ? 0 : 1;
	if (sel1==1) sel1 = rb1_2.GetCheck() ? 1 : 2;

	int sel2 = rb2_1.GetCheck() ? 0 : 1;
	CString dat = L"";

	if (sel1 == 0) dat += L"RB1-1";
	else if (sel1 == 1) dat += L"RB1-2";
	else dat += L"RB1-3";

	if (sel2 == 0) dat += L" RB2-1";
	else dat += L" RB2-2";
	MessageBox(dat,L"Radio buttons",MB_OK);
}
