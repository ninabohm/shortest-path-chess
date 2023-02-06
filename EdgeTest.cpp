#include "Node.h"
#include "Edge.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(Edge, ShouldReturnSourceNodeOfEdge) {
    Node node1 = Node("a1");
    Node node2 = Node("a2");
    Edge edge = Edge(node1, node2);
    string expected = "a1";
    EXPECT_EQ(expected, edge.getSrcNode().toString());
}

TEST(Edge, ShouldReturnDestinationNodeOfEdge) {
    Node node1 = Node("a1");
    Node node2 = Node("a2");
    Edge edge = Edge(node1, node2);
    string expected = "a2";
    EXPECT_EQ(expected, edge.getDstNode().toString());
}

TEST(Edge, ShouldReturnFalseIfEdgeNotConnectedToNode) {
    Node node1 = Node("a1");
    Node node2 = Node("a2");
    Node node3 = Node("a3");
    Edge edge = Edge(node1, node2);
    bool expected = false;
    EXPECT_EQ(expected, edge.isConnectedTo(node3));
}

TEST(Edge, ShouldReturnTrueIfEdgeConnectedToNode) {
    Node node1 = Node("a1");
    Node node2 = Node("a2");
    Edge edge = Edge(node1, node2);
    bool expected = true;
    EXPECT_EQ(expected, edge.isConnectedTo(node1));
}

TEST(Edge, ShouldReturnTwoRemainingEdgesInOutgoingEdges) {
    Node node1 = Node("a1");
    Node node2 = Node("a2");
    Edge *edge1 = new Edge(node1, node2);
    Edge *edge2 = new Edge(node1, node2);
    Edge *edge3 = new Edge(node1, node2);
    delete edge1;
    vector<Edge *> expected = {edge2, edge3};
    EXPECT_EQ(expected, node1.getOutEdges());
}

TEST(Edge, ShouldReturnTwoRemainingEdgesInIncomingEdges) {
    Node node1 = Node("a1");
    Node node2 = Node("a2");
    Edge *edge1 = new Edge(node1, node2);
    Edge *edge2 = new Edge(node1, node2);
    Edge *edge3 = new Edge(node1, node2);
    delete edge1;
    vector<Edge *> expected = {edge2, edge3};
    EXPECT_EQ(expected, node2.getInEdges());
}

TEST(Edge, ShouldReturnTheWeightOfTheEdge) {
    Node node1 = Node("a1");
    Node node2 = Node("a2");
    Edge edge = Edge(node1, node2);
    edge.setWeight(5);
    int expected = 5;
    EXPECT_EQ(expected, edge.getWeight());
}

TEST(Edge, ShouldOutgoingEdgesOfTheEdgeUsingSpeciaConstructor) {
    Node node1 = Node("a1");
    Node node2 = Node("a2");
    Node node3 = Node("a3");
    Edge *edge1 = new Edge(node1, node2, 1);
    Edge *edge2 = new Edge(node1, node3, 2);
    vector<Edge *> expected = {edge1, edge2};
    EXPECT_EQ(expected, node1.getOutEdges());
}