// w3_7_QuickSort.cpp : �������̨Ӧ�ó������ڵ㡣
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



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

