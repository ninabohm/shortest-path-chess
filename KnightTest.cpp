#include "Knight.h"
#include "Chessboard.h"
#include <gtest/gtest.h>
#include <vector>
#include "King.h"
#include "Pawn.h"

using namespace std;

TEST(Knight, ShouldReturnColor) {
    Knight knight = Knight(Color::BLACK, new Field(0, 0));
    EXPECT_EQ(Color::BLACK, knight.getColor());
}

TEST(Knight, ShouldMoveToNewField) {
    Knight knight = Knight(Color::BLACK, new Field(0, 0));
    Field *field = new Field(2, 1);
    knight.move(field);
    EXPECT_EQ(field, knight.getField());
}

TEST(Knight, ShouldReturnFalseIfKnightCannotMoveToFiled) {
    Knight knight = Knight(Color::BLACK, new Field(0, 0));
    Field *destination = new Field(1, 0);

    EXPECT_EQ(false, knight.canMoveHere(destination));
}

TEST(Knight, ShouldReturnFalseIfFieldIsOccupied) {
    Knight knight = Knight(Color::BLACK, new Field(0, 0));
    Field *destination = new Field(2, 1);
    Pawn pawn = Pawn(Color::BLACK, destination);
    EXPECT_EQ(false, knight.canMoveHere(destination));
}

TEST(Knight, ShouldReturnTrueIfKnightCanMoveToFiled) {
    Knight knight = Knight(Color::BLACK, new Field(0, 0));
    Field *destination = new Field(2, 1);

    EXPECT_EQ(true, knight.canMoveHere(destination));
}

TEST(Knight, ShouldNotMoveToNewField) {
    Field *origin = new Field(1, 0);
    Knight knight = Knight(Color::BLACK, origin);
    Field *destination = new Field(1, 0);
    knight.move(destination);
    EXPECT_EQ(origin, knight.getField());
}

TEST(Knight, ShouldReturnMarker) {
    Knight knight = Knight(Color::BLACK, new Field(0, 0));
    EXPECT_EQ("s", knight.getMarker());
}

//TEST(Knight, ShouldInitMovesForKnight) {
//    Chessboard chessboard;
//    Knight *knight = new Knight(Color::BLACK, chessboard.getBoard()[0][0]);
//    chessboard.initMoves(knight);
//    vector<Piece *> pieces;
//    pieces.push_back(knight);
//    chessboard.setPieces(pieces);
//    EXPECT_EQ(chessboard.getGraph().getEdges().size(), 336);
//    EXPECT_EQ(chessboard.getBoard()[0][0]->getOutEdges().size(), 2);
//    EXPECT_EQ(chessboard.getBoard()[0][0]->getInEdges().size(), 2);
//    EXPECT_EQ(chessboard.getBoard()[1][5]->getOutEdges().size(), 6);
//    EXPECT_EQ(chessboard.getBoard()[4][4]->getOutEdges().size(), 8);
//    EXPECT_EQ(chessboard.getBoard()[4][4]->getInEdges().size(), 8);
//    EXPECT_EQ(chessboard.getBoard()[7][7]->getOutEdges().size(), 2);
//}

TEST(Knight, ShouldCalculateShortestPathToKing) {
    Chessboard chessboard;
    Knight *knight = new Knight(Color::WHITE, chessboard.getBoard()[0][0]);
    vector<Piece *> pieces;
    pieces.push_back(knight);
    chessboard.initMoves(knight);
    King *king = new King(Color::BLACK, chessboard.getBoard()[7][7]);
    pieces.push_back(king);
    chessboard.setPieces(pieces);
    vector<Node *> path;
    Node &src = dynamic_cast<Node &>(*(chessboard.getBoard()[0][0]));
    Node &dst = dynamic_cast<Node &>(*(chessboard.getBoard()[7][7]));
    path = chessboard.getGraph().calcShortestPathDijkstra(src, dst);
    EXPECT_EQ(path.size(), 7);
}

TEST(Knight, ShouldCalculateShortestPathToKingIfPawnsAreInTheWay) {
    Chessboard chessboard;
    Knight *knight = new Knight(Color::WHITE, chessboard.getBoard()[0][0]);
    vector<Piece *> pieces;
    pieces.push_back(knight);
    King *king = new King(Color::BLACK, chessboard.getBoard()[7][7]);
    pieces.push_back(king);
    Pawn *pawn1 = new Pawn(Color::BLACK, chessboard.getBoard()[1][2]);
    pieces.push_back(pawn1);
    Pawn *pawn2 = new Pawn(Color::BLACK, chessboard.getBoard()[3][3]);
    pieces.push_back(pawn2);
    Pawn *pawn3 = new Pawn(Color::BLACK, chessboard.getBoard()[5][4]);
    pieces.push_back(pawn3);
    chessboard.setPieces(pieces);
    chessboard.initMoves(knight);
    vector<Node *> path;
    Node *src = chessboard.getGraph().findMarkedNode("S");
    Node *dst = chessboard.getGraph().findMarkedNode("k");
    path = chessboard.getGraph().calcShortestPathDijkstra(*src, *dst);

    chessboard.getGraph().printShortestPath(path);
    EXPECT_EQ(path.size(), 7);
    EXPECT_EQ(path[0]->toString(), "(0,0)");
    EXPECT_EQ(path[1]->toString(), "(2,1)");
    EXPECT_EQ(path[2]->toString(), "(0,2)");
    EXPECT_EQ(path[3]->toString(), "(1,4)");
    EXPECT_EQ(path[4]->toString(), "(3,5)");
    EXPECT_EQ(path[5]->toString(), "(5,6)");
    EXPECT_EQ(path[6]->toString(), "(7,7)");
}



