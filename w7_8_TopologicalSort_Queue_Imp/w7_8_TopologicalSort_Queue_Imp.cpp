// w7_8_TopologicalSort_Queue_Imp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "TS_Queue.h"

void Print(const vector<int>& vecIn)
{
	for (int i = 0; i < vecIn.size(); i++)
	{
		cout << vecIn[i] << "->";
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

	TS_Queue que(digraph);

	Print(que.GetResult());

	////////////////////////////////////
	Digraph g(9);
	g.addEdge(Edge(0, 2));
	g.addEdge(Edge(0, 7));
	g.addEdge(Edge(1, 2));
	g.addEdge(Edge(1, 4));
	g.addEdge(Edge(1, 3));
	g.addEdge(Edge(2, 3));
	g.addEdge(Edge(3, 5));
	g.addEdge(Edge(3, 6));
	g.addEdge(Edge(4, 5));
	g.addEdge(Edge(7, 8));
	g.addEdge(Edge(8, 6));

	TS_Queue que1(g);

	Print(que1.GetResult());
}
