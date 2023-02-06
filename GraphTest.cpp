//#include "Graph.h"
//#include <gtest/gtest.h>
//#include <string>
//#include "InputHelper.h"
//
//using namespace std;
//
//TEST(Graph, ShouldReturnReferenceToNodeIfNodeIsAdded) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node &result = graph.addNodeToGraph(pNode1);
//    EXPECT_EQ(pNode1, &result);
//}
//
//TEST(Graph, ShouldThrowExceptionIfNodeIsAddedTwice) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    graph.addNodeToGraph(pNode1);
//    EXPECT_THROW(graph.addNodeToGraph(pNode1), std::invalid_argument);
//}
//
//
//TEST(Graph, ShouldReturnPointerToNodeIfContainedInGraph) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    graph.addNodeToGraph(pNode1);
//    graph.addNodeToGraph(pNode2);
//    Node *result = graph.findNode("a2");
//    EXPECT_EQ(pNode2, result);
//}
//
//TEST(Graph, ShouldReturnNullIfNodeNotContainedInGraph) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    graph.addNodeToGraph(pNode1);
//    graph.addNodeToGraph(pNode2);
//    Node *result = graph.findNode("a3");
//    EXPECT_EQ(NULL, result);
//}
//
//
//TEST(Graph, ShouldReturnTrueIfNodeIsInGraph) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    graph.addNodeToGraph(pNode1);
//    bool result = graph.isNodeInGraph(*pNode1);
//    EXPECT_EQ(true, result);
//}
//
//TEST(Graph, ShouldReturnFalseIfNodeIsNotInGraph) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    graph.addNodeToGraph(pNode1);
//    bool result = graph.isNodeInGraph(*pNode2);
//    EXPECT_EQ(false, result);
//}
//
//TEST(Graph, ShouldReturnReferenceToEdgeIfEdgeWasAdded) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    Edge *pEdge = new Edge(*pNode1, *pNode2);
//    Edge &result = graph.addEdgeToGraph(pEdge);
//    EXPECT_EQ(pEdge, &result);
//}
//
//TEST(Graph, ShouldThrowExceptionIfEdgeIsAddedTwice) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    Edge *pEdge = new Edge(*pNode1, *pNode2);
//    graph.addEdgeToGraph(pEdge);
//    EXPECT_THROW(graph.addEdgeToGraph(pEdge), std::invalid_argument);
//}
//
//TEST(Graph, ShouldThrowInvalidArgumentIfEdgeIsAddedWithSrcNodeNotInGraph) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    Edge *pEdge = new Edge(*pNode1, *pNode2);
//    graph.addEdgeToGraph(pEdge);
//    EXPECT_THROW(graph.addEdgeToGraph(pEdge), std::invalid_argument);
//}
//
//TEST(Graph, ShouldThrowInvalidArgumentIfEdgeIsAddedWithDstNodeNotInGraph) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    graph.addNodeToGraph(pNode1);
//    Edge *pEdge = new Edge(*pNode1, *pNode2);
//    graph.addEdgeToGraph(pEdge);
//    EXPECT_THROW(graph.addEdgeToGraph(pEdge), std::invalid_argument);
//}
//
//TEST(Graph, ShouldReturnEdgeThatIsConnectedToNodes) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    Node *pNode3 = new Node("a3");
//    Node *pNode4 = new Node("a4");
//    Edge *pEdge1 = new Edge(*pNode1, *pNode2);
//    Edge *pEdge2 = new Edge(*pNode2, *pNode3);
//    Edge *pEdge3 = new Edge(*pNode1, *pNode4);
//    graph.addEdgeToGraph(pEdge1);
//    graph.addEdgeToGraph(pEdge2);
//    graph.addEdgeToGraph(pEdge3);
//    Edge *result = graph.findEdge(*pNode1, *pNode2);
//    EXPECT_EQ(pEdge1, result);
//}
//
//TEST(Graph, ShouldThrowInvalidArgumentIfNodeIsNotInGraph) {
//    Graph graph = Graph();
//    Node *pNode = new (Node);
//    EXPECT_THROW(graph.remove(*pNode), std::invalid_argument);
//}
//
//TEST(Graph, ShouldRemoveNodeFromGraph) {
//    Graph graph = Graph();
//    Node *pNode = new (Node);
//    graph.addNodeToGraph(pNode);
//    graph.remove(*pNode);
//    EXPECT_EQ(NULL, graph.findNode("a1"));
//    EXPECT_EQ(0, graph.getNodes().size());
//}
//
//
//TEST(Graph, ShouldThrowInvalidArgumentIfEdgeIsNotInGraph) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    Edge *pEdge1 = new Edge(*pNode1, *pNode2);
//    EXPECT_THROW(graph.remove(*pEdge1), std::invalid_argument);
//}
//
//TEST(Graph, ShouldRemoveEdgeFromGraph) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    Node *pNode3 = new Node("a3");
//    Edge *pEdge1 = new Edge(*pNode1, *pNode2);
//    Edge *pEdge2 = new Edge(*pNode2, *pNode3);
//    graph.addEdgeToGraph(pEdge1);
//    graph.addEdgeToGraph(pEdge2);
//    graph.remove(*pEdge2);
//
//    EXPECT_EQ(1, graph.getEdges().size());
//}
//
//TEST(Graph, ShouldRemoveSecondEdgeFromGraphAndKeepFirstAndLastEdge) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("a1");
//    Node *pNode2 = new Node("a2");
//    Node *pNode3 = new Node("a3");
//    Node *pNode4 = new Node("a4");
//    Edge *pEdge1 = new Edge(*pNode1, *pNode2);
//    Edge *pEdge2 = new Edge(*pNode2, *pNode3);
//    Edge *pEdge3 = new Edge(*pNode3, *pNode4);
//
//    graph.addNodeToGraph(pNode1);
//    graph.addNodeToGraph(pNode2);
//    graph.addNodeToGraph(pNode3);
//    graph.addNodeToGraph(pNode4);
//
//    graph.addEdgeToGraph(pEdge1);
//    graph.addEdgeToGraph(pEdge2);
//    graph.addEdgeToGraph(pEdge3);
//    graph.remove(*pEdge2);
//
//    EXPECT_EQ(2, graph.getEdges().size());
//}
//
//TEST(Graph, ShouldReturnTheShortestPathBetweenTwoNodes) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("n1");
//    Node *pNode2 = new Node("n2");
//    Node *pNode3 = new Node("n3");
//    Node *pNode4 = new Node("n4");
//    Edge *pEdge1 = new Edge(*pNode1, *pNode2);
//    Edge *pEdge2 = new Edge(*pNode2, *pNode3);
//    Edge *pEdge3 = new Edge(*pNode3, *pNode4);
//    Edge *pEdge4 = new Edge(*pNode1, *pNode4);
//
//    graph.addNodeToGraph(pNode1);
//    graph.addNodeToGraph(pNode2);
//    graph.addNodeToGraph(pNode3);
//    graph.addNodeToGraph(pNode4);
//
//    graph.addEdgeToGraph(pEdge1);
//    graph.addEdgeToGraph(pEdge2);
//    graph.addEdgeToGraph(pEdge3);
//    graph.addEdgeToGraph(pEdge4);
//    vector<Node *> result = graph.calcShortestPathDijkstra(*pNode1, *pNode4);
//
//    EXPECT_EQ(2, result.size());
//    EXPECT_EQ(pNode1, result[0]);
//    EXPECT_EQ(pNode4, result[1]);
//}
//
//TEST(Graph, ShouldReturnTheShortestPathInGraphWithDualDirections) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("n1");
//    Node *pNode2 = new Node("n2");
//    Node *pNode3 = new Node("n3");
//    Node *pNode4 = new Node("n4");
//    Node *pNode5 = new Node("n5");
//    Node *pNode6 = new Node("n6");
//    Node *pNode8 = new Node("n7");
//
//    graph.addNodeToGraph(pNode1);
//    graph.addNodeToGraph(pNode2);
//    graph.addNodeToGraph(pNode3);
//    graph.addNodeToGraph(pNode4);
//    graph.addNodeToGraph(pNode5);
//    graph.addNodeToGraph(pNode6);
//    graph.addNodeToGraph(pNode8);
//
//
//    Edge *pEdge1 = new Edge(*pNode1, *pNode2);
//    Edge *pEdge2 = new Edge(*pNode1, *pNode5);
//    Edge *pEdge3 = new Edge(*pNode5, *pNode6);
//    Edge *pEdge4 = new Edge(*pNode5, *pNode3);
//    Edge *pEdge5 = new Edge(*pNode3, *pNode4);
//    Edge *pEdge6 = new Edge(*pNode6, *pNode8);
//
//    graph.addEdgeToGraph(pEdge1);
//    graph.addEdgeToGraph(pEdge2);
//    graph.addEdgeToGraph(pEdge3);
//    graph.addEdgeToGraph(pEdge4);
//    graph.addEdgeToGraph(pEdge5);
//    graph.addEdgeToGraph(pEdge6);
//
//
//    vector<Node *> result = graph.calcShortestPathDijkstra(*pNode1, *pNode8);
//    EXPECT_EQ(4, result.size());
//    EXPECT_EQ(pNode1, result[0]);
//    EXPECT_EQ(pNode5, result[1]);
//    EXPECT_EQ(pNode6, result[2]);
//    EXPECT_EQ(pNode8, result[3]);
//}
//
//
//TEST(Graph, ShouldCreateGraphFromMatrix) {
//    Graph graph = Graph();
//    vector<vector<string>> matrix = {
//            {"#", " ", " ", "#"},
//            {"#", "#", " ", "#"},
//            {"#", "#", " ", "#"},
//            {" ", " ", " ", "#"}
//    };
//    graph.createGraphFromMatrix(matrix);
//    EXPECT_EQ(7, graph.getNodes().size());
//    EXPECT_EQ(12, graph.getEdges().size());
//    EXPECT_EQ("(0,1)", graph.findNode("(0,1)")->toString());
//    EXPECT_EQ("(0,2)", graph.findNode("(0,2)")->toString());
//    EXPECT_EQ(1, graph.getNodes()[0]->getOutEdges().size());
//}
//
//TEST(Graph, ShouldCreateShortestPath) {
//    Graph graph = Graph();
//    Node *pNode1 = new Node("(0,1)");
//    Node *pNode2 = new Node("(0,2)");
//    Node *pNode3 = new Node("(1,2)");
//    Node *pNode4 = new Node("(2,2)");
//    Node *pNode5 = new Node("(3,2)");
//    Node *pNode6 = new Node("(3,1)");
//    Node *pNode7 = new Node("(3,0)");
//
//    graph.addNodeToGraph(pNode1);
//    graph.addNodeToGraph(pNode2);
//    graph.addNodeToGraph(pNode3);
//    graph.addNodeToGraph(pNode4);
//    graph.addNodeToGraph(pNode5);
//    graph.addNodeToGraph(pNode6);
//    graph.addNodeToGraph(pNode7);
//
//    Edge *pEdge1 = new Edge(*pNode1, *pNode2);
//    Edge *pEdge2 = new Edge(*pNode2, *pNode3);
//    Edge *pEdge3 = new Edge(*pNode3, *pNode4);
//    Edge *pEdge4 = new Edge(*pNode4, *pNode5);
//    Edge *pEdge5 = new Edge(*pNode5, *pNode6);
//    Edge *pEdge6 = new Edge(*pNode6, *pNode7);
//
//    graph.addEdgeToGraph(pEdge1);
//    graph.addEdgeToGraph(pEdge2);
//    graph.addEdgeToGraph(pEdge3);
//    graph.addEdgeToGraph(pEdge4);
//    graph.addEdgeToGraph(pEdge5);
//    graph.addEdgeToGraph(pEdge6);
//
//    vector<Node *> result = graph.calcShortestPathDijkstra(*pNode1, *pNode7);
//    EXPECT_EQ(7, result.size());
//    EXPECT_EQ(pNode1, result[0]);
//    EXPECT_EQ(pNode2, result[1]);
//    EXPECT_EQ(pNode3, result[2]);
//    EXPECT_EQ(pNode4, result[3]);
//    EXPECT_EQ(pNode5, result[4]);
//    EXPECT_EQ(pNode6, result[5]);
//    EXPECT_EQ(pNode7, result[6]);
//}
//
//TEST(Graph, ShouldReturnTrueIfEdgeShouldBeAdded) {
//    Graph graph = Graph();
//    vector<vector<string>> matrix = {
//            {"#", " ", " ", "#"},
//            {"#", "#", " ", "#"},
//            {"#", "#", " ", "#"},
//            {" ", " ", " ", "#"}
//    };
//    graph.addNodesFromMatrix(matrix);
//    Node *pNode1 = graph.findNode("(0,1)");
//    Node *pNode2 = graph.findNode("(0,2)");
//    Edge *pEdge1 = new Edge(*pNode1, *pNode2);
//
//    EXPECT_TRUE(graph.edgeShouldBeAdded(pEdge1, matrix));
//}
//
//TEST(Graph, ShouldCreateShortestPathFromMatrix) {
//    Graph graph = Graph();
//    const int ROWS = 4;
//    const int COLS = 4;
//    string input[ROWS][COLS] = {
//            {"#", " ", " ", "#"},
//            {"#", "#", " ", "#"},
//            {"#", "#", " ", "#"},
//            {" ", " ", " ", "#"}
//    };
//
//    std::vector<std::vector<std::string>> matrix(ROWS, std::vector<std::string>(COLS));
//    for (int i = 0; i < matrix.size(); i++) {
//        for (int j = 0; j < matrix[i].size(); j++) {
//            matrix[i][j] = input[i][j];
//            graph.addNodeToGraph(new Node("(" + to_string(i) + "," + to_string(j) + ")"));
//        }
//    }
//
//    Node *pNode1 = graph.findNode("(0,1)");
//    Node *pNode2 = graph.findNode("(0,2)");
//    Node *pNode3 = graph.findNode("(1,2)");
//
//    Edge *pEdge1 = new Edge(*pNode1, *pNode2);
//    Edge *pEdge2 = new Edge(*pNode2, *pNode3);
//
//    graph.addEdgeToGraph(pEdge1);
//    graph.addEdgeToGraph(pEdge2);
//
//    vector<Node *> result = graph.calcShortestPathDijkstra(*pNode1, *pNode3);
//    EXPECT_EQ(3, result.size());
//    EXPECT_EQ(pNode1, result[0]);
//    EXPECT_EQ(pNode2, result[1]);
//    EXPECT_EQ(pNode3, result[2]);
//}
//
//
//TEST(Graph, ShouldFindShortestPathInGraphFromMatrix) {
//    Graph graph = Graph();
//    vector<vector<string>> matrix = {
//            {"#", " ", " ", "#"},
//            {"#", "#", " ", "#"},
//            {"#", "#", " ", "#"},
//            {" ", " ", " ", "#"}
//    };
//
//    graph.createGraphFromMatrix(matrix);
//    Node *pNodeStart = graph.findNode("(0,1)");
//    Node *pNodeEnd = graph.findNode("(3,0)");
//    vector<Node *> result = graph.calcShortestPathDijkstra(*pNodeStart, *pNodeEnd);
//    EXPECT_EQ(7, result.size());
//    EXPECT_EQ(graph.getNodes()[0]->toString(), result[0]->toString());
//}
//
//TEST(Graph, ShouldFindShortestPathInGraphFromMatrixWithSeveralWays) {
//    Graph graph = Graph();
//    vector<vector<string>> matrix = {
//            {"#", " ", " ", " ", " "},
//            {" ", " ", " ", "#", " "},
//            {"#", "#", " ", " ", " "},
//            {" ", " ", " ", "#", " "},
//            {" ", " ", " ", " ", " "}
//    };
//
//    graph.createGraphFromMatrix(matrix);
//    Node *pNodeStart = graph.findNode("(1,1)");
//    Node *pNodeEnd = graph.findNode("(4,4)");
//    vector<Node *> result = graph.calcShortestPathDijkstra(*pNodeStart, *pNodeEnd);
//    EXPECT_EQ(7, result.size());
//    EXPECT_EQ("(1,1)", result[0]->toString());
//    EXPECT_EQ("(1,2)", result[1]->toString());
//    EXPECT_EQ("(2,2)", result[2]->toString());
//    EXPECT_EQ("(2,3)", result[3]->toString());
//    EXPECT_EQ("(2,4)", result[4]->toString());
//    EXPECT_EQ("(3,4)", result[5]->toString());
//    EXPECT_EQ("(4,4)", result[6]->toString());
//}
//
//TEST(Graph, ShouldMarkShortestPathAsPointInMatrix) {
//    Graph graph = Graph();
//    vector<vector<string>> matrix = {
//            {"#", " ", " ", " ", " "},
//            {" ", " ", " ", "#", " "},
//            {"#", "#", " ", " ", " "},
//            {" ", " ", " ", "#", " "},
//            {" ", " ", " ", " ", " "}
//    };
//
//    vector<vector<string>> expected = {
//            {"#", " ", " ", " ", " "},
//            {" ", ".", ".", "#", " "},
//            {"#", "#", ".", ".", "."},
//            {" ", " ", " ", "#", "."},
//            {" ", " ", " ", " ", "."}
//    };
//
//    graph.createGraphFromMatrix(matrix);
//    Node *pNodeStart = graph.findNode("(1,1)");
//    Node *pNodeEnd = graph.findNode("(4,4)");
//    vector<Node *> shortestPath = graph.calcShortestPathDijkstra(*pNodeStart, *pNodeEnd);
//    vector<vector<string>> result = graph.markShortestPathInMatrix(matrix, shortestPath, ".");
//    EXPECT_EQ(expected, result);
//}
//
//TEST(Graph, ShouldFindCreateMarkedNodeForAllMarkers) {
//    Graph graph = Graph();
//    vector<vector<string>> matrix = {
//            {"#", " ", " ", "a", " "},
//            {" ", " ", " ", "#", " "},
//            {"#", "#", "b", " ", " "},
//            {"A", " ", " ", "#", "B"},
//            {" ", " ", " ", " ", " "}
//    };
//
//    graph.createGraphFromMatrix(matrix);
//    Node *a = graph.findMarkedNode("a");
//    Node *b = graph.findMarkedNode("b");
//    Node *A = graph.findMarkedNode("A");
//    Node *B = graph.findMarkedNode("B");
//    EXPECT_EQ("(0,3)", a->toString());
//    EXPECT_EQ("(2,2)", b->toString());
//    EXPECT_EQ("(3,0)", A->toString());
//    EXPECT_EQ("(3,4)", B->toString());
//}
//
//TEST(Graph, ShouldFindShortestPathInGraphFromMatrixBetweenTwoPointsaAndA) {
//    Graph graph = Graph();
//    vector<vector<string>> matrix = {
//            {"#", " ", " ", "a", " "},
//            {" ", " ", " ", "#", " "},
//            {"#", "#", " ", " ", " "},
//            {" ", "A", " ", "#", " "},
//            {" ", " ", " ", " ", " "}
//    };
//
//    graph.createGraphFromMatrix(matrix);
//    Node *pNodeStart = graph.findMarkedNode("a");
//    Node *pNodeEnd = graph.findMarkedNode("A");
//    vector<Node *> result = graph.calcShortestPathDijkstra(*pNodeStart, *pNodeEnd);
//    EXPECT_EQ(6, result.size());
//    EXPECT_EQ("(0,3)", result[0]->toString());
//    EXPECT_EQ("(0,2)", result[1]->toString());
//    EXPECT_EQ("(1,2)", result[2]->toString());
//    EXPECT_EQ("(2,2)", result[3]->toString());
//    EXPECT_EQ("(3,2)", result[4]->toString());
//    EXPECT_EQ("(3,1)", result[5]->toString());
//}
//
//TEST(Graph, ShouldFindShortestPathBetweenbAndBWhenAIsObstacle) {
//    Graph graph = Graph();
//    vector<vector<string>> matrix = {
//            {"#", " ", " ", " ", " "},
//            {" ", "b", " ", "#", " "},
//            {"#", "#", " ", "a", " "},
//            {" ", "A", " ", " ", " "},
//            {" ", " ", " ", "#", "B"}
//    };
//
//    graph.createGraphFromMatrix(matrix);
//    Node *pNodeStartA = graph.findMarkedNode("a");
//    Node *pNodeEndA = graph.findMarkedNode("A");
//    vector<Node *> pathA = graph.calcShortestPathDijkstra(*pNodeStartA, *pNodeEndA);
//    graph.updateGraph(pathA);
//    Node *pNodeStartB = graph.findMarkedNode("b");
//    Node *pNodeEndB = graph.findMarkedNode("B");
//    vector<Node *> pathB = graph.calcShortestPathDijkstra(*pNodeStartB, *pNodeEndB);
//
//    EXPECT_EQ(4, pathA.size());
//    EXPECT_EQ(9, pathB.size());
//    EXPECT_EQ("(1,1)", pathB[0]->toString());
//    EXPECT_EQ("(0,1)", pathB[1]->toString());
//    EXPECT_EQ("(0,2)", pathB[2]->toString());
//    EXPECT_EQ("(0,3)", pathB[3]->toString());
//    EXPECT_EQ("(0,4)", pathB[4]->toString());
//    EXPECT_EQ("(1,4)", pathB[5]->toString());
//    EXPECT_EQ("(2,4)", pathB[6]->toString());
//    EXPECT_EQ("(3,4)", pathB[7]->toString());
//    EXPECT_EQ("(4,4)", pathB[8]->toString());
//}
//
//TEST(Graph, ShouldReturnEdgesAndMarkedNodesInMatrixFromInputHelper) {
//    InputHelper inputHelper = InputHelper();
//    vector<vector<string>> fileContent = inputHelper.readFile("../printedCircuitBoard.txt");
//    Graph graph = Graph();
//    graph.createGraphFromMatrix(fileContent);
//    EXPECT_EQ(graph.getEdges().size(), 4938);
//    EXPECT_EQ(graph.getNodes().size(), 2462);
//    EXPECT_EQ(graph.findMarkedNode("a")->toString(), "(23,44)");
//    EXPECT_EQ(graph.findMarkedNode("b")->toString(), "(21,51)");
//    EXPECT_EQ(graph.findMarkedNode("c")->toString(), "(20,45)");
//    EXPECT_EQ(graph.findMarkedNode("A")->toString(), "(27,4)");
//    EXPECT_EQ(graph.findMarkedNode("B")->toString(), "(43,82)");
//    EXPECT_EQ(graph.findMarkedNode("C")->toString(), "(46,99)");
//}
//
//TEST(Graph, ShouldReturnShortestPathForAFromInputHelper) {
//    InputHelper inputHelper = InputHelper();
//    vector<vector<string>> fileContent = inputHelper.readFile("../printedCircuitBoard.txt");
//    Graph graph = Graph();
//    graph.createGraphFromMatrix(fileContent);
//    Node *pNodeStartA = graph.findMarkedNode("a");
//    Node *pNodeEndA = graph.findMarkedNode("A");
//    vector<Node *> pathA = graph.calcShortestPathDijkstra(*pNodeStartA, *pNodeEndA);
//    EXPECT_EQ(1, pathA.size());
//    EXPECT_EQ("(27,4)", pathA[0]->toString());
//}
//
//TEST(Graph, ShouldReturnShortestPathForBFromInputHelper) {
//    InputHelper inputHelper = InputHelper();
//    vector<vector<string>> fileContent = inputHelper.readFile("../printedCircuitBoard.txt");
//    Graph graph = Graph();
//    graph.createGraphFromMatrix(fileContent);
//    Node *pNodeStartB = graph.findMarkedNode("b");
//    Node *pNodeEndB = graph.findMarkedNode("B");
//    vector<Node *> pathB = graph.calcShortestPathDijkstra(*pNodeStartB, *pNodeEndB);
//    EXPECT_EQ(106, pathB.size());
//    EXPECT_EQ("(21,51)", pathB[0]->toString());
//    EXPECT_EQ("(43,82)", pathB[105]->toString());
//}
//
//TEST(Graph, ShouldReturnShortestPathForCFromInputHelper) {
//    InputHelper inputHelper = InputHelper();
//    vector<vector<string>> fileContent = inputHelper.readFile("../printedCircuitBoard.txt");
//    Graph graph = Graph();
//    graph.createGraphFromMatrix(fileContent);
//    Node *pNodeStartC = graph.findMarkedNode("c");
//    Node *pNodeEndC = graph.findMarkedNode("C");
//    vector<Node *> pathC = graph.calcShortestPathDijkstra(*pNodeStartC, *pNodeEndC);
//    EXPECT_EQ(127, pathC.size());
//    EXPECT_EQ("(20,45)", pathC[0]->toString());
//    EXPECT_EQ("(46,99)", pathC[126]->toString());
//}
//
//TEST(Graph, ShouldReturnShortestPathForAllPortsFromInputHelper) {
//    InputHelper inputHelper = InputHelper();
//    vector<vector<string>> fileContent = inputHelper.readFile("../printedCircuitBoard.txt");
//    Graph graph = Graph();
//    graph.createGraphFromMatrix(fileContent);
//    Node *pNodeStartA = graph.findMarkedNode("a");
//    Node *pNodeEndA = graph.findMarkedNode("A");
//    vector<Node *> pathA = graph.calcShortestPathDijkstra(*pNodeStartA, *pNodeEndA);
//    graph.updateGraph(pathA);
//    vector<vector<string>> resultWithA = graph.markShortestPathInMatrix(fileContent, pathA, ".");
//
//    Node *pNodeStartB = graph.findMarkedNode("b");
//    Node *pNodeEndB = graph.findMarkedNode("B");
//    vector<Node *> pathB = graph.calcShortestPathDijkstra(*pNodeStartB, *pNodeEndB);
//    graph.updateGraph(pathB);
//    vector<vector<string>> resultWithAAndB = graph.markShortestPathInMatrix(fileContent, pathB, "+");
//    inputHelper.printMatrix(graph.getMatrix());
//
//    Node *pNodeStartC = graph.findMarkedNode("c");
//    Node *pNodeEndC = graph.findMarkedNode("C");
//    vector<Node *> pathC = graph.calcShortestPathDijkstra(*pNodeStartC, *pNodeEndC);
//    graph.updateGraph(pathC);
//    vector<vector<string>> resultWithAAndBAndC = graph.markShortestPathInMatrix(fileContent, pathC, "*");
//    inputHelper.printMatrix(graph.getMatrix());
//
//    EXPECT_EQ(1, pathA.size());
//    EXPECT_EQ("(27,4)", pathA[0]->toString());
//
//    EXPECT_EQ(106, pathB.size());
//    EXPECT_EQ("(21,51)", pathB[0]->toString());
//    EXPECT_EQ("(43,82)", pathB[105]->toString());
//
//    EXPECT_EQ(127, pathC.size());
//    EXPECT_EQ("(20,45)", pathC[0]->toString());
//    EXPECT_EQ("(46,99)", pathC[126]->toString());
//}
