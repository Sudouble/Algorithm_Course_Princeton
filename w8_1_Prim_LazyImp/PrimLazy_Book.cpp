#include "PrimLazy_Book.h"
#include <algorithm>
#include <iostream>

PrimLazy_Book::PrimLazy_Book(WeightedEdgeGraph& graph)
{
	marked.resize(graph.GetV());

	for (size_t v = 0; v < graph.GetV(); v++)
	{
		if (!marked[v])
			prim(graph, v);
	}
}

void PrimLazy_Book::prim(WeightedEdgeGraph& graph, int s)
{
	scan(graph, s);
	while (!vecEdges.empty())
	{
		std::sort(vecEdges.begin(), vecEdges.end());
		WeightedEdge edge = vecEdges[0];
		vecEdges.erase(vecEdges.begin());

		int v = edge.either();
		int w = edge.other(v);
		if (marked[v] && marked[w])
			continue;

		nWeight += edge.Weight();
		mst.push_back(edge);

		if (!marked[v])
			scan(graph, v);
		if (!marked[w])
			scan(graph, w);
	}
}

void PrimLazy_Book::scan(WeightedEdgeGraph& graph, int v)
{
	marked[v] = true;
	for (auto edge : graph.adj(v))
	{
		if (!marked[edge.other(v)])
			vecEdges.push_back(edge);
	}
}

vector<WeightedEdge> PrimLazy_Book::edges()
{
	return mst;
}

double PrimLazy_Book::weight()
{
	return nWeight;
}

void PrimLazy_Book::Print()
{
	cout << "Search Result (book):" << endl;
	for (auto a : edges())
	{
		std::cout << a.toString() << endl;
	}
}
