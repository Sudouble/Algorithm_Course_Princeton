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
	InDegree.resize(V, 0);
}

void Digraph::addEdge(Edge edge)
{
	CheckValidate(edge.start);
	CheckValidate(edge.end);

	vecAdj[edge.start].push_back(edge.end);
	nEdge++;
	InDegree[edge.end]++;
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

void Digraph::CheckValidate(int v)
{
	if (v < 0 || v > vecAdj.size())
	{
		throw "Invalid v value.";
	}
}

