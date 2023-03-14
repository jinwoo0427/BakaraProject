#pragma once

class Hand;
class Player;
class Dealer;
class Deck;
class Game;
class BlackJack
{
public:
	BlackJack();
	
	void Init(Player* player1, Dealer* pdealer, Deck* pcardDeck);
	void PrintCardBoard();

	void DrawDealerCard(int x, int y);
	void DrawPlayerCard(int x, int y);
	void DrawDeleteCard(int drawNum);

	void StartGame();
	void DecisionWinner();
	void ResetCard();

	bool ExitGame();

	void PlayerWin();
	void DealerWin();


	//플레이어의 카드 합을 구하는 햄수
	int getBlackjackValue(Hand h);

	void PlayBlackJeck();


	void PrintRule();

private:
	Dealer* dealer;
	Player* player;
	Deck* cardDeck;
	Game* game;

	int betmoney;
	bool backMenu;
	bool isStand;
	bool gameOver;
	//Rule rule = new Rule();
};

