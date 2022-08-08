#ifndef BOARD_H
#define BOARD_H
#include "board.h"
#include "piece.h"
#include <string>
#include <iostream>

class board
{
	private:
		int numWhitePieces;
		int numBlackPieces;
	
		piece ** whitePieces;
		piece ** blackPieces;
		std::string ** chessboard;

		void applyMove();
		std::string move;
		char sideToMove;
	public:
		board(std::string pieceList);
		~board();
		void determineIfCheckMate();
		bool checkIfPieceHasCheck(std::string pieceType, int xPos, int yPos, int kingX, int KingY);
};

#endif