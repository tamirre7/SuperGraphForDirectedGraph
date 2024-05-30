#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <iostream>
#include "grapherror.h"

class Graph
{
private:
    int numNodes;                       // Number of nodes in the graph
    int numEdges;                       // Number of edges in the graph
    std::vector<std::list<int>> adjacencyList;  // Adjacency list representation of the graph

public:

    // Getters
    int GetNumNodes() const { return numNodes; };            // Returns the number of nodes in the graph
    int GetNumEdges() const { return numEdges; };            // Returns the number of edges in the graph

    // Setters
    void SetNumNodes(int n);            // Sets the number of nodes in the graph
    void SetNumEdges(int m);            // Sets the number of edges in the graph

    // Graph operations
    void MakeEmptyGraph(int n);         // Creates an empty graph with n nodes
    bool IsAdjacent(int u, int v) const;    // Checks if there is an edge between nodes u and v
    const std::list<int>& GetAdjList(int u) const;  // Returns the adjacency list of node u
    void AddEdge(int u, int v);         // Adds an edge from node u to node v
    void RemoveEdge(int u, int v);      // Removes the edge from node u to node v
    Graph Transpose() const;            // Returns the transpose of the graph
    void IncrementEdgeCount();
};

#endif // GRAPH_H
