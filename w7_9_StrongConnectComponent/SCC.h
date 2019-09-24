#pragma once

#include "DepthFirstOrder.h"

class SCC
{
public:
	SCC(Digraph& graph);
	bool IsSCC(int v, int w);
	int GetCount();

private:
	void DFS(int v);

private:
	Digraph graph;

	vector<bool> marked;
	vector<int> vecID;
	int count;
};

