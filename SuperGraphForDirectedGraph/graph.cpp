#include "graph.h"

using namespace std;


// Set the number of nodes in the graph.
void Graph::SetNumNodes(int n)
{
    if (n < 0)
    {
        throw GraphError("invalid input");
    }
    numNodes = n;
}


// Set the number of edges in the graph.
void Graph::SetNumEdges(int m)
{
    if (m < 0)
    {
        throw GraphError("invalid input");
    }
    numEdges = m;
}

// Create an empty graph with n nodes.
void Graph::MakeEmptyGraph(int n)
{
    if (n < 0)
    {
        cout << "invalid input";
        exit(1);
    }

    numNodes = n;
    numEdges = 0;
    adjacencyList.clear();
    adjacencyList.resize(n + 1);
}

// Add an edge from node u to node v.
void Graph::AddEdge(int u, int v)
{
    if (u < 0 || u > numNodes || v < 0 || v > numNodes)
    {
        cout << "invalid input";
        exit(1);
    }
       

    if (u == v)
    {
        cout << "invalid input";
        exit(1);
    }

        adjacencyList[u].push_back(v);
        
}

// Check if there is an edge between nodes u and v.
bool Graph::IsAdjacent(int u, int v) const
{

    if (u < 0 || u > numNodes || v < 0 || v > numNodes)
    {
        cout << "invalid input";
        exit(1);
    }    

    for (int neighbor : adjacencyList[u])  //searching the adjacencyList for v
        if (neighbor == v)
            return true;

    return false;
}

// Get the adjacency list of a node.
const std::list<int>& Graph::GetAdjList(int u) const
{
    if (u < 0 || u > numNodes)
        throw GraphError("Invalid node index."); // Throw a GraphError with the error message

    return adjacencyList[u];
}

// Remove the edge from node u to node v.
void Graph::RemoveEdge(int u, int v)
{
    if (u < 0 || u > numNodes || v < 0 || v > numNodes)
        throw GraphError("Invalid node index."); // Throw a GraphError with the error message

    adjacencyList[u].remove(v);
}

// Compute and return the transpose of the graph.
Graph Graph::Transpose() const
{
    Graph transposed;

    transposed.MakeEmptyGraph(numNodes);   // initializing the transposed graph
    transposed.SetNumEdges(numEdges);

    for (int u = 1; u < (numNodes + 1); ++u)  // for every node in the array
        for (int v : adjacencyList[u])  // for every edge of the node
            transposed.AddEdge(v, u);   //adding the transposed edge to the transposed graph

    return transposed;
}

// Increment the edge count
void Graph::IncrementEdgeCount()
{
    ++numEdges;
}