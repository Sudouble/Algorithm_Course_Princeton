// w7_3_ConnectedComponents.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CC.h"

int main()
{
	UnDirectedGraph graph(13);
	graph.AddEdge(0, 1);
	graph.AddEdge(0, 2);
	graph.AddEdge(0, 6);
	graph.AddEdge(0, 5);
	graph.AddEdge(5, 3);
	graph.AddEdge(5, 4);
	graph.AddEdge(4, 6);

	graph.AddEdge(7, 8);	
	
	graph.AddEdge(9, 10);
	graph.AddEdge(9, 11);
	graph.AddEdge(9, 12);
	graph.AddEdge(11, 12);

	CC cc(graph);
	
	cout << "Is 0 3 connected ? " << cc.connect(0, 3) << endl;
	cout << "Is 3 3 connected ? " << cc.connect(3, 3) << endl;
	cout << "Is 7 8 connected ? " << cc.connect(7, 8) << endl;
	cout << "Is 9 10 connected ? " << cc.connect(9, 10) << endl;
	cout << "Is 0 10 connected ? " << cc.connect(0, 10) << endl;
	cout << "Is 7 10 connected ? " << cc.connect(7, 10) << endl;

	cout << "graph has 4, size: " << cc.size(3) << endl;
	cout << "graph has 7, size: " << cc.size(7) << endl;
	cout << "graph has 11, size: " << cc.size(11) << endl;
}

