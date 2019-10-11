#pragma once

#include <vector>
#include <string>
using namespace std;

struct Node {
	char key;
	int value;

	Node* left;
	Node* middle;
	Node* right;

	Node()
	{
		key = ' ';
		value = -1;

		left = NULL;
		middle = NULL;
		right = NULL;
	}
	Node(char key_, int value_)
	{
		key = key_;
		value = value_;

		left = NULL;
		middle = NULL;
		right = NULL;
	}
};

class TenarySearch
{
public:
	TenarySearch();

	void insert(string key, int value);
	bool Contains(string key);
	int get(string key);

	bool IsEmpty();
	int size();

	string LongestPrefixOf(string query);
	vector<string> keysWithPrefixOf(string prefix);

private:
	Node* put(Node* node, string key, int value, int index);
	Node* Contains(Node* node, string key, int index);
	Node* get(Node* node, string key, int index);

	int LongestPrefixOf(Node* node, string query, int d);
	Node* keysWithPrefixOf(Node* node, string prefix, int d);
	void collect(Node* node, string prefix, vector<string>& results);

private:
	Node* root;
	int n;
};

