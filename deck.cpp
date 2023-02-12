// creates and updates decks for bnoth players
#pragma once
#include <cstdlib>
#include "card.h"
#include <time.h>
#include "deck.h"

//
// THIS CLASS MANAGES THE DECKS OF THE 2 PLAYERS AND THE MAIN UNO DECK //
//


deck::deck() { // default constructor * creates uno deck and shuffles it 3 times
		num_of_card1 = -1;
		num_of_card2 = -1;
		num_of_card = -1;
		srand(time(0));
		int count = 0;
		for (int k = 1; k <= 4; k++) {
			int i = 0;
			for (int j = 0; j <= 1; j++) {
				for (i; i <= 12; i++) {
					card* t_card = new card(i, k);
					t_card->png();
					deckAll[count] = t_card;
					count++;
				}
				i = 1;
			}
		}
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 3; k++) {
				card* t_card = new card(k, 0); 
				t_card->png();
				deckAll[count] = t_card;
				count++;
			}
		}
		shuffle(deckAll, 108);
		shuffle(deckAll, 108);
		shuffle(deckAll, 108);

		


	}

void deck::shuffle(card* d[], int n) { // shuffle function
		srand(time(0));
		for (int i = 0; i < n; i++) {
			int r = 0 + (rand() % (108 - i));

			card* temp = d[i];
			d[i] = d[r];
			d[r] = temp;
		}
	}


void deck::del1(int index) { // deletes a card from deck1
	//delete deck1[index];
	//delete deck1[index];
	if (index > num_of_card1 - 1) {

	}
	else {
		for (int i = index; i <= num_of_card1 - 1; i++) {
			deck1[i] = deck1[i + 1];

		}
	}

	num_of_card1 = num_of_card1 - 1;

}

void deck::del2(int index) { // deletes a card from deck2
	//delete deck2[index];
	if (index > num_of_card2 - 1) {
			
	}
	else {
		for (int j = index; j <= num_of_card2 - 1; j++) {
			deck2[j] = deck2[j + 1];

		}
	}

	num_of_card2 = num_of_card2 - 1;

}

void deck::add_card1() { // adds card to deck1
	num_of_card1++;
	num_of_card++;
	deck1[num_of_card1] = deckAll[num_of_card];
}

void deck::add_card2() { // adds card to deck2
	num_of_card2++;
	num_of_card++;
	deck2[num_of_card2] = deckAll[num_of_card];
}


int deck::get_n1(int index) { return deck1[index]->get_n(); }
int deck::get_c1(int index) { return deck1[index]->get_c(); }
int deck::get_n2(int index) { return deck2[index]->get_n(); }
int deck::get_c2(int index) { return deck2[index]->get_c(); }

int deck::get_num1() { return num_of_card1; }
int deck::get_num2() { return num_of_card2; }

void deck:: draw_deck1() { // draws deck of player 1 
	int x = 50; 
	int y = 420;
	for (int k = 0; k <= num_of_card1-1; k++) {
		deck1[k]->costume_print(x, y);
		x += 80;

	}
}

void deck::draw_deck2() { // draws deck of player 2 
	int x = 50;
	int y = 420;
	for (int k = 0; k <= num_of_card2-1; k++) {
		deck2[k]->costume_print(x, y);
		x += 80;

	}
}

void deck::share() { // shares cards to players
	for (int i = 0; i <= 4; i++) {
		add_card1();
		add_card2();
	}
}

card* deck::get1(int index) {
	return deck1[index];
}

card* deck::get2(int index) {
	return deck2[index];
}
