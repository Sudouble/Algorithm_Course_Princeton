// w10_4_Substring_KMP_MyThought.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

#define GET_FUNC_NAME(name) string(#name).c_str()


template<class T>
bool test_value(const T& expected, const T& actual, string strDescrib="", bool ToCoutWhenFail=true)
{
	if (expected != actual)
	{
		if (ToCoutWhenFail)
			cout << strDescrib.c_str() << " not equal! Expected: " << expected << " Actual:" << actual << endl;
		return false;
	}
	else
	{
		//cout << strDescrib.c_str() << " OK, value: " << expected << endl;
		return true;
	}
}

string form_array_string(vector<int> vec)
{
	string str = "";

	char tmp[100] = {0};
	for (int i = 0; i < vec.size(); i++)
	{
		sprintf(tmp, "%d ", vec[i]);
		str +=  tmp;
	}
	str += "\r\n";
	return str;
}

void test_array(const vector<int> &vecExpected, const vector<int> &vecActual, bool ToCoutWhenFail=true)
{
	if (!test_value(vecExpected.size(), vecActual.size(), "Array size", ToCoutWhenFail))
		return;
	
	for (int j = 0; j < vecExpected.size(); j++)
	{
		if (vecExpected[j] != vecActual[j])
		{
			if (ToCoutWhenFail)
			{
				cout << "Error!" << endl;

				cout << "Expected array: " << form_array_string(vecExpected).c_str();
				cout << "Actual array: " << form_array_string(vecActual).c_str();
			}			
			return;
		}
	}
	//cout << "OK!" << endl;
	//cout << "Expected array: " << form_array_string(vecExpected).c_str();
	//cout << "Actual array: " << form_array_string(vecActual).c_str();
	return;
}

struct ST_INPUT_FORM
{
	string text;
	string pattern;
	vector<int> expected_next;
	int expected_pos;

	ST_INPUT_FORM()
	{
		text = "";
		pattern = "";
		expected_pos = -1;
		expected_next.clear();
	}

	void initNext(int *array, int len)
	{
		expected_next.clear();
		for (int i = 0; i < len; i++)
		{
			int value = *(array+i);
			expected_next.push_back(value);
		}
	}
};

typedef vector<int> (*FUNC_NEXT_CALC)(string &pattern);

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
	cout << "*******Using function: " << __FUNCTION__ << "*******" << endl;

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
	cout << "*******Using function: " << __FUNCTION__ << "*******" << endl;

	int N = pattern.length();
	vector<int> next;	
	next.resize(N, 0); 
	// 初始条件：j=0时，i肯定是不存在的定义为-1，其他位置值任意。
	next[0] = -1;

	//// 优化前的代码
	//vector<int> f;
	//f.resize(N, -1);
	//// 初始条件：j=0时，i肯定是不存在的定义为-1，其他位置值任意。
	//f[0] = -1;

	//for (int j = 0; j < N-1;) {
	//	// 先找到pat[1,i-1]=pat[j-i+1,j-1]的情况
	//	int t = f[j];
	//	while (t > -1 && pattern[j] != pattern[t])
	//		t = next[t];
	//	f[j + 1] = t + 1;
	//	j++;

	//	// 判断pat[i]和pat[j]的情况
	//	if (pattern[j] == pattern[f[j]])
	//		next[j] = next[f[j]];
	//	else
	//	{
	//		next[j] = f[j];
	//	}
	//}

	// 优化后的代码	
	int t = -1; // 初始条件：j=0时，i肯定是不存在的定义为-1，其他位置值任意。
	for (int j = 0; j < N-1;) {
		// 先找到pat[1,i-1]=pat[j-i+1,j-1]的情况
		while (t > -1 && pattern[j] != pattern[t])
			t = next[t];
		t = t + 1;
		j++;

		// 判断pat[i]和pat[j]的情况
		if (pattern[j] != pattern[t])
			next[j] = t;
		else
			next[j] = next[t];
	}
	return next;
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

vector<FUNC_NEXT_CALC> initTestFunc();
vector<ST_INPUT_FORM> initTestInput();
void testSuite(vector<FUNC_NEXT_CALC> &vecFunc, vector<ST_INPUT_FORM> &vecInput);

//////////////////////////////////////////////////////////////////////////
int main()
{
	testCalcLongestFixed();

	vector<FUNC_NEXT_CALC> vecFunc = initTestFunc();
	vector<ST_INPUT_FORM> vecInput = initTestInput();	

	testSuite(vecFunc, vecInput);
	
	return 0;
}

//////////////////////////////////////////////////////////////////////////
vector<FUNC_NEXT_CALC> initTestFunc()
{
	vector<FUNC_NEXT_CALC> vecFunc;
	vecFunc.push_back(InitVectorNext_my_method);
	vecFunc.push_back(InitVectorNext_author_method);

	return vecFunc;
}

vector<ST_INPUT_FORM> initTestInput()
{
	vector<ST_INPUT_FORM> vecInput;

	{
		ST_INPUT_FORM testCase;
		testCase.pattern = "ABCDABD";
		int a[] = {-1,0,0,0,-1,0,2};
		testCase.initNext(a, sizeof(a)/sizeof(int));
		vecInput.push_back(testCase);

	}
	{
		ST_INPUT_FORM testCase;
		testCase.pattern = "abcabcacab";
		int a[] = {-1, 0, 0, -1, 0, 0, -1, 4, -1, 0};
		testCase.initNext(a, sizeof(a)/sizeof(int));

		vecInput.push_back(testCase);
	}
	{
		ST_INPUT_FORM testCase;
		testCase.text = "aabracadabra abacadabrabracabracadabrabrabracad";
		testCase.pattern = "abracadabra";
		int a[] = {-1,0,0,-1,1,-1,1,-1,0,0,-1};
		testCase.initNext(a, sizeof(a)/sizeof(int));
		testCase.expected_pos = 1;
		vecInput.push_back(testCase);
	}
	{
		ST_INPUT_FORM testCase;
		testCase.text = "abacadabrabracabracadabrabrabracad";
		testCase.pattern = "rab";
		int a[] = {-1, 0, 0};
		testCase.initNext(a, sizeof(a)/sizeof(int));
		testCase.expected_pos = 9;

		vecInput.push_back(testCase);
	}
	return vecInput;
}

void testCalcLongestFixed()
{
	string pattern = "aaabc";
	string s1 = "aaac"; // aaax处失配
	assert(calcLongestFixed(s1, pattern) == 2);

	string s2 = "aaabd"; // aaabx处失配
	assert(calcLongestFixed(s2, pattern) == 0);
}

void testSuite(vector<FUNC_NEXT_CALC> &vecFunc, vector<ST_INPUT_FORM> &vecInput)
{	
	for (int i = 0; i < vecFunc.size(); i++)
	{
		FUNC_NEXT_CALC funcNext = vecFunc[i];		

		int testCount = 1;
		for (int j = 0; j < vecInput.size(); j++)
		{
			cout << "=================================="<< endl;
			cout << "Testing case:" << testCount++ << endl;
			ST_INPUT_FORM stForm = vecInput[j];

			vector<int> vecNext = funcNext(stForm.pattern);
			test_array(stForm.expected_next, vecNext);

			if (stForm.text.length() > 0 && stForm.expected_pos != -1)
			{
				int pos = search(stForm.text, stForm.pattern, vecNext);
				test_value(stForm.expected_pos, pos, "match pos");
			}
		}
		cout << endl;
	}
}