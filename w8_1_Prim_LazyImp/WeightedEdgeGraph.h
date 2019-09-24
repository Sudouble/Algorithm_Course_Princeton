#pragma once
#include "WeightedEdge.h"
#include <vector>
using namespace std;

class WeightedEdgeGraph
{
public:
	WeightedEdgeGraph() {
		V = 0;
		E = 0;
	}
	WeightedEdgeGraph(int V);
	int GetV();
	int GetE();

	vector<WeightedEdge> adj(int v);
	void addEdge(WeightedEdge edge);
	
	void CheckValidate(int v);

private:
	int V;
	int E;

	vector<vector<WeightedEdge> > vecAdj;
};

