#include "Dijkstra.h"

#include <limits>
#include <stack>
#include <iostream>
#include <algorithm>

Dijkstra::Dijkstra(WeightedEdgeDigraph& graph, int s)
{
	marked.resize(graph.GetV(), false);
	distTo.resize(graph.GetV(), numeric_limits<double>::max());
	edgeTo.resize(graph.GetV(), -1);

	distTo[s] = 0.0;	
	vecQueue.push_back(Store(s, distTo[s]));
	
	while (!vecQueue.empty())
	{
		std::sort(vecQueue.begin(), vecQueue.end());
		Store ss = vecQueue[0];
		marked[ss.v] = true;
		
		vecQueue.erase(vecQueue.begin());

		for (auto edge : graph.adj(ss.v))
		{
			relaxation(graph, edge);
		}
	}
}

void Dijkstra::relaxation(WeightedEdgeDigraph& graph, WeightedEdge &edge)
{	
	int v = edge.either();
	int w = edge.other(v);
	double newDistance = distTo[v] + edge.Weight();
	if (marked[w] == false && distTo[w] > newDistance)
	{
		distTo[w] = newDistance;
		edgeTo[w] = v;

		UpdateStore(w, distTo[w]);
	}
}

void Dijkstra::UpdateStore(int v, double distance_)
{
	auto pos = std::find(vecQueue.begin(), vecQueue.end(), Store(v, distance_));
	if (pos == vecQueue.end())
		vecQueue.push_back(Store(v, distance_));
	else
	{
		pos->v = v;
		pos->distance = distance_;
	}
}

bool Dijkstra::HasPathTo(int v)
{
	return marked[v];
}

void Dijkstra::PrintPathTo(int dest)
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
