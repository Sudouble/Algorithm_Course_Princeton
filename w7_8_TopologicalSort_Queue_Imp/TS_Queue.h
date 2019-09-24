#pragma once

#include "Digraph.h"
#include <queue>

// 步骤：找无前驱的结点（即入度为 0 的结点），
// 一个一个地删去（使用队列或者栈），删的时候，
// 把邻居结点的入度（即度 - 1 ）。借助队列实现。

// “拓扑排序”用于对有先后顺序的任务的输出，
// 如果先后顺序形成一个环，那么就表示这些任务头尾依赖，就永远不能完成。

// 

class TS_Queue
{
public:
	TS_Queue(Digraph &graph);
	vector<int> GetResult();

private:
	void DFS();

private:
	Digraph graph;

	vector<int> vecResult;
};

