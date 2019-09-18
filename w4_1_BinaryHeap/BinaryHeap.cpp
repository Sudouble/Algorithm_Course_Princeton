#include "StdAfx.h"
#include "BinaryHeap.h"


BinaryHeap::BinaryHeap(void)
{

}

BinaryHeap::~BinaryHeap(void)
{

}

void BinaryHeap::Init(vector<string> &vecStr)
{
	vecTree.clear();
	vecTree.assign(vecStr.begin(), vecStr.end());
}

void BinaryHeap::Insert(string str)
{
	vecTree.push_back(str);
	swim(vecTree.size()-1);
}

string BinaryHeap::delMax()
{
	if (IsEmpty())
	{
		return ""; 
	}
	string result = vecTree[1];
	
	int removePos = vecTree.size()-1;
	swap(vecTree[1], vecTree[removePos]);
	sink(1);

	vecTree.erase(vecTree.begin()+removePos+1);

	return result;
}

bool BinaryHeap::IsEmpty()
{
	return vecTree.size() == 1;
}

void BinaryHeap::swim(int pos)
{
	int fatherPos = pos/2;
	while (fatherPos >=1 && vecTree[fatherPos] < vecTree[pos])
	{
		swap(vecTree[fatherPos], vecTree[pos]);
		pos = fatherPos;
		fatherPos = fatherPos/2;
	}
}

void BinaryHeap::sink(int pos)
{
	int childLeft = pos*2;
	int childRight = pos*2+1;

	while (pos < vecTree.size()-1)
	{
		if (vecTree[pos] < vecTree[childLeft])
		{
			swap(vecTree[pos], vecTree[childLeft]);
			pos = childLeft;
		}
		else
		{
			swap(vecTree[pos], vecTree[childRight]);
			pos = childRight;		
		}
		childLeft = pos*2;
		childRight = pos*2+1;
	}	
}
