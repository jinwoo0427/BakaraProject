#pragma once
#include <list>



class Card;
class Hand;
class Player
{
public:
	Player();
	~Player();

	void receiveCard(Card card);
	void removeCard(Card card);
	void removeCard(int position);

	void ClearCard();

	Card GetCard(int position);

	int CardCount();

	//std::list<Card> openCards();
	int GetPlayerMoney();
	void AddPlayerMoney(int money);
	void MinusPlayerMoney(int money);

	Hand GetHandCard();

	void SortHandCard();

	

	
private:

	//std::list<Card> cards;
	Hand * playerCards;
	int playerMoney;

	
};

