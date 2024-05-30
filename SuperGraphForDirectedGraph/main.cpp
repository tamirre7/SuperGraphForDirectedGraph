#include "graph.h"
#include "supergraph.h"

using namespace std;


/**
 * Main function to read a directed graph from input and construct its acyclic supergraph.
 *
 * This program reads a directed graph from input and constructs its acyclic supergraph.
 *
 * Input format:
 *  - The first line contains an integer n, the number of nodes in the graph.
 *  - The second line contains an integer m, the number of edges in the graph.
 *  - Each of the following m lines contains two integers u and v, representing an edge from node u to node v.
 *
 * Output format:
 *  - The output consists of two integers: the number of nodes and the number of edges in the acyclic supergraph.
 *  - The program may output 'invalid input' if the input graph violates the constraints.
 *
 * Usage:
 *  - Enter the graph data as described above. The program will output the number of nodes and edges in the acyclic supergraph.
 *
 */




int main()
{
    int numNodes, numEdges;
    Graph graph;
    
     cin >> numNodes >> numEdges;

    graph.MakeEmptyGraph(numNodes);
    graph.SetNumEdges(numEdges);

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.AddEdge(u, v);
    }

    SuperGraph superGraph(graph);
    superGraph.PrintSuperGraph();

    return 0;
}