#pragma once

#include <string>
#include <iostream>
using std::string;

class Node
{
public:
	Node()
	{
		left = NULL;
		right = NULL;
		val = 0;
		N = 1;
		key = "";
	}

	Node(string key_, int val_)
	{
		left = NULL;
		right = NULL;
		val = val_;
		key = key_;
		N = 1;
	}

public:
	string key;
	int val;
	int N;

	Node* left;
	Node* right;
};

class RedBlackTree
{
public:
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

