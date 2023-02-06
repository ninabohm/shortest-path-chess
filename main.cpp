#include "gtest/gtest.h"
#include "InputHelper.h"
#include "Chessboard.h"
#include "Piece.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    // include the line below to run the tests
    // ::testing::InitGoogleTest(&argc, argv);

    InputHelper inputHelper;
    vector<string> piecesWithPosition = inputHelper.readFromConsoleInput();

    vector<Piece *> pieces = inputHelper.decodePieces(piecesWithPosition);
    Chessboard chessboard;
    chessboard.setPieces(pieces);
    chessboard.printBoard();

    Knight *knight = inputHelper.findKnightInPieces(pieces);
    chessboard.initMoves(knight);
    vector<Node *> path;
    Node *src = chessboard.getGraph().findMarkedNode("s");
    Node *dst = chessboard.getGraph().findMarkedNode("K");
    path = chessboard.getGraph().calcShortestPathDijkstra(*src, *dst);
    chessboard.getGraph().printShortestPath(path);

    return 0;
    // include the line below to run the tests and exclude the line above
    // return RUN_ALL_TESTS();
}
