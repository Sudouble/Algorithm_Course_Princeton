#pragma once

#include <vector>
#include <string>
using namespace std;

class Edge
{
public:
	Edge();
	Edge(int start_, int end_)
	{
		start = start_;
		end = end_;
	}
	~Edge();

	int start;
	int end;
private:

};

class Digraph
{
public:
	Digraph() {
		nEdge = 0;
	}

	Digraph(int V);

	void addEdge(Edge edge);
	vector<int> adj(int v);

	int OutDegree(int v);
	int GetE();
	int GetV();

private:
	void CheckValidate(int v);

private:
	vector<vector<int> > vecAdj;	
	int nEdge;

public:
	vector<int> InDegree;
};

