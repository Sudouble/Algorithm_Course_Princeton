// w10_5_Substring_BoyerMoore.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

const int R = 256;
vector<int> vecRight;

void BoyerMoore(string &pat)
{
	vecRight.clear();
	vecRight.resize(R, -1);

	for (size_t i = 0; i < pat.length(); i++)
	{
		vecRight[pat[i]] = i;
	}
}

int search(string txt, string pat)
{
	int N = txt.length();
	int M = pat.length();

	int skip;
	for (int i = 0; i <= N - M; i += skip)
	{
		skip = 0;
		for (int j = M-1; j >= 0; j--)
		{
			if (pat[j] != txt[i + j])
			{
				skip = j - vecRight[txt[i + j]];
				if (skip < 1)
					skip = 1;
				break;
			}
		}
		if (skip == 0)
			return i;
	}
	return -1;
}

int main()
{
	string txt1 = "abracadabra abacadabrabracabracadabrabrabracad";
	string pattern1 = "abracadabra";
	cout << "===========================" << endl;
	BoyerMoore(pattern1);
	cout << search(txt1, pattern1) << endl;

	string txt2 = "abacadabrabracabracadabrabrabracad";
	string pattern2 = "rab";
	cout << "===========================" << endl;
	BoyerMoore(pattern2);
	cout << search(txt2, pattern2) << endl;
}

