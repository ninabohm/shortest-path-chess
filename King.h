#include "Color.h"
#include "Piece.h"

class King : public Piece {
public:
    King(Color color);
    
    King(Color color, Field *field);

    bool canMoveHere(Field *field);
};
