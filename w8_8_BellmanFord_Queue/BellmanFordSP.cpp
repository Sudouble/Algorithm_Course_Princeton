#include "BellmanFordSP.h"
#include <limits>
#include "EdgeWeightedDirectedCycle.h"
#include <iostream>

BellmanFordSP::BellmanFordSP(WeightedEdgeDigraph& g, int s)
{
	distTo.resize(g.GetV(), numeric_limits<double>::max());
	edgeTo.resize(g.GetV());
	onQueue.resize(g.GetV());

	distTo[s] = 0.0;
	queueQ.push(s);
	onQueue[s] = true;
	while (!queueQ.empty() && !HasNegativeCycle())
	{
		int ww = queueQ.front();
		queueQ.pop();
		onQueue[ww] = false;

		relax(g, ww);
	}
}

void BellmanFordSP::relax(WeightedEdgeDigraph& g, int v)
{
	for (auto e : g.adj(v))
	{
		int w = e.other(v);
		if (distTo[w] > distTo[v] + e.Weight())
		{
			distTo[w] = distTo[v] + e.Weight();
			edgeTo[w] = e;

			if (!onQueue[w]) {
				queueQ.push(w);
				onQueue[w] = true;
			}
		}

		if (++cost % g.GetV() == 0)
		{
			findNegtiveCycle();
			if (HasNegativeCycle())
			{
				return;
			}
		}
	}
}

bool BellmanFordSP::HasNegativeCycle()
{
	return cycle.size() > 0;
}

void BellmanFordSP::findNegtiveCycle()
{
	int V = edgeTo.size();
	WeightedEdgeDigraph spt(V);
	for (int v = 0; v < V; v++)
	{
		WeightedEdge e = edgeTo[v];
		int vv = e.either();
		int w = e.other(vv);
		if (vv != -1 && w != -1)
		{
			spt.addEdge(e);
		}
	}
	EdgeWeightedDirectedCycle finder(spt);
	cycle = finder.Cycle();
}

vector<WeightedEdge> BellmanFordSP::NegtiveCycle()
{
	return cycle;
}

void BellmanFordSP::PrintPathTo(int dest)
{
	stack<int> stackResult;
	cout << "Min distance:" << distTo[dest] << endl;

	for (int b = dest; b != -1; b = edgeTo[b].either())
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

