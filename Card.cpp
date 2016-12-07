#include "Card.h"
#include <iostream>
using namespace std;

void Card::printCard() {
	if (isUp ){
		cout << " _____" << endl;
		cout << "|    " << getEnumFace(face) << getSuit(S) << "|" << endl;
		if (isTop) {
			for (int i = 0; i < 2; i++) {
				cout << "|     |" << endl;
			}
			cout << "|_____|" << endl;
		}
  }
}

char Card::getEnumFace(Face inFace) {
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
	default:
		out = value;
		break;
	}
	return out;
}

char Card::getSuit(Suit inS) {
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
	default:
		out = 'S';
		break;
	}
	return out;
}
