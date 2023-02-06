#include "InputHelper.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Knight.h"
#include "King.h"
#include "Pawn.h"


using namespace std;

InputHelper::InputHelper()
= default;

vector<string> InputHelper::readFile(string pathToFile) {
    vector<string> piecesWithPosition;
    ifstream file(pathToFile);
    if (!file.is_open()) {
        throw runtime_error("File not found");
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string separator;
        while (getline(ss, separator, ',')) {
            piecesWithPosition.push_back(separator.substr(0, 3));
        }
    }


    file.close();

    return piecesWithPosition;
}

vector<string> InputHelper::readFromConsoleInput() {
    vector<string> piecesWithPosition;
    string line;

    cout << "Enter pieces (format: [pieceCode][column][row], separated by commas, e.g. sa1,bc2,bd4,be6,Kh8):\n";
    getline(cin, line);
    istringstream ss(line);
    string separator;
    while (getline(ss, separator, ',')) {
        piecesWithPosition.push_back(separator.substr(0, 3));
    }

    return piecesWithPosition;
}

void InputHelper::writeToFile(string pathToFile, vector<vector<string>> matrix) {
    ofstream out(pathToFile);
    if (out.is_open()) {
        for (vector<string> row: matrix) {
            for (string element: row) {
                out << element;
            }
            out << endl;
        }
        out.close();
    }
}

Piece *InputHelper::createPiece(char pieceCode) {
    if (pieceCode == 's') {
        return new Knight(Color::BLACK);
    }
    if (pieceCode == 'k') {
        return new King(Color::BLACK);
    }
    if (pieceCode == 'b') {
        return new Pawn(Color::BLACK);
    }
    if (pieceCode == 'S') {
        return new Knight(Color::WHITE);
    }
    if (pieceCode == 'K') {
        return new King(Color::WHITE);
    }
    if (pieceCode == 'B') {
        return new Pawn(Color::WHITE);
    }

    return nullptr;
}

vector<Piece *> InputHelper::decodePieces(vector<string> piecesWithPosition) {
    vector<Piece *> pieces;
    for (string piece: piecesWithPosition) {
        Piece *newPiece = createPiece(piece[0]);
        newPiece->setField(decodeField(piece));
        if (newPiece) {
            pieces.push_back(newPiece);
        }
    }
    return pieces;
}

Field *InputHelper::decodeField(string pieceWithPosition) {
    int col;
    switch (pieceWithPosition[1]) {
        case 'a':
            col = 0;
            break;
        case 'b':
            col = 1;
            break;
        case 'c':
            col = 2;
            break;
        case 'd':
            col = 3;
            break;
        case 'e':
            col = 4;
            break;
        case 'f':
            col = 5;
            break;
        case 'g':
            col = 6;
            break;
        case 'h':
            col = 7;
            break;
        default:
            col = 0;
            break;
    }
    int row = stoi(pieceWithPosition.substr(2, 1)) - 1;
    return new Field(row, col);
}

Knight *InputHelper::findKnightInPieces(vector<Piece *> pieces) {
    for (Piece *piece: pieces) {
        if (piece->getMarker() == "s" || piece->getMarker() == "S") {
            return (Knight *) piece;
        }
    }
    return nullptr;
}