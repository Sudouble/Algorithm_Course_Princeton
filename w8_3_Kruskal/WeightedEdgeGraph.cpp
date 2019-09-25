#include "WeightedEdgeGraph.h"

WeightedEdgeGraph::WeightedEdgeGraph(int V)
{
	this->V = V;

	vecAdj.resize(V);
}

int WeightedEdgeGraph::GetV()
{
	return V;
}

int WeightedEdgeGraph::GetE()
{
	return E;
}

vector<WeightedEdge> WeightedEdgeGraph::adj(int v)
{
	CheckValidate(v);

	return vecAdj[v];
}

void WeightedEdgeGraph::addEdge(WeightedEdge edge)
{
	int v = edge.either();
	int w = edge.other(v);
	CheckValidate(v);
	CheckValidate(w);

	E++;

	vecAdj[v].push_back(edge);
	vecAdj[w].push_back(edge);

	vecEdges.push_back(edge);
}

vector<WeightedEdge> WeightedEdgeGraph::edges()
{
	return vecEdges;
}

void WeightedEdgeGraph::CheckValidate(int v)
{
	if (v < 0 || v > V)
	{
		throw "Invalid v :" + to_string(v);
	}
}