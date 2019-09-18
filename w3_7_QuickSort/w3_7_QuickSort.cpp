// w3_7_QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

void Shuffling( vector<int> &vecIn )
{
	for (int i = vecIn.size()-1; i > 0; --i)
	{
		int nVal = rand()%(i);

		swap(vecIn[nVal], vecIn[i]);
	}
}

void MoveIn(vector<int> &vecIn, vector<int> &vecsrc)
{
	for (int i = 0; i < vecsrc.size(); i++)
	{
		vecIn.push_back(vecsrc[i]);
	}
}

void quick_sort(vector<int> &vecIn)
{
	if (vecIn.size() <= 1)
		return;

	int npivot = vecIn[0];

	vector<int> vecLess;
	vector<int> vecMore;
	for (int i = 1; i < vecIn.size(); i++)
	{
		if (vecIn[i] < npivot)
			vecLess.push_back(vecIn[i]);
		else
			vecMore.push_back(vecIn[i]);
	}	

	quick_sort(vecLess);
	quick_sort(vecMore);

	vecIn.clear();
	MoveIn(vecIn, vecLess);
	vecIn.push_back(npivot);
	MoveIn(vecIn, vecMore);
}

void Print(const vector<int> &vecIn)
{
	for (int i = 0; i < vecIn.size(); i++)
	{
		cout << vecIn[i] << ",";
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int index[] = {12,3,45,3,2,45,7,1,3,8,45,3,4,59,55};
	vector<int> vecIn;

	vecIn.assign(index, index+sizeof(index)/sizeof(int));
	cout << "Init: ";
	Print(vecIn);

	srand(int(time(0)));
	Shuffling(vecIn);
	cout << "Shuffled: ";
	Print(vecIn);

	quick_sort(vecIn);
	cout << "Sorted: ";
	Print(vecIn);

	return 0;
}

