#include<iostream>
#include"Game.h"
#include "console.h"	
#include <list>

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main()
{
	

	fullscreen();
	SetConsoleTitle(L"���� ���� �׽�Ʈ");
	//system("mode con cols=236 lines=66");//���� ���� ȭ�� ����
	//list<int> a;

	srand(unsigned int(time(NULL)));

	//�ܼ� Ŀ�� ���ֱ�
	CursorView();


	Game game;
	game.Init();
	int x = 0, y = 0;
	game.PrintTitle();
	while (true)
	{
		game.Update();

	}

	return 0;
}