#include "Graph.h"
#include <fstream>
#include <algorithm>
#include <limits>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

Node *Graph::findNode(const string &id) {
    if (nodes.empty()) {
        return nullptr;
    }

    if (id.empty()) {
        throw invalid_argument("Node id empty");
    }

    for (Node *element: nodes) {
        if (element->toString() == id) {
            return element;
        }
    }

    return nullptr;
}

Node *Graph::findNode(int i, int j) {
    if (nodes.empty()) {
        throw invalid_argument("No nodes in graph");
    }

    if (i < 0 || j < 0) {
        throw invalid_argument("Invalid row or column");
    }

    for (Node *element: nodes) {
        if (element->getRow() == i && element->getCol() == j) {
            return element;
        }
    }

    cout << "Node not found" << endl;
    return nullptr;
}

bool Graph::isNodeInGraph(const Node &rNode) {
    for (Node *element: nodes) {
        if (element->toString() == rNode.toString()) {
            return true;
        }
    }
    return false;
}

Node &Graph::addNodeToGraph(Node *pNewNode) {
    if (pNewNode == nullptr) {
        throw invalid_argument("pNewNode is null");
    }

    if (isNodeInGraph(*pNewNode)) {
        throw invalid_argument("Node already in graph");
    }

    nodes.push_back(pNewNode);
    return *pNewNode;
}

bool Graph::isEdgeInGraph(const Edge &rEdge) {
    for (Edge *element: edges) {
        if (element->toString() == rEdge.toString()) {
            return true;
        }
    }
    return false;
}

Edge &Graph::addEdgeToGraph(Edge *pNewEdge) {
    if (pNewEdge == nullptr) {
        throw invalid_argument("pNewEdge is null");
    }
    if (isEdgeInGraph(*pNewEdge)) {
        throw invalid_argument("Edge with src " + pNewEdge->getSrcNode().toString() + " and dst " +
                               pNewEdge->getDstNode().toString() + " already in graph");
    }

    edges.push_back(pNewEdge);
    return *pNewEdge;
}

Graph::~Graph() {
    nodes.clear();
    edges.clear();

}

void Graph::remove(Node &rNode) {
    if (!isNodeInGraph(rNode)) {
        throw invalid_argument("Node not in graph");
    }

    for (Edge *element: edges) {
        if (element->isConnectedTo(rNode)) {
            remove(*element);
        }
    }

    for (Node *element: nodes) {
        if (element == &rNode) {
            nodes.erase(find(nodes.begin(), nodes.end(), element));
            delete element;
            break;
        }
    }
}

void Graph::remove(Edge &rEdge) {
    if (!isEdgeInGraph(rEdge)) {
        throw invalid_argument("Edge not in graph");
    }

    if (find(edges.begin(), edges.end(), &rEdge) != edges.end()) {
        edges.erase(find(edges.begin(), edges.end(), &rEdge));
    }

    delete &rEdge;
}


Edge *Graph::findEdge(const Node &rSrc, const Node &rDst) {
    Edge *edge;
    for (Edge *element: edges) {
        if (element->isConnectedTo(rSrc) && element->isConnectedTo(rDst)) {
            edge = element;
            return edge;
        }
    }
    return nullptr;
}

vector<Node *> Graph::calcShortestPathDijkstra(const Node &src, const Node &dst) {
    Node *source = findNode(src.toString());
    Node *destination = findNode(dst.toString());
    if (source == nullptr || destination == nullptr) {
        throw invalid_argument("Source or destination node not in graph");
    }

    map<Node *, int> dist;
    for (Node *node: getNodes()) {
        dist[node] = numeric_limits<int>::max();
    }

    dist[source] = 0;

    map<Node *, Node *> predecessor;
    predecessor[source] = nullptr;

    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<>> priorityQueue;
    priorityQueue.emplace(0, source);

    while (!priorityQueue.empty()) {
        // extract the minimum distance node from the priority queue
        Node *minDistanceNode = priorityQueue.top().second;

        priorityQueue.pop();

        if (minDistanceNode == destination) {
            break;
        }

        for (Edge *edge: minDistanceNode->getOutEdges()) {
            Node *currDstNode = &(edge->getDstNode());
            int edgeWeight = edge->getWeight();

            if (dist[minDistanceNode] + edgeWeight < dist[currDstNode]) {
                dist[currDstNode] = dist[minDistanceNode] + edgeWeight;
                priorityQueue.emplace(dist[currDstNode], currDstNode);
                predecessor[currDstNode] = minDistanceNode;
            }
        }
    }

    vector<Node *> shortestPath;
    Node *curr = destination;
    while (curr != nullptr) {
        shortestPath.push_back(curr);
        curr = predecessor[curr];
    }

    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
}

void Graph::printShortestPath(vector<Node *> shortestPath) {
    if (shortestPath.empty()) {
        cout << "No path found" << endl;
        return;
    }

    cout << "Shortest path from s to K: " << endl;
    for (Node *element: shortestPath) {
        cout << element->toString();
        if (element != shortestPath.back()) {
            cout << " -> ";
        }
    }
    cout << endl;
}


void Graph::printGraph() {
    cout << "Nodes: " << endl;
    for (Node *node: nodes) {
        cout << node->toStringWithMarker() << " ";
        cout << node << endl;
        cout << endl;
    }

    cout << "Edges: " << endl;
    for (Edge *edge: edges) {
        cout << edge->toString() << " ";
        cout << &edge->getSrcNode() << " --  " << edge << "--> " << &edge->getDstNode() << endl;
        cout << endl;
    }
}

vector<vector<string>> Graph::createMatrixFromGraph() {
    vector<vector<string>> matrix;
    for (int i = 0; i < 8; i++) {
        vector<string> row;
        for (int j = 0; j < 8; j++) {
            row.push_back("");
        }
        matrix.push_back(row);
    }

    for (Node *node: nodes) {
        int row = node->getRow();
        int col = node->getCol();
        matrix[row][col] = node->toString();
    }

    return matrix;
}


bool Graph::nodeShouldBeAdded(Node *pNewNode, vector<vector<string>> matrix) {
    if (pNewNode == nullptr) {
        return false;
    }

    int row = pNewNode->getRow();
    int col = pNewNode->getCol();
    if (matrix[row][col] != "") {
        return false;
    }

    return true;
}

void Graph::addNodesFromMatrix(vector<vector<string>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            Node *node = new Node(i, j, matrix[i][j]);
            if (nodeShouldBeAdded(node, matrix)) {
                addNodeToGraph(node);
            } else {
                delete node;
            }
        }
    }
}

bool Graph::edgeShouldBeAdded(Edge *pNewEdge, vector<vector<string>> matrix) {
    if (pNewEdge == nullptr) {
        return false;
    }

    if (isEdgeInGraph(*pNewEdge)) {
        return false;
    }

    int srcRow = pNewEdge->getSrcNode().getRow();
    int srcCol = pNewEdge->getSrcNode().getCol();
    int dstRow = pNewEdge->getDstNode().getRow();
    int dstCol = pNewEdge->getDstNode().getCol();
    if (matrix[srcRow][srcCol] != "" || matrix[dstRow][dstCol] != "") {
        return false;
    }

    if (!isNodeInGraph(pNewEdge->getSrcNode())) {
        nodeShouldBeAdded(&pNewEdge->getSrcNode(), matrix);
    }

    if (!isNodeInGraph(pNewEdge->getDstNode())) {
        nodeShouldBeAdded(&pNewEdge->getDstNode(), matrix);
    }

    return true;
}

bool Graph::isMarked(vector<vector<string>> matrix, int row, int col) {
    if (matrix[row][col] == "a"
        || matrix[row][col] == "b"
        || matrix[row][col] == "c"
        || matrix[row][col] == "A"
        || matrix[row][col] == "B"
        || matrix[row][col] == "C") {
        return true;
    }
    return false;
}

void Graph::addEdgesFromMatrix(vector<vector<string>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == " " || isMarked(matrix, i, j)) {
                Node *srcNode = findNode(i, j);
                if (matrix[i][j + 1] == " " || isMarked(matrix, i, j + 1)) {
                    Node *dstNode = findNode(i, j + 1);
                    Edge *edge = new Edge(*srcNode, *dstNode, 1);
                    if (edgeShouldBeAdded(edge, matrix)) {
                        addEdgeToGraph(edge);
                    } else {
                        delete edge;
                    }
                }

                if (i + 1 < matrix.size() && (matrix[i + 1][j] == " " || isMarked(matrix, i + 1, j))) {
                    Node *dstNode = findNode(i + 1, j);
                    Edge *edge = new Edge(*srcNode, *dstNode, 1);
                    if (edgeShouldBeAdded(edge, matrix)) {
                        addEdgeToGraph(edge);
                    } else {
                        delete edge;
                    }
                }
                if (j - 1 >= 0 && (matrix[i][j - 1] == " " || isMarked(matrix, i, j - 1))) {
                    Node *dstNode = findNode(i, j - 1);
                    Edge *edge = new Edge(*srcNode, *dstNode, 1);
                    if (edgeShouldBeAdded(edge, matrix)) {
                        addEdgeToGraph(edge);
                    } else {
                        delete edge;
                    }
                }

                if (i - 1 >= 0 && (matrix[i - 1][j] == " " || isMarked(matrix, i - 1, j))) {
                    Node *dstNode = findNode(i - 1, j);
                    Edge *edge = new Edge(*srcNode, *dstNode, 1);
                    if (edgeShouldBeAdded(edge, matrix)) {
                        addEdgeToGraph(edge);
                    } else {
                        delete edge;
                    }
                }

            }
        }
    }

}

void Graph::createGraphFromMatrix(const vector<vector<std::string>> &rMatrix) {
    addNodesFromMatrix(rMatrix);
    addEdgesFromMatrix(rMatrix);
}

vector<vector<string>>
Graph::markShortestPathInMatrix(vector<vector<string>> &rMatrix, vector<Node *> shortestPath, string symbol) {
    for (Node *node: shortestPath) {
        if (node->getMarker() == " ") {
            rMatrix[node->getRow()][node->getCol()] = symbol;
        }
    }
    this->matrix = rMatrix;
    return rMatrix;
}

Node *Graph::findMarkedNode(string marker) {
    for (Node *node: nodes) {
        if (node->getMarker() == marker) {
            return node;
        }
    }

    throw invalid_argument("Node not found");
}

void Graph::updateGraph(vector<Node *> shortestPath) {
    for (int i = 0; i < shortestPath.size() - 1; i++) {
        Node *srcNode = shortestPath[i];
        Node *dstNode = shortestPath[i + 1];
        Edge *edge = findEdge(*srcNode, *dstNode);
        delete edge;
    }

    for (int i = 0; i < shortestPath.size() - 1; i++) {
        Node *srcNode = shortestPath[i + 1];
        Node *dstNode = shortestPath[i];
        Edge *edge = findEdge(*srcNode, *dstNode);
        delete edge;
    }
}

vector<vector<string>> Graph::getMatrix() {
    return matrix;
}