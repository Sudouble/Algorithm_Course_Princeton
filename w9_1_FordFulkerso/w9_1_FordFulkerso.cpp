// w9_1_FordFulkerso.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "FordFulkerson.h"

int main()
{
	FlowNetwork g(6);
	g.addEdge(new FlowEdge(0, 1, 2.0));
	g.addEdge(new FlowEdge(0, 2, 3.0));
	g.addEdge(new FlowEdge(1, 3, 3.0));
	g.addEdge(new FlowEdge(1, 4, 1.0));
	g.addEdge(new FlowEdge(2, 3, 1.0));
	g.addEdge(new FlowEdge(2, 4, 1.0));
	g.addEdge(new FlowEdge(3, 5, 2.0));
	g.addEdge(new FlowEdge(4, 5, 3.0));

	cout << g.toString() << endl;

	int s = 0, t = 5;
	FordFulkerson ff(g, s, t);
	
	cout << "Max flow from " << s << " to " << t << endl;
	for (int v = 0; v < g.GetV(); v++)
	{
		for (FlowEdge *e : g.adj(v))
		{
			if (v == e->from() && e->Flow() > 0)
				cout << "  " << e->toString() << endl;
		}		
	}

	// print min-cut
	cout << "Min cut:" << endl;
	for (int v = 0; v < g.GetV(); v++)
	{
		if (ff.inCut(v))
			cout << v << " ";
	}
	cout << endl;
	cout << "Max flow value = " << ff.Value() << endl;
}
