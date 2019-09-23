#include "DirectedBFS.h"

DirectedBFS::DirectedBFS(Digraph& digraph_, int v)
{
	this->digraph = digraph_;
	s = v;

	count = 0;

	marked.resize(digraph.GetV(), false);
	edgeTo.resize(digraph.GetV(), -1);

	DFS(v);
}

void DirectedBFS::DFS(int v)
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

bool DirectedBFS::IsMark(int v)
{
	return marked[v];
}

int DirectedBFS::GetCount()
{
	return count;
}

vector<int> DirectedBFS::pathTo(int v)
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

