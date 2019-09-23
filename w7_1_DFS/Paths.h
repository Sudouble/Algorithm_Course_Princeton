#pragma once
#include "UndirectedGraph.h"
#include <stack>

class Paths
{
public:
    Paths(UnDirectedGraph &graph, int s);
    ~Paths();

    bool HasPath(int w);
    vector<int> pathTo(int w);
	void DFS(int w);

private:
    int s;
	vector<bool> marked;
	vector<int> edgeTo;
	UnDirectedGraph graph;
};
