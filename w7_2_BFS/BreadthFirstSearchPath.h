#pragma once
#include "UndirectedGraph.h"
#include <queue>
#include <stack>

class BreadthFirstSearchPath
{
public:
	BreadthFirstSearchPath(UnDirectedGraph &graph, int s);

	bool HasPathTo(int v);
	vector<int> pathTo(int v);

	void BFS(int v);

private:
	UnDirectedGraph graph;

	int source;
	vector<bool> marked;
	vector<int> edgeTo;

	queue<int> queueBFS;
};

