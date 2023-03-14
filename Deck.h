#pragma once
//#include "Card.h"

class Card;
class Deck
{
    
public:
     /*
      * ������. ������ ���� ī�� ���� �����Ѵ�.
      */
    Deck();

        /*
         * ���� ��� ī�带 ���� �ǵ��� ����,
         * �������� ������ �̸� �ڼ��´�.
         */
    void shuffle();

        /*
         * ������ ī�尡 ������, ���� ī���� ������
         * �����Ѵ�. �� �Լ��� ���� ������ ���� �ִ�
         * ī���� ������ ��ȯ�Ѵ�.
         */
    int cardsLeft();

        /*
         * ������ ī�� �ϳ��� ���� ���� �̸� ��ȯ�Ѵ�.
         */
    Card dealCard();

private:

    Card* deck;

    int cardsUsed;
};

