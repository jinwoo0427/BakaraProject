#pragma once

class Hand;
class Player;
class Dealer;
class Deck;
class Game;
class Poker
{
public:
	Poker();
	~Poker();

	void PrintPokerBoard();
	void Init(Player* player1, Dealer* pdealer, Deck* pcardDeck);

	void DrawDealerCard(int x, int y);
	void DrawDealerCardNum(int x, int y, int i);
	void DrawPlayerCard(int x, int y);
	void DrawBoardCard(int x, int y);
	//void DrawDeleteCard(int drawNum);

	void ChooseState();
	void ClearChooseBoard();
	void StartGame();
	void DecisionWinner();
	void ResetCard();

	bool ExitGame();

	void SortCard(Hand h);

	void DealerChoice(bool first);
	void PlayerChoice(int y);
	
	void PlayerWin();
	void DealerWin();

	void RandomTurn(int i);

	//플레이어의 카드 합을 구하는 햄수
	int getPokerValue(Hand h);

	void PlayPokerGame();

	void TotalMoney(int money);

	int DetermineWinner();

private:
	Dealer* dealer;
	Player* player;
	Deck* cardDeck;
	Game* game;

	int round;

	int totalmoney;
	int callMoney;
	int dealerbat;
	int dealerchoice;
	int betmoney;
	bool backMenu;
	bool gameOver;
	bool playerturn;
};

