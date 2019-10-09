#include "NFA.h"
#include <stack>

NFA::NFA(string regexp)
{
	M = regexp.length();
	reg = regexp;

	stack<int> ops;	

	G = Digraph(M + 1);
	for (int i = 0; i < M; i++)
	{
		int lp = i;
		if (regexp[i] == '(' || regexp[i] == '|')
		{
			ops.push(i);
		}
		else if (regexp[i] == ')')
		{
			int nOr = ops.top();
			ops.pop();
			if (regexp[nOr] == '|')
			{
				lp = ops.top();
				ops.pop();
				G.addEdge(Edge(lp, nOr + 1));
				G.addEdge(Edge(nOr, i));
			}
			else
				lp = nOr;
		}

		if (i < M - 1 && regexp[i + 1] == '*')
		{
			G.addEdge(Edge(lp, i + 1));
			G.addEdge(Edge(i + 1, lp));
		}

		if (regexp[i] == '(' || regexp[i] == '*' || regexp[i] == ')')
		{
			G.addEdge(Edge(i, i+1));
		}
	}
}

bool NFA::recoginze(string txt)
{
	vector<int> pc;
	DirectedDFS *dfs = new DirectedDFS(G, 0);
	for (int v = 0; v < G.GetV(); v++)
	{
		if (dfs->IsMark(v))
			pc.push_back(v);
	}

	for (int i = 0; i < txt.length(); i++)
	{
		vector<int> match;
		for (int v : pc)
		{
			if (v < M)
			{
				if (reg[v] == txt[i] || reg[v] == '.')
				{
					match.push_back(v);
				}
			}
		}

		pc.clear();
		delete dfs;
		dfs = new DirectedDFS(G, match);
		for (int v = 0; v < G.GetV(); v++)
		{
			if (dfs->IsMark(v))
				pc.push_back(v);
		}
	}

	for (int v : pc)
	{
		if (v == M)
			return true;
	}

	return false;
}
