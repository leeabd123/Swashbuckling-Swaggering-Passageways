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
    cout << "1" << endl;
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
    cout << "2" << endl;

    Graph g2("./data/Edge-StartNode-EndNode-Dist.csv");
    g2.printAdjLists();
}
void testShortestPathSmall() {
    cout << "3" << endl;

    Graph g;
    for (int i = 0; i < 3; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.set_start_end(1,2);
    g.printAdjLists();
    g.Shortest_Path_Algo();
    g.Print_A_Shortest_Path();

    vector<int> path = g.A_Short_Path_Src_to_End();
    std::cout << "shortest path from 1 to 2" << std::endl;
    for (int v: path) {
        std::cout << v << std::endl;
    }
}
void testBetweennessSmall() {
    cout << "4" << endl;

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

    g.set_start_end(0, 4);
    g.printAdjLists();

    g.Shortest_Path_Algo(); 
    g.Print_A_Shortest_Path(); 
    g.Print_Short_Path_Dist_Src_to_End();
    g.Print_Short_Path_Distances();
    g.Print_Shortest_Paths();
    
    //https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg
    //^^ the graph I was using to test my code 
}


int main() {

    //testSmall();
    // testFull();
    // testShortEx1();
    testShortestPathSmall();
    // testBetweennessSmall();

    return 0;
}