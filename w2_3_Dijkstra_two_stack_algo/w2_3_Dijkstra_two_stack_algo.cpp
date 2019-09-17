// w2_3_Dijkstra_two_stack_algo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <string>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "(2+((2+3)*(4*5)))";

	stack<char> stackOps;
	stack<int>	stackInt;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
		}
		else if (str[i] == ')')
		{
			char ops = stackOps.top();
			stackOps.pop();

			int second = stackInt.top();
			stackInt.pop();
			int fisrt = stackInt.top();
			stackInt.pop();

			int result = 0;
			switch(ops)
			{
			case '+':
				result = fisrt + second;
				break;
			case '-':
				result = fisrt - second;
				break;				
			case '*':
				result = fisrt * second;
				break;
			case '/':
				result = fisrt / second;
				break;
			}
			
			stackInt.push(result);
		}
		else if (str[i] >= '0'&& str[i] <= '9')
		{
			char ch[1];
			ch[0] = str[i];
			stackInt.push(atoi(ch));
		}
		else
		{
			stackOps.push(str[i]);
		}
	}

	cout << "calced:" << stackInt.top() << ", expected:102" << endl;

	return 0;
}

