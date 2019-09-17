// w2_2_queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>
using namespace std;

#include "Queue_LinkList.h"
#include "Queue_Array.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Queue_LinkList<int> queue;
	queue.push(10);
	queue.push(11);
	queue.push(12);

	assert(10 == queue.pop());
	assert(11 == queue.pop());
	assert(12 == queue.pop());

	//////////////////////////////////////////////////////////////////////////
	Queue_Array<int> queueArr;
	queueArr.push(10);
	assert(10 == queueArr.pop());

	queueArr.push(11);
	queueArr.push(12);
	queueArr.push(13);
	assert(11 == queueArr.pop());

	queueArr.push(14);
	queueArr.push(15);
	queueArr.push(16);
	assert(12 == queueArr.pop());

	return 0;
}

