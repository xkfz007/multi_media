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
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#include <afxdisp.h>        // MFC �Զ�����



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // �������Ϳؼ����� MFC ֧��

#include <io.h>

#include <vector>
using std::vector;
//--------------------
/* 
 *
 * ����༭�Ի���
 * �༭������ӣ�
 *
 */
typedef enum TaskDlgState{
	TASK_DLG_ADD,
	TASK_DLG_EDIT
}TaskDlgState;


/* 
 *
 * ϵͳ״̬
 *
 */
typedef enum Systemstate{
	SYSTEM_PREPARE,
	SYSTEM_PROCESS,
	SYSTEM_PAUSE
}Systemstate;

/* 
 *
 * ����״̬
 *
 */
typedef enum Taskstate{
	TASK_PREPARE,
	TASK_PROCESS,
	TASK_FINISH
}Taskstate;

/* 
 *
 * ת��ģʽ
 *
 */
typedef enum Transcodemode{
	MODE_INTERNAL,
	MODE_EXTERNAL
}Transcodemode;


/* 
 *
 * ����
 *
 */
typedef struct Task{
	CString infile;
	long long insize;
	CString outfile;
	CString ifname;
	CString ofname;
	CString vcname;
	int vbitrate;
	double framerate;
	int reso_w;
	int reso_h;
	CString acname;
	int abitrate;
	int samplefmt;
	int channels;
	Taskstate taskstate;
	//�Ƿ������Ƶ��/��Ƶ����
	int	video_stream;
	int	audio_stream;
}Task;

//--------------------





#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


