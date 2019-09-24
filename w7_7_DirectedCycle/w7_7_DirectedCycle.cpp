// w7_7_DirectedCycle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DirectedCycle.h"

int main()
{
	Digraph graph(4);
	graph.addEdge(Edge(0, 1));
	graph.addEdge(Edge(1, 2));
	graph.addEdge(Edge(2, 3));
	graph.addEdge(Edge(3, 0));

	DirectedCycle dc(graph, 0);
	cout << dc.HasCycle() << endl;

	Digraph graph1(4);
	graph.addEdge(Edge(0, 1));
	graph.addEdge(Edge(1, 2));
	graph.addEdge(Edge(2, 3));

	DirectedCycle dc1(graph1, 0);
	cout << dc1.HasCycle() << endl;
}
