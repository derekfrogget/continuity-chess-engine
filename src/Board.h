#include <array>
class Move;

class Board {
public:
    static Board* fromEPD(char *epd[]);
    Board(std::array<unsigned long long, 12> bitboards, bool whiteToMove1, char castlingRights1, char enPassantSquare1);
    //Board(const Board& orig);
    Board* makeMove(const Move& move);
    unsigned long long getWhitePieces();
    unsigned long long getBlackPieces();
    unsigned long long getWhiteOwnedSquares();
    unsigned long long getBlackOwnedSquares();
    unsigned long long getOccupiedSquares();
    unsigned long long getEmptySquares();
    unsigned long long getLegalWhitePawnMoves();
    void print();
    char evaluateMaterial();
    //virtual ~Board();
//protected:
    //unsigned long long whitePawns;
    //unsigned long long whiteKing; //TODO: Make this not a bitboard
    //unsigned long long whiteQueens;
    //unsigned long long whiteRooks;
    //unsigned long long whiteBishops;
    //unsigned long long whiteKnights;
    //unsigned long long blackPawns;
    //unsigned long long blackKing; //TODO: Make this not a bitboard
    //unsigned long long blackQueens;
    //unsigned long long blackRooks;
    //unsigned long long blackBishops;
    //unsigned long long blackKnights;
    //bool whiteToMove;
    //char castlingRights;
    //char enPassantSquare; 
};