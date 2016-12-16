#include "Game.h"

void Game::playGame() {
	while (isPlaying) {

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
					cout << "Improper input.  Please enter C or D" << endl;
					looper = false;
				}
			}
			isGameWon = checkIfWon();
		}
		cout << "Congrats!  You won!" << endl;
		cont();
	}
}

void Game::moveTurn() {
	bool a = false, b = false;
	int x = 0, y = 0, z = 0;
	//why this doesn't work: using references but references can't change what they're pointing to; and they also can't be made null & initialized later.
	while (!a) {
		a = true;
		Card& movedCard = inputMovedCard();
		if (isCardinTab(movedCard)) { //if card is in foundation
			x = getCardX(movedCard);
			y = getCardY(movedCard);
		}
		cout << endl;
		if (!movedCard.getIsUp()) {
			a = false;
			cout << "That card is not movable.  Please try again" << endl;
		}
		else {
			if (!checkIfAnyMovable(movedCard)) {
				a = false;
				cout << "There are no possible moves with that card.  Please try again" << endl;
			}
			else {
				cout << "Choose where to move that card: " << endl;
				bool looper = false;
				while (!looper) {
					looper = true;
					char d = getUserInput<char>("Would you like to move to the foundation (F) or the tableau? (T)\n");
					if (d == 'f' || d == 'F') {
						z = checkUserInput(4, "Enter foundation number ");
						if (!isFoundationMoveValid(movedCard, z)) {
							cout << "You cannot move that card there.  please try again" << endl;
							//break;
						}
						else if (y + 1 != myBoard.getTabCol(y).getSize()) { //if it is not the top card
							cout << "You can only move 1 card at a time to the foundation.  Please try again. " << endl;
							//break;
						}
						else { //move is value
							if (isCardinTab(movedCard)) { //if it's a tableau card
								moveToFoundation(x, y, z);
							}
							else { //if it's from the hand
								moveFromHandtoFound(z);
							}
						}
					}
					else if (d == 't' || d == 'T') {
						z = checkUserInput(7, "Enter column number: ");
						if (!isMoveValid(movedCard, z)) {
							cout << "You cannot move that card there.  Please try again" << endl;
							//break;
						}
						else {
							if (isCardinTab(movedCard)) {
								moveCard(x, y, z);
							}
							else {
								moveFromHand(z);
							}
						}
					}
					else {
						cout << "Improper input.  Please enter  F or T" << endl;
						looper = false;
					}
				}
			}
		}
	}
}

Card& Game::inputMovedCard() {
	int x, y;
	bool b = false;
	while (!b) {
		b = true;
		char d = getUserInput<char>("would you like to move a card from the tableau(T), or from your hand(H)? \n");
		if (d == 't' || d == 'T') {
			cout << "Choose a card to move: " << endl;
			x = checkUserInput(7, "Enter column number: ");
			cout << endl;
			y = checkUserInput(myBoard.getTabCol(x - 1).getSize(), "Enter row number: ");
			return getTabCard(x, y);
		}
		else if (d == 'H' || d == 'h') {
			//x = checkUserInput(difficulty, "Enter card number: ");
			if (myBoard.getHand().isEmpty())
			{
				b = false;
				cout << "the hand is empty. please draw cards first" << endl;
			}
			else {
				return myBoard.getHand().getTopCard();
			}

		}
		else {
			b = false;
			cout << "improper input, please try again" << endl;
		}
	}
}

bool Game::isCardinTab(Card& inCard) {
	bool out = false;
	for (int i = 0; i < myBoard.getTableau().size(); i++) {
		if (myBoard.getTableau()[i].isCardinDeck(inCard)) {
			out = true;
		}
	}
	return out;
}

int Game::getCardX(Card& inCard) {
	int x = 0;
	for (int i = 0; i < myBoard.getTableau().size(); i++) {
		if (myBoard.getTableau()[i].isCardinDeck(inCard)) { //if card is in deck
			x = i; //get that number!!!
			break; //let's not keep looping if we don't have to.
		}
	}
	return x;
}
int Game::getCardY(Card& inCard) {
	int y = 0;
	for (int i = 0; i < myBoard.getTableau().size(); i++) {
		if (myBoard.getTableau()[i].isCardinDeck(inCard)) { //if the card is in the deck
			y = myBoard.getTableau()[i].findCard(inCard);  //get its index
			break; //and let's stop looping once we're done.
		}
	}
	return y;
}

void Game::moveToFoundation(int x, int y, int moveTo) {
	myBoard.getFoundationCol(moveTo - 1).addCard(myBoard.getTabCol(x).getTopCard());
}

void Game::moveFromHandtoFound(int moveTo) {
	myBoard.getFoundationCol(moveTo - 1).addCard(myBoard.getHand().drawCard());
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

void Game::moveFromHand(int moveTo) {
	//Deck& movedCard = drawHandCard();
	myBoard.getTabCol(moveTo - 1).addCard(myBoard.getHand().drawCard());
}

Deck& Game::getMovedDeck(int x, int y) { //getting a deck of cards:
	return myBoard.getTabCol(x).drawDeck(myBoard.getTabCol(x).getSize() - (y));
}
void Game::moveCard(int x, int y, int moveTo) { //card x-y coordinates; and # of column to move to.
	if (myBoard.getTabCol(x).getSize() == y + 1) { //if it's the top card...
		myBoard.getTabCol(moveTo - 1).addCard(myBoard.getTabCol(x).drawCard());
	}
	else { //if it's a deck to move
		Deck& movedDeck = getMovedDeck(x, y); //drawing the top # of cards
		myBoard.getTabCol(moveTo - 1) += movedDeck; //move the cards
	}

	if (myBoard.getTabCol(x).getSize() > 0) { //if there are still cards left in the first column, set its top card to be up.
		myBoard.getTabCol(x).getTopCard().setIsUp(true);
	}

}

bool Game::isMoveValid(int cardX, int cardY, int moveTo) { //also in a while loop?
	Card& inCard = getTabCard(cardX, cardY);
	Card& targetCard = myBoard.getTabCol(moveTo - 1).getTopCard();
	return  (inCard.getIsRed() != targetCard.getIsRed() && (inCard.getValue() == (targetCard.getValue() - 1))) ? true : false;
}

bool Game::isMoveValid(Card& inCard, int moveTo) {
	Card& targetCard = myBoard.getTabCol(moveTo - 1).getTopCard();
	return  (inCard.getIsRed() != targetCard.getIsRed() && (inCard.getValue() == (targetCard.getValue() - 1))) ? true : false;
}

bool Game::isFoundationMoveValid(Card& inCard, int moveTo) {
	bool out = false;
	if (myBoard.getFoundationCol(moveTo - 1).getSize() == 0) { //if it's empty...
		if (inCard.getValue() == 1) { //only let an ace.
			out = true;
		}
	}
	else { //if it's not empty, check its suit and value.
		Card& targetCard = myBoard.getFoundationCol(moveTo - 1).getTopCard();
		out = (inCard.getS() == targetCard.getS() && inCard.getValue() == targetCard.getValue() - 1) ? true : false;
	}
	return out;
}

Card& Game::getTabCard(int cardX, int cardY) {
	return myBoard.getTabCol(cardX - 1).getCard(cardY - 1);
}

Deck& Game::drawHandCard() {
	return myBoard.getHand().drawDeck(1);
}

void Game::drawFromDeck(int s) {
	if (myBoard.isDeckEmpty()) {
		myBoard.getTrash() += myBoard.getHand().drawDeck(s);
		myBoard.getDeck() += myBoard.getTrash().drawDeck(myBoard.getTrash().getSize());
		myBoard.getDeck().reverseDeck();

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
