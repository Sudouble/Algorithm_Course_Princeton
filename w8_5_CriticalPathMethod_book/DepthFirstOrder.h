#pragma once
#include "WeightedEdgeDigraph.h"
#include <queue>
#include <stack>

class DepthFirstOrder
{
public:	
	DepthFirstOrder(WeightedEdgeDigraph& graph);
	queue<int> PreOrder();
	queue<int> PostOrder();
	stack<int> ReverseOrder();

	void DFS(int s);

private:
	WeightedEdgeDigraph graph;

	vector<bool> vecMarked;
	
	queue<int> vecPreOrder;
	queue<int> vecPostOrder;
	stack<int> stackReversePostOrder;
};

