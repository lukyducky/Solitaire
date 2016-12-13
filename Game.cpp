#include "Game.h"

void Game::playGame() {
	myBoard.dealCards();
	bool looper;
	while (!isGameWon) {
		myBoard.printGameBoard();
		looper = false;
		while (!looper) {
			looper = true;
			char d = getUserInput<char>("Would you like to move a card(C), or draw from the deck? (D)");

			if (d == 'C' || d == 'c') {
				moveTurn();
			}
			else if (d == 'd' || d == 'D') {
				drawFromDeck(difficulty);
			}
			else {
				cout << "improper input.  please enter C or D" << endl;
				looper = false;
			}
		}

		isGameWon = checkIfWon();
	}
	cout << "Congrats!  You won! \n Do you want to play again?  yes or no" << endl;
}


bool Game::checkIfWon() {
	bool out = false;
	int totalSize = 0;
	for (int i = 0; i < 4; i++) {
		totalSize += myBoard.getFoundationCol(i).getSize();
	}
	return out;
}

bool checkIfLost() {
	return false;
}

int Game::checkUserInput(int d, string prompt) {
	bool b = false;
	int x;
	while (!b) {
		b = true;
		x = getUserInput<int>("please enter a number: ");
		if (x == 0 || x > d) {
			cout << "improper input; please enter a number between 1 and " << d << endl;
			b = false;
		}
	}
	return x;
}

void Game::moveTurn() {
	bool a = false;
	int x, y, z;
	while (!a) {
		a = true;
		cout << "Choose a card to move: " << endl;
		x = checkUserInput(7, "Enter column number: ");
		cout << endl;
		y = checkUserInput(myBoard.getTabCol(x).getSize(), "Enter row number: ");
		cout << endl;
		cout << "Chose where to move that card: " << endl;
		z = checkUserInput(7, "Enter column number: ");
		if (!isMoveValid(x, y, z)) {
			a = false;
			cout << "you cannot move that card there.  please try again";
		}
	}
	moveCard(x, y, z);
}

template <class T>
T Game::getUserInput(string message) { //makes sure input is of type int
	cout << message << endl;
	T input;
	while (!(cin >> input)) {//keeps the answers as an int-if it's not...
		cin.clear(); //clears cin
		cin.ignore(); //ignore the error flag
		cout << "invalid input, please try again" << endl;
	}
	return input;
}

bool Game::isInputValid(int size, string message) { //to be used inside a while loop
	int input = getUserInput<int>(message); //will get input of type int;
	if (input <= size) {
		return true;
	}
	else { return false; }
}

void Game::moveCard(int x, int y, int moveTo) { //card x-y coordinates; and # of column to move to.
		Deck& movedDeck = myBoard.getTabCol(x).drawDeck(myBoard.getTabCol(x).getSize() - (y - 1)); //drawing the top # of cards
		myBoard.getTabCol(moveTo) += movedDeck; //move the cards
}

bool Game::isMoveValid(int cardX, int cardY, int moveTo) { //also in a while loop?
	Card& inCard = myBoard.getTabCol(cardX - 1).getCard(cardY- 1);
	Card& targetCard = myBoard.getTabCol(moveTo-1).getTopCard();
	if (inCard.getIsRed() != targetCard.getIsRed() && (inCard.getValue() == (targetCard.getValue() - 1))) {
		return true;
	}
	else { return false; }
}

void Game::drawFromDeck(int s) {
	if (myBoard.isDeckEmpty()) {
		myBoard.getDeck() = myBoard.getTrash();

	}
	myBoard.drawFromDeck(s);
}

void Game::cont() {
	string a;
	cout << endl << "do you want to play again?" << endl;
	cin >> a;
	if (a == "yes" || a == "y") { this->setIsPlaying(true); }
	else { this->setIsPlaying(false); }
}

//explicit instantiation
template int Game::getUserInput<int>(string);
template char Game::getUserInput<char>(string);
