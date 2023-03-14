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
    * ������ ��� ī�带 ������ ���и� ���.
    */
    void clear();
    /**
    * ī�� c�� ���п� �߰�. c�� null�� �ƴϿ��� ��.
    */
    void addCard(Card c);
    /**
    * ������ ī�尡 �տ� �ִٸ�, �̸� ������.
    */
    void removeCard(Card c);
    /**
    * ������ ������ ��ġ�� �ִ� ī�带 ������.
    * ī��� 0���� ��ȣ�� ��.
    */
    void removeCard(int position);
    /**
    * ������ ī�� ���ڸ� ��ȯ.
    */
    int getCardCount();
    /**
    * ������ �־��� ��ġ���� ī�带 ����.
    * ��ġ�� 0���� �����Ͽ� ��ȣ�� ��.
    */
    Card getCard(int position);
    /**
    * ������ ������ ī�尡 �Բ� �׷��� �ǵ���,
    * �׸��� ���� �ȿ��� ���� ���� ī�尡 ������
    * �ǵ��� ������ ī�带 ����.
    */
    void sortBySuit();
    /**
    * ī�尡 �����Ǵ� ���� ������� ������ �ǵ���
    * ������ ī�带 ����. ������ ���� ������ ī���
    * ���翡 ���� ����. ���̽��� ���� ����
    * ���� ������ ������ ������.
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

