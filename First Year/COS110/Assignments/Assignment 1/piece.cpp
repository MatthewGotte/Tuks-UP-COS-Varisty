#include <iostream>
#include <string>
#include "piece.h"

piece::piece()
{
	
}

piece::piece(piece * newPiece)
{
	side = newPiece->side;
	pieceType = newPiece->pieceType;
	xPos = newPiece->xPos;
	yPos = newPiece->yPos;
}

piece::piece(std::string pType, char pSide, int x, int y)
{
	pieceType = pType;
	side = pSide;
	xPos = x;
	yPos = y;
}

piece::~piece()
{
	std::cout << "(" << xPos << "," << yPos << ") " << side << " " << pieceType << " deleted\n";
}

char piece::getSide()
{
	return side;
}

int piece::getX()
{
	return xPos;
}

int piece::getY()
{
	return yPos;
}

void piece::setX(int x)
{
	xPos = x;
}

void piece::setY(int y)
{
	yPos = y;
}

void piece::printPiece()
{
	std::cout << side << " " << pieceType << " at [" << xPos << "," << yPos << "]\n";
}