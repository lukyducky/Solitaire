#ifndef CARD_H
#define CARD_H

//class of Card

#include <iostream>
#include <string>

using namespace std;

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
	Card() { value = 0; S = diamond; isRed = true; isUp = false; face = static_cast<Face>(0); isTop = false; } 
	Card(int inV, Suit inSuit, bool inRed, bool inUp, Face inF){value = inV; S = inSuit; isRed = inRed; isUp = inUp; face = inF;}

	//~Card(){}
	//getters and setters
	
	Face getFace() const  { return face; }
	void setFace(Face inFace){ face = inFace; }

	Suit getS() const  { return S; }
	void setS(Suit inS){ S = inS; }

	int getValue() const  { return value; }
	void setVal(int inV){ value = inV; }

	bool getIsRed() const  { return isRed; }
	void setIsRed(bool inRed){ isRed = inRed; }

	bool getIsUp() const  { return isUp; }
	void setIsUp(bool inUp){ isUp = inUp; }

	bool getIsTop() const { return isTop; }
	void setisTop(bool inTop) { isTop = inTop; }
	
	void printCard() const;
	void printCardInfo();
	char getEnumFace(Face inFace) const;
	char getSuit(Suit inS) const;

	friend std::ostream& operator << (std::ostream&os, const Card& c){
		os << "value: " << c.value << ", face" << c.getEnumFace(c.getFace()) << ", suit: " << c.getSuit(c.getS()) 
			<< ", is red: " << c.isRed << ", isUp: " << c.isUp << ", isTop: " << c.isTop;
		return os;
	}
	
	bool operator ==(Card rhs) const {
		return((this->getIsRed() == rhs.isRed) || (this->getFace() == rhs.face) || (this->getS() == rhs.S) || (this->getValue() == rhs.value)) ? true: false;
	}
};

#endif