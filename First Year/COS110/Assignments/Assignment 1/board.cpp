#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "piece.h"
#include "board.h"

using namespace std;

string pName(char x)
{
    string output;
    switch (x) {
        case 'p': {
            output = "pawn";
            break;
        }
        case 'q': {
            output = "queen";
            break;
        }
        case 'r': {
            output = "rook";
            break;
        }
        case 'k' : {
            output = "knight";
            break;
        }
        case 'b': {
            output = "bishop";
            break;
        }
    }
    return output;
}

bool validRange(int x, int y)
{
    bool output = false;
    if ((0 <= x) && (x < 8) && (0 <= y) && (y < 8))
    {
        output = true;
    }
    return output;
}

void board::applyMove()
{
	int x1,x2,y1,y2;
	stringstream bb;
	
	bb<<move[0];
	bb>>x1;
	bb.clear();
	
	bb<<move[2];
	bb>>y1;
	bb.clear();
	
	bb<<move[4];
	bb>>x2;
	bb.clear();
	
	bb<<move[6];
	bb>>y2;
	bb.clear();
	
	chessboard[x2][y2] = chessboard[x1][y1];
	chessboard[x1][y1] = "-";
	
	bool white; 
	white = false;
	for(int i = 0; i<numWhitePieces; i++)
	{
		if((whitePieces[i]->getX()==x1)&&(whitePieces[i]->getY()==y1))
		{
			whitePieces[i]->setX(x2);
			whitePieces[i]->setY(y2);
			white = true;
			break;
		}
	}
	if(!white)
	{
		for(int i = 0; i<numBlackPieces; i++)
		{
			if((blackPieces[i]->getX()==x1)&&(blackPieces[i]->getY()==y1))
			{
				blackPieces[i]->setX(x2);
				blackPieces[i]->setY(y2);
				//white = true;
				break;
			}
		}
	}
}


board::board(string pieceList)
{
	ifstream file;
	string line;
	file.open(pieceList);
	
	file>>line;
	sideToMove  =line[0];
	file>>line;
	move = line;
	
	numBlackPieces = 0;
	numWhitePieces = 0;
	
	while(getline(file,line))
	{
		if(line[0] == 'b')
			numBlackPieces++;
		if(line[0] == 'w')
			numWhitePieces++;
	}	
	file.clear();
	file.seekg(0);
	getline(file, line);
	getline( file, line);
	
	chessboard = new string*[8];
	for(int i = 0; i < 8; i++)
	{
		chessboard[i] = new string[8];
		for(int j =0; j< 8; j++)
			chessboard[i][j] = "-";
	}
	blackPieces = new piece*[numBlackPieces];
	whitePieces = new piece*[numWhitePieces];
	
	char pSide, cType;
	string pType;
	int xVal,yVal,pos,bpieces = 0 , wpieces = 0;
	
	while(getline(file , line))
	{
		pSide = line[0];
		line.erase(0,2);
		pos = line.find(',');
		pType = line.substr(0, pos);
		line.erase(0, pos + 1);
		stringstream aa;
		aa<< line[0];
		aa>>xVal;
		aa.clear();
		aa<<line[2];
		aa>>yVal;
		
		if(pType == "king")
		{
			cType = 'K';
		}
		else if(pType == "queen")
		{
			cType = 'q';
		}
		else if(pType == "pawn")
		{
			cType = 'p';
		}
		else if(pType == "bishop")
		{
			cType = 'b';
		}
		else if(pType == "knight")
		{
			cType = 'k';
		}
		else if(pType == "rook")
		{
			cType = 'r';
		}
		stringstream out;
		out<<pSide;
		
		chessboard[xVal][yVal] = out.str() + cType;
		out.clear();
		
		if(pSide == 'b')
		{
			blackPieces[bpieces] = new piece(pType, pSide,xVal,yVal);
			bpieces++;
		}
		else if(pSide == 'w')
		{
			whitePieces[wpieces] = new piece(pType, pSide,xVal,yVal);
			wpieces++;
		}
	}
	applyMove();
}

board::~board()
{
	int output = numBlackPieces + numWhitePieces;
	
	for(int i = 0; i < numBlackPieces; i++)
	{
		delete blackPieces[i];
		blackPieces[i] = nullptr;
	}
	delete [] blackPieces;
	
	for(int i =0; i<numWhitePieces; i++)
	{
		delete whitePieces[i];
		whitePieces[i] = nullptr;
	}
	delete [] whitePieces;
	
	for(int i = 0; i<8; i++)
	{
		delete [] chessboard[i];
	}
	delete [] chessboard;
	cout<<"Num Pieces Removed: "<<output<<endl;
	
}

void board::determineIfCheckMate()
{
	bool output = true;
        int kingX = 0, kingY = 0;
	
       //Get king pos:
       if (sideToMove == 'w')
       {
           //get black king:
           for (int i = 0; i < 8; i++)
           {
               for (int j = 0; j < 8; j++)
               {
                   if (chessboard[i][j] == "bK")
                   {
                       kingX = i;
                       kingY = j;
                   }
               }
           }
       }
       else
       {
           //get white king:
           for (int i = 0; i < 8; i++)
           {
               for (int j = 0; j < 8; j++)
               {
                   if (chessboard[i][j] == "wK")
                   {
                       kingX = i;
                       kingY = j;
                   }
               }
           }
       }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            string temp = chessboard[i][j];
            if ((temp != "-") && (temp[0] == sideToMove))
            {
                //check piece with king pot. moves:
                for (int p = kingX - 1; p <= kingX + 1; p++)
                {
                    for (int q = kingY - 1; q < kingY + 1; q++)
                    {
                        if (output && validRange(p, q))
                        {
                            output = checkIfPieceHasCheck(pName(temp[1]), i, j, p, q);
                        }
                    }
                }
            }
        }
    }

    if (!output)
    {
        if (sideToMove == 'w')
            cout << "Success: Checkmate of b King at [" << kingX << "," << kingY << "]" << endl;
        else
            cout << "Success: Checkmate of w King at [" << kingX << "," << kingY << "]" << endl;
    }
    else
    {
        if (sideToMove == 'w')
            cout << "Failure: No Checkmate of b King" << endl;
        else
          cout << "Failure: No Checkmate of w King" << endl;
    }
	
}

bool board::checkIfPieceHasCheck(string pieceType,int xPos,int yPos,int kingX,int kingY)
{
	bool output=false; 
	
	if (pieceType == "pawn")
	{
	    if ((abs(xPos - kingX) == 0) && (abs(yPos - kingY) == 0))
            output = true;
	}

	if((pieceType == "bishop") || (pieceType == "queen"))
	{
		if (abs(kingX - xPos) == abs(kingY - yPos))
			output = true;
	}

	if((pieceType == "rook") || (pieceType == "queen"))
	{ 
		if ((xPos == kingX) || (yPos == kingY))
			output = true;
	}

	if (pieceType == "knight")
	{
		if (((abs(kingY - yPos) == 1) && (abs(kingX - xPos) == 2)) || ((abs(kingY - yPos) == 2) && (abs(kingX - xPos) == 1)))
			output = true;
	}
	return output;
}