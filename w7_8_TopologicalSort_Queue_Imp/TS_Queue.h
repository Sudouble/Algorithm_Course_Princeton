#pragma once

#include "Digraph.h"
#include <queue>

// ���裺����ǰ���Ľ�㣨�����Ϊ 0 �Ľ�㣩��
// һ��һ����ɾȥ��ʹ�ö��л���ջ����ɾ��ʱ��
// ���ھӽ�����ȣ����� - 1 ������������ʵ�֡�

// �������������ڶ����Ⱥ�˳�������������
// ����Ⱥ�˳���γ�һ��������ô�ͱ�ʾ��Щ����ͷβ����������Զ������ɡ�

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

