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
	return false;
}

void TenarySearch::Delete(string key)
{
}

bool TenarySearch::IsEmpty()
{
	return size() == 0;
}

int TenarySearch::size()
{
	return 0;
}

string TenarySearch::LongestPrefixOf(string query)
{
	return string();
}

vector<string> TenarySearch::keysWithPrefixOf(string prefix)
{
	return vector<string>();
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
	{
		node->left = put(node->left, key, value, index + 1);
	}
	else if (key[index] > node->key)
	{ 
		node->right = put(node->right, key, value, index + 1);
	}
	else 
	{
		node->middle = put(node->middle, key, value, index + 1);
	}

	return node;
}

Node* TenarySearch::Contains(Node* node, string key, int index)
{
	return nullptr;
}

void TenarySearch::Delete(Node*& node, string key, int index)
{
}

int TenarySearch::LongestPrefixOf(Node* node, string query, int d)
{
	return 0;
}

Node* TenarySearch::keysWithPrefixOf(Node* node, string prefix, int d)
{
	return nullptr;
}

void TenarySearch::collect(Node* node, string prefix, vector<string>& results)
{
}
