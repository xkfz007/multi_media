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


// TaskinfoDlg �Ի���

// Task ��Ϣ�ı༭
// Edit Task Information
class CffmpegmfcDlg;

class TaskinfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TaskinfoDlg)

public:
	TaskinfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TaskinfoDlg();

// �Ի�������
	enum { IDD = IDD_TASKINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//�Ի����ʼ��
	//Init Dialog
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	//CMFCPropertyGridCtrl
	CMFCPropertyGridCtrl m_taskinfoparam;
	CMFCPropertyGridProperty *format;
	CMFCPropertyGridProperty *format_if;
	CMFCPropertyGridProperty *format_of;
	CMFCPropertyGridProperty *video;
	CMFCPropertyGridProperty *video_bitrate;
	CMFCPropertyGridProperty *video_codec;
	CMFCPropertyGridProperty *video_framerate;
	CMFCPropertyGridProperty *video_reso;
	CMFCPropertyGridProperty *video_reso_w;
	CMFCPropertyGridProperty *video_reso_h;
	CMFCPropertyGridProperty *audio;
	CMFCPropertyGridProperty *audio_bitrate;
	CMFCPropertyGridProperty *audio_codec;
	CMFCPropertyGridProperty *audio_samplerate;
	CMFCPropertyGridProperty *audio_channels;

	
	//�༭��Task
	//Task
	TaskDlgState state;
	int tasklistid;
	Task task;
	//���Ի���
	//Main Dialog
	CffmpegmfcDlg *maindlg;

	//��װ��ʽ���������������Ϣ
	//Container formats, video codecs, audio codecs list
	vector<CString> iflist;
	vector<CString> oflist;
	vector<CString> vclist;
	vector<CString> aclist;

	//��ȡ֧�ֵķ�װ��ʽ����Ϣ�б�
	//Get support container format, video codec, audio codec etc. 
	void GetNamelist();

	//����Task
	//Set Task
	void SetTask();
	//����Task
	//Load Task
	void LoadTask(TaskDlgState state_temp,int tasklistid_temp);
	//ȷ����ť
	//"OK" Button
	afx_msg void OnBnClickedOk();
	//ȡ����ť
	//"Cancel" Button
	afx_msg void OnBnClickedCancel();
	//��ק�ļ�
	//Drop file
	afx_msg void OnDropFiles(HDROP hDropInfo);
	//��������ļ���Ϣ
	//Check input file information
	BOOL CheckInputMedia(CString url);

	CEdit m_codecachannels;
	CEdit m_codecaname;
	CEdit m_codecasamplerate;
	CEdit m_codecvframerate;
	CEdit m_codecvname;
	CEdit m_codecvresolution;
	CEdit m_formatbitrate;
	CEdit m_formatduration;
	CEdit m_formatinputformat;
	

	//Input/Output
	CEdit m_taskinfoinfile;
	CEdit m_taskinfooutfile;
	//���򿪡��ļ��Ի���
	//"Open" Dialog
	afx_msg void OnBnClickedTaskinfoInfileFdlg();
	//�����桱�ļ��Ի���
	//"Save" Dialog
	afx_msg void OnBnClickedTaskinfoOutfileFdlg();
	//���������ļ�·����������Ԥ�������ļ�·��
	//Set input and output URL
	void SetInputandOutput(CString inputurl);
	//��Ƶ��/��Ƶ��ID
	int	video_stream;
	int	audio_stream;
	
};
