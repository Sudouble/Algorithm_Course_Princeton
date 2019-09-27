#pragma once

#include "FlowNetwork.h"

class FordFulkerson
{
public:
	FordFulkerson(FlowNetwork& g, int s, int t);
	double Value();

	bool inCut(int v);
	void validate(int v);

	bool hasAugmentingPath(FlowNetwork& g, int s, int t);
	double excess(FlowNetwork& g, int v);
	bool isFeasible(FlowNetwork& g, int s, int t);
	bool check(FlowNetwork& g, int s, int t);

private:
	double FLOATING_POINT_SPSILON = 1E-11;
	int V;
	vector<bool> marked;
	vector<FlowEdge*> edgeTo;
	double value;
};

