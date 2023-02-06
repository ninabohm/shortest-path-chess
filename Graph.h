#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <deque>
#include <string>
#include "Node.h"
#include "Edge.h"
#include "Piece.h"

using namespace std;

class Graph {

public:

    virtual ~Graph();


    Node &addNodeToGraph(Node *pNewNode);

    bool nodeShouldBeAdded(Node *pNewNode, vector<vector<string>> matrix);

    void addNodesFromMatrix(vector<vector<string>> matrix);

    Edge &addEdgeToGraph(Edge *pNewEdge);

    bool edgeShouldBeAdded(Edge *pNewEdge, vector<vector<string>> matrix);

    void addEdgesFromMatrix(vector<vector<string>> matrix);

    void remove(Node &rNode);

    void remove(Edge &rEdge);


    const vector<Node *> &getNodes() { return nodes; }

    const vector<Edge *> &getEdges() { return edges; }

    Node *findNode(const string &id);

    Node *findNode(int i, int j);

    Edge *findEdge(const Node &rSrc, const Node &rDst);

    bool isNodeInGraph(const Node &rNode);

    bool isEdgeInGraph(const Edge &rEdge);

    vector<Node *> calcShortestPathDijkstra(const Node &src, const Node &dst);

    void createGraphFromMatrix(const vector<vector<string>> &rMatrix);

    void printGraph();

    void printShortestPath(vector<Node *> path);

    vector<vector<string>>
    markShortestPathInMatrix(vector<vector<string>> &rMatrix, vector<Node *> shortestPath, string symbol);

    Node *findMarkedNode(string marker);

    bool isMarked(vector<vector<string>> matrix, int row, int col);

    void updateGraph(vector<Node *> path);

    vector<vector<string>> getMatrix();


    vector<Node *> nodes;
    vector<Edge *> edges;
    vector<vector<string>> matrix;

    vector<vector<string>> createMatrixFromGraph();
};


#endif
