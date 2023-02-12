#pragma once

#include <iostream>
#include <string> 
#include "graphics.h"
#include <iostream>
#include <string> 
#include "config.h"
#include "Player.h"
using namespace std;

Player::Player(string username, int score, int bet) { // constructor
    this->p_username = username;
    this->p_cards = score;
    this->p_bet = bet;
    }

Player::Player() {
    this->p_username = "";
    this->p_cards = 0;
    this->p_bet = 0;
    }

string Player::getUsername() {
    return p_username;
    }

int Player::getNumberOfCards() {
    return p_cards;
}

int Player::getBet() {
    return p_bet;
}

void Player::setUsername(string username) {
    p_username = username;
}

void Player::setBet(int bet) {
    p_bet = bet;
}

void Player::cardMinus() {
    p_cards--;
}

void Player::cardPlus() {
    p_cards++;
}

void Player::setCards(int cards) {
    p_cards = cards;
}

