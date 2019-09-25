#include "BellmanFord.h"
#include <limits>
#include <stack>
#include <iostream>

BellmanFord::BellmanFord(WeightedEdgeDigraph& g, int s)
{
	distTo.resize(g.GetV(), numeric_limits<double>::max());
	edgeTo.resize(g.GetV(), -1);

	distTo[s] = 0.0;
	for (int i = 0; i < g.GetV(); i++)
	{
		for (size_t v = 0; v < g.GetV(); v++)
		{
			for (auto e : g.adj(v))
				relaxation(g, e);
		}
	}

	for (size_t v = 0; v < g.GetV(); v++)
	{
		for (auto e : g.adj(v))
		{
			int v = e.either();
			int w = e.other(v);

			if (distTo[w] > distTo[v] + e.Weight())
			{
				bHasNegCycle = true;
				return;
			}
		}
	}
}

void BellmanFord::relaxation(WeightedEdgeDigraph& graph, WeightedEdge& edge)
{
	int v = edge.either();
	int w = edge.other(v);
	double newDistance = distTo[v] + edge.Weight();
	if (distTo[w] > newDistance)
	{
		distTo[w] = newDistance;
		edgeTo[w] = v;		
	}
}


void BellmanFord::PrintPathTo(int dest)
{
	stack<int> stackResult;
	cout << "Min distance:" << distTo[dest] << endl;

	for (int b = dest; b != -1; b = edgeTo[b])
	{
		stackResult.push(b);
	}

	while (!stackResult.empty())
	{
		cout << stackResult.top() << "->";
		stackResult.pop();
	}
	cout << endl;
}
