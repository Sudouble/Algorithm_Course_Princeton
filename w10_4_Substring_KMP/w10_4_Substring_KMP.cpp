// w10_4_Substring_KMP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int R = 256;
vector<vector<int> > dfa;

void KMP(string &pat)
{
	dfa.clear();
	dfa.resize(R);
	for (int i = 0; i < dfa.size(); i++)
		dfa[i].resize(pat.length());

	int M = pat.length();
	dfa[pat[0]][0] = 1;
	for (int X = 0, j = 1; j < M; j++)
	{
		for (int c = 0; c < R; c++)
			dfa[c][j] = dfa[c][X];
		dfa[pat[j]][j] = j + 1;

		X = dfa[pat[j]][X];
	}
}

int search(string &txt, string &pat)
{
	int i, j;
	int N = txt.length(), M = pat.length();
	for (i = 0, j = 0; i < N && j < M; i++)
	{
		j = dfa[txt[i]][j];		
	}
	if (j == M)
		return i - M;
	return -1;
}

int main()
{
	string txt1 = "abracadabra abacadabrabracabracadabrabrabracad";
	string pattern1 = "abracadabra";
	cout << "===========================" << endl;
	KMP(pattern1);
	cout << search(txt1, pattern1) << endl;

	string txt2 = "abacadabrabracabracadabrabrabracad";
	string pattern2 = "rab";	
	cout << "===========================" << endl;
	KMP(pattern2);
	cout << search(txt2, pattern2) << endl;
}
