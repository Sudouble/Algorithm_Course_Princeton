// w9_6_SuffixArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> subStrings(string s)
{
	vector<string> vecStr;
	for (size_t i = 0; i < s.length(); i++)
	{
		vecStr.push_back(s.substr(i));
	}

	return vecStr;
}

inline int charAt(string& str, int i)
{
	if (i >= str.length())
		return -1;
	return str[i];
}

void _3WayQuickSort(vector<string>& vecStr, int lo, int hi, int d)
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

	_3WayQuickSort(vecStr, lo, lt - 1, d);
	if (v >= 0)
		_3WayQuickSort(vecStr, lt, gt, d + 1);
	_3WayQuickSort(vecStr, gt + 1, hi, d);
}

void _3WayQuickSort(vector<string>& vecStr)
{
	int w = vecStr.size();
	_3WayQuickSort(vecStr, 0, w - 1, 0);
}

int LongestCommonPrefix(string& str1, string& str2)
{
	int fs = 0;
	int second = 0;
	while (fs < str1.length() && second < str2.length())
	{
		if (str1[fs++] != str2[second++])
			break;
	}
	return fs;
}

string find_LRS(vector<string>& vecSrc)
{
	string s = "";
	for (size_t i = 0; i < vecSrc.size()-1; i++)
	{
		int len = LongestCommonPrefix(vecSrc[i], vecSrc[i+1]);
		if (len > s.length())
			s = vecSrc[i].substr(0, len);
	}
	return s;
}

int main()
{
	string s = "alike ali big dog";
	vector<string> subs = subStrings(s);

	for (size_t i = 0; i < subs.size(); i++)
	{
		cout << subs[i] << endl;
	}
	cout << "========================" << endl;
	_3WayQuickSort(subs);
	cout << "========================" << endl;
	cout << "LRS:" << find_LRS(subs) << endl;

	return 0;
}
