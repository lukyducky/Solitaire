#ifndef CARD_H
#define CARD_H

//class of Card

#include <iostream>

class Card{
private:
	Face face;
	int value;
	Suit S;
	bool isRed; //if not red, it's black
	bool isUp;


public:
	Card(){ value = 2; S = diamond; isRed = true; isUp = true; face = none; }

	Card(int inV, Suit inSuit, bool inRed, bool inUp, Face inF){value = inV; S = inSuit; isRed = inRed; isUp = inUp; face = inF;}

	~Card(){}

	//getters and setters
	
	Face face() { return face; }
	void setFace(Face inFace){ face = inFace; }

	Suit S(){ return S; }
	void setS(Suit inS){ S = inS; }

	int value(){ return value; }
	void setVal(int inV){ value = inV; }

	bool isRed(){ return isRed; }
	void setIsRed(bool inRed){ isRed = inRed; }

	bool isUp(){ return isUp; }
	void setIsUp(bool inUp){ isUp = inUp; }
	
	void printCard();
	
};


enum Face{none, J, Q, K, A};
enum Suit{ diamond, clover, heart, spades };



#endif