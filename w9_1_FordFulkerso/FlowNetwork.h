#pragma once

#include "FlowEdge.h"
#include <vector>

class FlowNetwork
{
public:
	FlowNetwork(int V);
	int GetV();
	int GetE();

	void addEdge(FlowEdge edge);
	vector<FlowEdge> adj(int v);
	vector<FlowEdge> edges();
	string toString();

private:
	int V;
	int E;
	vector<vector<FlowEdge> > vecAdj;
	vector<FlowEdge> vecEdge;
};

