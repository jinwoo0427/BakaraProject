#include "console.h"
#include "Card.h"
#include "Hand.h"

Hand::Hand()
{
	//hand = new list<Card>();
    ace = false;
}

void Hand::clear()
{
    hand->clear();
}

void Hand::addCard(Card c)
{
	/*if (c == NULL)
		return;*/
       
    hand->push_back(c);
}

void Hand::removeCard(Card c)
{
    // 요 새끼가 문제임
	// hand->remove(*c);

    //Card temp = hand->front();
    //find(hand->front(), hand->back(), *c);
    //list<Card>::iterator li;


    for (int i = 0; i < (int)hand->size(); i++)
    {

        if (hand->front().getSuit() == c.getSuit() && hand->front().getValue() == c.getValue())
        {
            hand->pop_front();
            continue;
        }
        else
        {
            hand->push_back(hand->front());
            hand->pop_front();
        }
        
    }
    
}

void Hand::removeCard(int position)
{
    if (position < 0 || position >= (int)hand->size())
    {
        cout << "제거에서 오류남";
		return;
    }


    for (int i = 0; i <(int)hand->size(); i++)
    {
        if (i == position)
        {
            hand->pop_front();
            continue;
        }
        hand->push_back(hand->front());
        hand->pop_front();
    }

	//hand.remove(position);
}

int Hand::getCardCount()
{
	return (int)hand->size();
}

Card Hand::getCard(int position)
{
    if (position < 0 || position >= (int)hand->size())
        cout << "머함";
    //list<Card>::iterator li;

    Card temp;
    for (int i = 0; i < (int)hand->size(); i++)
    {
        if (i == position)
        {
            temp = hand->front();

        }
        hand->push_back(hand->front());
        hand->pop_front();
    }

    return temp;
}

void Hand::sortBySuit()
{
    list<Card> newHand;
    while ((int)hand->size() > 0) {
        int pos = 0;  // 제일 작은 카드의 포지션
        Card c = this->getCard(0);// 제일 작은 카드
        for (int i = 1; i < (int)hand->size(); i++) {
            Card c1 = this->getCard(i);
            if (c1.getSuit() < c.getSuit() ||
                (c1.getSuit() == c.getSuit() && c1.getValue() < c.getValue())) {
                pos = i;
                c = c1;
            }
        }
        this->removeCard(pos);
        newHand.push_front(c);
    }
    hand = &newHand;
}

void Hand::sortByValue()
{
    list<Card> newHand;
        int j = 0;
    while ((int)hand->size() > 0) {
        int pos = 0;  // 제일 작은 카드의 포지션
        Card c = this->getCard(0);// 제일 작은 카드
        for (int i = 1; i < (int)hand->size(); i++) {
            Card c1 = this->getCard(i);
            if (c1.getValue() < c.getValue() ||
                (c1.getValue() == c.getValue() && c1.getSuit() < c.getSuit())) {
                pos = i;
                c = c1;
            }
        }
        this->removeCard(pos);
        newHand.push_front(c);
        lasthand[j] = c.getValue();
        //cout << this->lasthand[j]<<" ";
        j++;
    }
    hand = &newHand;

    
    
}

HandType Hand::ResultHand()
{
    if (this->IsRoyalFlush() == true)
        return HandType::royalFlush;
    else if (this->IsStraightFlush() == true)
        return HandType::straightFlush;
    else if (this->IsFourOfKind() == true)
        return HandType::fourOfAKind;
    else if (this->IsFullHouse() == true)
        return HandType::fullHouse;
    else if (this->IsFlush() == true)
        return HandType::Flush;
    else if (this->IsStraight() == true)
        return HandType::straight;
    else if (this->IsTriplets() == true)
        return HandType::threeOfAKind;
    else if (this->IsTwoPairs() == true)
        return HandType::twoPairs;
    else if (this->IsOnePair() == true)
        return HandType::Pair;
    else
        return HandType::HighCard;
}

int Hand::ResultHighCard()
{
   
    return lasthand[4];
}

bool Hand::IsOnePair()
{
    if ((lasthand[0] == lasthand[1]) || (lasthand[1] == lasthand[2]) ||
        (lasthand[2]== lasthand[3]) || (lasthand[3] == lasthand[4]))
        return true;
    else
        return false;


}

bool Hand::IsTwoPairs()
{
    if ((lasthand[0] == lasthand[1]) && (lasthand[2] == lasthand[3]))
        return true;
    else if ((lasthand[1] == lasthand[2]) && (lasthand[3] == lasthand[4]))
        return true;
    else if ((lasthand[0] == lasthand[1]) && (lasthand[3] == lasthand[4]))
        return true;
    else
        return false;

}

bool Hand::IsTriplets()
{
    if (lasthand[0] == lasthand[1] && lasthand[1] == lasthand[2])
        return true;
    else if (lasthand[1]== lasthand[2] && lasthand[2] == lasthand[3])
        return true;
    else if (lasthand[2] == lasthand[3] && lasthand[3] == lasthand[4])
        return true;
    else
        return false;
}

bool Hand::IsStraight()
{
    bool straight;
    for (int counter = 0; counter < 4; counter++)//if it's a straight
        if ((lasthand[counter] - 1) == lasthand[counter+1])
            straight = true;
        else
        {
            straight = false;
            break;
        }

    return straight;
}

bool Hand::IsFlush()
{
    bool flush;

    for (int counter = 0; counter < 4; counter++)//if it's a flush
        if (lasthand[counter] == lasthand[counter+1])
            flush = true;
        else
        {
            flush = false;
            break;
        }

    return flush;

}

bool Hand::IsFullHouse()
{
    if ((lasthand[0] == lasthand[1]&& lasthand[1] == lasthand[2]) && (lasthand[3] == lasthand[4]))
        return true;
    else if ((lasthand[2] == lasthand[3] && lasthand[3]== lasthand[4]) && lasthand[0] == lasthand[1])
        return true;
    else
        return false;
}

bool Hand::IsFourOfKind()
{
    if (this->lasthand[0] == this->lasthand[1] && this->lasthand[1] == this->lasthand[2] && this->lasthand[2] == this->lasthand[3])
    {
        return true;
    }
    else if (this->lasthand[1] == this->lasthand[2] && this->lasthand[2] == this->lasthand[3] && this->lasthand[3] == this->lasthand[4])
    {

        return true;
    }
    else
        return false;
}

bool Hand::IsStraightFlush()
{
    bool straight, flush;
    for (int counter = 0; counter < 4; counter++)
        if ((lasthand[counter] - 1) == lasthand[counter + 1])
            straight = true;
        else
        {
            straight = false;
            break;
        }


    for (int counter = 0; counter < 4; counter++)
        if (lasthand[counter]== lasthand[counter + 1])
            flush = true;
        else
        {
            flush = false;
            break;
        }

    if (straight == true && flush == true)
        return true;
    else
        return false;
}

bool Hand::IsRoyalFlush()
{
    bool straight, flush;
    for (int counter = 0; counter < 4; counter++)
        if ((lasthand[counter] - 1) == lasthand[counter + 1])
            straight = true;
        else
        {
            straight = false;
            break;
        }


    for (int counter = 0; counter < 4; counter++)
        if (lasthand[counter]== lasthand[counter + 1])
            flush = true;
        else
        {
            flush = false;
            break;
        }

    if (straight == true && flush == true && lasthand[0] == 14)
        return true;
    else
        return false;
}


