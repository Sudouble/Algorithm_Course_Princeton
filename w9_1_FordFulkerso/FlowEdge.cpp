#include "FlowEdge.h"

FlowEdge::FlowEdge(int v, int w, double capacity_)
{
	if (v < 0 || w < 0) 
		throw ("vertex index must be a non-negative integer");

	this->v = v;
	this->w = w;

	flow = 0.0;
	capacity = capacity_;
}

int FlowEdge::from()
{
	return v;
}

int FlowEdge::to()
{
	return w;
}

void FlowEdge::addResidualFlowTo(int vertex, double amount)
{
	if (amount < 0.0)
		throw ("Delta must be nonnegative");

	if (vertex == v)
		flow -= amount;	// backward edge
	else if (vertex == w)
		flow += amount; // forward edge
	else
		throw ("Invalid endpoint");

	if (flow > capacity)
		throw ("Flow exceeds capacity");
	if (flow < 0.0)
		throw ("Flow is negative");
}

int FlowEdge::other(int vertex)
{	
	if (vertex == v)
		return w;
	else if (vertex == w)
		return v;
	else
		throw ("invalid endpoint");
}

double FlowEdge::CapacityTo(int vertex)
{
	if (vertex == v)
		return flow;
	else if (vertex == w)
		return capacity - flow;
	else
		throw ("invalid endpoint");
}

string FlowEdge::toString()
{
	return to_string(v) + "->" + to_string(w)
			+ " " + to_string(flow)
			+ "/" + to_string(capacity);
}
