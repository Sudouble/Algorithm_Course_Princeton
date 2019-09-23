// w7_5_BFS_digraph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DirectedBFS.h"

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

	digraph.addEdge(Edge(4, 2));
	digraph.addEdge(Edge(2, 3));
	digraph.addEdge(Edge(3, 2));
	digraph.addEdge(Edge(6, 0));
	digraph.addEdge(Edge(0, 1));
	digraph.addEdge(Edge(2, 0));
	digraph.addEdge(Edge(11, 12));
	digraph.addEdge(Edge(12, 9));
	digraph.addEdge(Edge(9, 10));
	digraph.addEdge(Edge(9, 11));
	digraph.addEdge(Edge(7, 9));
	digraph.addEdge(Edge(10, 12));
	digraph.addEdge(Edge(11, 4));
	digraph.addEdge(Edge(4, 3));
	digraph.addEdge(Edge(3, 5));
	digraph.addEdge(Edge(6, 8));
	digraph.addEdge(Edge(8, 6));
	digraph.addEdge(Edge(5, 4));
	digraph.addEdge(Edge(0, 5));
	digraph.addEdge(Edge(6, 4));
	digraph.addEdge(Edge(6, 9));
	digraph.addEdge(Edge(7, 6));

	DirectedBFS bfs(digraph, 0);

	cout << "0 6 connected ? " << bfs.IsMark(6) << endl;
	cout << "0 2 connected ? " << bfs.IsMark(2) << endl;
	cout << "0 4 distTo :" << bfs.DistTo(4) << endl;

	cout << "path 0 -> 2" << endl;
	Print(bfs.pathTo(2));
}