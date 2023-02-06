#include "Chessboard.h"
#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

Chessboard::Chessboard() {
    for (int row = 0; row < 8; row++) {
        vector<Field *> rowVector;
        for (int col = 0; col < 8; col++) {
            Field *field = new Field(row, col);
            rowVector.push_back(field);
            graph.addNodeToGraph(dynamic_cast<Node *>(field));
        }
        board.push_back(rowVector);
    }
}

Chessboard::~Chessboard() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            delete board[row][col];
        }
    }
}

void Chessboard::printBoard() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            cout << board[row][col]->toString() << " ";
            if (board[row][col]->getMarker() == "") {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void Chessboard::setPieces(vector<Piece *> pieces) {
    for (Piece *piece: pieces) {
        string marker = piece->getMarker();
        Field *field = board[piece->getField()->getRow()][piece->getField()->getCol()];
        field->setMarker(marker);
        cout << "Set " << field->toString() << endl;
    }
}

void Chessboard::initMoves(Piece *piece) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    Field *origin = board[i][j];
                    piece->setField(origin);
                    Field *target = board[k][l];
                    if (piece->canMoveHere(target)) {
                        Edge *edge = new Edge(*origin, *target);
                        try {
                            graph.addEdgeToGraph(edge);
                        } catch (exception &e) {
                            cout << e.what() << endl;
                        }
                    }
                }
            }
        }
    }
}

