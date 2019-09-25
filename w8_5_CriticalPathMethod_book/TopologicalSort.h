#pragma once

#include "DepthFirstOrder.h"

class TopologicalSort
{
public:
	TopologicalSort(DepthFirstOrder dfo);

	vector<int> GetVec();

private:
	vector<int> vecTopologicalSort;
};

