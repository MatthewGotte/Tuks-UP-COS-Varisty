#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "board.h"
#include "piece.h"
#include "solver.h"

using namespace std;

int itemCount;

solver::solver(string games) {
    ifstream tfile;
    tfile.open(games);
    string sline;
    int noLines = 0;

    while (getline(tfile, sline))
        noLines++;

    tfile.clear();
    tfile.seekg(0);

    //cout << noLines << endl;
    itemCount = noLines;

    string **ary;
    ary = new string *[noLines];
    for (int i = 0; i < noLines; i++)
        ary[i] = new string[2];

    for (int i = 0; i < noLines; i++) {
        int pos = -1;
        tfile >> sline;
        pos = sline.find(',');
        ary[i][0] = sline.substr(0, pos);
        sline.erase(0, pos + 1);
        ary[i][1] = sline;
    }

    boards = new board*[noLines];
    for (int i = 0; i < noLines; i++)
    {
        boards[i] = new board(ary[i][0]);
    }

    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < noLines - 1; i++) {
            int n1, n2;
            string temp;
            stringstream ss;
            ss << ary[i][1];
            ss >> n1;
            ss.clear();
            ss << ary[i + 1][1];
            ss >> n2;
            ss.clear();
            if (n1 > n2) {
                temp = ary[i][0];
                ary[i][0] = ary[i + 1][0];
                ary[i + 1][0] = temp;
                temp = ary[i][1];
                ary[i][1] = ary[i + 1][1];
                ary[i + 1][1] = temp;
                flag = true;
            }
        }
    }

    board ** tempBoard = new board*[noLines];
    for (int i = 0; i < noLines; i++)
        tempBoard[i] = new board(ary[i][0]);

    for (int i = 0; i < noLines; i++)
    {
        cout << "[" << ary[i][1] << "] ";
        tempBoard[i]->determineIfCheckMate();
    }

    /*for (int i = 0; i < itemCount; i++) {
        delete tempBoard[i];
        tempBoard[i] = nullptr;
    }
    delete [] tempBoard;*/

    tfile.close();
}

solver::~solver()
{
    for (int i = 0; i < itemCount; i++) {
            delete boards[i];
            boards[i] = nullptr;
        }
    delete [] boards;
        cout << "Num Boards Deleted: " << itemCount << endl;
}