#include <string>
#include <sstream>
#include <iostream>

#include "Node.h"

using namespace std;

Node::Node() {
    stringstream s;
    id = s.str();
}

Node::Node(string id) {
    this->id = id;
    this->row = -1;
    this->col = -1;
}

Node::Node(string id, int row, int col) {
    this->id = id;
    this->row = row;
    this->col = col;
}

Node::Node(int row, int col) {
    stringstream s;
    s << "(" << row << "," << col << ")";
    id = s.str();
    this->row = row;
    this->col = col;
}

Node::Node(int row, int col, string marker) {
    stringstream s;
    s << "(" << row << "," << col << ")";
    id = s.str();
    this->row = row;
    this->col = col;
    this->marker = marker;
}

Node::~Node() {
    if (!outgoingEdges.empty()) {
        for (Edge *element: outgoingEdges) {
            outgoingEdges.erase(remove(outgoingEdges.begin(), outgoingEdges.end(), element), outgoingEdges.end());
        }
    }

    if (!incomingEdges.empty()) {
        for (Edge *element: incomingEdges) {
            outgoingEdges.erase(remove(outgoingEdges.begin(), outgoingEdges.end(), element), outgoingEdges.end());
        }
    }
}

void Node::setMarker(string marker) {
    this->marker = marker;
}

void Node::setRow(int row) {
    this->row = row;
}

void Node::setCol(int col) {
    this->col = col;
}

int Node::getRow() {
    return row;
}

int Node::getCol() {
    return col;
}