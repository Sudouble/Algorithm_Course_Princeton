#include "WeightedEdge.h"

WeightedEdge::WeightedEdge(int v, int w, double weight)
{
	this->v = v;
	this->w = w;
	this->weight = weight;
}

double WeightedEdge::Weight()
{
	return weight;
}

int WeightedEdge::either()
{
	return v;
}

int WeightedEdge::other(int vex)
{
	if (v == vex)
		return w;
	else
		return v;
}

bool WeightedEdge::operator<(const WeightedEdge& that)
{
	if (weight < that.weight)
		return true;
	else
		return false;
}

bool WeightedEdge::operator==(const WeightedEdge& that)
{
	if ((v == that.v && w == that.w) 
		|| (v == that.w && w == that.v))
	{
		return true;
	}
	return false;
}

string WeightedEdge::toString()
{
	string tmp;
	tmp += std::to_string(v) + "->"
		+ std::to_string(w) + " "
		+ std::to_string(weight);
	return tmp;
}
