#pragma once
//#include "Card.h"

class Card;
class Deck
{
    
public:
     /*
      * 생성자. 섞이지 않은 카드 덱을 생성한다.
      */
    Deck();

        /*
         * 사용된 모든 카드를 덱에 되돌린 다음,
         * 무작위한 순서로 이를 뒤섞는다.
         */
    void shuffle();

        /*
         * 덱에서 카드가 뽑히면, 남은 카드의 갯수는
         * 감소한다. 이 함수는 덱에 여전히 남아 있는
         * 카드의 갯수를 반환한다.
         */
    int cardsLeft();

        /*
         * 덱에서 카드 하나를 뽑은 다음 이를 반환한다.
         */
    Card dealCard();

private:

    Card* deck;

    int cardsUsed;
};

