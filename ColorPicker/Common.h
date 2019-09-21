#pragma once

class CCommon
{
public:
	CCommon();
	~CCommon();

	//��const char*�ַ���ת���ɿ��ַ��ַ���
	static std::wstring StrToUnicode(const char* str, bool utf8 = false);

	static std::string UnicodeToStr(const wchar_t* wstr, bool utf8 = false);

	static void StringNormalize(std::wstring& str);

	static void SetDrawRect(CDC* pDC, CRect rect);

	//��һ���ַ������浽������
	static bool CopyStringToClipboard(const std::wstring& str);

    static COLORREF GetWindowsThemeColor();

};

