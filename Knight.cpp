#include "Knight.h"
#include "Color.h"
#include "Edge.h"
#include "Graph.h"
#include "Chessboard.h"
#include <iostream>

using namespace std;

Knight::Knight(Color color) {
    this->setColor(color);
    if (color == Color::WHITE) {
        this->setMarker("S");
    } else {
        this->setMarker("s");
    }
}

Knight::Knight(Color color, Field *field) {
    this->setColor(color);
    this->setField(field);
    if (color == Color::WHITE) {
        this->setMarker("S");
    } else {
        this->setMarker("s");
    }
}


bool Knight::canMoveHere(Field *field) {
    //  true if field is where piece is at
    if (this->getField() == field) {
        return true;
    }
    
    if (abs(this->getField()->getRow() - field->getRow()) == 2 &&
        abs(this->getField()->getCol() - field->getCol()) == 1 && isNotPawn(field)) {
        return true;
    }

    if (abs(this->getField()->getRow() - field->getRow()) == 1 &&
        abs(this->getField()->getCol() - field->getCol()) == 2 && isNotPawn(field)) {
        return true;
    }
    return false;
}

bool Knight::isNotPawn(Field *field) {
    if (field->getPiece() == nullptr)
        return true;
    bool blackPawn = field->getPiece()->getMarker() != "b";
    bool whitePawn = field->getPiece()->getMarker() != "B";
    return blackPawn && whitePawn;
}

void Knight::move(Field *field) {
    if (!canMoveHere(field))
        return;
    this->setField(field);
}
