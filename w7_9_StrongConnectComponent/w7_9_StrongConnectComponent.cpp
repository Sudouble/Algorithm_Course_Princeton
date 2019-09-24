// w7_9_StrongConnectComponent.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "SCC.h"

int main()
{
	Digraph grah(13);
	grah.addEdge(Edge(4, 2));
	grah.addEdge(Edge(2, 3));
	grah.addEdge(Edge(3, 2));
	grah.addEdge(Edge(6, 0));
	grah.addEdge(Edge(0, 1));
	grah.addEdge(Edge(2, 0));
	grah.addEdge(Edge(11, 12));
	grah.addEdge(Edge(12, 9));
	grah.addEdge(Edge(9, 10));
	grah.addEdge(Edge(9, 11));
	grah.addEdge(Edge(7, 9));
	grah.addEdge(Edge(10, 12));
	grah.addEdge(Edge(11, 4));
	grah.addEdge(Edge(4, 3));
	grah.addEdge(Edge(3, 5));
	grah.addEdge(Edge(6, 8));
	grah.addEdge(Edge(8, 6));
	grah.addEdge(Edge(5, 4));
	grah.addEdge(Edge(0, 5));
	grah.addEdge(Edge(6, 4));
	grah.addEdge(Edge(6, 9));
	grah.addEdge(Edge(7, 6));

	SCC ssc(grah);
	
	cout << "ssc count:" << ssc.GetCount() << endl; 
	cout << "Is 0, 5 ssc (1)? " << ssc.IsSCC(0, 5) << endl;
	cout << "Is 1, 5 ssc (0)? " << ssc.IsSCC(1, 5) << endl;
	cout << "Is 6, 8 ssc (1)? " << ssc.IsSCC(6, 8) << endl;
	cout << "Is 7, 8 ssc (0)? " << ssc.IsSCC(7, 8) << endl;
	cout << "Is 9, 12 ssc (1)? " << ssc.IsSCC(9, 12) << endl;
	cout << "Is 3, 4 ssc (1)? " << ssc.IsSCC(3, 4) << endl;
}

