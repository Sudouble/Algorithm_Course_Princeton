#include "DirectedDFS.h"

DirectedDFS::DirectedDFS(Digraph& digraph_, int v)
{
	this->digraph = digraph_;
	s = v;

	count = 0;

	marked.resize(digraph.GetV(), false);
	edgeTo.resize(digraph.GetV(), -1);

	DFS(v);
}

DirectedDFS::DirectedDFS(Digraph& digraph_, vector<int> vecV)
{
	this->digraph = digraph_;

	count = 0;

	marked.resize(digraph.GetV(), false);
	edgeTo.resize(digraph.GetV(), -1);

	for (int v : vecV)
		if (!marked[v])
			DFS(v);
}

void DirectedDFS::DFS(int v)
{
	marked[v] = true;
	count++;

	for (int w : digraph.adj(v))
	{
		if (!marked[w])
		{
			edgeTo[w] = v;
			DFS(w);
		}
	}
}

bool DirectedDFS::IsMark(int v)
{
	return marked[v];
}

int DirectedDFS::GetCount()
{
	return count;
}

vector<int> DirectedDFS::pathTo(int v)
{
	if (!IsMark(v))
		return vector<int>();

	vector<int> vecOut;
	for (size_t x = v; x != -1; x = edgeTo[x])
	{
		vecOut.insert(vecOut.begin(), x);
	}
	return vecOut;
}

