#include<iostream>
#include"Game.h"
#include "console.h"	
#include <list>

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main()
{
	

	fullscreen();
	SetConsoleTitle(L"게임 제목 테스트");
	//system("mode con cols=236 lines=66");//가로 세로 화면 설정
	//list<int> a;

	srand(unsigned int(time(NULL)));

	//콘솔 커서 없애기
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