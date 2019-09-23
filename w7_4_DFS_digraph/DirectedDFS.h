#pragma once

#include "Digraph.h"

class DirectedDFS
{
public:
	DirectedDFS(Digraph &digraph_, int v);
	
	bool IsMark(int v);
	int GetCount();
	vector<int> pathTo(int v);

private:
	void DFS(int v);	

private:
	Digraph digraph;
	int s;

	vector<int> edgeTo;
	vector<int> marked;
	int count;
};

