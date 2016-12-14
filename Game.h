#pragma once

#include "Board.h"

class Game {
private:

	Board myBoard;
	bool isGameWon;
	bool isPlaying;
	int difficulty;
public:
	Game() { isGameWon = false; difficulty = 3; }

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
	Deck& moveDeck(int x, int y);
	void moveCard(int x, int y, int moveTo); //card x-y coordinates; and # of column to move to.

	//checkers
	bool checkIfWon();
	bool checkIfAnyMovable(Card inCard);
	bool isMoveValid(int cardX, int cardY, int moveTo);
	bool isFoundationMoveValid(Card& inCard, int moveTo);
	bool isMoveValid(Card& inCard, int moveTo);

	//getting cards from tableau or hand
	Card& getTabCard(int cardX, int cardY);
	Card& getHandCard(int CardY);

	void drawFromDeck(int s);

	void cont();
	
};