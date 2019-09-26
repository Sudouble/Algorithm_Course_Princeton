#pragma once
#include "WeightedEdgeDigraph.h"
#include <stack>

class EdgeWeightedDirectedCycle
{
public:
	EdgeWeightedDirectedCycle(WeightedEdgeDigraph& g);

	void dfs(WeightedEdgeDigraph& g, int v);

	bool hasCycle();
	vector<WeightedEdge> Cycle();


private:
	vector<bool> marked;
	vector<WeightedEdge> edgeTo;
	vector<bool> onStack;
	
	vector<WeightedEdge> cycle;
};

