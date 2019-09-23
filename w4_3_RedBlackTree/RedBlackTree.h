#pragma once

#include <string>
#include <iostream>
using std::string;

class Node
{
public:
	enum RBT_COLOR {
		BLACK = 0,
		RED = 1,
	};
public:
	Node()
	{
		left = NULL;
		right = NULL;
		val = 0;
		N = 1;
		key = "";
		color = RED;
	}

	Node(string key_, int val_)
	{
		left = NULL;
		right = NULL;
		val = val_;
		key = key_;
		N = 1;
		color = RED;
	}

public:
	string key;
	int val;
	int N;
	bool color;

	Node* left;
	Node* right;
};

class RedBlackTree
{
public:
	RedBlackTree() {
		root = NULL;
	}
	
	bool IsRed(Node* h);
	Node* rotateLeft(Node* h);
	Node* rotateRight(Node* h);
	Node* flipColors(Node* h);

	int size();
	int size(Node* x);

	int get(string key);
	int get(Node* x, string key);

	void put(string key, int val);
	Node* put(Node* x, string key, int val);

	int min();
	Node* min(Node* x);

	int floor(string key);
	Node* floor(Node* x, string key);

	int select(int k);
	Node* select(Node* x, int k);

	int rank(string key);
	int rank(string key, Node* x);

	void deleteMin();
	Node* deleteMin(Node* x);

	void deleteMax();
	Node* deleteMax(Node* x);

	void Delete(string key);
	Node* Delete(Node* x, string key);

private:
	Node* root;
};

