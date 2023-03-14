#pragma once

class Sound;
class Dealer;
class Deck;
class Player; //클래스 전방선언
class Poker;
class BlackJack;
class Game
{
public:
	Game();
	~Game();
	void Init();
	void Update();
	void PrintTitle();
	void PrintInfo();
	void PrintGameOver();
	void StartGameMenu();
	Sound getSound();

private:

	Sound* sound;
	Player* player;
	Deck* cardDeck;
	BlackJack* blackJack;
	Poker* poker;
	Dealer* dealer;
	int gameNum;
	
};

