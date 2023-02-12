#pragma once
#include <string>
using namespace std;

class Player {

public:
    Player(string username, int score, int bet);
    Player();

    string getUsername();

    void setUsername(string username);

    int getNumberOfCards();
    void setCards(int cards);

    int getBet();
    void setBet(int bet);

    void cardMinus();
    void cardPlus();






private:
    string p_username;
    int p_cards;
    int p_bet;
};
