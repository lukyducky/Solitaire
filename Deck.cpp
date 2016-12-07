#include"Deck.h"
#include <algorithm>


void Deck::randomizeDeck()
{
	random_shuffle(deck.begin(), deck.end());
}

void Deck::makeDeck() 
{
	for (int s = 0; s < 4; s++)//suits
	{
		for (int n = 1; n < 14; n++) //numbers
		{
			Card inCard;
			inCard.setVal(n);
			if (n == 1)
			{
				inCard.setFace(static_cast<Face>(4)); //face is A
			}
			else if (n <= 10)
			{
				inCard.setFace(static_cast<Face>(0));
			}
			else if (n > 10)
			{
				inCard.setFace(static_cast<Face>(n-10));
			}

			inCard.setS(static_cast<Suit>(s));
			inCard.setIsRed((s % 2 != 0) ? false : true);
			deck.push_back(inCard);
		}
	}
}


void Deck::addCard(Card inCard) { //adds card to current deck
	deck.push_back(inCard);
}

Card Deck::drawCard() {
	Card out;
	if (deck.size() > 0) {
		out = deck.back();
		deck.pop_back();
	}
	return out;
}

Card Deck::getTopCard() {
	return deck.back();
}

Deck Deck::drawDeck(int s) { //draw top x cards.
	Deck outDeck;
	for (int i = 0; i < s; i++) {
		outDeck.addCard(this->drawCard());
	}
	reverse(outDeck.deck.begin(), outDeck.deck.end());
	return outDeck;
}



Deck Deck::operator + (const Deck v)
{
	Deck outDeck;
	for (int i = 0; i < this->deck.size(); i++) {
		outDeck.deck.push_back(this->deck[i]);
	}
	for (int i = 0; i < v.deck.size(); i++) {
		outDeck.deck.push_back(v.deck[i]);
	}
	return outDeck;
}

/*
Deck& Deck::operator = (Deck & v)
{
	int s = (deck.size() < v.deck.size()) ? deck.size() : v.deck.size(); //s has the smaller size
	for (int i = 0; i < s; i++) {
		this->deck[i] = v.deck[i]; //copying elements over
	}
	return *this;
}*/