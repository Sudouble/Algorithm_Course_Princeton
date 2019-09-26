#include "EdgeWeightedDirectedCycle.h"

EdgeWeightedDirectedCycle::EdgeWeightedDirectedCycle(WeightedEdgeDigraph& g)
{
	marked.resize(g.GetV());
	onStack.resize(g.GetV());
	edgeTo.resize(g.GetV());
	for (size_t v = 0; v < g.GetV(); v++)
	{
		if (!marked[v])
			dfs(g, v);
	}
}

void EdgeWeightedDirectedCycle::dfs(WeightedEdgeDigraph& g, int v)
{
	onStack[v] = true;
	marked[v] = true;

	for (WeightedEdge e : g.adj(v))
	{
		int w = e.other(v);
		if (cycle.size() > 0)
			return;
		if (!marked[w])
		{
			edgeTo[w] = e;
			dfs(g, w);
		}
		else if (onStack[w])
		{
			WeightedEdge f = e;

			while (f.either() != w)
			{
				cycle.push_back(f);
				f = edgeTo[f.either()];
			}
			cycle.push_back(f);
			return;
		}
	}
}

bool EdgeWeightedDirectedCycle::hasCycle()
{
	return cycle.size() > 0;
}

vector<WeightedEdge> EdgeWeightedDirectedCycle::Cycle()
{
	return cycle;
}
