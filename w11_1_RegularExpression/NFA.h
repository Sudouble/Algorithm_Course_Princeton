#pragma once
#include "../w7_4_DFS_digraph/DirectedDFS.h"

class NFA
{
public:
	NFA(string regexp);
	bool recoginze(string txt);

private:
	string reg;
	int M;
	Digraph G;
	DirectedDFS *dfs;
};

