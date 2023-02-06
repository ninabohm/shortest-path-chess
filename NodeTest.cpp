#include "Node.h"
#include "Edge.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(Node, ShouldReturnNodeId) {
    string expected = "a1";
    Node node = Node("a1");
    string result = node.toString();
    EXPECT_EQ(expected, result);
}

TEST(Node, ShouldReturnOutgoingEdges) {
    Node node1 = Node("a1");
    Node node2 = Node("a2");
    Edge *pEdge = new Edge(node1, node2);
    vector<Edge *> expected = {pEdge};
    EXPECT_EQ(expected, node1.getOutEdges());
}

TEST(Node, ShouldReturnIncomingEdges) {
    Node node1 = Node("a1");
    Node node2 = Node("a2");
    Node node3 = Node("a3");
    Edge *pEdge1 = new Edge(node1, node2);
    Edge *pEdge2 = new Edge(node3, node2);
    vector<Edge *> incomingEdges;
    incomingEdges.push_back(pEdge1);
    incomingEdges.push_back(pEdge2);
    EXPECT_EQ(incomingEdges, node2.getInEdges());
}