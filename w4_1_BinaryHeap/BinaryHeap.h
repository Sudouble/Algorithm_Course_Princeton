#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class BinaryHeap
{
public:
	BinaryHeap(void);
	~BinaryHeap(void);

	void Init(vector<string> &vecStr);

	void Insert(string str);
	string delMax();

	bool IsEmpty();

	void swim(int pos);
	void sink(int pos);

	vector<string> GetTree() const{
		return vecTree;
	}

private:
	vector<string> vecTree;
};

