#include "BlackJack.h"
#include "console.h"
#include "Hand.h"
#include "Card.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include "Game.h"


BlackJack::BlackJack()
{
	/*player = new Player();
	dealer = new Dealer();
	cardDeck = new Deck();*/
	game = new Game();
	betmoney = 0;
	gameOver = false;
	isStand = false;
	backMenu = false;
}

void BlackJack::StartGame()
{
	int x = 0, y = 0;

	/*system("cls");
	PrintCardBoard();*/

	cardDeck->shuffle();
	
	backMenu = false;
	gameOver = false;
	isStand = false;
	
	gotoxy(x += 15, y += 26);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(x + 5, y + 2);//28
	cout << "플레이하시려면 Y를 누르세요 ";
	gotoxy(x+8, y+6);
	cout << "-> 뒤로가기 B";
	gotoxy(x, y + 10);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	int input = _getch();

	if (input == 'b' || input == 'B')
	{
		backMenu = true;
		return;
	}
	else if (input == 'y' || input == 'Y')
	{
		gotoxy(x, y + 2);
		cout << "                                        ";
		
		gotoxy(x + 7, y += 2);//28
		cout << "배팅금액을 적으세요. ";
		gotoxy(x + 7, y += 2);	//30
		cout << "내 자금 : " << player->GetPlayerMoney();
		gotoxy(x + 7, y += 2);	//20, 32
		cout << " 배팅액 :        " << endl;
		
		while (1)
		{
			
			gotoxy(x + 17, y);	//20, 28
			cout << "                          ";
			gotoxy(x + 17, y);	//20, 28
			cin >> betmoney;

			if (betmoney > player->GetPlayerMoney())
			{
				gotoxy(x + 2, y + 2);	//20, 28
				cout << "가진 돈을 초과해서 거실 수 없습니다.";
				Sleep(2000);
				gotoxy(x + 2, y + 2);	//20, 28
				cout << "                                     ";
				continue;
			}
			else
			{
				player->MinusPlayerMoney(betmoney);
				break;
			}
		}
		

		gotoxy(x, y - 4);
		cout << "                                                     ";
		gotoxy(x, y - 2);
		cout << "                                                     ";
		gotoxy(x, y);
		cout << "                                                     ";

		gotoxy(215, 60);
		cout << "             ";

		PlayBlackJeck();
		
	}
	//game->StartGameMenu();


}

void BlackJack::DecisionWinner()
{
	int playerValue = getBlackjackValue(player->GetHandCard());
	int dealerValue = getBlackjackValue(dealer->GetHandCard());

	if (!isStand)
	{
		if (playerValue == 21)
		{
			PlayerWin();
			player->AddPlayerMoney((betmoney * 2) + (betmoney / 2));
		}
		else if (playerValue > 21)
		{
			DealerWin();
		}
	}
	else if (isStand)
	{
		//딜러가 21보다 클때
		if (dealerValue > 21)
		{
			PlayerWin();
			player->AddPlayerMoney(betmoney * 2);

		}
		//플레이어와 딜러 둘다 21보다 작을때
		else if (dealerValue <= 21)
		{
			if (playerValue < dealerValue)
			{
				DealerWin();
			}
			else if (playerValue == dealerValue)
			{
				gotoxy(70, 26);
				cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
				gotoxy(73, 28);//28
				cout << " 무승부 !!!";
				gotoxy(70, 30);
				cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
				player->AddPlayerMoney(betmoney);
				gameOver = true;
				Sleep(2000);
			}
			else if (playerValue > dealerValue)
			{
				PlayerWin();
				player->AddPlayerMoney(betmoney * 2);
			}
		}
	}
	
	

}

void BlackJack::ResetCard()
{
	player->ClearCard();
	dealer->ClearCard();
}

bool BlackJack::ExitGame()
{
	return backMenu;
}

void BlackJack::PlayerWin()
{
	int x = 0, y = 0;
	
	
	gotoxy(x += 70, y += 26);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(x + 4, y += 2);//28
	cout << " 플레이어 Win !!!";
	gotoxy(x+1, y += 2);//30
	cout << "다시 시작하시려면 아무키나 누르세요.";
	gotoxy(x, y + 2);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	int anykey = _getch();
	gameOver = true;
	
	//Sleep(2000);
}

void BlackJack::DealerWin()
{
	int x = 0, y = 0;

	
	gotoxy(x += 70, y += 26);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(x + 3, y += 2);//28
	cout << " 딜러 Win !!!";
	gotoxy(x + 1, y += 2);//30
	cout << "다시 시작하시려면 아무키나 누르세요.";
	gotoxy(x, y + 2);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
	int anykey = _getch();
	gameOver = true;

	//Sleep(2000);
}


void BlackJack::Init(Player* player1, Dealer* pdealer, Deck* pcardDeck)
{
	player = player1;
	dealer = pdealer;
	cardDeck = pcardDeck;
	
	//GameLoop();
	//StartGame();
}

void BlackJack::PrintCardBoard()
{
#pragma region 겉 태두리
	cout << " ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	//gotoxy(0, 1);
	for (int i = 0; i < 61; i++)
	{
		gotoxy(0, i + 1);
		cout << " ■\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   ■" ;
	}
	gotoxy(0, 62);
	cout << " ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	
#pragma endregion
}

void BlackJack::DrawDealerCard(int x, int y)
{
	Sleep(500);
	dealer->receiveCard(cardDeck->dealCard());

	string suitandvalue = dealer->GetCard(dealer->CardCount() - 1).toString();

	gotoxy(x, y);
	cout << "┏━━━━━━━━━━┓";

	for (int j = 0; j < 8; j++)
	{
		Sleep(50);
		if (j == 1)
		{
			gotoxy(x, j + y + 1);
			if (dealer->GetCard(dealer->CardCount() - 1).getValue() == 10)
			{
				cout << "┃" << suitandvalue << "      ┃";
				continue;
			}
			cout << "┃" << suitandvalue << "       ┃";
			continue;
		}
		if (j == 6)
		{
			gotoxy(x, j + y + 1);
			if (dealer->GetCard(dealer->CardCount() - 1).getValue() == 10)
			{
				cout << "┃      " << suitandvalue << "┃";
				continue;
			}
			cout << "┃       " << suitandvalue << "┃";
			continue;
		}
		gotoxy(x, j + y + 1);
		cout << "┃          ┃";
	}
	gotoxy(x, y + 9);
	cout << "┗━━━━━━━━━━┛";

	gotoxy(60, 15);
	cout << "딜러 카드 수: " << dealer->CardCount();
	gotoxy(60, 17);
	cout << "딜러 합 : " << getBlackjackValue(dealer->GetHandCard());
}

void BlackJack::DrawPlayerCard(int x, int y)
{
	Sleep(500);

	player->receiveCard(cardDeck->dealCard());

	string suitandvalue = player->GetCard(player->CardCount()-1).toString();

	gotoxy(x, y);
	cout << "┏━━━━━━━━━━┓";

	for (int j = 0; j < 8; j++)
	{
		Sleep(50);
		if (j == 1)
		{
			gotoxy(x, j + y + 1);
			if (player->GetCard(player->CardCount() - 1).getValue() == 10)
			{
				cout << "┃" << suitandvalue << "      ┃";
				continue;
			}
			cout << "┃"<< suitandvalue <<"       ┃";
			continue;
		}
		if (j == 6)
		{
			gotoxy(x, j + y + 1);
			if (player->GetCard(player->CardCount() - 1).getValue() == 10)
			{
				cout << "┃      " << suitandvalue << "┃";
				continue;
			}
			cout << "┃       " << suitandvalue << "┃";
			continue;
		}
		gotoxy(x, j + y + 1);
		cout << "┃          ┃";
	}
	gotoxy(x, y + 9);
	cout << "┗━━━━━━━━━━┛";

	gotoxy(60, 50);
	cout << "플레이어 카드 수: " << player->CardCount();
	gotoxy(60, 52);
	cout << "플레이어 합 : " << getBlackjackValue(player->GetHandCard());

}

void BlackJack::DrawDeleteCard(int drawNum)
{
	int x = 90;
	int y = 5;
	for (int i = 0; i < drawNum; i++)
	{
		y = 5;
		//위아래 지우기
		for (int k = 1; k < 11; k+=9)
		{

			gotoxy(x, y *= k);
			cout << "            ";
			for (int j = 0; j < 8; j++)
			{
				gotoxy(x, j + y + 1);
				cout << "            ";
			}
			gotoxy(x, y + 9);
			cout << "            ";

		}
		x += 15;
	}
	
}


int BlackJack::getBlackjackValue(Hand h)
{
	int val;	// 계산된 손패의 값.
	bool ace;	// 손패에 에이스가 포함된 경우
				//   이는 true로 설정될 것이다.
	int cards;	// 손패의 카드 갯수.

	val = 0;
	ace = false;
	cards = h.getCardCount();  // (Hand 클래스에 정의된 메서드.)

	for (int i = 0; i < cards; i++) {
		// 손패의 i번째 카드의 값을 추가한다.
		Card card;    // i번째 카드; 
		int cardVal;  // i번째 카드의 블랙잭 값.
		card = h.getCard(i);
		cardVal = card.getValue();  // 일반적인 값으로, 1부터 13 사이.
		if (cardVal > 10) {
			cardVal = 10;   // 잭, 퀸, 킹의 경우.
		}
		if (cardVal == 1) {
			ace = true;     // 적어도 하나의 에이스가 존재.
		}
		val = val + cardVal;
	}

	// 현재, val은 손패의 값이며, 어떤 에이스든 1로 계산한다.
	// 에이스가 하나 존재하고 그 값이 1에서 11로 변경하여
	// 점수가 21보다 작거나 같다는 결과로 된다면,
	// val에 10을 추가적으로 더하여 그렇게 맞춘다. 

	if (ace == true && val + 10 <= 21)
		val = val + 10;

	return val;

}

void BlackJack::PlayBlackJeck()
{
	int x = 0, y = 0;
	int plusX = 15;
	int plusXDealer = 15;
	isStand = false;
	gotoxy(95, 48);
	cout << "<플레이어 카드>";
	gotoxy(95, 16);
	cout << "<딜러 카드>";

	DrawPlayerCard(90, 50);
	//Sleep(500);
	DrawPlayerCard(90 + plusX, 50);
	//Sleep(500);
	DrawDealerCard(90, 5);


	plusX += 15;

	x = 20, y = 29;
	gotoxy(x, y);
	cout << "> Hit - 카드를 더 받는다.";
	gotoxy(x, y + 2);
	cout << "  Stay - 카드를 더 받지 않는다.";

	gotoxy(x + 2, y + 6);
	cout << "[스페이스바로 선택하세요]";


	gotoxy(60, 50);
	cout << "플레이어 카드 수: " << player->CardCount();
	gotoxy(60, 52);
	cout << "플레이어 합 : " << getBlackjackValue(player->GetHandCard());

	gotoxy(60, 15);
	cout << "딜러 카드 수: " << dealer->CardCount();
	gotoxy(60, 17);
	cout << "딜러 합 : " << getBlackjackValue(dealer->GetHandCard());

	DecisionWinner();

	
	while (!gameOver)
	{
		char input = _getch();


		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (y > 29)
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
			if (y < 31)
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
			case 29:
				DrawPlayerCard(90 + plusX, 50);
				plusX += 15;
				
				DecisionWinner();

				break;
			case 31:
				isStand = true;
				while (1)
				{
					if (getBlackjackValue(dealer->GetHandCard()) < 17)
					{
						DrawDealerCard(90 + plusXDealer, 5);
						plusXDealer += 15;
						Sleep(500);
					}
					else
					{
						DecisionWinner();
						break;
					}
				}
				break;
			}
			
		}
	}

	

}

void BlackJack::PrintRule()
{
	system("cls");
	int x = 0, y = 0;

	gotoxy(x += 50, y += 20);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	
	gotoxy(x + 56, y +=2);//28
	cout << "[ 블랙잭 룰 설명!!! ]";

	gotoxy(x + 8, y +=4);
	cout << "-> 딜러와 게이머 단 2명만 존재한다.";
	gotoxy(x + 8, y +=2);
	cout << "-> 카드는 조커를 제외한 52장이다. (즉, 카드는 다이아몬드, 하트, 스페이드, 클럽 무늬를 가진 A, 2~10, K, Q, J 으로 이루어져있다.)";
	gotoxy(x + 8, y +=2);
	cout << "-> 2~10은 숫자 그대로 점수를, K / Q / J는 10점으로, A는 1 또는 11로 계산한다. (알아서 1또는 11로 계산해줌)";
	gotoxy(x + 8, y +=2);
	cout << "-> 게이머는 순차적으로 카드를 하나씩 뽑아 각자 2개의 카드를 소지한다.";
	gotoxy(x + 8, y +=2);
	cout << "-> 게이머는 얼마든지 카드를 추가로 뽑을 수 있다.";
	gotoxy(x + 8, y +=2);
	cout << "-> 게이머가 더 이상 카드를 받지 않는다 하면 딜러가 카드를 뽑기 시작한다.";
	gotoxy(x + 8, y +=2);
	cout << "-> 딜러는 2카드의 합계 점수가 16점 이하이면 반드시 1장을 추가로 뽑고, 17점 이상이면 추가할 수 없다.";
	gotoxy(x + 8, y +=2);
	cout << "-> 양쪽다 추가 뽑기가 없으면 딜러와 게이머 중 소유한 카드의 합이 21에 가장 가까운 쪽이 승리한다.";
	gotoxy(x + 8, y +=2);
	cout << "-> 단 21을 초과하면 초과한 쪽이 진다.";

	gotoxy(x, y + 2);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(223, 62);
	cout << "-> 뒤로가기 B";


	int input = _getch();

	if (input == 'b' || input == 'B')
	{
		backMenu = true;
		return;
	}


}


