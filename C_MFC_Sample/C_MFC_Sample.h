
// C_MFC_Sample.h : PROJECT_NAME 應用程式的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"		// 主要符號


// CC_MFC_SampleApp:
// 請參閱實作此類別的 C_MFC_Sample.cpp
//

class CC_MFC_SampleApp : public CWinApp
{
public:
	CC_MFC_SampleApp();

// 覆寫
public:
	virtual BOOL InitInstance();

// 程式碼實作

	DECLARE_MESSAGE_MAP()
};

extern CC_MFC_SampleApp theApp;