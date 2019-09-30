// w10_3_Substring_BruteForce.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int BruteForce_1(string txt, string pattern)
{
	for (size_t i = 0; i < txt.length(); i++)
	{
		int k = i;
		for (size_t j = 0; j < pattern.length(); j++)
		{
			if (txt[k++] != pattern[j])
			{
				break;
			}
		}
		if ((k - i) == pattern.length())
			return i;
	}
	return -1;
}

int BruteForce_2(string txt, string pattern)
{
	size_t i = 0, j = 0;
	size_t N = txt.length(), M = pattern.length();
	for (; i < N && j < M; i++)
	{
		if (txt[i] == pattern[j])
			j++;
		else
		{			
			i -= j;
			j = 0;
		}		
	}

	if (j == M)
		return i - M;
	else
		return -1;
}

int main()
{
	string txt1 = "abracadabra abacadabrabracabracadabrabrabracad";
	string pattern1 = "abracadabra";

	string txt2 = "abacadabrabracabracadabrabrabracad";
	string pattern2 = "rab";

	cout << "Brute force" << endl;
	cout << BruteForce_1(txt1, pattern1) << endl;
	cout << BruteForce_1(txt2, pattern2) << endl;

	cout << "Brute force with backup" << endl;
	cout << BruteForce_2(txt1, pattern1) << endl;
	cout << BruteForce_2(txt2, pattern2) << endl;
}
