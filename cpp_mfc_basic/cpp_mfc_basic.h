
// cpp_mfc_basic.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// основные символы


// CcppmfcbasicApp:
// Сведения о реализации этого класса: cpp_mfc_basic.cpp
//

class CcppmfcbasicApp : public CWinApp
{
public:
	CcppmfcbasicApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CcppmfcbasicApp theApp;
