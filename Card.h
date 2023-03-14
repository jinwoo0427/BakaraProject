#pragma once
#include <string>

class Card
{

public:
    const static int SPADES = 0;   // 4���� ���翡 ��Ŀ�� �߰��� �Ϳ� ���� �ڵ�.
    const static int HEARTS = 1;
    const static int DIAMONDS = 2;
    const static int CLUBS = 3;

    const static int ACE = 1;      // ���ڰ� �ƴ� ī�忡 ���� �ڵ�.
    const static int JACK = 11;    //   2���� 10 ������ ī���
    const static int QUEEN = 12;   //   �̵鿡 ���� �ڵ�� ���� ���� ������.
    const static int KING = 13;

    Card();

    /**
     * ������ ����� ������ ī�带 �����Ѵ�.
     * @param theValue ���ο� ī���� �ش� ��. �Ϲ����� ī���� ���,
     * �ش� ���� �ݵ�� 1���� 13 ������ ������ �־�� �ϸ�, ���⼭ 1�� ���̽��� ��Ÿ����.
     * ��� Card.ACE, Card.JACK, Card.QUEEN, �� Card.KING�� ����� ���� �ִ�.
     * @param theSuit ���ο� ī���� �ش� ����. �̴� Card.SPADES, Card.HEARTS,
     * Card.DIAMONDS, Card.CLUBS, �Ǵ� Card.JOKER ���� �� �ݵ�� �ϳ����� �Ѵ�.
     */
    Card(int theValue, int theSuit);

    /**
     * �� ī���� ������ ��ȯ.
     * @return ������ ��� Card.SPADES,
     * Card.HEARTS, Card.DIAMONDS, Card.CLUBS, �Ǵ� Card.JOKER �� �ϳ���.
     */
    int getSuit();

    /**
     * �� ī���� ���� ��ȯ.
     * @return ���� ����� ī���� ��� ���� 1���� 13 ������ �� �� �ϳ��̸�
     * ��Ŀ�� ��� � ���� �� �� ����.
     */
    int getValue();

    /**
     * ī���� ���翡 ���� ���ڿ� ǥ���� ��ȯ.
     * @return ���ڿ� "�����̵�", "��Ʈ", "���̾Ƹ��",
     * "Ŭ��" �� �ϳ���.
     */
    std::string getSuitAsString();

    /**
     * ī���� ���� ���� ���ڿ� ǥ���� ��ȯ.
     * @return ����� ī��� ���ڿ� "���̽�", "2",
     * "3", ..., "10", "��", "��", �Ǵ� "ŷ" �� �ϳ��� ��ȯ�Ѵ�.
     */
    std::string getValueAsString();

    /**
     * �� ī���� ���� �� ���� �����ϴ� ���ڿ� ǥ���� ��ȯ
     * (���������� �� 1�� ������ ��Ŀ�� ��� ��ȯ�Ǵ� ����
     * �ܼ��� "��Ŀ"��). ���� ��ȯ ���� ������ ����:
     * "��Ʈ ��", "���̾Ƹ�� 10", "�����̵� ���̽�",
     */
    std::string toString();

    //string a();


private:
    /**
     * �ش� ī���� ��������, ��� SPADES, HEARTS, DIAMONDS,
     * CLUBS �� �ϳ��̴�. �ش� ī�尡 ������ ���Ŀ���
     * ������ ����� �� ����.
     */
    int suit = 2;
    
    /**
     * �ش� ī���� ��. ����� ī���� ��� �̴� 1���� 13 ������ �� �� �ϳ��̸�,
     * ���⼭ 1�� ACE�� ��Ÿ����.
     * �ش� ī�尡 ������ ���Ŀ��� ���� ����� �� ����.
     */
    int value = 2;
    

};

