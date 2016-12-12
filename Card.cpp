#include "Card.h"
#include <iostream>

void Card::printCard(string s) const { 
	cout << " _____" << s;
	if (isUp) {
		cout << "|   ";
		if (value != 10) { 
			cout << getEnumFace(face);
		}
		else { cout << 10; }//10 is a special case becuase it's more than 1 digit.
		cout << getSuit(S) << "|" << s;
	}
	else if (!isUp) {
		cout << "|     |" << s;
	}
	if (isTop) {
		for (int i = 0; i < 2; i++) {
			cout << "|     |" << s;
		}
		cout << "|_____|" << s;
	}
}


char Card::getEnumFace(Face inFace) const {
	unsigned char out;
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
	case Face::none: //this is a terrible terrible thing!!!
		out = '0' + value;  //this is a very interesting thing.
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
