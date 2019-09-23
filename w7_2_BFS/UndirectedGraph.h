#pragma once

#include <vector>
#include <list>
#include <string>

using namespace std;

class UnDirectedGraph
{
public:
	UnDirectedGraph() 
	{
		E = 0;
		V = 0;
		vecAdj.clear();
	}
    UnDirectedGraph(int V); // 顶点数量

    void AddEdge(int v, int w);
    int GetE();
    int GetV();
    bool IsValidEdge(int v);

	vector<int> adj(int v);
    int degree(int v);

    string toString();

public:
    vector<vector<int> > vecAdj;

private:
    int E;
    int V;
};
