#include "Pawn.h"
#include "Color.h"

Pawn::Pawn(Color color) {
    this->setColor(color);
    if (color == Color::WHITE) {
        this->setMarker("B");
    } else {
        this->setMarker("b");
    }
}

Pawn::Pawn(Color color, Field *field) {
    this->setColor(color);
    this->setField(field);
    if (color == Color::WHITE) {
        this->setMarker("B");
    } else {
        this->setMarker("b");
    }
}


void Pawn::move(Field *field) {
    if (!canMoveHere(field))
        return;
    this->setField(field);
}

bool Pawn::canMoveHere(Field *target) {
    return true;
}

