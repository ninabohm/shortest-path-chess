#include <sstream>
#include <string>
#include "Node.h"
#include <vector>

#pragma once
using namespace std;

class Piece;

class Field : public Node {
public:
    Field();

    Field(int row, int col);

    Field(int row, int col, string marker);

    string toString();

    Piece *getPiece();

    void setPiece(Piece *piece);

private:
    Piece *piece;
};
