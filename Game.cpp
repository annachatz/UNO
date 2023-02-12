#pragma once
#include "card.h"
#include <iostream>
#include "deck.h"
#include <string>
#include "scancodes.h"
#include "Player.h"
#include "graphics.h"
#include "Game.h"
#include "config.h"

using namespace std;

//
// THIS CLASS RUNS THE MAIN LOOP OF THE GAME AND THE DRAW FOR THE WINDOW
// flag = true , PLAYER 1
// flag = false , PLAYER 2
// GAME ENDS WHEN ONE PLAYER REACHES 0 SCORE aka NO CARDS LEFT
//



Game::Game() {
		flag3 = true; // game is at menu phase
		this->n = (rand() % 12) + 1; // place your bets
		this->c = (rand() % 4) + 1;
		flag = true;
		string name;
		cout << "First player write your name \n";
		cin >> name;
		myp1.setUsername(name);
		cout << "Second player write your name \n";
		cin >> name;
		myp2.setUsername(name);
		myp1.setCards(4);
		myp2.setCards(4);
		cout << "Player's place your bets \n";
		graphics::playSound(std::string(ASSET_PATH) + "bet.mp3", 0.9, false);
		cout << myp1.getUsername();
		cout << " place your bet: \n";
		int money;
		cin >> money;
		myp1.setBet(money);
		cout << myp2.getUsername();
		cout << " place your bet: \n";
		cin >> money;
		myp2.setBet(money);
		mydeck.share();
	}

void Game::update() {

		graphics::MouseState mouse2;
		graphics::getMouseState(mouse2);
		graphics::Brush br;

		if (mouse2.button_left_released & flag3 == false) // player clicks
		{
			cout << "X: " << mouse2.cur_pos_x << "  Y:  " << mouse2.cur_pos_y << endl;
			if (mouse2.cur_pos_x <= 1161 & mouse2.cur_pos_x >= 1000 & mouse2.cur_pos_y >= 23 & mouse2.cur_pos_y <= 214) { // player wants to draw a card
				if (flag == true) {
					mydeck.add_card1();
					graphics::playSound(std::string(ASSET_PATH) + "card_set.mp3", 0.9, false);
					myp1.cardPlus();
				}
				else {
					mydeck.add_card2();
					graphics::playSound(std::string(ASSET_PATH) + "card_set.mp3", 0.9, false);
					myp2.cardPlus();
				}
			}

			if (mouse2.cur_pos_x <= 954 & mouse2.cur_pos_x >= 803 & mouse2.cur_pos_y >= 271 & mouse2.cur_pos_y <= 387) { // pass , "next player"
				flag = !flag;
			}

			if (mouse2.cur_pos_x <= 1172 & mouse2.cur_pos_x >= 1002 & mouse2.cur_pos_y >= 301 & mouse2.cur_pos_y <= 408) { //UNO

			}

			if (mouse2.cur_pos_x <= 94 & mouse2.cur_pos_x >= 25 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 0
				play(0);
			}

			if (mouse2.cur_pos_x <= 189 & mouse2.cur_pos_x >= 118 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 1
				play(1);
			}

			if (mouse2.cur_pos_x <= 285 & mouse2.cur_pos_x >= 217 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 2
				play(2);
			}

			if (mouse2.cur_pos_x <= 380 & mouse2.cur_pos_x >= 313 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 3
				play(3);
			}

			if (mouse2.cur_pos_x <= 478 & mouse2.cur_pos_x >= 408 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 4
				play(4);
			}

			if (mouse2.cur_pos_x <= 573 & mouse2.cur_pos_x >= 504 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 5
				play(5);
			}

			if (mouse2.cur_pos_x <= 670 & mouse2.cur_pos_x >= 600 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 6
				play(6);
			}

			if (mouse2.cur_pos_x <= 765 & mouse2.cur_pos_x >= 697 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 7
				play(7);
			}

			if (mouse2.cur_pos_x <= 861 & mouse2.cur_pos_x >= 793 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 8
				play(8);
			}

			if (mouse2.cur_pos_x <= 955 & mouse2.cur_pos_x >= 889 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 9
				play(9);
			}

			if (mouse2.cur_pos_x <= 1054 & mouse2.cur_pos_x >= 984 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 10
				play(10);
			}

			if (mouse2.cur_pos_x <= 1150 & mouse2.cur_pos_x >= 1079 & mouse2.cur_pos_y >= 437 & mouse2.cur_pos_y <= 571) { // play card 11
				play(11);
			}

			if (mouse2.cur_pos_x <= 79 & mouse2.cur_pos_x >= 14 & mouse2.cur_pos_y >= 2 & mouse2.cur_pos_y <= 89) {
				graphics::stopMessageLoop();
			}


		}


	}

void Game::draw() {

		graphics::MouseState mouse;
		graphics::getMouseState(mouse);
		graphics::Brush br;
		graphics::Brush br2;
		graphics::Brush br3;
		graphics::Brush br4;
		graphics::Brush br5;
		graphics::Brush br6;


		if (flag3) { // first screen when game is opened
			br.texture = std::string(ASSET_PATH) + "first.png"; // backround
			br.outline_opacity = 0.0f;
			graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
			graphics::setFont(std::string(ASSET_PATH) + "font.otf");

			br4.texture = std::string(ASSET_PATH) + "start.png";
			br4.outline_opacity = 0.0f;
			if (mouse.cur_pos_x <= 698 & mouse.cur_pos_x >= 500 & mouse.cur_pos_y <= 174 & mouse.cur_pos_y >= 15) {
				br4.fill_color[1] = 2.0f; br4.fill_color[2] = 1.4f;
			}
			graphics::drawRect(CANVAS_WIDTH - 500, 80, (CANVAS_WIDTH / 7) + 20, (CANVAS_HEIGHT / 3) - 35, br4);

			br5.texture = std::string(ASSET_PATH) + "exit.png";
			br5.outline_opacity = 0.0f;
			if (mouse.cur_pos_x<=698 & mouse.cur_pos_x>=500 & mouse.cur_pos_y<=570 & mouse.cur_pos_y>=440) {
				br5.fill_color[1] = 2.0f; br5.fill_color[2] = 1.4f;
			}
			graphics::drawRect(CANVAS_WIDTH - 500, 420, (CANVAS_WIDTH / 7) + 20, (CANVAS_HEIGHT / 3) - 35, br5);

		}

		// main game canvas
		if (mouse.button_left_pressed | flag3 == false) {
			if ((mouse.cur_pos_x <= 698 & mouse.cur_pos_x >= 500 & mouse.cur_pos_y <= 174 & mouse.cur_pos_y >= 15) | flag3 == false) {
				flag3 = false;


				br.texture = std::string(ASSET_PATH) + "back.png"; // backround
				br.outline_opacity = 0.0f;
				graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

				br.texture = std::string(ASSET_PATH) + "coins.png";
				br.outline_opacity = 0.0f;
				graphics::drawRect(100, 200, (CANVAS_WIDTH / 7) - 60, CANVAS_HEIGHT / 3, br);

				if (mouse.cur_pos_x <= 320 & mouse.cur_pos_x >= 124 & mouse.cur_pos_y >= 224 & mouse.cur_pos_y <= 397) {
					if (mouse.dragging) {
						graphics::drawRect(mouse.cur_pos_x, mouse.cur_pos_y, CANVAS_WIDTH / 7, CANVAS_HEIGHT / 3, br);
						flag4 = true;
					}
				}
				int x = mouse.cur_pos_x;
				int y = mouse.cur_pos_y;
				if (flag4 & mouse.dragging == false) {
					graphics::drawRect(322, 302, (CANVAS_WIDTH / 7) - 60, CANVAS_HEIGHT / 3, br);
					if (flag) {
						myp1.setBet(myp1.getBet() + 5); //the bet is raised
						flag4 = false;
					}
					else {
						myp2.setBet(myp2.getBet() + 5);
						flag4 = false;
					}
				}

				br.texture = std::string(ASSET_PATH) + "play.png";
				if (mouse.cur_pos_x <= 1172 & mouse.cur_pos_x >= 1002 & mouse.cur_pos_y >= 301 & mouse.cur_pos_y <= 408) {
					br.fill_color[1] = 2.0f; br.fill_color[2] = 1.4f;
				}
				br.outline_opacity = 0.0f;																					//
				graphics::drawRect(CANVAS_WIDTH - 100, 300, CANVAS_WIDTH / 7, (CANVAS_HEIGHT / 3) - 50, br);                  // putting pictures in window
																															//

				if (mouse.cur_pos_x <= 954 & mouse.cur_pos_x >= 803 & mouse.cur_pos_y >= 271 & mouse.cur_pos_y <= 387) {
					br2.texture = std::string(ASSET_PATH) + "pass2.png";
				}
				else {
					br2.texture = std::string(ASSET_PATH) + "pass.png";
				}
				br2.outline_opacity = 0.0f;
				graphics::drawRect(CANVAS_WIDTH - 260, 300, (CANVAS_WIDTH / 7) - 40, (CANVAS_HEIGHT / 3) - 66, br2);

				br3.texture = std::string(ASSET_PATH) + "unoback.png";
				if (mouse.cur_pos_x <= 1161 & mouse.cur_pos_x >= 1000 & mouse.cur_pos_y >= 23 & mouse.cur_pos_y <= 214) {
					br3.fill_color[1] = 2.0f; br3.fill_color[2] = 1.4f;
				}
				br3.outline_opacity = 0.0f;
				graphics::drawRect(CANVAS_WIDTH - 100, 100, CANVAS_WIDTH / 7, CANVAS_HEIGHT / 3, br3);

				br6.texture = std::string(ASSET_PATH) + "exit2.png";
				br6.outline_opacity = 0.0f;
				if (mouse.cur_pos_x <= 79 & mouse.cur_pos_x >= 14 & mouse.cur_pos_y >= 2 & mouse.cur_pos_y <= 89) {
					br6.fill_color[1] = 2.0f; br6.fill_color[2] = 1.4f;
				}
				graphics::drawRect(40, 42, (CANVAS_WIDTH / 7) - 90, (CANVAS_HEIGHT / 3) - 100, br6);

				graphics::setFont(std::string(ASSET_PATH) + "font.otf");
				drawText(CANVAS_WIDTH - 170, 200, 17, "CLICK TO DRAW", br);

				card temp_card(this->n, this->c);    //
				temp_card.png();                     // draw the current card
				temp_card.draw_card();               //

				if (flag == true) {
					mydeck.draw_deck1(); // draw deck of player 1
				}
				else {
					mydeck.draw_deck2(); // draw deck of player 2
				}


				print_score(myp1, myp2); // draw current score

				if (myp1.getNumberOfCards() == 0) { // player 1 won
					graphics::stopMusic();
					int score = myp1.getBet() + myp2.getBet();
					string s = std::to_string(score);
					drawText((CANVAS_WIDTH / 2) - 180, (CANVAS_HEIGHT / 3) - 100, 30, myp1.getUsername() + " is the winner! with " + s + " score", br); // draw message
					//graphics::playSound(std::string(ASSET_PATH) + "win.mp3", 0.9, false);
					
				}

				if (myp2.getNumberOfCards() == 0) { // player 2 won
					graphics::stopMusic();
					int score = myp1.getBet() + myp2.getBet();
					string s = std::to_string(score);
					drawText((CANVAS_WIDTH / 2) - 180, (CANVAS_HEIGHT / 3) - 100, 30, myp2.getUsername() + " is the winner! with " + s + " score", br); // draw message
					//graphics::playSound(std::string(ASSET_PATH) + "win.mp3", 0.9, false);
					
				}

			}
			else if (mouse.cur_pos_x <= 698 & mouse.cur_pos_x >= 500 & mouse.cur_pos_y <= 570 & mouse.cur_pos_y >= 440) {
				graphics::stopMessageLoop();
			}
		}

		
	}

void Game::play(const int k) {
		if (flag == true) { // player 1 plays
			if (this->c == mydeck.get_c1(k) | this->n == mydeck.get_n1(k)) { // card has either the same colour or number
				if (mydeck.get_n1(k) == 10) {
					myp2.cardPlus();
					myp2.cardPlus();
					mydeck.add_card2(); // in case its a +2 , give player 2 , 2 cards
					mydeck.add_card2();
				}

				if (mydeck.get_n1(k) == 11 | mydeck.get_n1(k) == 12) { // in case of "block" or "switch turns" , *since the game has 2 players they have the same purpose*
					flag = !flag; 
				}

				this->c = mydeck.get_c1(k); // sets card down
				this->n = mydeck.get_n1(k);
				mydeck.del1(k); // deletes card from deck
				myp1.cardMinus(); // score -1
				graphics::playSound(std::string(ASSET_PATH) + "card_set.mp3", 0.9, false); // card sound effect
				flag = !flag;
			}

			if ((this->c == 0 & this->n == 0) | (this->c == 0 & this->n == 1) | (this->c == 0 & this->n == 2) | (this->c == 0 & this->n == 3)) { // there is either a colour card or +4 on the ground
																																				// in this case player must play the colour the other player instructed
				if (mydeck.get_n1(k) == 10) {
					myp2.cardPlus();
					myp2.cardPlus(); // in case its a +2 , give player 2 , 2 cards
					mydeck.add_card2();
					mydeck.add_card2();
				}

				if (mydeck.get_n1(k) == 11 | mydeck.get_n1(k) == 12) { // in case of "block" or "switch turns" , *since the game has 2 players they have the same purpose*
					flag = !flag;
				}

				this->c = mydeck.get_c1(k); // sets card down
				this->n = mydeck.get_n1(k);
				mydeck.del1(k); // deletes card from deck
				myp1.cardMinus(); // score -1
				graphics::playSound(std::string(ASSET_PATH) + "card_set.mp3", 0.9, false); // card sound effect
				flag = !flag;
			}

			if ((mydeck.get_n1(k) == 0 & mydeck.get_c1(k) == 0) | (mydeck.get_n1(k) == 1 & mydeck.get_c1(k) == 0)) { // player has a +4
				this->c = mydeck.get_c1(k); // sets card down
				this->n = mydeck.get_n1(k);
				for (int i = 1; i <= 4; i++) { // add 4 cards to the other player
					mydeck.add_card2();
					myp2.cardPlus();
				}
				mydeck.del1(k); // deletes card from deck
				myp1.cardMinus(); // score -1
				graphics::playSound(std::string(ASSET_PATH) + "card_set.mp3", 0.9, false); // card sound effect
				flag = !flag;
			}

			if ((mydeck.get_n1(k) == 2 & mydeck.get_c1(k) == 0) | (mydeck.get_n1(k) == 3 & mydeck.get_c1(k) == 0)) { // player has a colour card
				this->c = mydeck.get_c1(k); // sets card down
				this->n = mydeck.get_n1(k);
				mydeck.del1(k); // deletes card from deck
				myp1.cardMinus(); // score -1
				graphics::playSound(std::string(ASSET_PATH) + "card_set.mp3", 0.9, false); // card sound effect
				flag = !flag;
			}



		}
		else { // player 2 plays
			if (this->c == mydeck.get_c2(k) | this->n == mydeck.get_n2(k)) { // card has either the same colour or number
				if (mydeck.get_n2(k) == 10) {
					myp1.cardPlus();
					myp1.cardPlus(); // in case its a +2 , give player 2 , 2 cards
					mydeck.add_card1();
					mydeck.add_card1();
				}

				if (mydeck.get_n2(k) == 11 | mydeck.get_n2(k) == 12) { // in case of "block" or "switch turns" , *since the game has 2 players they have the same purpose*
					flag = !flag;
				}

				this->c = mydeck.get_c2(k); // sets card down
				this->n = mydeck.get_n2(k);
				mydeck.del2(k); // deletes card from deck
				myp2.cardMinus(); // score -1
				flag = !flag;
				graphics::playSound(std::string(ASSET_PATH) + "card_set.mp3", 0.9, false); // card sound effect
			}

			if ((this->c == 0 & this->n == 0) | (this->c == 0 & this->n == 1) | (this->c == 0 & this->n == 2) | (this->c == 0 & this->n == 3)) { // there is either a colour card or +4 on the ground
																																				// in this case player must play the colour the other player instructed
				if (mydeck.get_n2(k) == 10) {
					myp1.cardPlus();
					myp1.cardPlus(); // in case its a +2 , give player 2 , 2 cards
					mydeck.add_card1();
					mydeck.add_card1();
				}

				if (mydeck.get_n2(k) == 11 | mydeck.get_n2(k) == 12) { // in case of "block" or "switch turns" , *since the game has 2 players they have the same purpose*
					flag = !flag;
				}

				this->c = mydeck.get_c2(k); // sets card down
				this->n = mydeck.get_n2(k);
				mydeck.del2(k); // deletes card from deck
				myp2.cardMinus(); // score -1
				flag = !flag;
				graphics::playSound(std::string(ASSET_PATH) + "card_set.mp3", 0.9, false); // card sound effect
			}
			
			if ((mydeck.get_n2(k) == 0 & mydeck.get_c2(k) == 0) | (mydeck.get_n2(k) == 1 & mydeck.get_c2(k) == 0)) { // player has a +4
				this->c = mydeck.get_c2(k); // sets card down
				this->n = mydeck.get_n2(k);
				for (int i = 1; i <= 4; i++) {
					mydeck.add_card1();       // add 4 cards to the other player
					myp1.cardPlus();
				}
				mydeck.del2(k);  // deletes card from deck
				myp2.cardMinus();  // score -1
				flag = !flag;
				graphics::playSound(std::string(ASSET_PATH) + "card_set.mp3", 0.9, false);  // card sound effect

			}

			if ((mydeck.get_n2(k) == 2 & mydeck.get_c2(k) == 0) | (mydeck.get_n2(k) == 3 & mydeck.get_c2(k) == 0)) { // player has a colour card
				this->c = mydeck.get_c2(k); // sets card down
				this->n = mydeck.get_n2(k);
				mydeck.del2(k); // deletes card from deck
				myp2.cardMinus(); // score -1
				flag = !flag;
				graphics::playSound(std::string(ASSET_PATH) + "card_set.mp3", 0.9, false); // card sound effect
			}



		}
	}

void Game::print_score(Player pl1, Player pl2) {
		string p1 = to_string(pl1.getNumberOfCards());
		string p2 = to_string(pl2.getNumberOfCards());
		string p3 = p1 + " : " + p2;
		graphics::Brush br;
		graphics::setFont(std::string(ASSET_PATH) + "score.otf"); // prints current game score using score from each player
		//br.fill_color[0] = 0.5f;
		br.fill_color[1] = 0.4f;
		br.fill_color[2] = 0.0f;
		drawText(55, 110, 50, p3, br);
	}

