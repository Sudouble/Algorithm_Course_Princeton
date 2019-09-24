#include "SCC.h"

SCC::SCC(Digraph& graph)
{
	marked.resize(graph.GetV(), false);
	vecID.resize(graph.GetV(), 0);
	count = 0;

	this->graph = graph;

	// ============================================
	Digraph graphReverse = graph.reverse();
	DepthFirstOrder dfo(graphReverse);
	stack<int> stackResult = dfo.ReverseOrder();
	while (!stackResult.empty())
	{
		int v = stackResult.top();
		stackResult.pop();

		if (!marked[v])
		{
			DFS(v);
			count++;
		}
	}
}

bool SCC::IsSCC(int v, int w)
{
	return vecID[v] == vecID[w];
}

int SCC::GetCount()
{
	return count;
}

void SCC::DFS(int v)
{
	marked[v] = true;
	vecID[v] = count;

	for (int w : graph.adj(v))
	{
		if (!marked[w])
		{
			DFS(w);
		}
	}
}
