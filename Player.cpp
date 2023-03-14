#include "console.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"


Player::Player()
{
	//cards = new list<Card>;
	playerCards = new Hand();
	playerMoney = 1000000;
}

Player::~Player()
{
}

void Player::receiveCard(Card card)
{
	//cards.push_front(card);
	playerCards->addCard(card);
}

void Player::removeCard(Card card)
{
	playerCards->removeCard(card);
}
void Player::removeCard(int position)
{
	playerCards->removeCard(position);
}
void Player::ClearCard()
{
	playerCards->clear();
}
Card Player::GetCard(int position)
{
	return playerCards->getCard(position);
}

int Player::CardCount()
{
	return playerCards->getCardCount();
}

Hand Player::GetHandCard()
{
	return *playerCards;
}

void Player::SortHandCard()
{
	playerCards->sortByValue();
}


//list<Card> Player::openCards()
//{
//	//return playerCards;
//	return cards;
//}

int Player::GetPlayerMoney()
{
	return playerMoney;
}

void Player::AddPlayerMoney(int money)
{
	playerMoney += money;

}

void Player::MinusPlayerMoney(int money)
{
	playerMoney -= money;
}


