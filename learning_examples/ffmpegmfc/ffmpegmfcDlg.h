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



#include "TaskinfoDlg.h"
#include "SysinfoDlg.h"



// CffmpegmfcDlg �Ի���
class CffmpegmfcDlg : public CDialogEx
{
// ����
public:
	CffmpegmfcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FFMPEGMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	CWinThread *pThreadffmpeg;

	//��ʼ��
	//Init Dialog
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	//Main Button
	//����ʼ����ť
	//"Start" Button
	afx_msg void OnBnClickedStart();
	//����ͣ����ť
	//"Pause" Button
	afx_msg void OnBnClickedPause();
	//��ֹͣ����ť
	//"Stop" Button
	afx_msg void OnBnClickedStop();
	//�����б�ġ���ӡ���ť
	//TaskList's "Add" Button
	afx_msg void OnBnClickedTasklistAdd();
	//�����б�ġ��༭����ť
	//TaskList's "Add" Button
	afx_msg void OnBnClickedTasklistEdit();
	//�����б�ġ�ɾ������ť
	//TaskList's "Delete" Button
	afx_msg void OnBnClickedTasklistDelete();
	//�����б�ġ���ա���ť
	//TaskList's "Clear" Button
	afx_msg void OnBnClickedTasklistClear();
	//�����б����ɫ
	//TaskList's Color
	void OnCustomdrawMyList ( NMHDR* pNMHDR, LRESULT* pResult );
	//ϵͳ��λ
	//Reset System
	void SystemClear();

	
	Systemstate state;
	//����ϵͳ״̬���ð�ť
	//Set Buuton's state
	void SetBtn(Systemstate state);

	//TaskList
	vector<Task> tasklist;
	//���һ������
	//Add a task
	void TasklistAdd(Task task);
	//�༭һ������
	//Edit a task
	void TasklistEdit(Task task,int taskid);
	//CmdStr
	//��ȡһ�������в���
	//Get a command's parameter
	vector<CString> GetCmdargv(int taskid);
	//��ȡ���е������в���
	//Get all command's parameter
	void GetAllCmdargv();
	vector<vector<CString>> cmdargvlist;
	char **charlist;
	int charlist_size;
	//CString��Vectorת��Ϊ char **
	//Convert CString Vector to char **
	char ** CStringListtoCharList(vector<CString> cmdargv);
	//CString��Vector�ϲ�Ϊһ��CString
	//Convert CString Vector to a CString
	CString CStringListtoCString(vector<CString> cmdargv);
	//�ͷ�һ�� char **
	//Free a char **
	void FreeCharList(char **charlist);

	//ProgressBar
	int current_process;
	int all_process;
	//���ý��ȵ���Ϣ��Ӧ����
	//Callback of Set Progress Message
	LRESULT OnSetProgress(WPARAM wParam, LPARAM lParam );
	//���ý���
	//Set Progress
	void SetProgress(int current,int all);
	CProgressCtrl m_progresscurrent;
	CProgressCtrl m_progressall;
	CEdit m_progressallp;
	CEdit m_progresscurrentp;

	//ListCtrl
	//�����б�
	//Refresh TaskList
	void RefreshList();
	//��ȡ�ļ�·���е��ļ���
	//Get filename in an URL
	CString URLtoFilename(CString url);
	//�ֽڵ�λ���ļ���Сת��ΪKBMBGB
	//Convert bytes to KBMBGB
	CString bytetoKBMBGB(int filesize);
	CListCtrl m_tasklist;

	//Dialog
	TaskinfoDlg *taskinfodlg;
	SysinfoDlg sysinfodlg;

	//TaskList�˵�
	CMenu tasklistmenu;
	CMenu *ptasklistsubmenu;
	//Menu
	//�����ڡ��Ի���
	//"About" Dialog
	afx_msg void OnAbout();
	//��ϵͳ��Ϣ���Ի���
	//"System Information" Dialog
	afx_msg void OnSysinfo();
	//��������Ϊ����
	//Set Language to Chinese
	afx_msg void OnLangCn();
	//��������ΪӢ��
	//Set Language to English
	afx_msg void OnLangEn();
	//˫�������б��޸�����
	//Double Click Tasklist
	afx_msg void OnDblclkTasklist(NMHDR *pNMHDR, LRESULT *pResult);
	//�Ҽ������б������˵���
	//Right Click Tasklist
	afx_msg void OnRclickTasklist(NMHDR *pNMHDR, LRESULT *pResult);
	//��ק�ļ�
	//Drop file
	afx_msg void OnDropFiles(HDROP hDropInfo);
	//��վ
	//Website
	afx_msg void OnWebsite();
	//�˳�
	//Exit
	afx_msg void OnIdcancel();

	afx_msg void OnOuttranscode();
	afx_msg void OnIntranscode();
	//ģʽ
	void LoadTranscodemode();
	Transcodemode transcodemode;
};
