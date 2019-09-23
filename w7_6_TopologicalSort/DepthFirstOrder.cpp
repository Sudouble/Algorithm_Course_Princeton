#include "DepthFirstOrder.h"


DepthFirstOrder::DepthFirstOrder(Digraph& graph)
{
	this->graph = graph;

	vecMarked.resize(graph.GetV(), false);
	
	for (size_t v = 0; v < graph.GetV(); v++)
	{
		if (!vecMarked[v])
			DFS(v);
	}	
}

void DepthFirstOrder::DFS(int s)
{
	vecMarked[s] = true;
	vecPreOrder.push(s);

	for (int j : graph.adj(s))
	{
		if (!vecMarked[j])
		{			
			DFS(j);			
		}
	}

	vecPostOrder.push(s);
	stackReversePostOrder.push(s);
}

queue<int> DepthFirstOrder::PreOrder()
{
	return vecPreOrder;
}

queue<int> DepthFirstOrder::PostOrder()
{
	return vecPostOrder;
}

stack<int> DepthFirstOrder::ReverseOrder()
{
	return stackReversePostOrder;
}

