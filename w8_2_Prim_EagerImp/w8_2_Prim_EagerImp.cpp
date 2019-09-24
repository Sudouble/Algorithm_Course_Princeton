// w8_2_Prim_EagerImp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "PrimEager.h"

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

	PrimEager prim(graph);

	prim.Print();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
