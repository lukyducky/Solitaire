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

	void playGame();

	void moveTurn();
	void moveToFoundation(int x, int y, int moveTo);

	bool checkIfWon();
	bool checkIfAnyMovable(Card inCard);

	template <class T>
	T getUserInput(string message);


	int checkUserInput(int d, string prompt);

	bool isInputValid(int size, string message); //to be used inside a while loop
	//void isInputValid(string message);

	Deck& moveDeck(int x, int y);
	void moveCard(int x, int y, int moveTo); //card x-y coordinates; and # of column to move to.

	bool isMoveValid(int cardX, int cardY, int moveTo);
	bool isFoundationMoveValid(int x, int y, int moveTo);

	Card& getTabCard(int cardX, int cardY);

	void drawFromDeck(int s);

	void cont();
	
};