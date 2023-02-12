#pragma once

#include <string>
#include <iostream>
#include "graphics.h"
#include "config.h"
#include "card.h"

// this class manages the cards of the game


void card::png() {
		//imports the right png depending on colour and number
		//colour: 1 = blue , 2 = green , 3 = red , 4 = yellow
		//num: 0,1,2,....,11

		switch (this->colour) {
		case 0: // special cards
			if (this->num == 0) {
				br.texture = "assets\\0_0.png";
			}
			else if (this->num == 1) {
				br.texture = "assets\\0_1.png";
			}
			else if (this->num == 2) {
				br.texture = "assets\\0_2.png";
			}
			else if (this->num == 3) {
				br.texture = "assets\\0_3.png";
			}
			break;

		case 1: // blue
			switch (this->num) {
			case 0:
				br.texture = "assets\\1_0.png";
				break;
			case 1:
				br.texture = "assets\\1_1.png";
				break;
			case 2:
				br.texture = "assets\\1_2.png";
				break;
			case 3:
				br.texture = "assets\\1_3.png";
				break;
			case 4:
				br.texture = "assets\\1_4.png";
				break;
			case 5:
				br.texture = "assets\\1_5.png";
				break;
			case 6:
				br.texture = "assets\\1_6.png";
				break;
			case 7:
				br.texture = "assets\\1_7.png";
				break;
			case 8:
				br.texture = "assets\\1_8.png";
				break;
			case 9:
				br.texture = "assets\\1_9.png";
				break;
			case 10:
				br.texture = "assets\\1_10.png";
				break;
			case 11:
				br.texture = "assets\\1_11.png";
				break;
			case 12:
				br.texture = "assets\\1_12.png";
				break;
				break;
			}
			break;
		case 2: // green
			switch (this->num) {
			case 0:
				br.texture = "assets\\2_0.png";
				break;
			case 1:
				br.texture = "assets\\2_1.png";
				break;
			case 2:
				br.texture = "assets\\2_2.png";
				break;
			case 3:
				br.texture = "assets\\2_3.png";
				break;
			case 4:
				br.texture = "assets\\2_4.png";
				break;
			case 5:
				br.texture = "assets\\2_5.png";
				break;
			case 6:
				br.texture = "assets\\2_6.png";
				break;
			case 7:
				br.texture = "assets\\2_7.png";
				break;
			case 8:
				br.texture = "assets\\2_8.png";
				break;
			case 9:
				br.texture = "assets\\2_9.png";
				break;
			case 10:
				br.texture = "assets\\2_10.png";
				break;
			case 11:
				br.texture = "assets\\2_11.png";
				break;
			case 12:
				br.texture = "assets\\2_12.png";
				break;

			}
			break;
		case 3: // red
			switch (this->num) {
			case 0:
				br.texture = "assets\\3_0.png";
				break;
			case 1:
				br.texture = "assets\\3_1.png";
				break;
			case 2:
				br.texture = "assets\\3_2.png";
				break;
			case 3:
				br.texture = "assets\\3_3.png";
				break;
			case 4:
				br.texture = "assets\\3_4.png";
				break;
			case 5:
				br.texture = "assets\\3_5.png";
				break;
			case 6:
				br.texture = "assets\\3_6.png";
				break;
			case 7:
				br.texture = "assets\\3_7.png";
				break;
			case 8:
				br.texture = "assets\\3_8.png";
				break;
			case 9:
				br.texture = "assets\\3_9.png";
				break;
			case 10:
				br.texture = "assets\\3_10.png";
				break;
			case 11:
				br.texture = "assets\\3_11.png";
				break;
			case 12:
				br.texture = "assets\\3_12.png";
				break;

			}
			break;
		case 4: // yellow
			switch (this->num) {
			case 0:
				br.texture = "assets\\4_0.png";
				break;
			case 1:
				br.texture = "assets\\4_1.png";
				break;
			case 2:
				br.texture = "assets\\4_2.png";
				break;
			case 3:
				br.texture = "assets\\4_3.png";
				break;
			case 4:
				br.texture = "assets\\4_4.png";
				break;
			case 5:
				br.texture = "assets\\4_5.png";
				break;
			case 6:
				br.texture = "assets\\4_6.png";
				break;
			case 7:
				br.texture = "assets\\4_7.png";
				break;
			case 8:
				br.texture = "assets\\4_8.png";
				break;
			case 9:
				br.texture = "assets\\4_9.png";
				break;
			case 10:
				br.texture = "assets\\4_10.png";
				break;
			case 11:
				br.texture = "assets\\4_11.png";
				break;
			case 12:
				br.texture = "assets\\4_12.png";
				break;

			}
			break;
			break;
		}// checks what card it is based on colour and number

	}

void card::draw_card() { //draws the current png
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, (CANVAS_HEIGHT / 4) + 50, CANVAS_WIDTH / 7, CANVAS_HEIGHT / 3, br);
	}

card::card() {
	this->num = 0;
	this->colour = 0;
} // default constructor

card::card(int in_num, int in_colour) {
	this->num = in_num;
	this->colour = in_colour;
} // constructor

void card::costume_print(int x, int y) {
	this->png();
	graphics::drawRect(x, y, (CANVAS_WIDTH / 7)-75, 110, br); //graphics::drawRect(x, y, (CANVAS_WIDTH / 7) - 200, 110, br);
} // prints card in costume given coordinates


int card::get_n() { return this->num; } // returns number
int card::get_c() { return this->colour; } // returns colour

void card::set_n(int n) { this->num = n; } // changes number
void card::set_c(int c) { this->colour = c; } // changes colour

card::~card() { // destructor
	//this->num = 16;
	//this->colour = 16; 
}
