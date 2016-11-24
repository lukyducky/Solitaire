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

Deck& Deck::operator = (const Deck & v)
{
	int s = (size < v.size) ? size : v.size; //s has the smaller size
	for (int i = 0; i < s; i++) {
		this->deck[i] = v.deck[i]; //copying elements over
	}
	return *this;
}