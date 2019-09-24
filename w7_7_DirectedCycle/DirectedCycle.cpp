#include "DirectedCycle.h"

DirectedCycle::DirectedCycle(Digraph &graph, int s)
{
	this->graph = graph;

	marked.resize(graph.GetV(), false);

	DFS(s);
}

void DirectedCycle::DFS(int v)
{
	marked[v] = true;

	for (int w : graph.adj(v))
	{
		if (inStack.size() > 0)
			return;

		if (!marked[w])
		{
			DFS(w);
		}
		else
		{
			inStack.push(w);
		}
	}
}

bool DirectedCycle::HasCycle()
{
	return inStack.size() > 0;
}
