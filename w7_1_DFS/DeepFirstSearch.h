#pragma once

#include "UndirectedGraph.h"

class DeepFirstSearch
{
private:
    /* data */
public:
	DeepFirstSearch() {
		count = 0;
	}
    DeepFirstSearch(UnDirectedGraph &graph, int s);
    ~DeepFirstSearch();

    int Count();

private:
    void dfs(UnDirectedGraph &graph, int v);
    bool IsMarked(int v);

private:
    UnDirectedGraph graph;
    vector<bool> marked;
    int count;
};
