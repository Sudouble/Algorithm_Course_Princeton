#include "Kruskal.h"

#include <algorithm>
#include <iostream>

Kruskal::Kruskal(WeightedEdgeGraph& graph)
{
	marked.resize(graph.GetV());

	vector<WeightedEdge> vecEdges = graph.edges();
	std::sort(vecEdges.begin(), vecEdges.end());
	
	for (size_t i = 0; i < vecEdges.size(); i++)
	{
		if (vecResult.size() >= graph.GetV() - 1)
			break;

		scan(graph, vecEdges[i]);
	}
}

void Kruskal::scan(WeightedEdgeGraph& graph, WeightedEdge& edge)
{
	int v = edge.either();
	int w = edge.other(v);

	if (marked[v] && marked[w])
		return;

	marked[v] = true;
	marked[w] = true;

	vecResult.push_back(edge);
}

void Kruskal::Print()
{
	cout << "Search Result (Eager):" << endl;
	for (size_t i = 0; i < vecResult.size(); i++)
	{
		cout << vecResult[i].toString() << endl;
	}
}
