#include <Windows.h>

#define MESSAGE_BOX
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT hCmdShow)
{
#ifdef  MESSAGE_BOX
	MessageBox
	(
		NULL, //родительское окно
		"Hello WinAPI!\nЭто Message Box, детка", 
		"Заголовок окна", //Если NULL пишется error
		MB_YESNOCANCEL|MB_ICONQUESTION //кнопки(4 кнопки максимум) и состояния(иконки) 
		| MB_HELP
		|MB_DEFBUTTON4 //Фокус кнопки
		//мадальность -свойство окна может ли пользователь взаимодействовать с другми окнами пока оно открыто
		//|MB_SYSTEMMODAL //поверх остальных ококн

	);
#endif //MESSAGE_BOX
	return 0;
}