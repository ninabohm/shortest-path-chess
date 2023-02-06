#include "Chessboard.h"
#include "Knight.h"
#include "King.h"
#include <gtest/gtest.h>
#include <vector>
#include "Pawn.h"
#include "InputHelper.h"

using namespace std;

TEST(Chessboard, shouldHave64FieldsAndAGraphWith64Nodes) {
    Chessboard chessboard;
    EXPECT_EQ(8, chessboard.getBoard().size());
    EXPECT_EQ(8, chessboard.getBoard()[0].size());
    EXPECT_EQ(64, chessboard.getGraph().getNodes().size());
}

TEST(Chessboard, shouldSetMarkersForKingAndKnightAndPawn) {
    Chessboard chessboard;
    vector<Piece *> pieces;
    Knight *knight = new Knight(Color::BLACK, chessboard.getBoard()[0][0]);
    pieces.push_back(knight);
    King *king = new King(Color::WHITE, chessboard.getBoard()[0][1]);
    pieces.push_back(king);
    Pawn *pawn = new Pawn(Color::WHITE, chessboard.getBoard()[1][0]);
    pieces.push_back(pawn);
    chessboard.setPieces(pieces);
    EXPECT_EQ("s", chessboard.getBoard()[0][0]->getMarker());
    EXPECT_EQ("K", chessboard.getBoard()[0][1]->getMarker());
    EXPECT_EQ("B", chessboard.getBoard()[1][0]->getMarker());
}

TEST(Chessboard, ShouldReturnFieldsOfKnightAndKingAndPawnOnGraph) {
    Chessboard chessboard;
    vector<Piece *> pieces;
    Knight *knight = new Knight(Color::WHITE, chessboard.getBoard()[0][0]);
    pieces.push_back(knight);
    King *king = new King(Color::BLACK, chessboard.getBoard()[7][7]);
    pieces.push_back(king);
    Pawn *pawn = new Pawn(Color::WHITE, chessboard.getBoard()[1][0]);
    pieces.push_back(pawn);
    chessboard.setPieces(pieces);
    chessboard.initMoves(knight);
    Field *knightField = dynamic_cast<Field *>(chessboard.getGraph().findMarkedNode("S"));
    Field *kingField = dynamic_cast<Field *>(chessboard.getGraph().findMarkedNode("k"));
    Field *pawnField = dynamic_cast<Field *>(chessboard.getGraph().findMarkedNode("B"));
    EXPECT_EQ(knightField->toString(), "(0, 0) S");
    EXPECT_EQ(kingField->toString(), "(7, 7) k");
    EXPECT_EQ(pawnField->toString(), "(1, 0) B");
}

TEST(Chessboard, ShouldSetPiecesFromExternalFile) {
    Chessboard chessboard;
    InputHelper inputHelper;
    vector<string> piecesWithPosition = inputHelper.readFile("../chessboard.txt");
    vector<Piece *> pieces = inputHelper.decodePieces(piecesWithPosition);
    chessboard.setPieces(pieces);
    EXPECT_EQ("s", chessboard.getBoard()[0][0]->getMarker());
    EXPECT_EQ("b", chessboard.getBoard()[1][2]->getMarker());
    EXPECT_EQ("b", chessboard.getBoard()[3][3]->getMarker());
    EXPECT_EQ("b", chessboard.getBoard()[5][4]->getMarker());
    EXPECT_EQ("K", chessboard.getBoard()[7][7]->getMarker());
}

