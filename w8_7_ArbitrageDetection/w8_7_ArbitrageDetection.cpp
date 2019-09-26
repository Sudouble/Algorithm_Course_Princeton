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
	g.addEdge(WeightedEdge(mapName2ID["USD"], mapName2ID["USD"], -int(log(1.0)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["USD"], mapName2ID["EUR"], -int(log(0.741)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["USD"], mapName2ID["GBP"], -int(log(0.657)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["USD"], mapName2ID["CHF"], -int(log(1.061)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["USD"], mapName2ID["CAD"], -int(log(1.005)*1000)/1000.0));

	g.addEdge(WeightedEdge(mapName2ID["EUR"], mapName2ID["USD"], -int(log(1.349)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["EUR"], mapName2ID["EUR"], -int(log(1.0)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["EUR"], mapName2ID["GBP"], -int(log(0.888)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["EUR"], mapName2ID["CHF"], -int(log(1.433)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["EUR"], mapName2ID["CAD"], -int(log(1.366)*1000)/1000.0));

	g.addEdge(WeightedEdge(mapName2ID["GBP"], mapName2ID["USD"], -int(log(1.521)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["GBP"], mapName2ID["EUR"], -int(log(1.126)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["GBP"], mapName2ID["GBP"], -int(log(1.0)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["GBP"], mapName2ID["CHF"], -int(log(1.614)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["GBP"], mapName2ID["CAD"], -int(log(1.538)*1000)/1000.0));

	g.addEdge(WeightedEdge(mapName2ID["CHF"], mapName2ID["USD"], -int(log(0.942)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["CHF"], mapName2ID["EUR"], -int(log(0.698)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["CHF"], mapName2ID["GBP"], -int(log(0.619)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["CHF"], mapName2ID["CHF"], -int(log(1.0)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["CHF"], mapName2ID["CAD"], -int(log(0.953)*1000)/1000.0));

	g.addEdge(WeightedEdge(mapName2ID["CAD"], mapName2ID["USD"], -int(log(0.995)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["CAD"], mapName2ID["EUR"], -int(log(0.732)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["CAD"], mapName2ID["GBP"], -int(log(0.650)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["CAD"], mapName2ID["CHF"], -int(log(1.049)*1000)/1000.0));
	g.addEdge(WeightedEdge(mapName2ID["CAD"], mapName2ID["CAD"], -int(log(1.0)*1000)/1000.0));

	ArbitrageDetection ad(g, 0);
}
