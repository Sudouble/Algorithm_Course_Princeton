#pragma once

#include <string>
using namespace std;

class FlowEdge
{
public:
	FlowEdge() {}
	FlowEdge(int v, int w, double capacity_);

	int from();
	int to();

	void addResidualFlowTo(int vertex, double amount);

	int other(int vertex);
	double CapacityTo(int vertex);

	double Flow() {
		return flow;
	}
	double Capacity() {
		return capacity;
	}
	
	string toString();

private:
	int v;
	int w;

	double capacity;
	double flow;
};

