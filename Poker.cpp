#include "Poker.h"
#include "console.h"
#include "Hand.h"
#include "Card.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include "Game.h"
#include <time.h>

Poker::Poker()
{
	game = new Game();
	betmoney = 0;
	gameOver = false;
	backMenu = false;
}

Poker::~Poker()
{
	
}



void Poker::StartGame()
{
	int x = 0, y = 0;

	/*system("cls");
	PrintCardBoard();*/

	cardDeck->shuffle();

	totalmoney = 0;
	backMenu = false;
	gameOver = false;
	dealerbat = 5000;
	callMoney = 5000;
	round = 0;

	gotoxy(x += 15, y += 26);
	cout << "����������������������������������������������������������������������������";
	gotoxy(x + 5, y + 6);//32
	cout << "�÷����Ͻ÷��� Y�� �������� ";
	gotoxy(x + 8, y + 10);
	cout << "-> �ڷΰ��� B";
	gotoxy(x, y + 14);
	cout << "����������������������������������������������������������������������������";

	gotoxy(x + 170, y);
	cout << "����������������������������������������������������������������������������";
	gotoxy(x + 170, y + 14);
	cout << "����������������������������������������������������������������������������";

	int input = _getch();

	if (input == 'b' || input == 'B')
	{
		backMenu = true;
		return;
	}
	else if (input == 'y' || input == 'Y')
	{
		gotoxy(x, y + 6);
		cout << "                                           ";
		gotoxy(x+8, y+10);
		cout << "                  ";
		gotoxy(x + 2, y += 4);//30
		cout << "�ʱ� ���ñݾ��� ��������. �ּ� " << callMoney;
		gotoxy(x + 7, y += 2);	//32
		cout << "�� �ڱ� : " << player->GetPlayerMoney();
		gotoxy(x + 7, y += 2);	//34
		cout << "���þ� :        " << endl;

		while (1)
		{

			gotoxy(x + 17, y);	//20, 32
			cout << "                          ";
			gotoxy(x + 17, y);	//20, 32
			cin >> betmoney;

			if (betmoney > player->GetPlayerMoney())
			{
				gotoxy(x+2, y+2);	//20, 28
				cout << "���� ���� �ʰ��ؼ� �Ž� �� �����ϴ�.";
				Sleep(2000);
				gotoxy(x+2, y+2);	//20, 28
				cout << "                                     ";
				continue;
			}
		    else if (betmoney < 5000)
			{
				gotoxy(x+3, y+2);	//20, 28
				cout << "�ּ� ���� �ݾ׺��� �����ϴ�.";
				Sleep(2000);
				gotoxy(x+3, y+2);	//20, 28
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

		TotalMoney(betmoney * 2);
		//PlayBlackJeck();
		PlayPokerGame();

	}
	//game->StartGameMenu();


}



void Poker::ResetCard()
{
	player->ClearCard();
	dealer->ClearCard();
}

bool Poker::ExitGame()
{
	return backMenu;
}



void Poker::DealerChoice(bool first)
{
	//// 0�� ������ 1�� ���� 2�� �� 3�� üũ
	//Sleep(500);
	//int dealerChoice;
	//if (!first)
	//{
	//	dealerChoice = rand() % 3;

	//}
	//else
	//{
	//	dealerChoice = rand() % 4;
	//}

	//switch (dealerChoice)
	//{
	//
	//case 0:
	//	dealerbat = rand() % (player->GetPlayerMoney()-callMoney) + callMoney;
	//	gotoxy(185, 32);
	//	cout << "������ �������� �ϼ̽��ϴ�.(�ݾ� : " << dealerbat;
	//	callMoney = dealerbat;
	//	TotalMoney(dealerbat);
	//	Sleep(1500);
	//	break;
	//case 1:
	//	gotoxy(190, 32);
	//	cout << "������ �����̽��ϴ�.";
	//	player->AddPlayerMoney(totalmoney);
	//	Sleep(1500);
	//	gameOver = true;
	//	break;
	//case 2:
	//	gotoxy(190, 32);
	//	cout << "������ ���� �ϼ̽��ϴ�.";
	//	TotalMoney(betmoney);
	//	Sleep(1500);
	//	break;
	//case 3:
	//	gotoxy(190, 32);
	//	cout << "������ üũ�� �ϼ̽��ϴ�.";
	//	Sleep(1500);
	//	break;
	//	gotoxy(190, 32);
	//	cout << "                                                    ";
	//
	//}


}



void Poker::PlayerWin()
{


}

void Poker::DealerWin()
{


}

void Poker::RandomTurn(int i)
{
	dealerchoice = i;
	//������ ���� ����
	if (dealerchoice % 2 == 0)
	{
		DealerChoice(true);
		dealerchoice= 1;
		ChooseState();
	}
	else
	{
		ChooseState();
		dealerchoice= 0;
	}
}
void Poker::SortCard(Hand h)
{
	//h.sortByValue();
}
int Poker::getPokerValue(Hand h)
{
	//

	return 1;
}

void Poker::ChooseState()
{
	int x = 0, y = 0;
	x = 25, y = 29;
	gotoxy(x, y);
	cout << "> Call �� �ݾ� " << callMoney;
	gotoxy(x, y += 2);
	cout << "  Raise";
	gotoxy(x, y += 2);
	cout << "  fold";
	gotoxy(x, y += 2);
	cout << "  Check";
	gotoxy(x, y + 2);
	cout << "�� �� : " << player->GetPlayerMoney();
	gotoxy(x - 3, y + 4);
	cout << "[�����̽��ٷ� �����ϼ���]";
	gotoxy(x, y -= 6);

}

void Poker::ClearChooseBoard()
{
	int x = 0, y = 0;
	x = 25, y = 29;
	gotoxy(x, y);
	cout << "                               ";
	gotoxy(x, y += 2);
	cout << "                               ";
	gotoxy(x, y += 2);
	cout << "                               ";
	gotoxy(x, y += 2);
	cout << "                               ";
	//gotoxy(x, y + 2);
	//cout << "                               ";

	gotoxy(x - 3, y + 4);
	cout << "                               ";
	gotoxy(x, y -= 6);
}
void Poker::PlayerChoice(int y)
{
	int plusX = 15;
	switch (y)
	{
	case 29: //call
		player->MinusPlayerMoney(callMoney);
		TotalMoney(callMoney);
		callMoney = 5000;

		break;
	case 31: //raise
		if (player->GetPlayerMoney() <= 5000)
		{
			cout << "����� �Ͻ� �� �����ϴ�.";
		}
		ClearChooseBoard();
		gotoxy(25, 31);

		cout << "�ݾ��� �Է��ϼ��� : ";
		gotoxy(45, 31);
		cin >> betmoney;
		if (betmoney < callMoney || betmoney > player->GetPlayerMoney())
		{
			gotoxy(25, 32);
			cout << "�߸� �� �ݾ��� �Է� �ϼ̽��ϴ�.";
			Sleep(1500);
			ClearChooseBoard();
			ChooseState();
		}
		else
		{
			TotalMoney(betmoney);
		}
		player->MinusPlayerMoney(betmoney);
		break;
	case 33: //fold 
		gotoxy(25, 33);
		cout << "�����̽��ϴ�. ";
		Sleep(1500);
		gameOver = true;
		break;
	case 35: //check
		if (dealerchoice == 1)
		{
			gotoxy(25, 35);
			cout << "üũ�Ͻ� �� �����ϴ�.";
			Sleep(1000);
			gotoxy(25, 35);
			cout << "                          ";
		}
		else
		{
			gotoxy(25, 35);
			cout << "üũ�ϼ̽��ϴ�.";
			Sleep(1000);
			gotoxy(25, 35);
			cout << "                          ";
		}
		break;
	}
	ClearChooseBoard();
	round++;
	return;
}
void Poker::DecisionWinner()
{
	gotoxy(100, 30);
	cout << "�÷��̾� : ";
	gotoxy(110, 30);
	if (player->GetHandCard().ResultHand() == HandType::royalFlush)
		cout << "Royal Flush." << endl;
	else if (player->GetHandCard().ResultHand() == HandType::straightFlush)
		cout << "Straight Flush." << endl;
	else if (player->GetHandCard().ResultHand() == HandType::fourOfAKind)
		cout << "Four Of A Kind." << endl;
	else if (player->GetHandCard().ResultHand() == HandType::fullHouse)
		cout << "Full House." << endl;
	else if (player->GetHandCard().ResultHand() == HandType::Flush)
		cout << "Flush." << endl;
	else if (player->GetHandCard().ResultHand() == HandType::straight)
		cout << "Straight." << endl;
	else if (player->GetHandCard().ResultHand() == HandType::threeOfAKind)
		cout << "Three Of A Kind." << endl;
	else if (player->GetHandCard().ResultHand() == HandType::twoPairs)
		cout << "Two Pair." << endl;
	else if (player->GetHandCard().ResultHand() == HandType::Pair)
		cout << "Pair." << endl;
	else
	{
		if (player->GetHandCard().ResultHighCard() < 11)
			cout << " High Card of " << player->GetHandCard().ResultHighCard() << "." << endl;
		else if (player->GetHandCard().ResultHighCard() == 11)
			cout << " High Card of J." << endl;
		else if (player->GetHandCard().ResultHighCard() == 12)
			cout << " High Card of Q." << endl;
		else if (player->GetHandCard().ResultHighCard() == 13)
			cout << " High Card of K." << endl;
		else if (player->GetHandCard().ResultHighCard() == 14)
			cout << " High Card of A." << endl;

	}

	gotoxy(100, 25);
	cout << "���� : ";
		gotoxy(110, 25);
	if (dealer->GetHandCard().ResultHand() == HandType::royalFlush)
		cout << "Royal Flush." << endl;
	else if (dealer->GetHandCard().ResultHand() == HandType::straightFlush)
		cout << "Straight Flush." << endl;
	else if (dealer->GetHandCard().ResultHand() == HandType::fourOfAKind)
		cout << "Four Of A Kind." << endl;
	else if (dealer->GetHandCard().ResultHand() == HandType::fullHouse)
		cout << "Full House." << endl;
	else if (dealer->GetHandCard().ResultHand() == HandType::Flush)
		cout << "Flush." << endl;
	else if (dealer->GetHandCard().ResultHand() == HandType::straight)
		cout << "Straight." << endl;
	else if (dealer->GetHandCard().ResultHand() == HandType::threeOfAKind)
		cout << "Three Of A Kind." << endl;
	else if (dealer->GetHandCard().ResultHand() == HandType::twoPairs)
		cout << "Two Pair." << endl;
	else if (dealer->GetHandCard().ResultHand() == HandType::Pair)
		cout << "Pair." << endl;
	else
	{
		if (dealer->GetHandCard().ResultHighCard()< 11)
			cout << " High Card of " << dealer->GetHandCard().ResultHighCard() << "." << endl;
		else if (dealer->GetHandCard().ResultHighCard() == 11)
			cout << " High Card of J." << endl;
		else if (dealer->GetHandCard().ResultHighCard() == 12)
			cout << " High Card of Q." << endl;
		else if (dealer->GetHandCard().ResultHighCard() == 13)
			cout << " High Card of K." << endl;
		else if (dealer->GetHandCard().ResultHighCard() == 14)
			cout << " High Card of A." << endl;

	}

	gotoxy(73, 34);
	if (DetermineWinner() == 1)
	{
		player->AddPlayerMoney(totalmoney);
		cout << " player wins! " << endl;

	}
	else if (DetermineWinner() == 2)
	{
		//player->MinusPlayerMoney(totalmoney);
		cout << " dealer wins! " << endl;
	}
	else
	{
		cout << "���º�. " << endl;

	}


}
void Poker::PlayPokerGame()
{
	int x = 0, y = 0;
	int plusX = 15;
	int plusXDealer = 15;
	//isStand = false;
	gotoxy(95, 48);
	cout << "<�÷��̾� ī��>";
	/*gotoxy(95, 16);
	cout << "<���� ī��>";*/

	ChooseState();
	

	x = 25, y = 29;
	int k = rand() % 3+1;
	

	while (!gameOver)
	{
		if (round == 0)
		{
			DrawPlayerCard(90, 50);
			DrawPlayerCard(90 + plusX, 50);
			DrawPlayerCard(90 + plusX*2, 50);
			DrawPlayerCard(90 + plusX*3, 50);
			DrawPlayerCard(90 + plusX*4, 50);
			//Sleep(500);
			DrawDealerCard(90, 5);
			DrawDealerCard(90 + plusX, 5);
			DrawDealerCard(90 + plusX * 2, 5);
			DrawDealerCard(90 + plusX * 3, 5);
			DrawDealerCard(90 + plusX * 4, 5);

			//DrawDealerCard(90 + plusX, 5);
			/*DrawBoardCard(60 + plusX, 25);
			DrawBoardCard(60 + plusX * 2, 25);
			DrawBoardCard(60 + plusX * 3, 25);
			DrawBoardCard(60 + plusX * 4, 25);
			DrawBoardCard(60 + plusX * 5, 25);*/


		}
		else if (round == 1)
		{
			DrawDealerCardNum(90, 5, 0);
			DrawDealerCardNum(90 + plusX, 5, 1);
			DrawDealerCardNum(90 + plusX*2, 5, 2);
			DrawDealerCardNum(90 + plusX*3, 5, 3);
			DrawDealerCardNum(90 + plusX*4, 5, 4);


			player->SortHandCard();
			dealer->SortHandCard();

			//Sleep(2000);
			clock_t delay = 1.5f * CLOCKS_PER_SEC;
			clock_t start = clock();
			while (clock() - start < delay)
			{
				//��ٸ���
			}
			//����ٰ� s���� ����ؼ� �º� �����ϴ� �Լ� ������ �ɰ� ����
			DecisionWinner();

			gotoxy(70, 32);
			cout << "����������������������������������������������������������������������������";
			gotoxy(71, 36);//30
			cout << "�ٽ� �����Ͻ÷��� �ƹ�Ű�� ��������.";
			gotoxy(71, 38);
			cout << "����������������������������������������������������������������������������";
			int anykey = _getch();
			gameOver = true;
			break;
		}

		x = 25, y = 29;
		ChooseState();
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
				if (y < 35)
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
				PlayerChoice(y);
				break;
			}
		}
		
	}
}

void Poker::TotalMoney(int money)
{
	totalmoney += money;
	gotoxy(190, 36);
	cout << "�� �ǵ� : " << totalmoney;
}

int Poker::DetermineWinner()
{
	if (player->GetHandCard().ResultHand() > dealer->GetHandCard().ResultHand())
		return 1;
	else if (player->GetHandCard().ResultHand() > dealer->GetHandCard().ResultHand())
		return 2;
	else
	{
		if ((player->GetHandCard().ResultHighCard() > dealer->GetHandCard().ResultHighCard()) || (player->GetHandCard().ResultHand() > dealer->GetHandCard().ResultHand()))
			return 1;
		else if ((dealer->GetHandCard().ResultHighCard() > player->GetHandCard().ResultHighCard()) || (dealer->GetHandCard().ResultHand() > player->GetHandCard().ResultHand()))
			return 2;
		else
			return 3;
	}
}

void Poker::PrintPokerBoard()
{
#pragma region �� �µθ�
	cout << " �����������������������������������������������������������������������������������������������������������������������";
	//gotoxy(0, 1);
	for (int i = 0; i < 61; i++)
	{
		gotoxy(0, i + 1);
		cout << " ��\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   ��";
	}
	gotoxy(0, 62);
	cout << " �����������������������������������������������������������������������������������������������������������������������";

#pragma endregion

 

}

void Poker::Init(Player* player1, Dealer* pdealer, Deck* pcardDeck)
{

	player = player1;
	dealer = pdealer;
	cardDeck = pcardDeck;
}

void Poker::DrawPlayerCard(int x, int y)
{
	clock_t delay = 0.2f * CLOCKS_PER_SEC;
	clock_t start = clock();
	while (clock() - start < delay)
	{
		//��ٸ���
	}

	player->receiveCard(cardDeck->dealCard());

	string suitandvalue = player->GetCard(player->CardCount() - 1).toString();

	gotoxy(x, y);
	cout << "������������������������";

	for (int j = 0; j < 8; j++)
	{
		Sleep(50);
		if (j == 1)
		{
			gotoxy(x, j + y + 1);
			if (player->GetCard(player->CardCount() - 1).getValue() == 10)
			{
				cout << "��" << suitandvalue << "      ��";
				continue;
			}
			cout << "��" << suitandvalue << "       ��";
			continue;
		}
		if (j == 6)
		{
			gotoxy(x, j + y + 1);
			if (player->GetCard(player->CardCount() - 1).getValue() == 10)
			{
				cout << "��      " << suitandvalue << "��";
				continue;
			}
			cout << "��       " << suitandvalue << "��";
			continue;
		}
		gotoxy(x, j + y + 1);
		cout << "��          ��";
	}
	gotoxy(x, y + 9);
	cout << "������������������������";


}
void Poker::DrawBoardCard(int x, int y)
{
	//Sleep(500);
	clock_t delay = 0.5f * CLOCKS_PER_SEC;
	clock_t start = clock();
	while (clock() - start < delay)
	{
		//��ٸ���
	}
	Card boardCard = cardDeck->dealCard();
	player->receiveCard(boardCard);
	dealer->receiveCard(boardCard);

	
	string suitandvalue = boardCard.toString();
	
	gotoxy(x, y);
	cout << "������������������������";

	for (int j = 0; j < 8; j++)
	{
		Sleep(50);
		if (j == 1)
		{
			gotoxy(x, j + y + 1);
			if (boardCard.getValue() == 10)
			{
				cout << "��" << suitandvalue << "      ��";
				continue;
			}
			cout << "��" << suitandvalue << "       ��";
			continue;
		}
		if (j == 6)
		{
			gotoxy(x, j + y + 1);
			if (boardCard.getValue() == 10)
			{
				cout << "��      " << suitandvalue << "��";
				continue;
			}
			cout << "��       " << suitandvalue << "��";
			continue;
		}
		gotoxy(x, j + y + 1);
		cout << "��          ��";
	}
	gotoxy(x, y + 9);
	cout << "������������������������";

}
void Poker::DrawDealerCard(int x, int y)
{
	clock_t delay = 0.2f * CLOCKS_PER_SEC;
	clock_t start = clock();
	while (clock() - start < delay)
	{
		//��ٸ���
	}
	dealer->receiveCard(cardDeck->dealCard());


	gotoxy(x, y);
	cout << "������������������������";

	for (int j = 0; j < 8; j++)
	{
		Sleep(50);
		gotoxy(x, j + y + 1);
		cout << "��          ��";
	}
	gotoxy(x, y + 9);
	cout << "������������������������";

}

void Poker::DrawDealerCardNum(int x, int y, int i)
{
	Sleep(500);
	Card boardCard = dealer->GetCard(i);

	string suitandvalue = boardCard.toString();

	gotoxy(x, y);
	cout << "������������������������";

	for (int j = 0; j < 8; j++)
	{
		Sleep(50);
		if (j == 1)
		{
			gotoxy(x, j + y + 1);
			if (boardCard.getValue() == 10)
			{
				cout << "��" << suitandvalue << "      ��";
				continue;
			}
			cout << "��" << suitandvalue << "       ��";
			continue;
		}
		if (j == 6)
		{
			gotoxy(x, j + y + 1);
			if (boardCard.getValue() == 10)
			{
				cout << "��      " << suitandvalue << "��";
				continue;
			}
			cout << "��       " << suitandvalue << "��";
			continue;
		}
		gotoxy(x, j + y + 1);
		cout << "��          ��";
	}
	gotoxy(x, y + 9);
	cout << "������������������������";
	
}
