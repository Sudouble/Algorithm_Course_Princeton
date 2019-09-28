// w9_5_Quick3String.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

inline int charAt(string &str, int i)
{
	if (i >= str.length())
		return -1;
	return str[i];
}

void _3WayQuickSort(vector<string> & vecStr, int lo, int hi, int d)
{
	if (lo >= hi)
		return;

	int lt = lo, gt = hi;
	int v = charAt(vecStr[lo], d);
	int i = lo + 1;
	while (i <= gt)
	{
		int t = charAt(vecStr[i], d);
		if (t < v)
			swap(vecStr[i++], vecStr[lt++]);
		else if (t > v)
			swap(vecStr[i], vecStr[gt--]);
		else
			i++;
	}

	_3WayQuickSort(vecStr, lo, lt-1, d);
	if (v >= 0)
		_3WayQuickSort(vecStr, lt, gt, d + 1);
	_3WayQuickSort(vecStr, gt+1, hi, d);
}

int main()
{
	vector<string> vecString;
	vecString.push_back("4PGC938");
	vecString.push_back("2IYE230");
	vecString.push_back("3CI0720");
	vecString.push_back("1ICK750");
	vecString.push_back("10HV845");
	vecString.push_back("4JZY524");
	vecString.push_back("1ICK750");

	int w = vecString.size();
	_3WayQuickSort(vecString, 0, w-1, 0);

	for (size_t i = 0; i < vecString.size(); i++)
	{
		cout << vecString[i] << endl;
	}
}
