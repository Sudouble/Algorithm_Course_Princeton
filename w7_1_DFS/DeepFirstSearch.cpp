#include "DeepFirstSearch.h"

DeepFirstSearch::DeepFirstSearch(UnDirectedGraph &graph, int s)
{
    marked.resize(graph.GetV(), false);    
    dfs(graph, s);
}

DeepFirstSearch::~DeepFirstSearch()
{
}

void DeepFirstSearch::dfs(UnDirectedGraph &graph, int v)
{
    count++;
    marked[v] = true;

    for (auto w : graph.adj(v))
    {
        if (!marked[w])
        {            
            dfs(graph, w);
        }        
    }
    
}

bool DeepFirstSearch::IsMarked(int v)
{
    return marked[v];
}

int DeepFirstSearch::Count()
{
    return count;
}
