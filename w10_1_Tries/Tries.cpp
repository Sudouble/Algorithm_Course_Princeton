#include "Tries.h"

Tries::Tries()
{
	root = NULL;
	root = new Node();
}

void Tries::insert(string key, int value)
{
	if (!Contains(key))
	{
		int index = key[0] - 'a';

		put(root, key, value, 0);
	}
}

Node* Tries::put(Node* node, string key, int value, int index)
{
	//int pos = key[index] - 'a';
	//Node* node_ = node->nextNode[pos];

	//if (node_ == NULL)
	//{
	//	node_ = new Node(key[index], -1);
	//	node->nextNode[pos] = node_;
	//}

	//if (key.length() == (index+1))
	//{
	//	node_->value = value;
	//	return;
	//}
	//
	//put(node_, key, value, index + 1);

	if (node == NULL)
		node = new Node();
	if (key.length() == index)
	{
		if (node->value == -1)
			n++;

		node->value = value;		
		return node;
	}

	int pos = key[index] - 'a';
	node->nextNode[pos] = put(node->nextNode[pos], key, value, index + 1);
	node->nextNode[pos]->key = key[index];

	return node;
}

bool Tries::Contains(string key)
{
	int index = key[0] - 'a';

	return Contains(root, key, 0) != NULL;
}

Node* Tries::Contains(Node* node, string key, int index)
{
	//if (node == NULL)
	//	return false;

	//int pos = key[index] - 'a';
	//Node* node_ = node->nextNode[pos];

	//if (key.length() == (index+1) && node_->value != -1)
	//{
	//	return true;
	//}

	//if (node_ != NULL)
	//{
	//	int pos = key[index] - 'a';
	//	return Contains(node_, key, index + 1);
	//}
	//return false;

	if (node == NULL)
		return NULL;

	if (key.length() == index)
		return node;

	int pos = key[index] - 'a';
	return Contains(node->nextNode[pos], key, index + 1);
}

void Tries::Delete(string key)
{
	if (Contains(key))
	{
		Delete(root, key, 0);
	}
}

bool Tries::IsEmpty()
{
	return size() == 0;
}

int Tries::size()
{
	return n;
}

string Tries::LongestPrefixOf(string query)
{
	int pos = query[0] - 'a';
	int len = LongestPrefixOf(root->nextNode[pos], query, 0);
	return query.substr(0, len);
}

vector<string> Tries::keysWithPrefixOf(string prefix)
{
	Node* node = keysWithPrefixOf(root, prefix, 0);
	vector<string> results;
	if (node != NULL)
	{
		collect(node, prefix, results);
	}

	return results;
}

void Tries::Delete(Node* &node, string key, int index)
{
	if (key.length() == index)
	{
		node->value = -1;
		n--;
		return;
	}

	int pos = key[index] - 'a';
	Delete(node->nextNode[pos], key, index + 1);


	if (node->value != -1)
		return;

	int count = 0;
	for (int i = 0; i < R; i++)
	{
		if (node->nextNode[i] != NULL)
			count++;
	}
	if (count != 1)
		return;
	
	// ªÿ ’ƒ⁄¥Ê
	for (int i = 0; i < R; i++)
	{
		if (node->nextNode[i] != NULL)
		{
			delete node->nextNode[i];
			node->nextNode[i] = NULL;
		}
	}
}

int Tries::LongestPrefixOf(Node* node, string query, int d)
{
	if (node == NULL)
		return 0;

	if (node->key == query[d])
	{
		int pos = query[d+1] - 'a';
		return 1 + LongestPrefixOf(node->nextNode[pos], query, d + 1);
	}
	return 0;
}

Node* Tries::keysWithPrefixOf(Node* node, string prefix, int d)
{
	if (node == NULL)
		return NULL;
	
	if (d == prefix.length())
		return node;

	int pos = prefix[d] - 'a';
	return keysWithPrefixOf(node->nextNode[pos], prefix, d + 1);
}

void Tries::collect(Node* node, string prefix,vector<string> &results)
{
	if (node == NULL)
		return;

	if (node->value != -1)
	{
		results.push_back(prefix);
	}
	
	for (int i = 0; i < R; i++)
	{
		string prefixTmp = prefix;
		prefixTmp += (i + 'a');
		collect(node->nextNode[i], prefixTmp, results);
	}
}
