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

void Tries::Delete(Node* &node, string key, int index)
{
	if (key.length() == index)
	{
		delete node;
		node = NULL;
		return;
	}

	int pos = key[index] - 'a';
	Delete(node->nextNode[pos], key, index + 1);
}
