#pragma once

#include "Digraph.h"
#include <queue>

class DirectedBFS
{
public:
	DirectedBFS(Digraph &digraph_, int v);
	
	bool IsMark(int v);
	int GetCount();
	vector<int> pathTo(int v);
	int DistTo(int v);

private:
	void BFS(int v);	

private:
	Digraph digraph;
	int s;

	vector<int> edgeTo;
	vector<int> marked;
	vector<int> distTo;
	int count;
};

