#include "DirectedBFS.h"

DirectedBFS::DirectedBFS(Digraph& digraph_, int v)
{
	this->digraph = digraph_;
	s = v;

	count = 0;

	marked.resize(digraph.GetV(), false);
	edgeTo.resize(digraph.GetV(), -1);
	distTo.resize(digraph.GetV(), 0);

	BFS(v);
}

void DirectedBFS::BFS(int v)
{
	count++;

	queue<int> queueBFS;
	queueBFS.push(v);

	while (!queueBFS.empty())
	{
		int vv = queueBFS.front();
		queueBFS.pop();
		marked[vv] = true;

		for (int j : digraph.adj(vv))
		{
			if (!marked[j])
			{
				marked[j] = true;
				edgeTo[j] = vv;
				distTo[j] = distTo[vv] + 1;

				queueBFS.push(j);
			}
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

int DirectedBFS::DistTo(int v)
{
	return distTo[v];
}

