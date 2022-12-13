#include "graph.h"
#include <iostream>
// #include "../data/Edge-StartNode-EndNode-Dist.csv"
void printTraversal(std::vector<int> traversal) {
    std::cout << "traversal from node " << traversal.at(0) << ": " << std::endl;
    for (int node_id: traversal) {
        std::cout << node_id << " ";
    }
    std::cout << std::endl;
}
void testSmall() {
    Graph g;
    for (int i = 0; i < 5; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(1,3,1);
    g.addEdge(3,4,1);
    g.printAdjLists();
    /**
     *    -x
     * x-x
     *    -x-x
     **/

    std::vector<int> traversal0 = g.BFS(0);
    printTraversal(traversal0);
}

void testFull() {
    // Need to initialize with filename
    Graph g2("./data/Edge-StartNode-EndNode-Dist.csv");
    g2.printAdjLists();
}
void testShortestPathSmall() {
    Graph g;
    for (int i = 0; i < 3; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);

    vector<int> path = g.Shortest_Path(1,2);
    std::cout << "shortest path from 1 to 2" << std::endl;
    for (int v: path) {
        std::cout << v << std::endl;
    }
}
void testBetweennessSmall() {
    Graph g;
    for (int i = 0; i < 3; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    vector<int> scores = g.Betweenness();
    int size = g.size();
    std::cout << "Betweenness Scores: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i << ": " << scores[i] << std::endl;
    }
}

void testShortEx1() {
    Graph g;
    for (int i = 0; i < 9; i++) {
        g.addNode(i);
    }
    //outer edges
    g.addEdge(0,1,4);
    g.addEdge(1,2,8);
    g.addEdge(2,3,7);
    g.addEdge(3,4,9);
    g.addEdge(0,7,8);
    g.addEdge(7,6,1);
    g.addEdge(6,5,2);
    g.addEdge(5,4,10);
    //inner edges
    g.addEdge(7,8,7);
    g.addEdge(7,1,11);
    g.addEdge(6,8,6);
    g.addEdge(8,2,2);
    g.addEdge(2,5,4);
    g.addEdge(5,3,14);
    g.Shortest_Path_Algo(4); //src node is gonna be this argument 

    g.printAdjLists();
    g.Print_A_Shortest_Path(7); //shortest path from src node to 5
    //https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg
}

int main() {

    //testSmall();
    // testFull();
    // testShortEx1();
    testShortestPathSmall();
    // testBetweennessSmall();

    return 0;
}