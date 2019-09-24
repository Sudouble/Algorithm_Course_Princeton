// w8_1_Prim_LazyImp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "PrimLazy.h"
#include "PrimLazy_Book.h"

int main()
{
	WeightedEdgeGraph graph(8);

	graph.addEdge(WeightedEdge(4, 5, 0.35));
	graph.addEdge(WeightedEdge(4, 7, 0.37));
	graph.addEdge(WeightedEdge(5, 7, 0.28));
	graph.addEdge(WeightedEdge(0, 7, 0.16));
	graph.addEdge(WeightedEdge(1, 5, 0.32));
	graph.addEdge(WeightedEdge(0, 4, 0.38));
	graph.addEdge(WeightedEdge(2, 3, 0.17));
	graph.addEdge(WeightedEdge(1, 7, 0.19));
	graph.addEdge(WeightedEdge(0, 2, 0.26));
	graph.addEdge(WeightedEdge(1, 2, 0.36));
	graph.addEdge(WeightedEdge(1, 3, 0.29));
	graph.addEdge(WeightedEdge(2, 7, 0.34));
	graph.addEdge(WeightedEdge(6, 2, 0.40));
	graph.addEdge(WeightedEdge(3, 6, 0.52));
	graph.addEdge(WeightedEdge(6, 0, 0.58));
	graph.addEdge(WeightedEdge(6, 4, 0.93));

	PrimLazy primLazy(graph);
	primLazy.Print();

	PrimLazy_Book prim(graph);

	prim.Print();
}
