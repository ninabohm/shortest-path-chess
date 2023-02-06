#ifndef INPUTHELPER_H

#include <string>
#include "Piece.h"

using namespace std;

class Knight;

class InputHelper {
public:
    InputHelper();

    vector<string> readFile(string pathToFile);

    vector<string> readFromConsoleInput();

    void writeToFile(string pathToFile, vector<vector<string>> matrix);

    vector<Piece *> decodePieces(vector<string> piecesWithPosition);

    Piece *createPiece(char pieceCode);

    Field *decodeField(string pieceWithPosition);

    Knight *findKnightInPieces(vector<Piece *> pieces);
};

#endif
