// w4_6_MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

// Directly split up, and merge
// O(NlgN)
// D(N) = 2D(N/2)+N

void sort(vector<int> &vec_);


void MergeSort(vector<int> &vec_)
{
	sort(vec_);
}

void Merge( vector<int> &vec_, vector<int> &vecLeft, vector<int> &vecRight )
{
	vec_.clear();
	int nLeft = 0, nRight = 0;
	while (nLeft < vecLeft.size() && nRight < vecRight.size())
	{		
		if (vecLeft[nLeft] < vecRight[nRight])
		{
			vec_.push_back(vecLeft[nLeft]);
			nLeft++;
		}
		else
		{
			vec_.push_back(vecRight[nRight]);
			nRight++;
		}
	}

	while (nLeft < vecLeft.size())
	{
		vec_.push_back(vecLeft[nLeft]);
		nLeft++;
	}
	while (nRight < vecRight.size())
	{
		vec_.push_back(vecRight[nRight]);
		nRight++;
	}
}

void sort(vector<int> &vec_)
{
	if (vec_.size() == 1)
		return;

	// split
	int half = vec_.size()/2;
	vector<int> vecLeft;
	vecLeft.assign(vec_.begin(), vec_.begin()+half);
	sort(vecLeft);

	vector<int> vecRight;
	vecRight.assign(vec_.begin()+half, vec_.end());
	sort(vecRight);

	// merge
	Merge(vec_, vecLeft, vecRight);
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
	Print(vecIn);

	MergeSort(vecIn);
	Print(vecIn);

	return 0;
}

