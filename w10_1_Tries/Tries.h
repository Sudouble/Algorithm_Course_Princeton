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
	Node* put(Node* node, string key, int value, int index);

	bool Contains(string key);
	Node* Contains(Node* node, string key, int index);

	void Delete(string key);
	void Delete(Node* &node, string key, int index);

	string LongestPrefixOf(string prefix);
	vector<string> keysWithPrefixOf(string prefix);


private:
	Node* root;
};

