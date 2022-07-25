// AboutDlg.cpp : ʵ���ļ�
// SUN Junwen

#include "stdafx.h"

#include <atlbase.h>

#include "version.h"
#include "FilesHash.h"
#include "AboutDlg.h"
#include "WindowsUtils.h"
#include "WinCommon/WindowsComm.h"
#include "WinCommon/WindowsStrings.h"

// CAboutDlg �Ի���

IMPLEMENT_DYNAMIC(CAboutDlg, CDialog)
CAboutDlg::CAboutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAboutDlg::IDD, pParent)
	, m_about(_T(""))
{
}

CAboutDlg::~CAboutDlg()
{
}

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetWindowText(GetStringByKey(ABOUTDLG_TITLE)); // ���ñ���

	CWnd* pWnd;
	pWnd = GetDlgItem(IDOK);
	pWnd->SetWindowText(GetStringByKey(BUTTON_OK));
	pWnd = GetDlgItem(IDC_SYSLINK_SITE);
	pWnd->SetWindowText(GetStringByKey(ABOUTDLG_PROJECT_SITE));

	CString fHashVersion = _T(STR_VERSION); //GetExeFileVersion(exeFullPath);

	sunjwbase::tstring tstrOsinfo = WindowsComm::GetWindowsInfo();
	m_about = GetStringByKey(ABOUTDLG_INFO_TITLE);
	m_about.Append(_T(" "));
	m_about.Append(fHashVersion);
	if (sizeof(void*) == 8)
	{
		m_about.Append(_T(" x64"));
	}
	m_about.Append(_T("\r\n"));
	m_about.Append(GetStringByKey(ABOUTDLG_INFO_RIGHT));
	m_about.Append(_T("\r\n\r\n"));
	m_about.Append(GetStringByKey(ABOUTDLG_INFO_MD5));
	m_about.Append(_T("\r\n"));
	m_about.Append(GetStringByKey(ABOUTDLG_INFO_SHA256));
	m_about.Append(_T("\r\n"));
	m_about.Append(GetStringByKey(ABOUTDLG_INFO_SHA512));
	m_about.Append(_T("\r\n\r\n"));

	//m_about = m_about + "��ǰ����ϵͳ:\r\n" + osinfo;
	m_about.Append(GetStringByKey(ABOUTDLG_INFO_OSTITLE));
	m_about.Append(_T("\r\n"));
	m_about.Append(tstrOsinfo.c_str());

	UpdateData(FALSE);

	return TRUE;
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MAIN, m_about);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_SITE, &CAboutDlg::OnNMClickSyslinkSite)
END_MESSAGE_MAP()


// CAboutDlg ��Ϣ�������

void CAboutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
	EndDialog(0);
}

void CAboutDlg::OnNMClickSyslinkSite(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	WindowsUtils::OpenURL(GetStringByKey(ABOUTDLG_PROJECT_URL));

	*pResult = 0;
}
