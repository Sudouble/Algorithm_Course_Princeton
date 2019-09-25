#include "WeightedEdgeDigraph.h"

WeightedEdgeDigraph::WeightedEdgeDigraph(int V)
{
	this->V = V;

	vecAdj.resize(V);
}

int WeightedEdgeDigraph::GetV()
{
	return V;
}

int WeightedEdgeDigraph::GetE()
{
	return E;
}

vector<WeightedEdge> WeightedEdgeDigraph::adj(int v)
{
	CheckValidate(v);

	return vecAdj[v];
}

void WeightedEdgeDigraph::addEdge(WeightedEdge edge)
{
	int v = edge.either();
	int w = edge.other(v);
	CheckValidate(v);
	CheckValidate(w);

	E++;

	vecAdj[v].push_back(edge);
	vecAdj[w].push_back(edge);
}

void WeightedEdgeDigraph::CheckValidate(int v)
{
	if (v < 0 || v > V)
	{
		throw "Invalid v :" + to_string(v);
	}
}