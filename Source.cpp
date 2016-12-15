#include "Game.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void main(){
	srand(time(NULL));
	//Game myGame;
	//myGame.playGame();
	
	Deck myDeck;
	myDeck.makeDeck();
	myDeck.randomizeDeck();
	Deck aNewDeck = myDeck.drawDeck(13);

	Card& aCard = myDeck.getTopCard();
	Card& bCard = aNewDeck.getTopCard();
	cout << "myDeck:\n" << myDeck << endl << "newDeck:\n" << aNewDeck << endl;
	cout << "is " << aCard << "in newDeck? " << aNewDeck.isCardinDeck(aCard) << endl; //should be no...
	cout << "is " << aCard << " in myDeck? " << myDeck.isCardinDeck(aCard) << endl; //should be yes

	cout << "is" << bCard << "int newDeck? " << aNewDeck.isCardinDeck(bCard) << endl; //should be yes (1)
	cout << "is " << bCard << "in myDeck?" << myDeck.isCardinDeck(bCard) << endl; //should be no(0)
	//testing the find card in deck functions!!!!


	

	
	system("pause");

}