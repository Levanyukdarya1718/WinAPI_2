#include <Windows.h>
#include "resource.h"
CONST CHAR g_sz_LOGIN_INVITATICATION[] = "Введите имя пользователя";
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
/*
Точкой входа является функция WinMain, она всегда принимает 4 параметра
hInstansce - это экземпляр запущнного *exe -файла нашей программы
hPrevInst -предидущй запущенный экземпляр этот параметр уже не используется 
и оставлен только для совместимости, этот параметр использовался в windows98
lpCmdLine -командная строка с которой запустилась программа
			содержит имя исполняемого файла и параметры запуска
			например, имя открываемого файла URL ресурса и тд
			Drag'n Drop так жже работает через командную строку
LPSTR - Long Pointer To String 
nCmdShow-сщсещяние окна при запуске развернуто на весь экранб всернуто в окно, 
		 свернуто на панель задач	 
*/

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdshow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc, 0);
	// taskkill /f /im DialogBox.exe

	return 0;
	//Caption-заголовок окна
}
/*
в winAPI АБСОЛЮТНО ВСЕ ЯВЛЯЕТСЯ ОКНОМ
у каждогоокнае есть ПРОЦЕДУРА - этто функция которая неявно вызывается при запуске окна
в нашем случае это функция DlgProc
любая процедура окна всегда принимает 4 параметра
---------------------------------------------------
hwnd (Handler to Windows)- дискриптор окна - это число через которое к нему можно обратиться
---------------------------------------------------
uMsg (Unsigned Message) - это сообщение которое отправляетс в окно
---------------------------------------------------
wParam, lParam - параметры сообщения, зависят от сообщения которое отправляется в окно в данный момент
представляют собой значения типа DWORD(DOUBLE WORD) -двойное слово(4-байта/32 бита)
---------------------------------------------------
вместе с сообщением в окно можно передпть до 4 параметров
BYTE   = 8bit
WORD   = 16bit
DWORD  = 23bit
QWORD  = 64 bit
TBYTE  = 80bit
DQBYTE = 128 bit
wParam и lParam можно разделить на 2 части
		LOWORD
		HIWORD

*/
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
		HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_LOGIN_INVITATICATION);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE]{};
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			if (HIWORD(wParam) == EN_SETFOCUS && strcmp(sz_buffer, g_sz_LOGIN_INVITATICATION) == 0)
				SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");
			if (HIWORD(wParam) == EN_KILLFOCUS && strcmp(sz_buffer, "") == 0)
				SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_LOGIN_INVITATICATION);


		}  
		case IDC_BUTTON_COPY: 
		{
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			//Функция GetDlgItem() возвращает HWND дочернего окна по его ResourceID
			//HWND -Hander to Window (Дислриптор окна) это число пи помощи которого можно обратиться к окну
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			SendMessage(hEditPassword, WM_SETTEXT,0, (LPARAM)sz_buffer);
			SendMessage(hwnd, WM_SETTEXT,0, (LPARAM)sz_buffer);
			SendMessage(GetDlgItem(hwnd, IDC_BUTTON_COPY), WM_SETTEXT,0, (LPARAM)sz_buffer);
		}
		break;

		case IDOK: MessageBox(hwnd, "Была нажата кнопка ОК!", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0); //работает крестик
		break;

	}
	return FALSE;
}
