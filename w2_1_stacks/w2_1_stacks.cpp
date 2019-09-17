// w2_1_stacks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "assert.h"
#include <iostream>
using namespace std;

#include "Stack_Linklist.h"

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		Stack_Linklist<int> stack;
		stack.push(1);
		int item = stack.pop();
		assert(1 == item);
		assert(0 == stack.size());
		assert(true == stack.IsEmpty());
		
		stack.push(2);
		stack.push(4);
		assert(4 == stack.pop());
		assert(2 == stack.pop());
	}
	catch (...)
	{
		cout << "Catch One" << endl;
	}		

	return 0;
}

