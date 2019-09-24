#include "Digraph.h"


Edge::Edge()
{
}

Edge::~Edge()
{
}

Digraph::Digraph(int V)
{
	nEdge = 0;

	vecAdj.resize(V);
}

void Digraph::addEdge(Edge edge)
{
	CheckValidate(edge.start);
	CheckValidate(edge.end);

	vecAdj[edge.start].push_back(edge.end);
	nEdge++;
}

vector<int> Digraph::adj(int v)
{
	CheckValidate(v);
	return vecAdj[v];
}

int Digraph::OutDegree(int v)
{
	CheckValidate(v);
	return vecAdj[v].size();
}

int Digraph::GetE()
{
	return nEdge;
}

int Digraph::GetV()
{
	return vecAdj.size();
}

Digraph Digraph::reverse()
{
	Digraph graph_(GetV());
	for (size_t v = 0; v < GetV(); v++)
	{
		for (int w : this->adj(v))
			graph_.addEdge(Edge(w, v));
	}
	return graph_;
}

void Digraph::CheckValidate(int v)
{
	if (v < 0 || v > vecAdj.size())
	{
		throw "Invalid v value.";
	}
}

