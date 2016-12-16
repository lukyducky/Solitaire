#include "Board.h"

void Board::dealCards(){ //sets up game grid
	//setting up your main deck.
	myDeck.makeDeck();
	myDeck.randomizeDeck();

	for (int i = 1; i < 8; i++) { //setting up the tableau;
		tableau.push_back(myDeck.drawDeck(i));
		tableau[i - 1].getTopCard().setIsUp(true);
	}
}
void Board::printGameBoard(){
	printHand();
	printFoundation();
	cout << "Tableau: " << endl;
	printTableau();
}

void Board::printTableau() {
	for (int x = 0; x < tableau.size(); x++) //x-axis grid #s
	{
		cout << "    " << x + 1 << "  \t";
	}
	cout << endl;
	for (int y = 0; y < 13; y++) {  //goes row by row, or it should.
		cout << y + 1;
		for (int h = 0; h < 2; h++) {
			for (int x = 0; x < tableau.size(); x++) {
				if (y < tableau[x].getSize()){ //if it exists, print it out?
					if (h == 0) { //print the top of card
						cout << " _____\t";
					}
					else { //printing card info
						if (tableau[x].getCard(y).getIsUp()) {
							if (tableau[x].getCard(y).getValue() != 10) { //getting the #/face
								cout << "|   " << tableau[x].getCard(y).getEnumFace(tableau[x].getCard(y).getFace());
							}
							else { //10 is a special case becuase it's more than 1 digit.
								cout << "|  " << 10;
							}
							cout << tableau[x].getCard(y).getSuit(tableau[x].getCard(y).getS()) << "|\t";
						}
						else { //if not up: it's blank
							cout << "|     |\t";
						}
					}
				}
				else
				{
					cout << "      \t"; //print out a blank card...
				}

			}
			cout << endl;
		}
	}
}

void Board::printFoundation() {
	cout << "Foundation:" << endl;
	for (int i = 0; i < foundation.size(); i++) {
		cout << "   "<< i + 1<< " \t";
	}
	cout << endl;
	for (int i = 0; i < foundation.size(); i++) {
		cout << " _____\t";
	}
	cout << endl;
	for (int i = 0; i < foundation.size(); i++) {
		if (foundation[i].getSize() > 0) {//if there are cards
			foundation[i].getTopCard().printCardInfo();
			cout << "\t";
		}
		else {
			cout << "|     |\t";
		}
	}
	cout << endl;
	for (int i = 0; i < 2; i++) {
		for (int i = 0; i < foundation.size(); i++) {
			cout << "|     |\t";
		}
		cout << endl;
	}
	for (int i = 0; i < foundation.size(); i++) {
		cout << "|_____|\t";
	}
	cout << endl<< endl;
}
void Board::printHand() { //prints out deck and hand and trash deck.
	cout << "Cards left in deck: " << myDeck.getSize() << endl;
	hand.setDeckisUp(true);
	hand.printDeck();
}

Deck & Board::getTabCol(int i) {
	return tableau[i];
}

void Board::drawFromDeck(int s) {
	if (!hand.isEmpty()) {
		trashDeck += hand.drawDeck(s);
	}
	hand += myDeck.drawDeck(s);
}


