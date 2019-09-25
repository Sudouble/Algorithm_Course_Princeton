#pragma once

#include "WeightedEdgeGraph.h"

class Kruskal
{
public:
	Kruskal(WeightedEdgeGraph& graph);

	void scan(WeightedEdgeGraph& graph, WeightedEdge& edge);
	void Print();

private:	
	vector<WeightedEdge> vecResult;

	vector<bool> marked;
};

