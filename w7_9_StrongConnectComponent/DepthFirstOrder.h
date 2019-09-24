#pragma once
#include "Digraph.h"
#include <queue>
#include <stack>

class DepthFirstOrder
{
public:	
	DepthFirstOrder(Digraph& graph);
	queue<int> PreOrder();
	queue<int> PostOrder();
	stack<int> ReverseOrder();

	void DFS(int s);

private:
	Digraph graph;

	vector<bool> vecMarked;
	
	queue<int> vecPreOrder;
	queue<int> vecPostOrder;
	stack<int> stackReversePostOrder;
};

