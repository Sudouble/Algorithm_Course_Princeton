#include "TopologicalSort.h"

TopologicalSort::TopologicalSort(DepthFirstOrder dfo)
{
	stack<int> r_o = dfo.ReverseOrder();
	while (!r_o.empty())
	{
		vecTopologicalSort.push_back(r_o.top());
		r_o.pop();
	}
}

vector<int> TopologicalSort::GetVec()
{
	return vecTopologicalSort;
}

