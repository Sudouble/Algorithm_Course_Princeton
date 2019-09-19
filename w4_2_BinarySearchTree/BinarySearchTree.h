#pragma once
#include <string>
using namespace std;

struct Node{
	string key;
	int count;

	Node *left;
	Node *right;

	Node() {
		key = "";
		count = 0;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree
{
public:
	BinarySearchTree(void);
	~BinarySearchTree(void);

	bool search(string str);
	void insert(string key);
	void put();
	
	void Delete();

private:
	Node *root;
};

