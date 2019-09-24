#include "PrimLazy.h"
#include <algorithm>
#include <iostream>

PrimLazy::PrimLazy()
{

}

PrimLazy::PrimLazy(WeightedEdgeGraph& graph)
{
	this->graph = graph;

	vecEdges.clear();

	Append(0);	
}

int PrimLazy::GetMin()
{
	WeightedEdge edge = vecEdges[0];
	vecEdges.erase(vecEdges.begin());

	vecResult.push_back(edge);

	int v = edge.either();
	auto result = std::find(vecResultPool.begin(), vecResultPool.end(), v);
	if (result == vecResultPool.end())
	{
		return v;
	}
	else
	{
		return edge.other(v);
	}
}

void PrimLazy::Append(int v)
{
	vecResultPool.push_back(v);
	if (vecResultPool.size() == graph.GetV())
		return;	

	for (WeightedEdge edge : graph.adj(v))
	{
		int ww = edge.other(v);
		auto result = std::find(vecResultPool.begin(), vecResultPool.end(), ww);
		if (result != vecResultPool.end())
			continue;

		if (!Contains(vecEdges, edge))
			vecEdges.push_back(edge);
	}
	std::sort(vecEdges.begin(), vecEdges.end());
	
	int min = GetMin();
	Remove(min);

	Append(min);
}

void PrimLazy::Remove(int v)
{
	for (int i = vecEdges.size() - 1; i >= 0 ; i--)
	{
		WeightedEdge edge = vecEdges[i];
		int v1 = edge.either();
		if (v1 == v || edge.other(v1) == v)
		{
			for (size_t j = 0; j < vecResultPool.size(); j++)
			{
				WeightedEdge edge1(v, vecResultPool[j], 0.0);
				if (Contains(vecEdges, edge1))
				{
					vecEdges.erase(vecEdges.begin() + i);
					break;
				}
			}
		}
	}
}

bool PrimLazy::Contains(const vector<WeightedEdge>& vecEdges, 
						WeightedEdge& edge)
{
	for (size_t i = 0; i < vecEdges.size(); i++)
	{
		if (edge == vecEdges[i])
		{
			return true;
		}
	}
	return false;
}

void PrimLazy::Print()
{
	cout << "Search Result (mine):" << endl;
	for (size_t i = 0; i < vecResult.size(); i++)
	{
		std::cout << vecResult[i].toString() << endl;
	}
}
