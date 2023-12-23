
// Draw.h: Draw 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CDrawApp:
// 有关此类的实现，请参阅 Draw.cpp
//

class CDrawApp : public CWinApp
{
public:
	CDrawApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawApp theApp;
