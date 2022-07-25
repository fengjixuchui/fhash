// MD5SUM03Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include "HyperEditHash.h"

#include "Common/strhelper.h"
#include "OsUtils/OsThread.h"

#include "Common/Global.h"
#include "UIBridgeMFC.h"

// CMD5SUM03Dlg �Ի���
class CFilesHashDlg : public CDialog
{
// ����
public:
	CFilesHashDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MAIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedAbout();
	afx_msg void OnBnClickedClean();
	afx_msg void OnBnClickedFind();
	afx_msg void OnBnClickedContext();
	afx_msg void OnBnClickedCheckup();
	afx_msg void OnBnClickedUpperHash();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnThreadMsg(WPARAM, LPARAM);
	afx_msg LRESULT OnCustomMsg(WPARAM, LPARAM);
	afx_msg void OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnHypereditmenuCopyhash();
	afx_msg void OnHypereditmenuSearchgoogle();
	afx_msg void OnHypereditmenuSearchvirustotal();
	afx_msg void OnUpdateHypereditmenuCopyhash(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHypereditmenuSearchgoogle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHypereditmenuSearchvirustotal(CCmdUI *pCmdUI);

// ʵ��
protected:
	HICON m_hIcon;

	CProgressCtrl m_progWhole;
	CHyperEditHash m_editMain;
	CButton m_btnOpen;
	CButton m_btnExit;
	CButton m_btnClr;
	CButton m_btnFind;
	CButton m_chkUppercase;
	CButton m_btnContext;

	sunjwbase::OsMutex m_mainMtx;

	UIBridgeMFC *m_uiBridgeMFC;
	ThreadData m_thrdData;
	HANDLE m_hWorkThread;
	float m_calculateTime;
	UINT_PTR m_timer;
	BOOL m_waitingExit; // �ȴ��߳��˳����˳�����
	BOOL m_bAdvTaskbar;
	ITaskbarList3* pTl;

	BOOL m_bFind; // �Ƿ�������ģʽ
	CString m_strFindFile;
	CString m_strFindHash;

	BOOL m_bLimited;

	TStrVector ParseFilesCmdLine(LPTSTR filesCmdLine);
	void ClearFilePaths();
	void PrepareAdvTaskbar();

	void ResultFind(CString strFile, CString strHash);
	void AppendResult(const ResultData& result);
	void ClearFind();

	void DoMD5();
	void StopWorkingThread();
	
	// �����Ϊ����ʱʹ�ã�һ�㲻Ҫ��
	void SetCtrls(BOOL working);
	void SetWholeProgPos(UINT pos);
	void RefreshResult();
	void RefreshMainText(BOOL bScrollToEnd = TRUE);
	void CalcSpeed(ULONGLONG tsize);

};
