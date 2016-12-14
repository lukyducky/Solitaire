#ifndef GRID_H
#define GRID_H

#include "Card.h"
#include <vector>

using namespace std;
#include "Deck.h"

//will have a mxn grid to display cards, either face up or not.

class Board{
	
private:
	vector<Deck> tableau; //should be size 7;
	vector<Deck> foundation; //should be size 4;
	Deck myDeck;
	Deck trashDeck;
	Deck hand; //only size 3.

public:
	Board():foundation(4){}
	~Board() {}
	
	void dealCards(); //sets up game grid
	void printGameBoard(); //prints out cards

	//printing out individual stuff
	void printTableau();
	void printFoundation();
	void printHand(); //prints out deck and hand and trash deck.

	Deck& getTabCol(int i);
	
	Deck& getHand() { return hand; }
	Deck& getDeck() { return myDeck; }
	Deck& getTrash() { return trashDeck; }
	vector<Deck>& getTableau() { return tableau; }
	vector<Deck>& getFoundation() { return foundation; }
	Deck& getFoundationCol(int i) { return foundation[i]; }
	

	void drawFromDeck(int s); //draw s cards from deck into hand; moves the prev hand cards to the "trash".

	bool isDeckEmpty() { return (myDeck.getSize() != 0) ? false : true; }
};

#endif 