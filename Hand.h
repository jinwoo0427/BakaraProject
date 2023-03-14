#pragma once
#include "Card.h"
#include <list>
enum class HandType {
    HighCard = 0, Pair = 1, twoPairs = 2, threeOfAKind = 3,
    straight = 4, Flush = 5, fullHouse = 6, fourOfAKind = 7,
    straightFlush = 8, royalFlush = 9
};
class Card;
class Hand
{
public:
    

    Hand();

    /**
    * 손패의 모든 카드를 버려서 손패를 비움.
    */
    void clear();
    /**
    * 카드 c를 손패에 추가. c는 null이 아니여야 함.
    */
    void addCard(Card c);
    /**
    * 지정된 카드가 손에 있다면, 이를 제거함.
    */
    void removeCard(Card c);
    /**
    * 손패의 지정된 위치에 있는 카드를 제거함.
    * 카드는 0부터 번호를 셈.
    */
    void removeCard(int position);
    /**
    * 손패의 카드 숫자를 반환.
    */
    int getCardCount();
    /**
    * 손패의 주어진 위치에서 카드를 얻음.
    * 위치는 0부터 시작하여 번호를 셈.
    */
    Card getCard(int position);
    /**
    * 동일한 문양의 카드가 함께 그룹이 되도록,
    * 그리고 문양 안에서 값에 의해 카드가 정렬이
    * 되도록 손패의 카드를 정렬.
    */
    void sortBySuit();
    /**
    * 카드가 증가되는 값의 순서대로 정렬이 되도록
    * 손패의 카드를 정렬. 동일한 값을 가지는 카드는
    * 문양에 의해 정렬. 에이스가 가장 낮은
    * 값을 가지는 것으로 간주함.
    */
    void sortByValue();


    HandType ResultHand();
    int ResultHighCard();

    bool IsOnePair();
    bool IsTwoPairs();
    bool IsTriplets();
    bool IsStraight();
    bool IsFlush();
    bool IsFullHouse();
    bool IsFourOfKind();
    bool IsStraightFlush();
    bool IsRoyalFlush();

private:

    list<Card> *hand = new list<Card>;

    //Card lasthand[5];
    int lasthand[5];
    bool ace;
    int highCardNum;

   

};

