#include "CC.h"

CC::CC(UnDirectedGraph& graph)
{
	this->graph = graph;

	vecCC.resize(graph.GetV(), -1);
	marked.resize(graph.GetV(), false);
	vecSize.resize(graph.GetV(), 0);

	nCount = 0;

	for (int v = 0; v < graph.GetV(); v++)
	{
		if (!marked[v])
		{
			DFS(v);
			nCount++;
		}
	}
}

void CC::DFS(int v)
{
	marked[v] = true;

	vecCC[v] = nCount;
	vecSize[nCount]++;

	for (int w : graph.adj(v))
	{
		if (!marked[w])
		{
			DFS(w);
		}
	}
}

bool CC::connect(int v, int w)
{
	validVertex(v);
	validVertex(w);

	return vecCC[v] == vecCC[w];
}

void CC::validVertex(int v)
{
	if (v < 0 || v > graph.GetV())
	{
		throw "Invalid vertex";
	}
}

int CC::size(int v)
{
	return vecSize[vecCC[v]];
}

