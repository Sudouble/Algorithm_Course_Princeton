#include "AcyclicLongestPath.h"
#include <limits>
#include "TopologicalSort.h"

AcyclicLongestPath::AcyclicLongestPath(WeightedEdgeDigraph& graph, int s)
{
	distTo.resize(graph.GetV(), -numeric_limits<double>::min());
	edgeTo.resize(graph.GetV(), -1);

	distTo[s] = 0.0;

	DepthFirstOrder dfo(graph);
	TopologicalSort topological(dfo);

	for (int v : topological.GetVec())
	{
		for (auto e : graph.adj(v))
		{
			relax(e);
		}
	}
}

bool AcyclicLongestPath::hasPathTo(int v)
{
	return false;
}

void AcyclicLongestPath::relax(WeightedEdge e)
{
	int v = e.from();
	int w = e.to();
	if (distTo[w] < distTo[v] + e.Weight())
	{
		distTo[w] = distTo[v] + e.Weight();
		edgeTo[w] = v;
	}
}
