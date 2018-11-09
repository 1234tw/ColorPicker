
// ColorPickerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcolorbutton.h"


// CColorPickerDlg �Ի���
class CColorPickerDlg : public CDialogEx
{
// ����
public:
	CColorPickerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLORPICKER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	COLORREF m_color;			//��ɫ��COLORREFֵ
	unsigned char m_color_r;	//��ɫRGB�еĺ�ɫֵ
	unsigned char m_color_g;	//��ɫRGB�е���ɫֵ
	unsigned char m_color_b;	//��ɫRGB�е���ɫֵ
	unsigned int m_color_hex;	//��ɫ��ʮ������ֵ

	CEdit m_edit;		//��ɫ��COLORREFֵ�ؼ�
	CEdit m_edit_r;		//��ɫRGB�еĺ�ɫֵ�ؼ�
	CEdit m_edit_g;		//��ɫRGB�е���ɫֵ�ؼ�
	CEdit m_edit_b;		//��ɫRGB�е���ɫֵ�ؼ�
	CEdit m_edit_hex;	//��ɫʮ������ֵ�ؼ�
//	CStatic m_preview;
//��ɫԤ���ؼ�

	CMFCColorButton m_color_control;

	unsigned int RGB2Hex(unsigned char R, unsigned char G, unsigned char B);	//RGBֵת������ɫʮ������ֵ
	unsigned char Hex2R(unsigned int hex);	//����ɫʮ�����ƻ�ȡRGB�еĺ�ɫֵ
	unsigned char Hex2G(unsigned int hex);	//����ɫʮ�����ƻ�ȡRGB�е���ɫֵ
	unsigned char Hex2B(unsigned int hex);	//����ɫʮ�����ƻ�ȡRGB�е���ɫֵ

	void SetColorRefText();
	void SetColorRText();
	void SetColorGText();
	void SetColorBText();
	void SetColorHexText();

	void SetPreview();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

//	afx_msg void OnBnClickedSelectColor();
	afx_msg void OnEnChangeColorValue();
	afx_msg void OnEnChangeColorR();
	afx_msg void OnEnChangeColorG();
	afx_msg void OnEnChangeColorB();
	afx_msg void OnEnChangeColorHex();
	afx_msg void OnBnClickedAboutButton();
public:
	afx_msg void OnBnClickedMfccolorbutton1();
};
