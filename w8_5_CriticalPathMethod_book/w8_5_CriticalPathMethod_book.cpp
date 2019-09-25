// w8_5_CriticalPathMethod_book.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "AcyclicLongestPath.h"

int main()
{
	int n = 10; // number of jobs

	int source = 2 * n;
	int sink = 2 * n + 1;
	WeightedEdgeDigraph G(2*n+2);

	int i = 0;
	G.addEdge(WeightedEdge(source, i, 0.0));
	G.addEdge(WeightedEdge(i+n,	   sink, 0.0));
	G.addEdge(WeightedEdge(i,      i+n, 41.0));
	// constrains
	G.addEdge(WeightedEdge(i + n, 1, 0.0));
	G.addEdge(WeightedEdge(i + n, 7, 0.0));
	G.addEdge(WeightedEdge(i + n, 9, 0.0));

	i = 1;
	G.addEdge(WeightedEdge(source, i, 0.0));
	G.addEdge(WeightedEdge(i + n, sink, 0.0));
	G.addEdge(WeightedEdge(i, i + n, 51.0));
	// constrains
	G.addEdge(WeightedEdge(i + n, 2, 0.0));	

	i = 2;
	G.addEdge(WeightedEdge(source, i, 0.0));
	G.addEdge(WeightedEdge(i + n, sink, 0.0));
	G.addEdge(WeightedEdge(i, i + n, 50.0));

	i = 3;
	G.addEdge(WeightedEdge(source, i, 0.0));
	G.addEdge(WeightedEdge(i + n, sink, 0.0));
	G.addEdge(WeightedEdge(i, i + n, 36.0));

	i = 4;
	G.addEdge(WeightedEdge(source, i, 0.0));
	G.addEdge(WeightedEdge(i + n, sink, 0.0));
	G.addEdge(WeightedEdge(i, i + n, 38.0));

	i = 5;
	G.addEdge(WeightedEdge(source, i, 0.0));
	G.addEdge(WeightedEdge(i + n, sink, 0.0));
	G.addEdge(WeightedEdge(i, i + n, 45.0));

	i = 6;
	G.addEdge(WeightedEdge(source, i, 0.0));
	G.addEdge(WeightedEdge(i + n, sink, 0.0));
	G.addEdge(WeightedEdge(i, i + n, 21.0));
	// constrains
	G.addEdge(WeightedEdge(i + n, 3, 0.0));
	G.addEdge(WeightedEdge(i + n, 8, 0.0));

	i = 7;
	G.addEdge(WeightedEdge(source, i, 0.0));
	G.addEdge(WeightedEdge(i + n, sink, 0.0));
	G.addEdge(WeightedEdge(i, i + n, 32.0));
	// constrains
	G.addEdge(WeightedEdge(i + n, 3, 0.0));
	G.addEdge(WeightedEdge(i + n, 8, 0.0));

	i = 8;
	G.addEdge(WeightedEdge(source, i, 0.0));
	G.addEdge(WeightedEdge(i + n, sink, 0.0));
	G.addEdge(WeightedEdge(i, i + n, 21.0));
	// constrains
	G.addEdge(WeightedEdge(i + n, 2, 0.0));

	i = 9;
	G.addEdge(WeightedEdge(source, i, 0.0));
	G.addEdge(WeightedEdge(i + n, sink, 0.0));
	G.addEdge(WeightedEdge(i, i + n, 29.0));
	// constrains
	G.addEdge(WeightedEdge(i + n, 4, 0.0));
	G.addEdge(WeightedEdge(i + n, 6, 0.0));

	AcyclicLongestPath lp(G, source);
	cout << "Job start finish" << endl;
	cout << "--------------------------" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << i << " " << lp.DistTo(i) << " " << lp.DistTo(i + n) << endl;
	}
	cout << "Finish time:" << lp.DistTo(sink) << endl;
}
