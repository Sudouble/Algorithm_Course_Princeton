// Week1_QuickFind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

// Quik Find -- Eager Approach

// index 0 1 2 3 4 5 6 7 8 9
// id[i] 0 1 1 8 8 0 0 1 8 8

// In Graph:
// 0  1--2  3--4
// |     |  |  |
// 5--6  7  8  9

int index[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int id[] = {0, 1, 1, 8, 8, 0, 0, 1, 8, 8};

vector<int> vecIndex;
vector<int> vecID;

void Init();

void connect(int index, int index2)
{
	cout << "connect " << index << " with " << index2<< endl;

	// 遍历一次花费较大
	int nID = vecID[index];
	int nID_Old = vecID[index2];
	for (int i = 0; i < vecID.size(); i++)
	{
		if (vecID[i] == nID_Old)
		{
			vecID[i] = nID;
		}
	}
}

bool IsConnect(int index, int index2)
{
	return vecID[index] == vecID[index2];
}

void Print()
{
	vector<bool> vecBMarked(vecID.size());

	for (int i = 0; i < vecIndex.size(); i++)
	{
		int nID = vecID[i];
		bool bHasOut = false;
		for (int j = 0; j < vecIndex.size(); j++)
		{
			if (vecBMarked[j] == false && nID == vecID[j])
			{
				bHasOut = true;

				vecBMarked[j] = true;
				cout << vecIndex[j] << " ";
			}
		}
		if (bHasOut)
		{
			cout << endl;
		}		
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Init();

	cout << "Original" << endl;
	Print();
	int index = 0, index2 = 1;
	cout << "IsConnect(" 
		<< index << "-" << index2 << "): " 
		<< IsConnect(index, index2) << endl;


	cout << endl;
	connect(0, 1);
	Print();

	cout << "IsConnect(" 
		<< index << "-" << index2 << "): " 
		<< IsConnect(index, index2) << endl;

	return 0;
}

void Init()
{
	vecIndex.assign(index, index+10);
	vecID.assign(id, id+10);
}
