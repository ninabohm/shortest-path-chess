#include "Field.h"
#include <iostream>

using namespace std;

Field::Field() : Node() {
    this->setRow(0);
    this->setCol(0);
}

Field::Field(int row, int col) : Node(row, col) {
    this->setRow(row);
    this->setCol(col);
}

Field::Field(int row, int col, string marker) : Node(row, col, marker) {
    this->setRow(row);
    this->setCol(col);
    this->setMarker(marker);
}

string Field::toString() {
    stringstream ss;
    ss << "(" << this->getRow() << ", " << this->getCol() << ")" << this->getMarker();
    return ss.str();
}

Piece *Field::getPiece() {
    return piece;
}

void Field::setPiece(Piece *piece) {
    this->piece = piece;
}
