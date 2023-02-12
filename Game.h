#pragma once
#include "Player.h"
#include "deck.h"

class Game {
public:
	Game();

	void update();

	void draw();

	void play(const int k);

	void print_score(Player pl1, Player pl2);


private:
	bool flag3; // when false the game is at the menu state , if true the game is at the main loop
	bool flag; // player turn 
	int n, c; // current card's stats
	deck mydeck; // card deck
	Player myp1; // player 1
	Player myp2; // player 2
	string name;
	int money;
	bool flag4 = false;
};
