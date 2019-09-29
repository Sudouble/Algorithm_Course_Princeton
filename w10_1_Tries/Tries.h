#pragma once

#include <vector>
#include <string>
using namespace std;

const int R = 26;

struct Node {
	char key;
	int value;

	Node* nextNode[R];

	Node()
	{
		key = ' ';
		value = -1;
		
		for (int i = 0; i < R; i++)
			nextNode[i] = NULL;
	}
	Node(char key_, int value_)
	{
		key = key_;
		value = value_;
		
		for (int i = 0; i < R; i++)
			nextNode[i] = NULL;
	}
};

class Tries
{
public:
	Tries();

	void insert(string key, int value);	
	bool Contains(string key);
	void Delete(string key);

	bool IsEmpty();
	int size();

	string LongestPrefixOf(string query);
	vector<string> keysWithPrefixOf(string prefix);

private:
	Node* put(Node* node, string key, int value, int index);
	Node* Contains(Node* node, string key, int index);
	void Delete(Node*& node, string key, int index);

	int LongestPrefixOf(Node* node, string query, int d);
	Node* keysWithPrefixOf(Node* node, string prefix, int d);
	void collect(Node* node, string prefix, vector<string> &results);

private:
	Node* root;

	int n;
};

