#pragma once

#include "Card.h"
#include <vector>

using namespace std;

//typical deck of cards for deck of cards things.  is a wrapper around vector.
//"top" of stack of cards is the "back" of the vector.

class Deck{
private:
	vector<Card> deck;
public:
	Deck(){}
	~Deck() {}

	void randomizeDeck(); //shuffles your deck!
	void makeDeck(); //makes a typical deck of 52 cards.
	//void drawCard();

	//operator overload =; only copies up to smallest size if the two are different sizes!!
	Deck& operator = (const Deck & v);

	friend ostream& operator <<(ostream&os, const Deck& d)
	{
		vector<Card>::const_iterator it;
		for (it = d.deck.begin(); it < d.deck.end(); it++)
		{
			os << *it << endl;
		}
		return os;
	}

};



