#include"Deck.h"
#include <algorithm>

void Deck::randomizeDeck()
{
	random_shuffle(deck.begin(), deck.end());
	//setisTop();
}

void Deck::makeDeck() 
{
	for (int s = 0; s < 4; s++)//suits
	{
		for (int n = 1; n < 14; n++) //numbers
		{
			Card inCard;
			inCard.setVal(n);
			if (n == 1){
				inCard.setFace(static_cast<Face>(4)); //face is A
			}
			else if (n <= 10){
				inCard.setFace(static_cast<Face>(0));
			}
			else if (n > 10){
				inCard.setFace(static_cast<Face>(n-10));
			}

			inCard.setS(static_cast<Suit>(s));
			inCard.setIsRed((s % 2 != 0) ? false : true);
			deck.push_back(inCard);
		}
	}
	//deck.back().setisTop(true);
}

void Deck::addCard(Card inCard) { //adds card to current deck
	deck.push_back(inCard);
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
	//setisTop(); //reset the top cards.
	return out;
}

Card& Deck::getTopCard() { //shows you card; doesnt remove from deck.  "peek"
	return deck.back();
}

Card& Deck::getCard(int s) {
	return deck[s];
}

void Deck::setDeckisUp(bool in) { //sets entire deck's isUP 
	vector<Card>::iterator it;
	for (it = deck.begin(); it < deck.end(); it++) {
		it->setIsUp(in);
	}
}

Deck Deck::drawDeck(int s) { //draw top x cards.
	Deck outDeck;
	for (int i = 0; i < s; i++) { //pushing back the new card
		outDeck.addCard(this->drawCard());
	}
	reverse(outDeck.deck.begin(), outDeck.deck.end()); //reversing so it's in the right order
	return outDeck;
}


int Deck::findCard(Card& inCard) { //should be getting the index
	return distance(deck.begin(), find(deck.begin(), deck.end(), inCard));
}

bool Deck::isCardinDeck(Card inCard) {
	bool out;
	out =  ((find(this->deck.begin(), this->deck.end(), inCard) != this->deck.end()));
	return out;
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

Deck& Deck::operator += (const Deck & v) {
	*this = *this + v;
	return *this;
}

void Deck::reverseDeck() {
	reverse(deck.begin(), deck.end());
}

void Deck::printDeck() const {
	vector<Card>::const_iterator it;
	for (it = deck.begin(); it < deck.end(); it++){
		it->printCard();
	}
	cout << endl;
}