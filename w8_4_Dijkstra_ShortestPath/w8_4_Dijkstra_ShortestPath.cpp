// w8_4_Dijkstra_ShortestPath.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Dijkstra.h"

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
	
	Dijkstra dij(graph, 0);
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

	Dijkstra d2(graph1, 0);
	d2.PrintPathTo(3);

	//////////////////////////////////////////
	WeightedEdgeDigraph graph2(8);
	graph2.addEdge(WeightedEdge(4, 5, 0.35));
	graph2.addEdge(WeightedEdge(5, 4, 0.35));
	graph2.addEdge(WeightedEdge(4, 7, 0.37));
	graph2.addEdge(WeightedEdge(5, 7, 0.28));
	graph2.addEdge(WeightedEdge(7, 5, 0.28));
	graph2.addEdge(WeightedEdge(5, 1, 0.32));
	graph2.addEdge(WeightedEdge(0, 4, 0.38));
	graph2.addEdge(WeightedEdge(0, 2, 0.26));
	graph2.addEdge(WeightedEdge(7, 3, 0.39));
	graph2.addEdge(WeightedEdge(1, 3, 0.29));
	graph2.addEdge(WeightedEdge(2, 7, 0.34));
	graph2.addEdge(WeightedEdge(6, 2, 0.40));
	graph2.addEdge(WeightedEdge(3, 6, 0.52));
	graph2.addEdge(WeightedEdge(6, 0, 0.58));
	graph2.addEdge(WeightedEdge(6, 4, 0.93));

	Dijkstra d3(graph2, 0);
	d3.PrintPathTo(3);
}
