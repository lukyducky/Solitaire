#ifndef DECK_H
#define DECK_H


#include "Card.h"
#include <stack>

//typical deck of cards for deck of cards things.

class Deck{
private:
	std::stack<Card> deck;
	int size;
	int maxSize;
public:
	Deck(){ size = 0; maxSize = 52; }
	Deck(int inSize, int inMax){ size = inSize; maxSize = inMax; }
	~Deck(){}

	int Size(){ return size; }
	
	int maxSize(){ return maxSize; }
	void setSize(int inMax){ maxSize = inMax; }

};



#endif