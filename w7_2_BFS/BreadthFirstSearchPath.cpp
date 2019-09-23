#include "BreadthFirstSearchPath.h"

BreadthFirstSearchPath::BreadthFirstSearchPath(UnDirectedGraph& graph, int s)
{
	this->graph = graph;

	source = s;
	marked.resize(graph.GetV(), false);
	edgeTo.resize(graph.GetV(), -1);
	edgeTo[source] = source;

	BFS(s);
}

bool BreadthFirstSearchPath::HasPathTo(int v)
{
	return marked[v];
}

vector<int> BreadthFirstSearchPath::pathTo(int v)
{
	if (!HasPathTo(v))
	{
		vector<int> vec;
		return vec;
	}

	stack<int> stackOut;
	for (size_t i = v; i != source; i = edgeTo[i])
	{
		stackOut.push(i);
	}

	vector<int> vecOut;
	while (!stackOut.empty())
	{
		vecOut.push_back(stackOut.top());
		stackOut.pop();
	}
	vecOut.push_back(source);

	return vecOut;
}

void BreadthFirstSearchPath::BFS(int v)
{
	marked[v] = true;
	for (auto j : graph.adj(v))
	{
		if (marked[j] == false)
		{
			queueBFS.push(j);
			edgeTo[j] = v;
		}
		marked[j] = true;
	}

	while (!queueBFS.empty())
	{
		int value = queueBFS.front();
		queueBFS.pop();
		BFS(value);
	}
}
