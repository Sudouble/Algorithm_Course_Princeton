#include "PrimEager.h"
#include <limits>
#include <algorithm>
#include <iostream>

PrimEager::PrimEager(WeightedEdgeGraph& graph)
{
	edgeTo.resize(graph.GetV());
	distTo.resize(graph.GetV(), (numeric_limits<double>::max)());
	marked.resize(graph.GetV());

	distTo[0] = 0.0;
	vecQueue[0] = 0.0;
	while (!vecQueue.empty())
	{
		map<int, double>::iterator itt = MinIt();
		int v = itt->first;
		vecQueue.erase(itt);

		eager(graph, v);
	}
}

void PrimEager::eager(WeightedEdgeGraph& graph, int v)
{
	marked[v] = true;

	for (auto edge : graph.adj(v))
	{
		int w = edge.other(v);
		if (marked[w])
			continue;
		else if (edge.Weight() < distTo[w])
		{
			distTo[w] = edge.Weight();
			edgeTo[w] = edge;

			if (vecQueue.find(w) == vecQueue.end())
				vecQueue[w] = distTo[w];
			else
				vecQueue[w] = distTo[w];
		}
	}
}

void PrimEager::Print()
{
	cout << "Search Result (Eager):" << endl;
	for (size_t i = 1; i < edgeTo.size(); i++)
	{
		cout << edgeTo[i].toString() << endl;
	}
}

map<int, double>::iterator PrimEager::MinIt()
{
	map<int, double>::iterator itMin = vecQueue.begin();
	
	map<int, double>::iterator it = vecQueue.begin();
	it++;
	for (; it != vecQueue.end(); it++)
	{
		if (itMin->second > it->second)
		{
			itMin = it;
		}
	}
	return itMin;
}
