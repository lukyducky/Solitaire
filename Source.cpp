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

	Card& aCard = myDeck.drawCard();
	Card& bCard = aNewDeck.drawCard();

	cout << "is " << aCard << "in newDeck? " << aNewDeck.isCardinDeck(aCard) << endl; //should be no...
	cout << "is " << aCard << " in myDeck? " << myDeck.isCardinDeck(aCard) << endl;

	//testing the find card in deck functions!!!!


	

	
	system("pause");

}