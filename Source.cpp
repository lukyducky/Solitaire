#include "Deck.h"
#include <iostream>
using namespace std;

void main(){
	Deck aDeck;
	aDeck.makeDeck();
	aDeck.randomizeDeck();
	cout << aDeck << endl << aDeck.getTopCard() << endl;
	Card myCard = aDeck.getTopCard();
	myCard.setIsUp(true);
	
	aDeck.drawDeck(6).printDeck();

	myCard.printCard();
	system("pause");

}