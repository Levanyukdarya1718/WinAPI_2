#include <Windows.h>

#define MESSAGE_BOX
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT hCmdShow)
{
#ifdef  MESSAGE_BOX
	MessageBox
	(
		NULL, //������������ ����
		"Hello WinAPI!\n��� Message Box, �����", 
		"��������� ����", //���� NULL ������� error
		MB_YESNOCANCEL|MB_ICONQUESTION //������(4 ������ ��������) � ���������(������) 
		| MB_HELP
		|MB_DEFBUTTON4 //����� ������
		//����������� -�������� ���� ����� �� ������������ ����������������� � ������ ������ ���� ��� �������
		//|MB_SYSTEMMODAL //������ ��������� �����

	);
#endif //MESSAGE_BOX
	return 0;
}