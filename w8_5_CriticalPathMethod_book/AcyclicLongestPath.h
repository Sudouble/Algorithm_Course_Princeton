#pragma once

#include "WeightedEdgeDigraph.h"

class AcyclicLongestPath
{
public:
	AcyclicLongestPath(WeightedEdgeDigraph& graph, int s);

	bool hasPathTo(int v);
	double DistTo(int v) {
		return distTo[v];
	}
private:
	void relax(WeightedEdge e);

private:
	vector<int> edgeTo;
	vector<double> distTo;
};

