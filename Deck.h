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
	void addCard(Card inCard); //add a card to the "top" of the deck
	Card drawCard();
	Deck drawDeck(int s);

	Deck& operator = (Deck & v); //only copies up to smallest size if the two are different sizes!!
	//Deck& operator = (const Deck & v);

	Deck operator + (const Deck rhs);

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



