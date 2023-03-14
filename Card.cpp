#include "console.h"
#include "Card.h"

Card::Card()
{
	value = 2;
	suit = 2;
}

Card::Card(int theValue, int theSuit)
{
	if (theSuit != SPADES && theSuit != HEARTS && theSuit != DIAMONDS &&
		theSuit != CLUBS)
		return;

	value = theValue;
	suit = theSuit;
}

int Card::getSuit()
{
	return suit;
}

int Card::getValue()
{
	return value;
}

string Card::getSuitAsString()
{
	switch (suit) {
	case SPADES:   return "♠";
	case HEARTS:   return "♥";
	case DIAMONDS: return "◆";
	case CLUBS:    return "♣";
	//default:    return "♣";
	}
	return "클로버";
}

string Card::getValueAsString()
{
	switch (value) {
	case 1:   return "A";
	case 2:   return "2";
	case 3:   return "3";
	case 4:   return "4";
	case 5:   return "5";
	case 6:   return "6";
	case 7:   return "7";
	case 8:   return "8";
	case 9:   return "9";
	case 10:  return "10";
	case 11:  return "J";
	case 12:  return "Q";
	case 13:  return "K";
	}
	return "케이";
}

string Card::toString()
{
	return getSuitAsString() + getValueAsString();
}

//string Card::a()
//{
//
//	return "asdfjkl";
//}