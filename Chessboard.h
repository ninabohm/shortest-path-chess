#include "vector"
#include "Field.h"
#include "Piece.h"
#include "Graph.h"

class Chessboard {
public:
    Chessboard();

    ~Chessboard();

    void printBoard();

    vector<vector<Field *>> getBoard() { return board; };

    void setPieces(vector<Piece *> pieces);

    Graph getGraph() { return graph; }

    void initMoves(Piece *piece);

private:
    vector<vector<Field *>> board;
    Graph graph;
};
