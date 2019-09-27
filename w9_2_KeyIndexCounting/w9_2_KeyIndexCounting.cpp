// w9_2_KeyIndexCounting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> KeyIndexCount(string a)
{
	vector<int> r_count;
	r_count.resize(26 + 1, 0);

	// count
	for (size_t i = 0; i < a.length(); i++)
	{
		r_count[a[i] - 'a' + 1]++;
	}

	// index
	for (size_t i = 0; i < 26; i++)
	{
		r_count[i + 1] += r_count[i];
	}

	// arrange
	vector<char> aa;
	aa.resize(a.length());

	for (size_t i = 0; i < a.length(); i++)
	{
		aa[r_count[a[i] - 'a']] = a[i];
		r_count[a[i] - 'a']++;
	}
	
	return aa;
}

int main()
{
	string a = "dacffbdbfbea";

	vector<char> aa = KeyIndexCount(a);

	for (size_t i = 0; i < aa.size(); i++)
	{
		cout << aa[i];
	}
	cout << endl;
}
