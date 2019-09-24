#pragma once

#include "WeightedEdgeGraph.h"
#include <map>

class PrimEager
{
public:
	PrimEager(WeightedEdgeGraph& graph);

	void eager(WeightedEdgeGraph& graph, int s);

	void Print();

private:
	map<int, double>::iterator MinIt();

private:
	vector<WeightedEdge> edgeTo;
	vector<double> distTo;
	vector<bool> marked;

	map<int, double> vecQueue;
};

