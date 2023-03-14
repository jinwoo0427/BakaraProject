#pragma once
#include <list>


class Card;
class Hand;
class Dealer
{
public:
	Dealer();
	~Dealer();

	void receiveCard(Card card);
	void removeCard(Card card);
	void removeCard(int position);
	
	void ClearCard();

	Card GetCard(int position);

	Hand GetHandCard();

	int CardCount();
	void SortHandCard();
private:
	Hand* dealerCards;
	int dealerMoney;
};

