#include "TenarySearch.h"

TenarySearch::TenarySearch()
{
	root = NULL;
}

void TenarySearch::insert(string key, int value)
{
	root = put(root, key, value, 0);
}

bool TenarySearch::Contains(string key)
{
	return Contains(root, key, 0) != NULL;
}

bool TenarySearch::IsEmpty()
{
	return size() == 0;
}

int TenarySearch::size()
{
	return n;
}

string TenarySearch::LongestPrefixOf(string query)
{
	int len = LongestPrefixOf(root, query, 0);
	return query.substr(0, len);
}

vector<string> TenarySearch::keysWithPrefixOf(string prefix)
{	
	Node* node = keysWithPrefixOf(root, prefix, 0);

	vector<string> vecResult;
	if (node != NULL)
	{
		collect(node, prefix, vecResult);
	}
	return vecResult;
}

Node* TenarySearch::put(Node* node, string key, int value, int index)
{
	if (node == NULL)
		node = new Node(key[index], -1);

	if (key.length() == index+1)
	{
		if (node->value == -1)
			n++;

		node->value = value;
		return node;
	}

	if (key[index] < node->key)
		node->left = put(node->left, key, value, index);
	else if (key[index] > node->key)
		node->right = put(node->right, key, value, index);
	else 
		node->middle = put(node->middle, key, value, index + 1);

	return node;
}

Node* TenarySearch::Contains(Node* node, string key, int index)
{
	if (node == NULL)
		return NULL;

	if (key.length() == index+1)
	{
		if (node->value != -1)
			return node;
		return NULL;
	}

	if (key[index] < node->key)
		return Contains(node->left, key, index);
	else if (key[index] > node->key)
		return Contains(node->right, key, index);
	else
		return Contains(node->middle, key, index + 1);
}

int TenarySearch::LongestPrefixOf(Node* node, string query, int d)
{
	if (node == NULL)
		return 0;

	if (query[d] < node->key)
		return LongestPrefixOf(node->left, query, d);
	else if (query[d] > node->key)
		return LongestPrefixOf(node->right, query, d);
	else
		return 1 + LongestPrefixOf(node->middle, query, d + 1);
}

Node* TenarySearch::keysWithPrefixOf(Node* node, string prefix, int d)
{
	if (node == NULL)
		return NULL;

	if (prefix.length() == d)
		return node;

	if (prefix[d] < node->key)
		return keysWithPrefixOf(node->left, prefix, d);
	else if (prefix[d] > node->key)
		return keysWithPrefixOf(node->right, prefix, d);
	else 
		return keysWithPrefixOf(node->middle, prefix, d+1);
}

void TenarySearch::collect(Node* node, string prefix, vector<string>& results)
{
	if (node == NULL)
		return;

	string tmp = prefix + node->key;
	if (node->value != -1)
		results.push_back(tmp);
	
	collect(node->left, prefix, results);
	collect(node->middle, tmp, results);
	collect(node->right, prefix, results);
}
