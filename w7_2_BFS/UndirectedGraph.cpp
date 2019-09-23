#include "UnDirectedGraph.h"

UnDirectedGraph::UnDirectedGraph(int V) // 顶点数量
{
	E = 0;
	this->V = V;
    vecAdj.clear();
    vecAdj.resize(V);
}

void UnDirectedGraph::AddEdge(int v, int w)
{
    if (!IsValidEdge(v) || !IsValidEdge(w))
        return;

    E++;
    vecAdj[v].push_back(w);
    vecAdj[w].push_back(v);
}

int UnDirectedGraph::GetE()
{
    return E;
}

int UnDirectedGraph::GetV()
{
    return V;
}

bool UnDirectedGraph::IsValidEdge(int v)
{
    if (v >= vecAdj.size())
        return false;
    return true;
}

vector<int> UnDirectedGraph::adj(int v)
{   
    return vecAdj[v];
}

int UnDirectedGraph::degree(int v)
{
    if (IsValidEdge(v))
        return vecAdj[v].size();
    return 0;
}

string UnDirectedGraph::toString()
{
    string str = "";
    str += "vectices:" + to_string(V) + ", edges:" + to_string(E) + "\r\n";
    for (size_t v = 0; v < V; v++)
    {
		str += to_string(v) + ":";
        for (auto j : adj(v))
            str += to_string(j) + " ";
        str += "\r\n";
    }
    return str;    
}
