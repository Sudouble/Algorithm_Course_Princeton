// Week1_QuickFind.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ��¼ÿ�����Ĵ�С���ںϲ���ʱ��һֱ��С�����������ȥ��
// Weighted Quik Find

// index 0 1 2 3 4 5 6 7 8 9
// id[i] 6,2,6,4,4,6,6,2,4,4

// In Graph:
//   4        6
// / | \    / | \
//3  8  9  0  2  5
//           / \
//          1   7

int index[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int id[] =	  {6, 2, 6, 4, 4, 6, 6, 2, 4, 4};

vector<int> vecIndex;
vector<int> vecID;

void Init();
int GetRootID(int index);

void connect(int index, int index2)
{
	cout << "connecting " << index << " with " << index2<< endl;

	int rootP = GetRootID(index);
	int rootQ = GetRootID(index2);
	if (rootP == rootQ)
		return;

	vecID[index2] = rootP;
}

int GetRootID(int index)
{
	while (vecID[index] != index)
	{
		index = vecID[index];
	}
	return index;
}

bool IsConnect(int index, int index2)
{	
	bool bResult = GetRootID(index) == GetRootID(index2);

	cout << "IsConnect(" 
		<< index << "-" << index2 << "): " 
		<< bResult << endl;

	return bResult;
}

void PathCompress(int p)
{
	int rootP = GetRootID(p);

	while (rootP != vecID[p])
	{
		int newP = vecID[p];

		vecID[p] = rootP;
		p = newP;
	}
}

void Print()
{
	// �Ȱ�Rootһ���Ķ���һ��
	// ����ʱ���ѹ�����Ҳ�ŵ�һ��

	// ��ʹ�õ����ݽṹ Map<int, vector<int> >;
	// ���У�KeyΪRoot��vector<int>Ϊ���ֵ
}

int _tmain(int argc, _TCHAR* argv[])
{
	Init();

	cout << "Original" << endl;
	Print();
	IsConnect(0, 1);
	IsConnect(7, 8);

	//////////////////////////////////////////////////////////////////////////
	cout << endl;	
	IsConnect(9, 6);
	IsConnect(9, 5);
	//connect(9, 6);
	Print();

	IsConnect(9, 6);
	IsConnect(9, 5);
	IsConnect(2, 3);

	for (int i = 0; i < vecIndex.size(); i++)
	{
		PathCompress(vecIndex[i]);
	}	

	return 0;
}

void Init()
{
	vecIndex.assign(index, index+10);
	vecID.assign(id, id+10);
}
