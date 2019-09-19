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

	vecTree.erase(vecTree.begin()+removePos);

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
	while ((2*pos) < vecTree.size()-1)
	{
		int j = 2*pos;
		if ((j+1) < (vecTree.size()-1)
			&& vecTree[j] < vecTree[j+1])
		{
			j = j+1;
			swap(vecTree[pos], vecTree[j]);
		} 
		else if (vecTree[pos] < vecTree[j])
		{
			swap(vecTree[pos], vecTree[j]);
		}

		pos = j;
	}	
}
