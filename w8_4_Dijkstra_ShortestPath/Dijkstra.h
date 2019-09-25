#pragma once

#include "WeightedEdgeDigraph.h"
class Store 
{
public:
	Store(int v_, double distance_)
	{
		v = v_;
		distance = distance_;
	}

	bool operator==(const Store& that)
	{
		return v == that.v;
	}

	bool operator<(const Store& that)
	{
		return distance < that.distance;
	}

public:
	int v;
	double distance;
};

class Dijkstra
{
public:
	Dijkstra(WeightedEdgeDigraph& graph, int s);

	void UpdateStore(int v, double distance_);
	void relaxation(WeightedEdgeDigraph& graph, WeightedEdge& edge);
	bool HasPathTo(int v);

	void PrintPathTo(int dest);

private:
	vector<int> edgeTo;
	vector<double> distTo;

	vector<Store> vecQueue;
	
	vector<bool> marked;
};


