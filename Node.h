#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>
#include <vector>

using namespace std;

class Edge;

class Node {
public:
    Node();

    Node(string id);

    Node(string id, int row, int col);

    Node(int row, int col);

    Node(int row, int col, string marker);

    virtual ~Node();

    string toString() const { return id; }

    string toStringWithMarker() const { return id + marker; }

    vector<Edge *> &getOutEdges() { return outgoingEdges; }

    vector<Edge *> &getInEdges() { return incomingEdges; }

    int getRow();

    int getCol();

    string getMarker() { return marker; }

    void setMarker(string marker);

    vector<Edge *> outgoingEdges;
    vector<Edge *> incomingEdges;

    void setRow(int row);

    void setCol(int col);


private:
    string id;
    int row;
    int col;
    string marker;
};


#endif
