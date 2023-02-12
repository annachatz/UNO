#pragma once
#include "card.h"

class deck {

public:
	deck();

	void shuffle(card* d[], int n);

	void del1(int index);
	void del2(int index);

	void add_card1();
	void add_card2();

	int get_n1(int index);
	int get_c1(int index);
	int get_n2(int index);
	int get_c2(int index);

	int get_num1();
	int get_num2();

	void draw_deck1();
	void draw_deck2();

	void share();

	card* get1(int index);
	card* get2(int index);



private:
	card* deckAll[108]; //deck with all the cards for both players
	card* deck1[30]; // deck1 
	card* deck2[30]; // deck2 
	int num_of_card1; // num of cards in deck1
	int num_of_card2; // num of cards in deck2
	int num_of_card;
};
