/* 
 * FFmpeg for MFC
 *
 * ������ Lei Xiaohua
 * leixiaohua1020@126.com
 * �й���ý��ѧ/���ֵ��Ӽ���
 * Communication University of China / Digital TV Technology
 *
 * http://blog.csdn.net/leixiaohua1020
 * 
 * �����̽�ffmpeg�����е�ffmpegת������ffmpeg.c����ֲ����VC�����¡�
 * ����ʹ��MFC����һ�׼򵥵Ľ��档
 * This software transplant ffmpeg to Microsoft VC++ environment. 
 * And use MFC to build a simple Graphical User Interface. 
 */

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CffmpegmfcApp:
// �йش����ʵ�֣������ ffmpegmfc.cpp
//

class CffmpegmfcApp : public CWinApp
{
public:
	CffmpegmfcApp();

	void LoadLanguage();
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CffmpegmfcApp theApp;