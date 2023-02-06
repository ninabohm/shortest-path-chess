#include "Color.h"
#include <string>
#include "Field.h"

#pragma once

using namespace std;

class Piece {
public:
    Piece();

    Piece(Color color, Field field);

    Piece(Color color);

    Color getColor();

    void setColor(Color color);

    void setField(Field *field);

    void setMarker(string marker);

    virtual void move(Field *field);

    Field *getField();

    virtual string getMarker();

    string toString();

    virtual bool canMoveHere(Field *field) = 0;

private:
    Field *field;
    Color color;
    string marker = "";
};
