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

	vector<int> result = graph.adj(s);
	for (int j = result.size()-1; j >= 0 ; j--)
	{
		int v = result[j];
		if (!vecMarked[v])
		{			
			DFS(v);			
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

