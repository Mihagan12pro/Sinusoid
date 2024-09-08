
// Sinusoid.h: основной файл заголовка для приложения Sinusoid
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSinusoidApp:
// Сведения о реализации этого класса: Sinusoid.cpp
//

class CSinusoidApp : public CWinApp
{
public:
	CSinusoidApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSinusoidApp theApp;
