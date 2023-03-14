#include "Game.h"
#include "Player.h"
#include "BlackJack.h"
#include "Poker.h"
#include "console.h"
#include "Dealer.h"
#include "Deck.h"
#include "Sound.h"


Game::Game()
{
	/*m_player = new Player();
	blackJack = new BlackJack();
	poker = new Poker();*/

	gameNum = 0;
}

Game::~Game()
{

}

void Game::Init()
{
	player = new Player();
	dealer = new Dealer();
	cardDeck = new Deck();
	blackJack = new BlackJack();
	poker = new Poker();

	//cardDeck->shuffle();
}

void Game::Update()
{

	switch (gameNum)
	{
	case -2:
		PrintTitle();
		break;
	case -1:
		PrintInfo();
		break;
	case 0:
		StartGameMenu();
		break;
	case 1:
		poker->Init(player, dealer, cardDeck);
		while (1)
		{
			system("cls");
			if (player->GetPlayerMoney() <= 0)
			{
				PrintGameOver();
				break;
			}

			poker->PrintPokerBoard();
			poker->StartGame();
			if (poker->ExitGame() == true)
			{
				gameNum = 0;
				break;
			}
			poker->ResetCard();
		}
		break;
	case 2:

		break;
	case 3:
		blackJack->Init(player, dealer, cardDeck);
		while (1)
		{
			system("cls");
			if (player->GetPlayerMoney() <= 0)
			{
				PrintGameOver();
				break;
			}

			blackJack->PrintCardBoard();
			blackJack->StartGame();
			if (blackJack->ExitGame() == true)
			{
				gameNum = 0;
				
				break;
			}
			blackJack->ResetCard();
		}
		
		//Sleep(500);
		break;
	case 4:
		break;
	case 12:
		blackJack->PrintRule();
		if (blackJack->ExitGame() == true)
		{
			gameNum = -1;
			break;
		}
		break;
	}
}
void Game::StartGameMenu()
{
	system("cls");
	int x = 0, y = 0;
	
	gotoxy(x += 105, y += 20);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(x += 13, y +=2);//22
	cout << "> 포커";
	gotoxy(x, y += 2);	//24
	cout << "  룰렛 ";
	gotoxy(x, y += 2);	//26
	cout << "  블랙잭 " << endl;
	gotoxy(x, y += 2);	//28
	cout << "  바카라 " << endl;
	gotoxy(x, y += 2);	//20
	cout << "  슬롯머신 " << endl;

	gotoxy(x-10, y+3);
	cout << "스페이스바로 게임을 선택하세요."<<endl;

	gotoxy(x-13, y+5);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(223, 62);
	cout << "-> 뒤로가기 B";

	gotoxy(x, y -= 8);

	while (1)
	{
		char input = _getch();
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (y > 22)
			{
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, y -= 2);
				cout << ">";
				Sleep(100);

			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (y < 30)
			{
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, y += 2);
				cout << ">";
				Sleep(100);

			}
		}
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{

			switch (y)
			{
			case 22://포커
				gameNum = 1;
				break;
			case 24://룰렛
				break;
			case 26://블랙잭
				gameNum = 3;
				//blackJack->Init(player, dealer, cardDeck);
				break;
			case 28://바카라
				break;
			case 30://슬롯머신
				break;

			}
			
			//Update();
			break;
		}
		if (input == 'b' || input == 'B')
		{
			system("cls");
			gameNum = -2;
			//PrintTitle();
			break;
		}

	}
}

Sound Game::getSound()
{
	return *sound;
}


void Game::PrintTitle()
{
	/*gotoxy(236, 66);
	cout << "a";*/
	int x = 0, y = 0;
#pragma region 게임 타이틀
	y += 13;
	gotoxy(x, y);
	_setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t        _____  __            __       __                     " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t       /     |/  |          /  |  _  /  |                    	 " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t       $$$$$ |$$/  _______  $$ | / | $$ |  ______    ______  	 " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t          $$ |/  |/       | $$ |/$  |$$ | /      |  /      | 	 " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t     __   $$ |$$ |$$$$$$$  |$$ /$$$  $$ |/$$$$$$  |/$$$$$$  |	 " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t    /  |  $$ |$$ |$$ |  $$ |$$ $$/$$ $$ |$$ |  $$ |$$ |  $$ |	 " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t    $$ |__$$ |$$ |$$ |  $$ |$$$$/  $$$$ |$$ |__$$ |$$ |__$$ |	 " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t    $$    $$/ $$ |$$ |  $$ |$$$/    $$$ |$$    $$/ $$    $$/ 	 " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t     $$$$$$/  $$/ $$/   $$/ $$/      $$/  $$$$$$/   $$$$$$/  	 " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t                                                             	 " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t             __                                  __             " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t            /  |                                /  |            " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t            $$ |        ______   _______    ____$$ |            " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t            $$ |       /      | /       |  /    $$ |            " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t            $$ |       $$$$$$  |$$$$$$$  |/$$$$$$$ |            " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t            $$ |       /    $$ |$$ |  $$ |$$ |  $$ |            " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t            $$ |_____ /$$$$$$$ |$$ |  $$ |$$ |__$$ |            " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t            $$       |$$    $$ |$$ |  $$ |$$    $$ |            " << endl;
	wcout << L"\t\t\t\t\t\t\t\t\t\t\t            $$$$$$$$/  $$$$$$$/ $$/   $$/  $$$$$$$/             " << endl;
                                                         
	_setmode(_fileno(stdout), _O_TEXT);

#pragma endregion


	x = 110;
	y = 40;
	gotoxy(x, y);
	cout << "> 게임시작 ";
	gotoxy(x, y += 2);	//30
	cout << "  게임 정보 ";
	gotoxy(x, y += 2);	//34
	cout << "  종료 "<<endl;
	gotoxy(x-4, y + 3);
	cout << "( 스페이스바로 선택하세요. )";
	gotoxy(x, y-=4);
	

	while (1)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (y > 40)
			{
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, y -= 2);
				cout << ">";
				Sleep(100);

			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (y < 44)
			{
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, y += 2);
				cout << ">";
				Sleep(100);

			}
		}
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (y == 40)
			{
				Sleep(200);
				gameNum = 0;
				//StartGameMenu();
			}
			else if (y == 42)
			{
				Sleep(500);
				gameNum = -1;
				//PrintInfo();
			}
			else if (y == 44)
			{
				exit(0);
			}
			break;
		}

	}
}

void Game::PrintInfo()
{
	system("cls");
	int x = 0, y = 0;
	gotoxy(x+= 80, y+=20);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(x+= 35, y+=2);//22
	cout << "<게임 룰>";
	gotoxy(x-=30, y+=2);//24
	cout << "-> 플레이어는 처음에 1억을 가지고 있습니다. ";
	gotoxy(x, ++y);
	cout << "-> 플레이어는 다양한 게임을 할 수 있습니다.";
	gotoxy(x, ++y);
	cout << "-> 플레이어의 돈이 100억을 달성하면 인생이 극락으로 가고 게임은 끝납니다.";;
	gotoxy(x, ++y);
	cout << "-> 만약 플레이어의 돈이 0원이 되면 파산하게 되고, 게임은 종료됩니다.";

	gotoxy(x+=25, y+=5); //32
	cout << "<카지노 게임 종류>";

	gotoxy(x, y+=2); //34
	cout << "포커";
	gotoxy(x, y+=2);
	cout << "룰렛";
	gotoxy(x, y+=2);
	cout << "블랙잭";
	gotoxy(x, y+=2);
	cout << "바카라";
	gotoxy(x, y+=2);
	cout << "슬롯머신";
	gotoxy(x-=7, y+=2);
	cout << "[스페이스바를 눌러서 게임 방법 보기]";
	gotoxy(x-=23, y+=2);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
	gotoxy(x+=42, y-=12);
	cout << "<- ";
	
	gotoxy(223, 62);
	cout << "-> 뒤로가기 B";
	
	while (true)
	{
		char input = _getch();
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (y > 34)
			{
				gotoxy(x, y);
				cout << "    ";
				gotoxy(x, y-=2);
				cout << "<- ";
				Sleep(150);
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (y < 42)
			{
				gotoxy(x, y);
				cout << "    ";
				gotoxy(x, y+=2);
				cout << "<- ";
				Sleep(150);
			}

		}
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			switch (y)
			{
			case 34:
				
				break;
			case 36:

				break;
			case 38:
				gameNum = 12;
				break;
			case 40:

				break;
			case 42:

				break;
			}
			system("cls");
			break;
		}
		if (input == 'b' || input == 'B')
		{
			system("cls");
			gameNum = - 2;
			//PrintTitle();
			break;
		}
		
		
	}
}

void Game::PrintGameOver()
{
	system("cls");
	int x = 0, y = 0;
#pragma region 게임 타이틀
	y += 13;
	gotoxy(x, y);
	_setmode(_fileno(stdout), _O_U8TEXT);

	wcout << L"\t\t\t\t    __      __                         __                                                                      __       __                                                __ "<<endl;
	wcout << L"\t\t\t\t   /  ∖    /  |                       /  |                                                                    /  ∖     /  |                                              /  |"<<endl;
	wcout << L"\t\t\t\t   $$  ∖  /$$/______   __    __       $$ |____    ______   __     __  ______         _______    ______        $$  ∖   /$$ |  ______   _______    ______   __    __       $$ |"<<endl;
	wcout << L"\t\t\t\t    $$  ∖/$$//      ∖ /  |  /  |      $$      ∖  /      ∖ /  ∖   /  |/      ∖       /        ∖ /       ∖      $$$  ∖ /$$$ | /       ∖/        ∖ /       ∖/  |  /  |      $$ |"<<endl;
	wcout << L"\t\t\t\t     $$  $$//$$$$$$  |$$ |  $$ |      $$$$$$$  | $$$$$$  |$$  ∖ /$$//$$$$$$  |      $$$$$$$  |/$$$$$$  |      $$$$  /$$$$ |/$$$$$$  |$$$$$$$  |/$$$$$$  |$$ |  $$ |      $$ |"<<endl;
	wcout << L"\t\t\t\t      $$$$/ $$ |  $$ |$$ |  $$ |      $$ |  $$ | /    $$ | $$  /$$/ $$    $$ |      $$ |  $$ |$$ |  $$ |      $$ $$ $$/$$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$ |      $$/ "<<endl;
	wcout << L"\t\t\t\t       $$ | $$ ∖__$$ |$$ ∖__$$ |      $$ |  $$ |/$$$$$$$ |  $$ $$/  $$$$$$$$/       $$ |  $$ |$$ ∖__$$ |      $$ |$$$/ $$ |$$ ∖__$$ |$$ |  $$ |$$$$$$$$/ $$ ∖__$$ |       __ "<<endl;
	wcout << L"\t\t\t\t       $$ | $$    $$/ $$    $$/       $$ |  $$ |$$    $$ |   $$$/   $$       |      $$ |  $$ |$$    $$/       $$ | $/  $$ |$$    $$/ $$ |  $$ |$$       |$$    $$ |      /  |"<<endl;
	wcout << L"\t\t\t\t       $$/   $$$$$$/   $$$$$$/        $$/   $$/  $$$$$$$/     $/     $$$$$$$/       $$/   $$/  $$$$$$/        $$/      $$/  $$$$$$/  $$/   $$/  $$$$$$$/  $$$$$$$ |      $$/ "<<endl;
	wcout << L"\t\t\t\t                                                                                                                                                         /  ∖__$$ |          "<<endl;
	wcout << L"\t\t\t\t                                                                                                                                                         $$    $$/           "<<endl;
	wcout << L"\t\t\t\t                                                                                                                                                          $$$$$$/            "<<endl;

	_setmode(_fileno(stdout), _O_TEXT);
	
	gotoxy(77, 25);
	cout << "파산 하셨습니다...";
#pragma endregion



	exit(0);

}



