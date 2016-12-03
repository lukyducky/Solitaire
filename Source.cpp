#include "Deck.h"
#include <iostream>
using namespace std;

void main(){
	Deck myDeck;
	myDeck.makeDeck();
	//cout << myDeck << endl;
	myDeck.randomizeDeck();
	cout << myDeck << endl;
	Deck newDeck = myDeck.drawDeck(10);
	Deck aDeck = myDeck.drawDeck(5);
	cout << newDeck << endl << aDeck << endl << endl;
	myDeck =  newDeck + aDeck;
	system("pause");

}