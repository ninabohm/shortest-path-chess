#include "Piece.h"
#include "Color.h"

Piece::Piece() {
    this->color = Color::WHITE;
}

Piece::Piece(Color color) {
    this->color = color;
}

Color Piece::getColor() {
    return color;
}

void Piece::setColor(Color color) {
    this->color = color;
}

void Piece::move(Field *field) {
    this->field = field;
}

Field *Piece::getField() {
    return field;
}

void Piece::setField(Field *field) {
    this->field = field;
    field->setPiece(this);
}

string Piece::getMarker() {
    return marker;
}

string Piece::toString() {
    stringstream ss;
    ss << this->getMarker() << "-> (" << field->getRow() << ", " << field->getCol() << ")";
    return ss.str();
}

void Piece::setMarker(string marker) {
    this->marker = marker;
}