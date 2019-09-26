#include "ArbitrageDetection.h"
#include <iostream>
#include <cmath>

ArbitrageDetection::ArbitrageDetection(WeightedEdgeDigraph& g, int s)
{
	BellmanFordSP spt(g, s);
	if (spt.HasNegativeCycle())
	{
		double stake = 1000.0;

		vector<WeightedEdge> result = spt.NegtiveCycle();
		for (int i = result.size()-1; i >= 0; i--)
		{
			int v = result[i].either();
			int w = result[i].other(v);
			cout << stake << " " << v;
			stake *= exp(-result[i].Weight());
			cout << " = " << stake << " " << w << endl;
		}
	}
	else
	{
		cout << "No arbitrage opportunity";
	}
}

void ArbitrageDetection::Print()
{
}
