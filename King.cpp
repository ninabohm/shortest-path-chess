#include "King.h"

King::King(Color color) {
    this->setColor(color);
    if (color == Color::WHITE) {
        this->setMarker("K");
    } else {
        this->setMarker("k");
    }
}

King::King(Color color, Field *field) {
    this->setColor(color);
    this->setField(field);
    if (color == Color::WHITE) {
        this->setMarker("K");
    } else {
        this->setMarker("k");
    }
}

bool King::canMoveHere(Field *field) {
    if (abs(this->getField()->getRow() - field->getRow()) == 1 &&
        abs(this->getField()->getCol() - field->getCol()) == 1)
        return true;

    if (abs(this->getField()->getRow() - field->getRow()) == 1 &&
        abs(this->getField()->getCol() - field->getCol()) == 0)
        return true;

    if (abs(this->getField()->getRow() - field->getRow()) == 0 &&
        abs(this->getField()->getCol() - field->getCol()) == 1)
        return true;

    return false;
}