#include "Piece.h"
#include "Field.h"

class Pawn : public Piece {
public:
    Pawn(Color color);

    Pawn(Color color, Field *field);

    bool canMoveHere(Field *target);

    void move(Field *field);
};

