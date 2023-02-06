#include "Piece.h"
#include "Color.h"
#include <string>
#include "Graph.h"

class Knight : public Piece {
public:
    Knight(Color color);

    Knight(Color color, Field *field);

    bool canMoveHere(Field *field);

    bool isNotPawn(Field *field);

    void move(Field *field);

};
