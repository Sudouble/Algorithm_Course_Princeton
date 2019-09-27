#include "FordFulkerson.h"
#include <limits>
#include <cmath>
#include <queue>
#include <iostream>
#include <cassert>

FordFulkerson::FordFulkerson(FlowNetwork& g, int s, int t)
{
	V = g.GetV();
	if (s == t)
		throw ("Source equals sink");
	if (!isFeasible(g, s, t))
		throw ("Initial flow is infeasible");

	value = excess(g, t);
	while (hasAugmentingPath(g, s, t))
	{
		// bottleneck capacity
		double bottle = numeric_limits<double>::max();
		for (int v = t; v != s; v = edgeTo[v].other(v))
		{
			bottle = std::fmin(bottle, edgeTo[v].CapacityTo(v));
		}

		// augment flow
		for (size_t v = t; v != s; v = edgeTo[v].other(v))
		{
			edgeTo[v].addResidualFlowTo(v, bottle);
		}

		value += bottle;
	}

	assert(check(g, s, t));
}

double FordFulkerson::Value()
{
	return value;
}

bool FordFulkerson::inCut(int v)
{
	validate(v);

	return marked[v];
}

void FordFulkerson::validate(int v) 
{
	if (v < 0 || v >= V)
		throw ("vertex is not valid");
}

bool FordFulkerson::hasAugmentingPath(FlowNetwork& g, int s, int t)
{
	edgeTo.clear();
	edgeTo.resize(g.GetV());

	marked.clear();
	marked.resize(g.GetV(), false);

	queue<int> queueIn;
	queueIn.push(s);
	marked[s] = true;

	while (!queueIn.empty() && !marked[t])
	{
		int v = queueIn.front();
		queueIn.pop();

		for (FlowEdge e : g.adj(v))
		{
			int w = e.other(v);
			
			// if residual capacity from v to w
			if (e.CapacityTo(w) > 0)
			{
				if (!marked[w])
				{
					marked[w] = true;

					edgeTo[w] = e;		
					queueIn.push(w);
				}
			}
		}
	}

	return marked[t];
}

double FordFulkerson::excess(FlowNetwork& g, int v)
{
	double excess = 0.0;
	for (auto e : g.adj(v))
	{
		if (v == e.from())
			excess -= e.Flow();
		else
			excess += e.Flow();
	}
	return excess;
}

bool FordFulkerson::isFeasible(FlowNetwork& g, int s, int t)
{
	for (int v = 0; v < g.GetV(); v++)
	{
		for (auto e : g.adj(v))
		{
			if (e.Flow() < -FLOATING_POINT_SPSILON
				|| e.Flow() > e.Capacity() + FLOATING_POINT_SPSILON)
			{
				cout << "Edge does not satisfy capacity constraints: " << e.toString() << endl;
				return false;
			}
		}
	}

	if (abs(value + excess(g, s)) > FLOATING_POINT_SPSILON)
	{
		cout << ("Excess at source = ") << excess(g, s) << endl;
		cout << "Max flow         = " << value << endl;
		return false;
	}

	if (abs(value - excess(g, t)) > FLOATING_POINT_SPSILON)
	{
		cout << "Excess at sink   = " << excess(g, t) << endl;
		cout << "Max flow          = " << value << endl;
		return false;
	}

	for (int v = 0; v < g.GetV(); v++)
	{
		if (v == s || v == t)
			continue;
		if (abs(excess(g, v)) > FLOATING_POINT_SPSILON)
		{
			cout << "Net flow out of " << v << " doesn't equal zero" << endl;
			return false;
		}
	}
	
	return true;
}

// check optimality conditions
bool FordFulkerson::check(FlowNetwork& g, int s, int t)
{
	if (!isFeasible(g, s, t))
	{
		cout << "Flow is infeasible" << endl;
		return false;
	}
	
	// check that s is on the source side of min cut and that t is not on source side
	if (!inCut(s)) {
		cout << "source " << s << " is not on source side of min cut" << endl;
		return false;
	}
	if (inCut(t)) {
		cout << "sink " << t << " is on source side of min cut" << endl;
		return false;
	}

	double mincutValue = 0.0;
	for (int v = 0; v < g.GetV(); v++)
	{
		for (auto e : g.adj(v))
		{
			if (v == e.from()
				&& inCut(e.from())
				&& !inCut(e.to()))
				mincutValue += e.Capacity();
		}
	}

	if (abs(mincutValue - value) > FLOATING_POINT_SPSILON)
	{
		cout << "Max flow value = " << value << ", min cut value = " << mincutValue << endl;
		return false;
	}

	return true;
}
