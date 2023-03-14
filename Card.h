#pragma once
#include <string>

class Card
{

public:
    const static int SPADES = 0;   // 4가지 문양에 조커를 추가한 것에 대한 코드.
    const static int HEARTS = 1;
    const static int DIAMONDS = 2;
    const static int CLUBS = 3;

    const static int ACE = 1;      // 숫자가 아닌 카드에 대한 코드.
    const static int JACK = 11;    //   2부터 10 사이의 카드는
    const static int QUEEN = 12;   //   이들에 대한 코드로 숫자 값을 가진다.
    const static int KING = 13;

    Card();

    /**
     * 지정된 문양과 값으로 카드를 생성한다.
     * @param theValue 새로운 카드의 해당 값. 일반적인 카드의 경우,
     * 해당 값은 반드시 1부터 13 사이의 범위에 있어야 하며, 여기서 1은 에이스를 나타낸다.
     * 상수 Card.ACE, Card.JACK, Card.QUEEN, 및 Card.KING을 사용할 수도 있다.
     * @param theSuit 새로운 카드의 해당 문양. 이는 Card.SPADES, Card.HEARTS,
     * Card.DIAMONDS, Card.CLUBS, 또는 Card.JOKER 값들 중 반드시 하나여야 한다.
     */
    Card(int theValue, int theSuit);

    /**
     * 이 카드의 문양을 반환.
     * @return 문양은 상수 Card.SPADES,
     * Card.HEARTS, Card.DIAMONDS, Card.CLUBS, 또는 Card.JOKER 중 하나임.
     */
    int getSuit();

    /**
     * 이 카드의 값을 반환.
     * @return 값은 평범한 카드의 경우 숫자 1부터 13 사이의 것 중 하나이며
     * 조커의 경우 어떤 값도 될 수 있음.
     */
    int getValue();

    /**
     * 카드의 문양에 관한 문자열 표상을 반환.
     * @return 문자열 "스페이드", "하트", "다이아몬드",
     * "클럽" 중 하나임.
     */
    std::string getSuitAsString();

    /**
     * 카드의 값에 관한 문자열 표상을 반환.
     * @return 평범한 카드는 문자열 "에이스", "2",
     * "3", ..., "10", "잭", "퀸", 또는 "킹" 중 하나를 반환한다.
     */
    std::string getValueAsString();

    /**
     * 이 카드의 문양 및 값을 포함하는 문자열 표상을 반환
     * (예외적으로 값 1을 가지는 조커의 경우 반환되는 값은
     * 단순히 "조커"임). 샘플 반환 값은 다음과 같음:
     * "하트 퀸", "다이아몬드 10", "스페이드 에이스",
     */
    std::string toString();

    //string a();


private:
    /**
     * 해당 카드의 문양으로, 상수 SPADES, HEARTS, DIAMONDS,
     * CLUBS 중 하나이다. 해당 카드가 생성된 이후에는
     * 문양은 변경될 수 없다.
     */
    int suit = 2;
    
    /**
     * 해당 카드의 값. 평범한 카드의 경우 이는 1부터 13 사이의 값 중 하나이며,
     * 여기서 1은 ACE를 나타낸다.
     * 해당 카드가 생성된 이후에는 값은 변경될 수 없다.
     */
    int value = 2;
    

};

