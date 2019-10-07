// w10_Substring_RabinKarp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

const int R = 10;
const int Q = 997;

int genLongValue()
{
	return 997;
}

long hashCalc(string key, int lenth)
{
	long h = 0;
	for (int i = 0; i < lenth; i++)
	{
		h = (R * h + key[i]) % Q;
	}
	return h;
}

int search(string txt, string pattern)
{
	int N = txt.length();
	int M = pattern.length();

	long hashPattern = hashCalc(pattern, pattern.length());

	int RM = 1;
	for (int i = 1; i < M; i++)
	{
		RM = (R * RM) % Q;
	}

	long txtHash = hashCalc(txt, M);
	for (int i = M; i < N; i++)
	{
		int tmpResult = txt[i - M] * (Q) % Q;
		//txtHash = (txtHash + Q - txt[i - M] * RM % Q) % Q;
		txtHash = (txtHash + txt[i - M] * (Q - RM) % Q) % Q; // 恢复并减去
		txtHash = (txtHash * R + txt[i]) % Q;  // 加上末尾
		if (txtHash == hashPattern)
			return i - M + 1;
	}
	return -1;
}

int main()
{
	string txt = "3141592653589793";
	string pattern = "26535";

	cout << search(txt, pattern) << endl;
}
