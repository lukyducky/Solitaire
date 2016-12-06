#include "Deck.h"
#include <iostream>
using namespace std;

void main(){
	Deck myDeck, deck2;
	myDeck.makeDeck();
	//cout << myDeck << endl;
	myDeck.randomizeDeck();
	cout << myDeck << endl;
	Deck newDeck = myDeck.drawDeck(10);
	Deck deck1 = myDeck.drawDeck(5);
	deck2 = newDeck + deck1;
	cout << newDeck << endl << deck1 << endl;
	cout << deck2;
	system("pause");

}