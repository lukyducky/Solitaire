#include "Card.h"
#include <iostream>
using namespace std;

void Card::printCard() {
	cout << " _____" << endl;
	if (isUp) {
		cout << "|    " << getEnumFace(face) << getSuit(S) << "|" << endl;
	}
	else if (!isUp) {
		cout << "|     |" << endl;
	}
	if (isTop) {
		for (int i = 0; i < 2; i++) {
			cout << "|     |" << endl;
		}
		cout << "|_____|" << endl;
	}
  
}

char Card::getEnumFace(Face inFace) const {
	char out;
	switch (inFace) {
	case Face::A:
		out = 'A';
		break;
	case Face::J:
		out = 'J';
		break;
	case Face::K:
		out = 'K';
		break;
	case Face::Q:
		out = 'Q';
		break;
	case Face::none:
		out = static_cast<char>(value);
		break;
	default:
		out = '0';
		break;
	}
	return out;
}

char Card::getSuit(Suit inS) const  {
	char out;
	switch (inS) {
	case Suit::clover:
		out = 'C';
		break;
	case Suit::heart:
		out = 'H';
		break;
	case Suit::diamond:
		out = 'D';
		break;
	case Suit::spades:
		out = 'S';
		break;
	default:
		out = '0';
		break;
	}
	return out;
}
