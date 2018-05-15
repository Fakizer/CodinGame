#ifndef WARIOR_HPP
#define WARIOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class	Warior {
    enum        SUIT{D, H, C, S};
    enum        NUMB{J = 11, Q, K, A};


    struct  Card {
        SUIT    suit;
        int     value;
    };

public:
	Warior();
    ~Warior();
    void    addCard(string, bool = false);
    void    playRound();
    bool    isFinished();
    string  result();

private:
    int     rounds;
    bool    isPat;

    queue<Card*>* player1;
    queue<Card*>* player2;
    queue<Card*>* pile1;
    queue<Card*>* pile2;

    Card* converCard(string);
    string printCard(Card*);

    inline Card* getCard(queue<Card*>*);
    inline void returnCardTo(queue<Card*>*);

    void battle();
    void war();

};

#endif