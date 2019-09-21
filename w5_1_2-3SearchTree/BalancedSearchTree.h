#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node
{
	vector<string> vecStrKey;
	vector<int> vecValue;

	vector<Node*> childNode;
	Node* parent;
	
	Node()
	{
		parent = NULL;

		vecStrKey.clear();
		vecValue.clear();
		childNode.clear();
		childNode.push_back(NULL);
		childNode.push_back(NULL);
	}

	Node(string key, int value, Node* parent_)
	{
		parent = parent_;

		vecStrKey.push_back(key);
		vecValue.push_back(value);

		childNode.push_back(NULL);
		childNode.push_back(NULL);
	}
};

class BalancedSearchTree
{
public:
	BalancedSearchTree();
	
	void Insert(string key, int value=0);
	bool Contains(string key);

private:
	void put(Node* node, string key, int value);

	int calcNodePos(Node* node, string key);	

	bool IsEmpty();

	Node* get(Node* node, string key);
	void Node3(Node* node);
	Node* UpdateParent(Node* node);

private:
	Node* root;
};

