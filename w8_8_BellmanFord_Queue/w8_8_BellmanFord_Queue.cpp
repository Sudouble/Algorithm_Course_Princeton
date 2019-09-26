// w8_8_BellmanFord_Queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "BellmanFordSP.h"

int main()
{
	WeightedEdgeDigraph graph(8);

	graph.addEdge(WeightedEdge(0, 4, 9));
	graph.addEdge(WeightedEdge(0, 1, 5));
	graph.addEdge(WeightedEdge(0, 7, 8));
	graph.addEdge(WeightedEdge(1, 3, 15));
	graph.addEdge(WeightedEdge(1, 2, 12));
	graph.addEdge(WeightedEdge(1, 7, 4));
	graph.addEdge(WeightedEdge(4, 7, 5));
	graph.addEdge(WeightedEdge(4, 5, 4));
	graph.addEdge(WeightedEdge(4, 6, 20));
	graph.addEdge(WeightedEdge(7, 2, 7));
	graph.addEdge(WeightedEdge(7, 5, 6));
	graph.addEdge(WeightedEdge(5, 2, 1));
	graph.addEdge(WeightedEdge(5, 6, 13));
	graph.addEdge(WeightedEdge(2, 3, 3));
	graph.addEdge(WeightedEdge(2, 6, 11));
	graph.addEdge(WeightedEdge(3, 6, 9));

	BellmanFordSP dij(graph, 0);
	dij.PrintPathTo(6);
	dij.PrintPathTo(7);
	dij.PrintPathTo(3);

	//////////////////////////////////////////
	// 负权边测试--->结果是OK的？？emmm
	WeightedEdgeDigraph graph1(4);
	graph1.addEdge(WeightedEdge(0, 1, 2));
	graph1.addEdge(WeightedEdge(1, 2, 6));
	graph1.addEdge(WeightedEdge(2, 3, -9));
	graph1.addEdge(WeightedEdge(0, 3, 2));

	BellmanFordSP d2(graph1, 0);
	d2.PrintPathTo(3);
}
