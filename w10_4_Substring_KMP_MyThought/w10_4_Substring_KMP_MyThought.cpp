// w10_4_Substring_KMP_MyThought.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

// 我的计算方法
int calcLongestFixed(string strMismatch, string pattern, int max_index) {	
	if (max_index < 1)
		return -1;

	int subpos = strMismatch.length() - max_index;
	// 从最长的子字符串开始，进行匹配	
	string subSuffix = strMismatch.substr(subpos, max_index);
	string strPrefix = pattern.substr(0, max_index);

	int M = subSuffix.length();	

	string sub_true_suffix = subSuffix.substr(0, M - 1);
	string sub_true_prefix = strPrefix.substr(0, M - 1);

	char pos_i_char = strPrefix[M - 1]; // 新位置
	char pos_j_char = subSuffix[M - 1]; // 原失配处	

	// 找到pat[1, i - 1] = pat[j - i + 1, j - 1],并满足
	// pat[i] != pat[j]的情况
	if (sub_true_suffix.compare(sub_true_prefix) == 0
		&& pos_i_char != pos_j_char){
		return sub_true_suffix.length();
	} else {
		return calcLongestFixed(strMismatch, pattern, max_index - 1);
	}
}

int calcLongestFixed(string strMismatch, string pattern ){
	int i = strMismatch.length();
	int max_index = i - 1;
	return calcLongestFixed(strMismatch, pattern, max_index);
}

vector<int> InitVectorNext_my_method(string& pattern) {
	vector<int> vecNext;
	for (int i = 0; i < pattern.length(); i++) {
		string substring = pattern.substr(0, i + 1);
		int pos = calcLongestFixed(substring, pattern);

		vecNext.push_back(pos);
	}
	return vecNext;
}

// 作者论文中所描述的方法
vector<int> InitVectorNext_author_method(string &pattern)
{
	int N = pattern.length();
	vector<int> vecNext;
	vecNext.resize(N, -1); // 初始条件：vecNext[0] = 0，其他重新计算;

	vector<int> f;
	f.resize(N, -1); // 初始条件：vecF[0] = 0，其他重新计算;

	for (int j = 0; j < N-1;) {
		// 先找到pat[1,i-1]=pat[j-i+1,j-1]的情况
		int t = f[j];
		while (t >= 0 && pattern[j] != pattern[t])
			t = vecNext[t];
		f[j + 1] = t + 1;
		j++;

		// 判断pat[i]和pat[j]的情况
		if (pattern[j] == pattern[f[j]])
			vecNext[j] = vecNext[f[j]];
		else
		{
			vecNext[j] = f[j];
		}
	}
	return vecNext;
}

int search(string& strText, string& pattern, vector<int> &vecNext) {
	int i = 0, j = 0;
	int N = strText.length();
	int M = pattern.length();
	for (; i < N && j < M;) {
		if (j == -1 || strText[i] == pattern[j]) {
			j++; i++;
			if (j >= M)
				return i - M;
		} else {
			j = vecNext[j];
		}
	}
	return -1;
}

void testCalcLongestFixed();

int main()
{
	testCalcLongestFixed();
	
	/////////////////////////////////////////////////////////////////
	cout << "test 1" << endl;
	cout << "Expected: -1 0 0 0 -1 0 2" << endl;
	string patter_ryf = "ABCDABD";
	vector<int> vecNextRYF = InitVectorNext_author_method(patter_ryf);
	for (int i = 0; i < vecNextRYF.size(); i++) {
		cout << vecNextRYF[i] << " ";
	}
	cout << endl;
	/////////////////////////////////////////////////////////////////
	cout << "test 2" << endl;
	cout << "Expected: -1 0 0 -1 0 0 -1 4 -1 0" << endl << "Actual: ";
	string pattern_paper = "abcabcacab";
	vector<int> vecNext_author = InitVectorNext_author_method(pattern_paper);
	for (int i = 0; i < vecNext_author.size(); i++) {
		cout << vecNext_author[i] << " ";
	}
	cout << endl;
	/////////////////////////////////////////////////////////////////
	{
		cout << "========My method============" << endl;
		string txt1 = "aabracadabra abacadabrabracabracadabrabrabracad";
		string pattern1 = "abracadabra";
		cout << "===========================" << endl;
		vector<int> vecNext = InitVectorNext_my_method(pattern1);
		cout << search(txt1, pattern1, vecNext) << endl;

		string txt2 = "abacadabrabracabracadabrabrabracad";
		//string txt2 = "rrabasdsfsdasdfra";
		string pattern2 = "rab";
		cout << "===========================" << endl;
		vector<int> vecNext2 = InitVectorNext_my_method(pattern2);
		cout << search(txt2, pattern2, vecNext2) << endl;
	}	
	{
		cout << "========Author's method============" << endl;
		string txt1 = "aabracadabra abacadabrabracabracadabrabrabracad";
		string pattern1 = "abracadabra";
		cout << "===========================" << endl;
		vector<int> vecNext = InitVectorNext_author_method(pattern1);
		cout << search(txt1, pattern1, vecNext) << endl;

		string txt2 = "rrarabasdsfsdasdfra";
		string pattern2 = "rab";
		cout << "===========================" << endl;
		vector<int> vecNext2 = InitVectorNext_author_method(pattern2);
		cout << search(txt2, pattern2, vecNext2) << endl;
	}	
}

void testCalcLongestFixed()
{
	string pattern = "aaabc";
	string s1 = "aaac"; // aaax处失配
	assert(calcLongestFixed(s1, pattern) == 2);

	string s2 = "aaabd"; // aaabx处失配
	cout << calcLongestFixed(s2, pattern);
	assert(calcLongestFixed(s2, pattern) == 0);
}