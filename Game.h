#pragma once

#include "Board.h"

class Game {
private:

	Board myBoard;
	bool isGameWon;
	bool isPlaying;
	int difficulty;
public:
	Game() { isGameWon = false; difficulty = 3; isPlaying = true; }

	void setIsPlaying(bool inBool) { isPlaying = inBool; }

	//actually playing the game.
	void playGame();

	//actually moving cards
	void moveTurn();
	void moveToFoundation(int x, int y, int moveTo);
	
	//user input 
	template <class T>
	T getUserInput(string message);
	int checkUserInput(int d, string prompt);
	bool isInputValid(int size, string message); 

	//big wrapper for the move card; gets user input and verifies valid card
	Card& inputMovedCard();

	//moving cards
	Deck& getMovedDeck(int x, int y);
	void moveCard(int x, int y, int moveTo); //card x-y coordinates; and # of column to move to.
	void moveFromHand(int moveTo);
	void moveFromHandtoFound(int moveTo);

	//checkers
	bool checkIfWon();
	bool checkIfAnyMovable(Card inCard);
	bool isMoveValid(int cardX, int cardY, int moveTo);
	bool isFoundationMoveValid(Card& inCard, int moveTo);
	bool isMoveValid(Card& inCard, int moveTo);
	bool isCardinTab(Card& inCard);

	int getCardX(Card& inCard); //get column...
	int getCardY(Card& inCard); //get row of card


	//getting cards from tableau or hand
	Card& getTabCard(int cardX, int cardY);
	Deck& drawHandCard(); //you should only be able to get the top card; it's a deck of 1 to move.

	void drawFromDeck(int s);

	void cont();
	
};