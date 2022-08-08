#ifndef PIECE_H
#define PIECE_H

class piece
{
	private:
		std::string pieceType;
		piece * newPiece;
		char side;
		int xPos;
		int yPos;
	public:
		piece();
		piece(piece * newPiece);
		piece(std::string pType, char pSide, int x, int y);
		~piece();
		char getSide();
		int getX();
		int getY();
		void setX(int x);
		void setY(int y);
		void printPiece();
};

#endif