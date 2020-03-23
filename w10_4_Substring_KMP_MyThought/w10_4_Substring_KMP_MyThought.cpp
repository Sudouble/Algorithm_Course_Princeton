// w10_4_Substring_KMP_MyThought.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

int calcLongestFixed(string strCur, string &pattern, int i)
{	
	int N = strCur.length();
	if (i > N)
		return 0;

	string strsub = strCur.substr(0, i-1);
	string patternPrefix = pattern.substr(N-i);
	if (strsub.substr(0, i-2) == patternPrefix.substr(0, i-2)
		&& strsub[i-1] != patternPrefix[i-1])
	{
		return strsub.length();
	}
	else
		return calcLongestFixed(strCur, pattern, i + 1);
}

int calcLongestFixed(string strCur, string& pattern)
{
	return calcLongestFixed(strCur, pattern, 1);
}

vector<int> InitVectorNext1(string& pattern)
{
	vector<int> vecNext;
	for (int i = 0; i < pattern.length(); i++)
	{
		string substring = pattern.substr(0, i + 1);
		int pos = calcLongestFixed(substring, pattern);

		vecNext.push_back(pos);
	}
	return vecNext;
}

vector<int> InitVectorNext2(string &pattern)
{
	int N = pattern.length();
	
	vector<int> vecNext;
	vecNext.resize(N);
	vecNext[0] = 0;

	int j = 0;
	for (int pos = 0; pos < N; pos++)
	{
		if (pattern[pos] == pattern[vecNext[j]])
		{
			vecNext[j + 1] = vecNext[j] + 1;
		}
		else
		{
			j = j - vecNext[j];
		}
	}
	return vecNext;
}

int search(string& strText, string& pattern, vector<int> &vecNext)
{
	int i = 0, j = 0;
	int N = strText.length();
	int M = pattern.length();
	for (; i < N && j < M; i++)
	{
		if (strText[i] == pattern[j])
		{
			j++;			
		}
		else
		{
			j = 0;
			i = i - vecNext[j];
		}
	}
	if (j == M)
		return i - M;
	return -1;
}

void testCalcLongestFixed();

int main()
{
    std::cout << "Hello World!\n";

	testCalcLongestFixed();

	string patter_ryf = "ABCDABD";
	vector<int> vecNextRYF = InitVectorNext1(patter_ryf);
	
	string txt1 = "aabracadabra abacadabrabracabracadabrabrabracad";
	string pattern1 = "abracadabra";	
	cout << "===========================" << endl;
	vector<int> vecNext = InitVectorNext1(pattern1);
	cout << search(txt1, pattern1, vecNext) << endl;

	string txt2 = "abacadabrabracabracadabrabrabracad";
	string pattern2 = "rab";
	cout << "===========================" << endl;
	vector<int> vecNext2 = InitVectorNext1(pattern2);
	cout << search(txt2, pattern2, vecNext2) << endl;
}

void testCalcLongestFixed()
{
	string pattern = "aaabc";
	string s1 = "aaa"; // aaax处失配
	assert(calcLongestFixed(s1, pattern) == 3);

	string s2 = "aaab"; // aaabx处失配
	assert(calcLongestFixed(s2, pattern) == 4);

	// 《算法：第四版》第497页的例子
	string  pattern2 = "ABABAC";
	{
		string s3 = "A";
		assert((__LINE__, calcLongestFixed(s3, pattern2) == 1));
	}
	{
		string s3 = "B";
		assert((__LINE__, calcLongestFixed(s3, pattern2) == 0));
	}
	{
		string s3 = "C";
		assert((__LINE__, calcLongestFixed(s3, pattern2) == 0));
	}
	{
		string s3 = "AA";
		assert((__LINE__, calcLongestFixed(s3, pattern2) == 1));
	}
	{
		string s3 = "AB";
		assert((__LINE__, calcLongestFixed(s3, pattern2) == 2));
	}
	{
		string s3 = "AC";
		assert((__LINE__, calcLongestFixed(s3, pattern2) == 0));
	}
	{
		string s3 = "ABAB";
		assert((__LINE__, calcLongestFixed(s3, pattern2) == 4));
	}
	{
		string s3 = "ABABB";
		assert((__LINE__, calcLongestFixed(s3, pattern2) == 0));
	}
	{
		string s3 = "ABABAB";
		assert((__LINE__, calcLongestFixed(s3, pattern2) == 4));
	}
}