#include "Deck.h"
#include "Card.h"
#include "console.h"
Deck::Deck()
{
    deck = new Card[52];
    int cardCt = 0; 
    for (int suit = 0; suit < 4; suit++) {
        for (int value = 1; value < 14; value++) {
            deck[cardCt] = Card(value, suit);

            cardCt++;
        }
    }
    cardsUsed = 0;
}

void Deck::shuffle()
{
    for(int i = 51; i > 0; i--) {
        int random = rand() % i;
        Card temp = deck[i];
        deck[i] = deck[random];
        deck[random] = temp;
    }
    cardsUsed = 0;
}

int Deck::cardsLeft()
{
    
    return 52 - cardsUsed;
}

Card Deck::dealCard()
{
    /*if (cardsUsed == deck.length)
        throw new IllegalStateException("No cards are left in the deck.");*/

    /*if (cardsUsed == sizeof(deck) / sizeof(Card))
        return deck[0];*/

    cardsUsed++;
    return deck[cardsUsed - 1];
}
