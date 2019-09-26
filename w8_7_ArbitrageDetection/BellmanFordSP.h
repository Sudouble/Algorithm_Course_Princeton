#pragma once

#include "WeightedEdgeDigraph.h"
#include <queue>
using namespace std;

class BellmanFordSP
{
public:
	BellmanFordSP(WeightedEdgeDigraph& g, int s);
	void relax(WeightedEdgeDigraph& g, int v);
	bool HasNegativeCycle();
	void findNegtiveCycle();

	vector<WeightedEdge> NegtiveCycle();
	void PrintPathTo(int dest);

private:
	vector<WeightedEdge> edgeTo;
	vector<double> distTo;
	vector<bool> onQueue;

	queue<int> queueQ;
	vector<WeightedEdge> cycle;

	int cost = 0;
};

