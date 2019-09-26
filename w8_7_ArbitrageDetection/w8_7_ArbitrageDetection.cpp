// w8_7_ArbitrageDetection.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ArbitrageDetection.h"
#include <map>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	map<string, int> mapName2ID;
	mapName2ID["USD"] = 0;
	mapName2ID["EUR"] = 1;
	mapName2ID["GBP"] = 2;
	mapName2ID["CHF"] = 3;
	mapName2ID["CAD"] = 4;

	WeightedEdgeDigraph g(5);
	g.addEdge(WeightedEdge(mapName2ID["USD"], mapName2ID["USD"], log10(1.0)));
	g.addEdge(WeightedEdge(mapName2ID["USD"], mapName2ID["EUR"], log10(0.741)));
	g.addEdge(WeightedEdge(mapName2ID["USD"], mapName2ID["GBP"], log10(0.657)));
	g.addEdge(WeightedEdge(mapName2ID["USD"], mapName2ID["CHF"], log10(1.061)));
	g.addEdge(WeightedEdge(mapName2ID["USD"], mapName2ID["CAD"], log10(1.005)));

	g.addEdge(WeightedEdge(mapName2ID["EUR"], mapName2ID["USD"], log10(1.349)));
	g.addEdge(WeightedEdge(mapName2ID["EUR"], mapName2ID["EUR"], log10(1.0)));
	g.addEdge(WeightedEdge(mapName2ID["EUR"], mapName2ID["GBP"], log10(0.888)));
	g.addEdge(WeightedEdge(mapName2ID["EUR"], mapName2ID["CHF"], log10(1.433)));
	g.addEdge(WeightedEdge(mapName2ID["EUR"], mapName2ID["CAD"], log10(1.366)));

	g.addEdge(WeightedEdge(mapName2ID["GBP"], mapName2ID["USD"], log10(1.521)));
	g.addEdge(WeightedEdge(mapName2ID["GBP"], mapName2ID["EUR"], log10(1.126)));
	g.addEdge(WeightedEdge(mapName2ID["GBP"], mapName2ID["GBP"], log10(1.0)));
	g.addEdge(WeightedEdge(mapName2ID["GBP"], mapName2ID["CHF"], log10(1.614)));
	g.addEdge(WeightedEdge(mapName2ID["GBP"], mapName2ID["CAD"], log10(1.538)));

	g.addEdge(WeightedEdge(mapName2ID["CHF"], mapName2ID["USD"], log10(0.942)));
	g.addEdge(WeightedEdge(mapName2ID["CHF"], mapName2ID["EUR"], log10(0.698)));
	g.addEdge(WeightedEdge(mapName2ID["CHF"], mapName2ID["GBP"], log10(0.619)));
	g.addEdge(WeightedEdge(mapName2ID["CHF"], mapName2ID["CHF"], log10(1.0)));
	g.addEdge(WeightedEdge(mapName2ID["CHF"], mapName2ID["CAD"], log10(0.953)));

	g.addEdge(WeightedEdge(mapName2ID["CAD"], mapName2ID["USD"], log10(0.995)));
	g.addEdge(WeightedEdge(mapName2ID["CAD"], mapName2ID["EUR"], log10(0.732)));
	g.addEdge(WeightedEdge(mapName2ID["CAD"], mapName2ID["GBP"], log10(0.650)));
	g.addEdge(WeightedEdge(mapName2ID["CAD"], mapName2ID["CHF"], log10(1.049)));
	g.addEdge(WeightedEdge(mapName2ID["CAD"], mapName2ID["CAD"], log10(1.0)));

	ArbitrageDetection ad(g, 0);
}
