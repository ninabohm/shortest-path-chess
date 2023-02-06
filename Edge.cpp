#include "Edge.h"
#include <iostream>

using namespace std;


Edge::Edge(Node &rSrc, Node &rDst) : rSrc(rSrc), rDst(rDst) {
    rSrc.getOutEdges().push_back(this);
    rDst.getInEdges().push_back(this);
    weight = 1;
}

Edge::Edge(Node &rSrc, Node &rDst, int weight) : rSrc(rSrc), rDst(rDst) {
    if (weight < 0) {
        cout << "Invalid weight" << endl;
        return;
    }
    if (weight == 0) {
        cout << "Invalid weight" << endl;
        return;
    }
    if (weight > 0) {
        rSrc.getOutEdges().push_back(this);
        rDst.getInEdges().push_back(this);
        this->weight = weight;
    }
    if (rSrc.toString() == rDst.toString()) {
        cout << "Invalid edge" << endl;
        return;
    }
    rDst.getInEdges().push_back(this);
}


Edge::~Edge() {
    if (isConnectedTo(rSrc)) {
        rSrc.getOutEdges().erase(remove(rSrc.getOutEdges().begin(), rSrc.getOutEdges().end(), this),
                                 rSrc.getOutEdges().end());
    }
    if (isConnectedTo(rDst)) {
        rDst.getInEdges().erase(remove(rDst.getInEdges().begin(), rDst.getInEdges().end(), this),
                                rDst.getInEdges().end());
    }

}


bool Edge::isConnectedTo(const Node &rNode) const {
    if (&rSrc == &rNode) {
        return true;
    }

    if (&rDst == &rNode) {
        return true;
    }
    return false;
}


string Edge::toString() const {
    std::string result;
    result = rSrc.toString() + " -> " + rDst.toString();
    return result;
}

void Edge::setWeight(int weight) {
    this->weight = weight;
}

