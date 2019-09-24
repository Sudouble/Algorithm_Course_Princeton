#pragma once

#include "Digraph.h"
#include <stack>

class DirectedCycle
{
public:
	DirectedCycle(Digraph &graph, int s);
	bool HasCycle();

private:
	void DFS(int v);	

private:
	Digraph graph;

	vector<bool> marked;
	stack<int> inStack;
};

