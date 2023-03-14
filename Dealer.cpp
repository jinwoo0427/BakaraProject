#include "console.h"
#include "Card.h"
#include "Hand.h"
#include "Dealer.h"

Dealer::Dealer()
{
	dealerCards = new Hand();
}

Dealer::~Dealer()
{
}

Hand Dealer::GetHandCard()
{
	return *dealerCards;
}

void Dealer::receiveCard(Card card)
{
	dealerCards->addCard(card);
}

void Dealer::removeCard(Card card)
{
	dealerCards->removeCard(card);
}

void Dealer::removeCard(int position)
{
	dealerCards->removeCard(position);
}

void Dealer::ClearCard()
{
	dealerCards->clear();
}

Card Dealer::GetCard(int position)
{
	return dealerCards->getCard(position);
}

void Dealer::SortHandCard()
{
	dealerCards->sortByValue();
}


int Dealer::CardCount()
{
	return dealerCards->getCardCount();
}


