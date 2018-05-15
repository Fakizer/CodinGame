

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#include "Warior.hpp"

int main()
{
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();

	auto wars = new Warior();
    
    for (int i = 0; i < n; i++) {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
        wars->addCard(cardp1, true);
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp2; // the m cards of player 2
        cin >> cardp2; cin.ignore();
        wars->addCard(cardp2);
    }

    while (!wars->isFinished())
		wars->playRound();

    cout << wars->result() << endl;

    delete wars;
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}