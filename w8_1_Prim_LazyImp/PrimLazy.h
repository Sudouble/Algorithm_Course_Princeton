#pragma once
#include "WeightedEdgeGraph.h"

class PrimLazy
{
public:
	PrimLazy();
	PrimLazy(WeightedEdgeGraph& graph);

	int GetMin();
	void Append(int v);
	void Remove(int v);
	void Print();

private:
	bool Contains(const vector<WeightedEdge> &vecEdges, WeightedEdge &edge);

private:
	WeightedEdgeGraph graph;

	vector<WeightedEdge> vecEdges;

	vector<WeightedEdge> vecResult;
	vector<int> vecResultPool;
};

