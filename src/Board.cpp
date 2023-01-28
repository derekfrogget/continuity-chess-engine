#include "Board.h"
#include <string>
#include <array>
#include <vector>
#include <iostream>

using namespace std;

unsigned long long whitePawns;
unsigned long long whiteKing;
unsigned long long whiteQueens;
unsigned long long whiteRooks;
unsigned long long whiteBishops;
unsigned long long whiteKnights;

unsigned long long blackPawns;
unsigned long long blackKing;
unsigned long long blackQueens;
unsigned long long blackRooks;
unsigned long long blackBishops;
unsigned long long blackKnights;

bool whiteToMove;
char castlingRights;
char enPassantSquare;

Board::Board(unsigned long long bitboards[12], bool whiteToMove1, char castlingRights1, char enPassantSquare1)
{
    whitePawns = bitboards[0];
    whiteKing = bitboards[1];
    whiteQueens = bitboards[2];
    whiteRooks = bitboards[3];
    whiteBishops = bitboards[4];
    whiteKnights = bitboards[5];
    blackPawns = bitboards[6];
    blackKing = bitboards[7];
    blackQueens = bitboards[8];
    blackRooks = bitboards[9];
    blackBishops = bitboards[10];
    blackKnights = bitboards[11];
    whiteToMove = whiteToMove1;
    castlingRights = castlingRights1;
    enPassantSquare = enPassantSquare1;
}

Board* Board::fromEPD(char *epd[]) 
{
    unsigned long long bitboards[12] = { 0 };

    //Piece placement
    string ranks = epd[2];
    for (size_t i = 0; i < ranks.size(); i++)
    {
        size_t bb = 0;
        switch (ranks[i])
        {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                i += ranks[i] - (unsigned char)'1';
                continue;
                break;
            case 'P':
                bb = 0;
                break;
            case 'K':
                bb = 1;
                break;
            case 'Q':
                bb = 2;
                break;
            case 'R':
                bb = 3;
                break;
            case 'B':
                bb = 4;
                break;
            case 'N':
                bb = 5;
                break;
            case 'p':
                bb = 6;
                break;
            case 'k':
                bb = 7;
                break;
            case 'q':
                bb = 8;
                break;
            case 'r':
                bb = 9;
                break;
            case 'b':
                bb = 10;
                break;
            case 'n':
                bb = 11;
                break;
            default:
                cout << "Problem occured" << endl;
                break;
        }

        bitboards[bb] |= 1ULL << i;
    }

    //Active color
    bool whiteToMove = epd[3] == "w";

    //Castling availability
    char castlingRights = 0;
    if (string(epd[4]).find('K') != string::npos)
        castlingRights |= 1;
    if (string(epd[4]).find('Q') != string::npos)
        castlingRights |= 2;
    if (string(epd[4]).find('k') != string::npos)
        castlingRights |= 4;
    if (string(epd[4]).find('q') != string::npos)
        castlingRights |= 8;

    //En passant target square
    char enPassantSquare = 0;
    if (epd[5] != "-")
        enPassantSquare = (epd[5][0] - 'a') + (epd[5][1] - '1') * 8;

    //TODO: Halfmove clock

    return new Board(bitboards, whiteToMove, castlingRights, enPassantSquare);
}

char Board::evaluateMaterial()
{
    return 
    (__popcnt64(whitePawns) * 10 
    + __popcnt64(whiteBishops) * 30 
    + __popcnt64(whiteKnights) * 30 
    + __popcnt64(whiteRooks) * 50 
    + __popcnt64(whiteQueens) * 90)
    - 
    (__popcnt64(blackPawns) * 10 
    +__popcnt64(blackBishops) * 30 
    + __popcnt64(blackKnights) * 30 
    + __popcnt64(blackRooks) * 50 
    + __popcnt64(blackQueens) * 90);
}

unsigned long long Board::getWhitePieces()
{
    return whitePawns | whiteKing | whiteQueens | whiteRooks | whiteBishops | whiteKnights;
}

unsigned long long Board::getBlackPieces()
{
    return blackPawns | blackKing | blackQueens | blackRooks | blackBishops | blackKnights;
}

unsigned long long Board::getOccupiedSquares()
{
    return getWhitePieces() | getBlackPieces();
}

unsigned long long Board::getEmptySquares()
{
    return ~getOccupiedSquares();
}

unsigned long long Board::getLegalWhitePawnMoves()
{
    unsigned long long upOne = (whitePawns << 8) & getEmptySquares();
    return 0ULL;
}

void Board::print()
{
    for (int i = 0; i < 64; i++)
    {
        if (i % 8 == 0)
            cout << endl;
        if (whitePawns & (1ULL << i))
            cout << "P";
        else if (whiteKing & (1ULL << i))
            cout << "K";
        else if (whiteQueens & (1ULL << i))
            cout << "Q";
        else if (whiteRooks & (1ULL << i))
            cout << "R";
        else if (whiteBishops & (1ULL << i))
            cout << "B";
        else if (whiteKnights & (1ULL << i))
            cout << "N";
        else if (blackPawns & (1ULL << i))
            cout << "p";
        else if (blackKing & (1ULL << i))
            cout << "k";
        else if (blackQueens & (1ULL << i))
            cout << "q";
        else if (blackRooks & (1ULL << i))
            cout << "r";
        else if (blackBishops & (1ULL << i))
            cout << "b";
        else if (blackKnights & (1ULL << i))
            cout << "n";
        else
            cout << ".";
    }
    cout << endl;
}

// vector<string> splitString(string str, char delimiter) {
//     vector<string> result;
//     size_t pos = 0;
//     while ((pos = str.find(delimiter)) != string::npos) {
//         result.push_back(str.substr(0, pos));
//         str.erase(0, pos + 1);
//     }
//     return result;
// }
