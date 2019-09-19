#pragma once
#include <string>
using namespace std;

struct Node{
	string key;
	int value;

	Node *left;
	Node *right;
	int size;

	Node(string key_, int value_, int size_) {
		key = key_;
		value = value_;
		size = size_;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree
{
public:
	BinarySearchTree(void);
	~BinarySearchTree(void);

	bool IsEmpty();

	Node* search(string str);
	void insert(string key, int value);
	
	void Delete(string key);
	void DeleteMin();
	void DeleteMax();

private:
	Node* put(Node* node, string str, int value);
	Node* get(Node* node, string str);
	int size(Node* node);

	Node* DeleteMin(Node *node);
	Node* DeleteMax(Node *node);
	Node* Delete(Node* node, string key);
	Node* GetMin(Node* node);

private:
	Node *root;
};

