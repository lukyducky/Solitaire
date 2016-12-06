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
	cout << newDeck;
	system("pause");

}