#include "supergraph.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Color states for DFS
enum { WHITE, GRAY, BLACK };

// Helper function for the first DFS to fill the finish stack
void SuperGraph::DFSFillOrder(const Graph& graph, int v, vector<int>& color, stack<int>& finishStack) const {
    color[v] = GRAY;
    for (int neighbor : graph.GetAdjList(v)) {
        if (color[neighbor] == WHITE) {
            DFSFillOrder(graph, neighbor, color, finishStack);
        }
    }
    color[v] = BLACK;
    finishStack.push(v);
}

// Helper function for the second DFS to explore and mark SCCs
void SuperGraph::DFSExploreSCC(const Graph& graph, int v, vector<int>& color, vector<int>& scc, int sccIndex, vector<int>& root) {
    color[v] = GRAY;
    scc[v] = sccIndex;

    // Update the root node of the current SCC
    if (root[v] == 0 || scc[root[v]] > sccIndex) {
        root[v] = v;
    }

    for (int neighbor : graph.GetAdjList(v)) {
        if (color[neighbor] == WHITE) {
            DFSExploreSCC(graph, neighbor, color, scc, sccIndex, root);
        }
        else if (color[neighbor] == BLACK && scc[neighbor] != scc[v]) {
            // Check if the last edge in the adjacency list of the current node in the supergraph is to the same SCC
            const list<int>& superAdjList = superGraph.GetAdjList(scc[v]);
            if (superAdjList.empty() || superAdjList.back() != scc[neighbor]) 
            {
                superGraph.AddEdge(scc[v], scc[neighbor]);
                superGraph.IncrementEdgeCount();  // Increment the edge count each time an edge is added
            }
        }
    }
    color[v] = BLACK;
}

SuperGraph::SuperGraph(const Graph& original) {
    int numNodes = original.GetNumNodes();
    vector<int> color(numNodes + 1, WHITE); // numNodes + 1 for 1-indexing
    vector<int> root(numNodes + 1, 0); // numNodes + 1 for 1-indexing
    stack<int> finishStack;

    // First DFS to fill the finish stack
    for (int i = 1; i <= numNodes; ++i) { // Start from 1
        if (color[i] == WHITE) {
            DFSFillOrder(original, i, color, finishStack);
        }
    }

    // Get the transpose of the graph
    Graph transposed = original.Transpose();

    // Second DFS on the transposed graph to find SCCs
    fill(color.begin(), color.end(), WHITE);
    vector<int> scc(numNodes + 1, -1); // numNodes + 1 for 1-indexing
    int sccIndex = 0;

    // Create the super graph with the maximum possible number of nodes (i.e., numNodes)
    superGraph.MakeEmptyGraph(numNodes);

    while (!finishStack.empty()) {
        int v = finishStack.top();
        finishStack.pop();

        if (color[v] == WHITE) {
            DFSExploreSCC(transposed, v, color, scc, sccIndex, root);
            ++sccIndex;
        }
    }

    // Update the number of nodes in the super graph to the actual number of SCCs
    superGraph.SetNumNodes(sccIndex);
}

// Prints the number of nodes and edges in the SuperGraph.
void SuperGraph::PrintSuperGraph() const {
    cout << superGraph.GetNumNodes() << " " << superGraph.GetNumEdges() << endl;
}
