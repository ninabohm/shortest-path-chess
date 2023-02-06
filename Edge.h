#ifndef EDGE_H
#define EDGE_H

#include "Node.h"


class Edge {
public:
    Edge(Node &rSrc, Node &rDst);

    Edge(Node &rSrc, Node &rDst, int weight);

    virtual ~Edge();

    bool isConnectedTo(const Node &rNode) const;

    Node &getSrcNode() {
        return rSrc;
    }

    Node &getDstNode() {
        return rDst;
    }

    std::string toString() const;

    virtual double getWeight() {
        return weight;
    }

    void setWeight(int weight);

private:
    Node &rSrc;
    Node &rDst;
    int weight;

};

#endif
