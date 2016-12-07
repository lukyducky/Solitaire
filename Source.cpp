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
	

	myCard.printCard();
	system("pause");

}