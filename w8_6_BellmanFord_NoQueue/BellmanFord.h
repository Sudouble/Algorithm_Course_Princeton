#pragma once

#include "WeightedEdgeDigraph.h"

class BellmanFord
{
public:
	BellmanFord(WeightedEdgeDigraph& g, int s);

	bool hasResult() {
		return bHasNegCycle;
	}
	void PrintPathTo(int dest);
private:
	void relaxation(WeightedEdgeDigraph& graph, WeightedEdge& edge);	

private:
	vector<int> edgeTo;
	vector<double> distTo;

	bool bHasNegCycle;
};

