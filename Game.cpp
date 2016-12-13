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

void Game::moveTurn() {
	bool a = false;
	int x, y, z;
	while (!a) {
		a = true;
		cout << "Choose a card to move: " << endl;
		x = checkUserInput(7, "Enter column number: ");
		cout << endl;
		y = checkUserInput(myBoard.getTabCol(x - 1).getSize(), "Enter row number: ");
		cout << endl;
		if (!myBoard.getTabCol(x - 1).getCard(y - 1).getIsUp()) {
			a = false;
			cout << "That card is not movable.  Please try again" << endl;
		}
		else {
			if (!checkIfAnyMovable(getTabCard(x, y))) {
				a = false;
				cout << "there are no possible moves with that card.  please try again" << endl;
			}
			else {
				cout << "Chose where to move that card: " << endl;

				bool looper = false;
				while (!looper) {
					looper = true;
					char d = getUserInput<char>("Would you like to move to the foundation (F) or the tableau? (T)");
					if (d == 'f' || d == 'F') {
						z = checkUserInput(4, "enter foundation number ");
						if (!isFoundationMoveValid(x, y, z)) {
							cout << "you cannot move that card there.  please try again" << endl;
							break;
						}
						else {
							moveToFoundation(x, y, z);
						}
					}
					else if (d == 't' || d == 'T') {
						z = checkUserInput(7, "Enter column number: ");
						if (!isMoveValid(x, y, z)) {
							cout << "you cannot move that card there.  please try again" << endl;
							break;
						}
						else {
							moveCard(x, y, z);
						}
					}
					else {
						cout << "improper input.  please enter C or D" << endl;
						looper = false;
					}
				}
			}
		}
	}
}


void Game::moveToFoundation(int x, int y, int moveTo) {
	Deck& movedDeck = moveDeck(x, y); //drawing the top # of cards
	myBoard.getFoundationCol(moveTo - 1) += movedDeck;
}

bool Game::checkIfWon() {
	bool out = false;
	int totalSize = 0;
	for (int i = 0; i < 4; i++) {
		totalSize += myBoard.getFoundationCol(i).getSize();
	}
	return out;
}

bool Game::checkIfAnyMovable(Card inCard) {
	vector<Deck>::iterator it;
	bool out = false;
	Card targetCard;
	for (it = myBoard.getTableau().begin(); it < myBoard.getTableau().end(); it++) {
		targetCard = it->getTopCard();
		if (inCard.getIsRed() != targetCard.getIsRed() && (inCard.getValue() == (targetCard.getValue() - 1))) {
			out = true;
		}
	}
	for (it = myBoard.getFoundation().begin(); it < myBoard.getFoundation().end(); it++) {
		if (it->getSize() == 0) {
			if (inCard.getValue() == 1) {
				out = true;
			}
		}
		else {
			targetCard = it->getTopCard();
			if (inCard.getS() == targetCard.getS() && inCard.getValue() == targetCard.getValue() - 1) {
				out = true;
			}
		}
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
		x = getUserInput<int>(prompt);
		if (x == 0 || x > d) {
			cout << "improper input; please enter a number between 1 and " << d << endl;
			b = false;
		}
	}
	return x;
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

Deck& Game::moveDeck(int x, int y) {
	return myBoard.getTabCol(x - 1).drawDeck(myBoard.getTabCol(x - 1).getSize() - (y - 1));
}
void Game::moveCard(int x, int y, int moveTo) { //card x-y coordinates; and # of column to move to.
	Deck& movedDeck = moveDeck(x, y); //drawing the top # of cards
	myBoard.getTabCol(moveTo - 1) += movedDeck; //move the cards
	myBoard.getTabCol(x - 1).getTopCard().setIsUp(true);
}

bool Game::isMoveValid(int cardX, int cardY, int moveTo) { //also in a while loop?
	Card& inCard = getTabCard(cardX, cardY);
	Card& targetCard = myBoard.getTabCol(moveTo - 1).getTopCard();
	return  (inCard.getIsRed() != targetCard.getIsRed() && (inCard.getValue() == (targetCard.getValue() - 1))) ? true : false;
}

bool Game::isFoundationMoveValid(int x, int y, int moveTo) {
	
	Card& inCard = getTabCard(x, y);
	if (myBoard.getFoundationCol(moveTo).getSize() == 0) {
		if (inCard.getValue() == 1) {
			return true;
		}
	}
	else {
		Card& targetCard = myBoard.getFoundationCol(moveTo - 1).getTopCard();
		return (inCard.getS() == targetCard.getS() && inCard.getValue() == targetCard.getValue() - 1) ? true : false;
	}
}

Card& Game::getTabCard(int cardX, int cardY) {
	return myBoard.getTabCol(cardX - 1).getCard(cardY - 1);
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
