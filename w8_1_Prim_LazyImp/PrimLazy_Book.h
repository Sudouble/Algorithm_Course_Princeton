#pragma once

#include "WeightedEdgeGraph.h"
#include <queue>

class PrimLazy_Book
{
public:
	PrimLazy_Book(WeightedEdgeGraph& graph);

	void prim(WeightedEdgeGraph& graph, int s);
	void scan(WeightedEdgeGraph& graph, int v);

	vector<WeightedEdge> edges();
	double weight();

	void Print();

private:
	vector<bool> marked;

	double nWeight;
	vector<WeightedEdge> vecEdges;
	vector<WeightedEdge> mst;
};

