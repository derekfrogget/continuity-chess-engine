#include <iostream>
#include "Board.h"
#include <vector>
#include "Continuity.h"

#define depth 10

using namespace std;

int main(int argc, char *argv[])
{
    Board* startingBoard = Board::fromEPD(argv);
    int evaluation = startingBoard->evaluateMaterial();
    vector<Board*> legalMoves = findAllLegalMoves(startingBoard);
    // for (int i = 0; i < depth; i++)
    // {
    //     for (int j = 0; j < legalMoves.length; j++)
    //     {
    //         findAllLegalMoves(legalMoves[j]);
    //     }
    // }

    cout << "Evaluation: " << evaluation << endl;

    return 0;
}

vector<Board*> findAllLegalMoves(Board* board)
{
    vector<Board*> legalMoves;
    return legalMoves;
}