// w9_4_MSDRadixSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <string>
#include <vector>
using namespace std;

int charAt(string str, int i)
{
	if (i >= str.length())
		return -1;	
	return str[i];
}

// Most-significant-digit-first string sort
void KeyIndexCount(vector<string>& vecStr, int w)
{
	int R = 256;

	for (int d = 0; d < w; d++)
	{
		vector<int> r_count;
		r_count.resize(R + 2, 0);

		// count
		for (size_t i = 0; i < vecStr.size(); i++)
		{
			r_count[charAt(vecStr[i], d) + 2]++;
		}

		// index
		for (size_t i = 0; i < R+1; i++)
		{
			r_count[i + 1] += r_count[i];
		}

		// arrange
		vector<string> aa;
		aa.resize(vecStr.size());
		for (size_t i = 0; i < vecStr.size(); i++)
		{
			aa[r_count[charAt(vecStr[i], d) + 1]++] = vecStr[i];
		}

		// copy
		vecStr = aa; //第一轮OK，接下来对子序列进行排序
	}
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
	KeyIndexCount(vecString, w);

	for (size_t i = 0; i < vecString.size(); i++)
	{
		cout << vecString[i] << endl;
	}
}
