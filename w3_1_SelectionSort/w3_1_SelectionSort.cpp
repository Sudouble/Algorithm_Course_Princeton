// w3_1_SelectionSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

void SelectionSort(vector<int> &vecIn)
{
	for (int i = 0; i < vecIn.size(); i++)
	{
		for (int j = i+1; j < vecIn.size(); j++)
		{
			if (vecIn[i] > vecIn[j])
			{
				swap(vecIn[i], vecIn[j]);
			}
		}
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

int _tmain(int argc, _TCHAR* argv[])
{
	int index[] = {12,3,45,3,2,45,7,1,3,8,45,3,4,59,55};
	vector<int> vecIn;
	vecIn.assign(index, index+sizeof(index)/sizeof(int));	
	Print(vecIn);

	SelectionSort(vecIn);
	Print(vecIn);

	return 0;
}

