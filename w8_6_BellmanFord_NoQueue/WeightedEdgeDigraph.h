#pragma once
#include "WeightedEdge.h"
#include <vector>
using namespace std;

class WeightedEdgeDigraph
{
public:
	WeightedEdgeDigraph() {
		V = 0;
		E = 0;
	}
	WeightedEdgeDigraph(int V);
	int GetV();
	int GetE();

	vector<WeightedEdge> adj(int v);
	void addEdge(WeightedEdge edge);
	vector<WeightedEdge> edges();
	
	void CheckValidate(int v);

private:
	int V;
	int E;

	vector<vector<WeightedEdge> > vecAdj;
	vector<WeightedEdge> vecEdges;
};

