// w7_6_TopologicalSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "TopologicalSort.h"

void Print(const vector<int>& vecIn)
{
	for (int i = 0; i < vecIn.size(); i++)
	{
		cout << vecIn[i] << "->";
	}
	cout << endl;
}

void Print(queue<int> vecIn)
{
	while (!vecIn.empty())
	{
		cout << vecIn.front() << "->";
		vecIn.pop();
	}	
	cout << endl;
}

int main()
{

	Digraph digraph(13);

	digraph.addEdge(Edge(2, 3));
	digraph.addEdge(Edge(0, 6));
	digraph.addEdge(Edge(0, 1));
	digraph.addEdge(Edge(2, 0));
	digraph.addEdge(Edge(11, 12));
	digraph.addEdge(Edge(9, 12));

	digraph.addEdge(Edge(9, 10));
	digraph.addEdge(Edge(9, 11));
	digraph.addEdge(Edge(3, 5));
	digraph.addEdge(Edge(8, 7));
	digraph.addEdge(Edge(5, 4));
	digraph.addEdge(Edge(0, 5));

	digraph.addEdge(Edge(6, 4));
	digraph.addEdge(Edge(6, 9));
	digraph.addEdge(Edge(7, 6));

	DepthFirstOrder dfo(digraph);

	TopologicalSort ts(dfo);
	Print(dfo.PreOrder());
	Print(ts.GetVec());
	// =====================================

	Digraph digraph1(7);

	digraph1.addEdge(Edge(0, 5));
	digraph1.addEdge(Edge(0, 1));
	digraph1.addEdge(Edge(3, 5));
	digraph1.addEdge(Edge(5, 2));
	digraph1.addEdge(Edge(6, 0));
	digraph1.addEdge(Edge(1, 4));

	digraph1.addEdge(Edge(0, 2));
	digraph1.addEdge(Edge(3, 6));
	digraph1.addEdge(Edge(3, 4));
	digraph1.addEdge(Edge(6, 4));
	digraph1.addEdge(Edge(3, 2));

	DepthFirstOrder dfo1(digraph1);	

	TopologicalSort ts1(dfo1);	
	Print(ts1.GetVec());
}
