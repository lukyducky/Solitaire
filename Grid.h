#ifndef GRID_H
#define GRID_H

#include "Card.h"
#include <vector>

using namespace std;
typedef vector<vector<Card>> grid;

//will have a mxn grid to display cards, either face up or not.

class Grid{
	
private:
	
	int xSize;
	int ySize;

public:
	Grid(){ xSize = 0; ySize = 0; }
	Grid(int x, int y){ xSize = x;  ySize = y; }


	int xSize(){ return xSize; }
	void setxSize(int x){ xSize = x; }

	int ySize(){ return ySize; }
	void setySize(int y){ ySize = y; }

	grid makeGrid();//makes an empty grid of xSize x ySize

	void printGrid(); //prints out the grid
	
	Card getCard(int x, int y); //gets a card at the spot (x, y)
	
};

#endif 