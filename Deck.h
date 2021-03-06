#pragma once

#include "Card.h"
#include <vector>
#include <string>

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
	void setisTop();

	int getSize() const { return deck.size(); }

	Card drawCard();
	Deck drawDeck(int s);
	Card& getTopCard();
	Card& getCard(int s);
	void setDeckisUp(bool in);
	bool isEmpty() { return (getSize() != 0) ? false : true; }

	int findCard(Card& inCard);
	bool Deck::isCardinDeck(Card inCard);

	void reverseDeck();

	//Deck& operator = (const Deck & v);
	Deck operator + (const Deck v);
	Deck& operator += (const Deck & v);

	friend ostream& operator <<(ostream&os, const Deck& d)
	{
		vector<Card>::const_iterator it;
		int i = 1;
		for (it = d.deck.begin(); it < d.deck.end(); it++)
		{
			os <<i << ": "<< *it << endl;
			i++;
		}
		return os;
	}

	void printDeck() const;
};



