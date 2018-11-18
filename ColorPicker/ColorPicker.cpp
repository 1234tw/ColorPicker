
// ColorPicker.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "ColorPicker.h"
#include "ColorPickerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CColorPickerApp

BEGIN_MESSAGE_MAP(CColorPickerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CColorPickerApp ����

CColorPickerApp::CColorPickerApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
	CWindowDC dc(NULL);
	HDC hDC = dc.GetSafeHdc();
	m_dpi = GetDeviceCaps(hDC, LOGPIXELSY);
}

int CColorPickerApp::DPI(int pixel)
{
	return m_dpi * pixel / 96;
}


// Ψһ��һ�� CColorPickerApp ����

CColorPickerApp theApp;


// CColorPickerApp ��ʼ��

BOOL CColorPickerApp::InitInstance()
{
	//�滻���Ի�������Ĭ������
	WNDCLASS wc;
	::GetClassInfo(AfxGetInstanceHandle(), _T("#32770"), &wc);	//MFCĬ�ϵ����жԻ��������Ϊ#32770
	wc.lpszClassName = _T("ColorPicker-2rW332K9");	//���Ի���������޸�Ϊ������
	AfxRegisterClass(&wc);

	//����Ƿ�����ʵ���������У�Debugʱ����飩
#ifndef _DEBUG
	HANDLE hMutex = ::CreateMutex(NULL, TRUE, _T("c1A0pd1NE1v7"));		//ʹ��һ��������ַ�������һ��������
	if (hMutex != NULL)
	{
		if (GetLastError() == ERROR_ALREADY_EXISTS)		//����������ʧ�ܣ�˵���Ѿ���һ�������ʵ����������
		{
			HWND handle = FindWindow(_T("ColorPicker-2rW332K9"), NULL);		//������������������ʵ�����ڵľ��
			if (handle != NULL)
			{
				ShowWindow(handle, SW_SHOWNORMAL);		//��ʾ�������еĴ���
				SetForegroundWindow(handle);
				return FALSE;		//�˳���ǰ����
			}
		}
	}
#endif

	//��ȡ��ǰ����·��
	wchar_t buff[MAX_PATH];
	GetModuleFileNameW(NULL, buff, MAX_PATH);
	size_t index;
	m_modle_dir = buff;
	index = m_modle_dir.rfind(L'\\');
	m_modle_dir = m_modle_dir.substr(0, index + 1);

	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	//SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CColorPickerDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

