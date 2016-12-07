#ifndef CARD_H
#define CARD_H

//class of Card

#include <iostream>


enum Face { none, J, Q, K, A };
enum Suit { diamond, clover, heart, spades };

class Card{
private:
	Face face;
	int value;
	Suit S;
	bool isRed; //if not red, it's black
	bool isUp;
	bool isTop;

public:
	Card(){ value = 0; S = diamond; isRed = true; isUp = false; face = static_cast<Face>(0); }

	Card(int inV, Suit inSuit, bool inRed, bool inUp, Face inF){value = inV; S = inSuit; isRed = inRed; isUp = inUp; face = inF;}

	//~Card(){}

	//getters and setters
	
	Face getFace() { return face; }
	void setFace(Face inFace){ face = inFace; }

	Suit getS(){ return S; }
	void setS(Suit inS){ S = inS; }

	int getValue(){ return value; }
	void setVal(int inV){ value = inV; }

	bool getIsRed(){ return isRed; }
	void setIsRed(bool inRed){ isRed = inRed; }

	bool getIsUp(){ return isUp; }
	void setIsUp(bool inUp){ isUp = inUp; }

	bool getIsTop() { return isTop; }
	void setisTop(bool inTop) { isTop = inTop; }
	
	
	void printCard();
	char getEnumFace(Face inFace);
	char getSuit(Suit inS);

	friend std::ostream& operator << (std::ostream&os, const Card& c)
	{
		os << "value: " << c.value << ", face: " << c.face << ", suit: " << c.S << ", is red: " << c.isRed << ", isUp: " << c.isUp;
		return os;
	}
	
	bool operator ==(Card& rhs) {
		bool equal = false;
		if ((this->isRed == rhs.isRed) || (this->face == rhs.face) || (this->S == rhs.S) || (this->value == rhs.value) )
		{
			equal = true;
		}
	}
};





#endif