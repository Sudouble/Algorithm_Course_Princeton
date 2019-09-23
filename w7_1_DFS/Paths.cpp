#include "Paths.h"

Paths::Paths(UnDirectedGraph &graph, int s_)
{	
    s = s_;
	this->graph = graph;

	marked.resize(graph.GetV(), false);
	edgeTo.resize(graph.GetV(), -1);
	edgeTo[s] = s;

	DFS(s);
}

Paths::~Paths()
{
}

void Paths::DFS(int w)
{
	marked[w] = true;
	for (auto ww : graph.adj(w))
	{
		if (marked[ww] == false)
		{
			edgeTo[ww] = w;
			DFS(ww);
		}
	}
}

bool Paths::HasPath(int w)
{
	return marked[w];
}

vector<int> Paths::pathTo(int w)
{
	stack<int> stackOut;	
	while (HasPath(w) && edgeTo[w] != -1)
	{
		stackOut.push(w);

		if (w == edgeTo[w])
			break;
		w = edgeTo[w];
	}

	vector<int> out;
	while (!stackOut.empty())
	{
		out.push_back(stackOut.top());
		stackOut.pop();
	}
	return out;
}
