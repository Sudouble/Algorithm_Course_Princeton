// w3_4_shuffling.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
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

// 

int _tmain(int argc, _TCHAR* argv[])
{
	int index[] = {12,3,45,3,2,45,7,1,3,8,45,3,4,59,55};
	vector<int> vecIn;

	vecIn.assign(index, index+sizeof(index)/sizeof(int));
	Print(vecIn);

	Shuffling(vecIn);

	cout << "After Shuffle: ";
	Print(vecIn);


	return 0;
}

