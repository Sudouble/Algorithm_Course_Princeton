// w7_2_BFS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "BreadthFirstSearchPath.h"

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
	UnDirectedGraph graph(7);
	graph.AddEdge(0, 1);
	graph.AddEdge(0, 2);
	graph.AddEdge(0, 6);
	graph.AddEdge(0, 5);
	graph.AddEdge(5, 3);
	graph.AddEdge(3, 4);
	graph.AddEdge(6, 4);
	graph.AddEdge(5, 4);

	BreadthFirstSearchPath path(graph, 0);

	Print(path.pathTo(4));
	cout << path.HasPathTo(1) << endl;
	cout << path.HasPathTo(3) << endl;
}