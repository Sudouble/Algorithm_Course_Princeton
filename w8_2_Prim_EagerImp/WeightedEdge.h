#pragma once

#include <string>
using std::string;

class WeightedEdge
{
public:
	WeightedEdge() {}
	WeightedEdge(int v, int w, double weight);

	double Weight();
	int either();
	int other(int v);
	bool operator<(const WeightedEdge& that);
	bool operator==(const WeightedEdge& that);
	string toString();

private:
	int v;
	int w;
	double weight;
};

