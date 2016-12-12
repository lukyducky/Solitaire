#include"Deck.h"
#include <algorithm>


void Deck::randomizeDeck()
{
	random_shuffle(deck.begin(), deck.end());
	setisTop();
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
	deck.back().setisTop(true);
}

void Deck::addCard(Card inCard) { //adds card to current deck
	/*if (deck.size() != 0){
		deck.back().setisTop(false);
	}
	deck.push_back(inCard);
	deck.back().setisTop(true);*/
	deck.push_back(inCard);
	setisTop();
}

void Deck::setisTop() {
	vector<Card>::iterator it;
	for (it = deck.begin(); it != deck.end(); it++) {
		it->setisTop(false);
	}//make sure all of them are false
	deck.back().setisTop(true); //then make the top one true
}

Card Deck::drawCard() { //returns "default" card if empty deck.
	Card out;
	if (deck.size() > 0) {
		out = deck.back(); // get the card
		deck.pop_back(); //remove the card
	}
	setisTop(); //reset the top cards.
	return out;
}

Card& Deck::getTopCard() { //shows you card; doesnt remove from deck.  "peek"
	return deck.back();
}

Card& Deck::getCard(int s) {
	return deck[s];
}


Deck Deck::drawDeck(int s) { //draw top x cards.
	Deck outDeck;
	for (int i = 0; i < s; i++) { //pushing back the new card
		outDeck.addCard(this->drawCard());
	}
	reverse(outDeck.deck.begin(), outDeck.deck.end()); //reversing so it's in the right order
	//setisTop();
	outDeck.setisTop();
	return outDeck;
}

Deck Deck::operator + (const Deck v)
{
	Deck outDeck;
	for (int i = 0; i < this->deck.size(); i++) {
		outDeck.deck.push_back(this->deck[i]);
	}
	//this->deck.back().setisTop(true);
	for (int i = 0; i < v.deck.size(); i++) {
		outDeck.deck.push_back(v.deck[i]);
	}
	outDeck.setisTop();
	return outDeck;
}


Deck& Deck::operator = (const Deck & v)
{
	int s = (deck.size() < v.deck.size()) ? deck.size() : v.deck.size(); //s has the smaller size
	for (int i = 0; i < s; i++) {
		this->deck[i] = v.deck[i]; //copying elements over
	}
	this->setisTop();
	return *this;
}

void Deck::printDeck(string s) const {
	vector<Card>::const_iterator it;
	for (it = deck.begin(); it < deck.end(); it++){
		it->printCard(s);
	}
	cout << endl;
}