#pragma once
#include "UndirectedGraph.h"
#include <vector>
using namespace std;

class CC
{
public:
	CC(UnDirectedGraph &graph);	

	bool connect(int v, int w);	
	int size(int v);

private:
	void DFS(int v);
	void validVertex(int v);

private:
	UnDirectedGraph graph;
	
	vector<bool> marked;
	vector<int> vecCC;
	vector<int> vecSize;
	int nCount;
};

