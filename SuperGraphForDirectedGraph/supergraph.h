#ifndef SUPERGRAPH_H
#define SUPERGRAPH_H

#include <stack>
#include "graph.h"

using namespace std;

class SuperGraph
{
private:
    Graph superGraph;

public:
    // Constructor that builds the SuperGraph from an original Graph
    SuperGraph(const Graph& original);

    void DFSFillOrder(const Graph& graph, int v, vector<int>& color, stack<int>& finishStack) const;

    void DFSExploreSCC(const Graph& graph, int v, vector<int>& color, vector<int>& scc, int sccIndex, vector<int>& root);

    // Method to print the SuperGraph
    void PrintSuperGraph() const;
};

#endif 

