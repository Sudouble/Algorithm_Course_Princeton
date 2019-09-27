#include "FlowNetwork.h"

FlowNetwork::FlowNetwork(int V)
{
	vecAdj.resize(V);

	this->V = V;
	E = 0;
}

int FlowNetwork::GetV()
{
	return V;
}

int FlowNetwork::GetE()
{
	return E;
}

void FlowNetwork::addEdge(FlowEdge edge)
{
	int v = edge.from();
	int w = edge.to();
	if (v < 0 || v >= V)
		throw "Invalid Input";
	if (w < 0 || w >= V)
		throw "Invalid Input";

	vecAdj[v].push_back(edge);
	vecAdj[w].push_back(edge);

	vecEdge.push_back(edge);

	E++;
}

vector<FlowEdge> FlowNetwork::adj(int v)
{
	if (v < 0 || v >= V)
		throw "Invalid Input";

	return vecAdj[v];
}

vector<FlowEdge> FlowNetwork::edges()
{
	return vecEdge;
}

string FlowNetwork::toString()
{
	return string();
}
