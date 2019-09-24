#include "TS_Queue.h"

TS_Queue::TS_Queue(Digraph& graph)
{
	this->graph = graph;

	vecResult.clear();
	DFS();
}

void TS_Queue::DFS()
{
	queue<int> queueIN;
	for (size_t v = 0; v < graph.GetV(); v++)
	{
		if (graph.InDegree[v] == 0)
		{
			queueIN.push(v);
		}
	}

	while (!queueIN.empty())
	{
		int v = queueIN.front();
		queueIN.pop();

		vecResult.push_back(v);

		for (int w : graph.adj(v))
		{
			if (graph.InDegree[w] > 0)
			{
				graph.InDegree[w]--;
			}
			
			if (graph.InDegree[w] == 0)
			{
				queueIN.push(w);
			}
		}
	}
}

vector<int> TS_Queue::GetResult()
{
	return vecResult;
}
