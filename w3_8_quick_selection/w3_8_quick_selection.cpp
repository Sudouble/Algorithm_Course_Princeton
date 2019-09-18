// w3_8_quick_selection.cpp : 定义控制台应用程序的入口点。
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

void Print(const vector<int> &vecIn)
{
	for (int i = 0; i < vecIn.size(); i++)
	{
		cout << vecIn[i] << ",";
	}
	cout << endl;
}


int quick_selection(vector<int> &vecIn, int rank)
{	
	if (vecIn.size() == 1)
		return vecIn[0];

	//////////////////////////////////////////////////////////////////////////
	int nPivot = vecIn[0];

	vector<int> vecLess;
	vector<int> vecMore;
	for (int i = 1; i < vecIn.size(); i++)
	{
		if (vecIn[i] > nPivot)
			vecMore.push_back(vecIn[i]);
		else
			vecLess.push_back(vecIn[i]);
	}
	
	if (rank < vecMore.size())
	{
		return quick_selection(vecMore, rank);
	}
	else if (rank >= vecMore.size()+1)
	{
		rank -= vecMore.size()+1;
		return quick_selection(vecLess, rank);		
	}
	else
	{
		return nPivot;
	}
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

	int rank = quick_selection(vecIn, 5);
	cout << "rank 5: " << rank << endl;

	rank = quick_selection(vecIn, 2);
	cout << "rank 2: " << rank << endl;

	rank = quick_selection(vecIn, 1);
	cout << "rank 1: " << rank << endl;

	rank = quick_selection(vecIn, 0);
	cout << "rank 0: " << rank << endl;

	return 0;
}

