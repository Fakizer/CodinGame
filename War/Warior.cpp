#include "Warior.hpp"

Warior::Warior() : player1(new queue<Card*>), player2(new queue<Card*>), pile1(new queue<Card*>), pile2(new queue<Card*>), rounds(0){}
Warior::~Warior() {
    delete this->player1;
    delete this->player2;
    delete this->pile1;
    delete this->pile2;
}

void    Warior::addCard(string cardString, bool toFirst) {
    queue<Card*>* player = toFirst ? player1 : player2;
    player->push(this->converCard(cardString));
}

Warior::Card* Warior::converCard(string cardString){
	Card* card = new Card{};
	int n = cardString.size();
	for(int i = 0; i < n; ++i){
		char c = cardString.at(i);
		switch(c){
			case 'D': card->suit = D; break;
			case 'H': card->suit = H; break;
			case 'C': card->suit = C; break;
			case 'S': card->suit = S; break;

			case 'J': card->value = J; break;
			case 'Q': card->value = Q; break;
			case 'K': card->value = K; break;
			case 'A': card->value = A; break;
			case '0': card->value = 10; break;
			default:
				card->value = c - '0';
				break;
		}
	}
// 	cerr << J << ", " << Q << ", " << K << ", " << A << endl;
	return card;
}

bool	Warior::isFinished(){
	return this->player1->empty() || this->player2->empty();
}

void	Warior::playRound(){
	this->rounds++;
	this->battle();
}

inline Warior::Card* Warior::getCard(queue<Card*>* player){
	Card* card = player->front();
	queue<Card*>* pile = player == this->player1 ? this->pile1 : this->pile2;
	pile->push(card);
	player->pop();
	return card;
}

inline void Warior::returnCardTo(queue<Card*>* player){
	queue<Card*>* pile = this->pile1;
	while(!pile->empty()){
		player->push(pile->front());
		pile->pop();
	}

	pile = this->pile2;
	while(!pile->empty()){
		player->push(pile->front());
		pile->pop();
	}
}

void	Warior::war(){
	if(this->player1->size() < 3 || this->player2->size() < 3){
		isPat = true;
		return;
	}

	for(int i = 0; i < 3; ++i)
		this->getCard(this->player1);
	for(int i = 0; i < 3; ++i)
		this->getCard(this->player2);
	this->battle();
}

void	Warior::battle() {
	Card* c1 = this->getCard(this->player1);
	Card* c2 = this->getCard(this->player2);

	if(c1->value > c2->value)
		this->returnCardTo(this->player1);
	else if(c1->value < c2->value)
		this->returnCardTo(this->player2);
	else
		this->war();
}

string	Warior::result(){
	if(this->isPat) return "PAT";
	return to_string(this->player1->empty() ? 2 : 1) + " " + to_string(this->rounds);
}