#include "Board.h"

void Board::dealCards() //sets up game grid
{
	//setting up your main deck.
	myDeck.makeDeck();
	myDeck.randomizeDeck();

	for (int i = 1; i < 8; i++) { //setting up the tableau;
		tableau.push_back(myDeck.drawDeck(i)); 
		tableau[i].getTopCard().setIsUp(true);
	}
	

}
void Board::printGameBoard()
{
	
}

void Board::printTableau() {

}