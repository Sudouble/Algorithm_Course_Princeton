#include "BalancedSearchTree.h"

BalancedSearchTree::BalancedSearchTree()
{
	root = NULL;
}

void BalancedSearchTree::Insert(string key, int value)
{
	if (IsEmpty())
	{
		root = new Node(key, value, NULL);
	}
	else
	{
		put(root, key, value);
	}
}

void BalancedSearchTree::put(Node* node, string key, int value)
{
	int index = calcNodePos(node, key);
	
	if (node->childNode[index] != NULL)
	{
		return put(node->childNode[index], key, value);
	}	

	node->vecStrKey.insert(node->vecStrKey.begin() + index, key);
	node->vecValue.insert(node->vecValue.begin() + index, value);

	node->childNode.insert(node->childNode.begin() + index, NULL);

	Node3(node);
}

int BalancedSearchTree::calcNodePos(Node* node, string key)
{
	if (key > node->vecStrKey.back())
	{
		return node->vecStrKey.size();
	}

	for (int i = 0; i < node->vecStrKey.size(); i++)
	{
		if (key < node->vecStrKey[i])
		{
			return i;
		}
	}	
}

bool BalancedSearchTree::Contains(string key)
{
	Node* node = get(root, key);
	if (node == NULL)
		return false;
	return true;
}

Node* BalancedSearchTree::get(Node* node, string key)
{
	if (node == NULL)
		return NULL;

	for (size_t i = 0; i < node->vecStrKey.size(); i++)
	{
		if (node->vecStrKey[i] == key)
		{
			return node;
		}
	}

	for (size_t i = 0; i < node->childNode.size(); i++)
	{
		return get(node->childNode[i], key);
	}
}

bool BalancedSearchTree::IsEmpty()
{
	return root == NULL;	
}

void BalancedSearchTree::Node3(Node* node)
{
	if (node == NULL)
		return;

	bool bAllEmpty = true;
	for (size_t i = 0; i < node->childNode.size(); i++)
	{
		if (node->childNode[i] != NULL)
		{
			bAllEmpty = false;
			break;
		}
	}

	if (node->vecStrKey.size() == 3)
	{
		Node* left = new Node(node->vecStrKey[0], node->vecValue[0], node);
		left->childNode[0] = node->childNode[0];
		if (left->childNode[0] != NULL)
			left->childNode[0]->parent = left;
		left->childNode[1] = node->childNode[1];
		if (left->childNode[1] != NULL)
			left->childNode[1]->parent = left;

		Node* right = new Node(node->vecStrKey[2], node->vecValue[2], node);
		right->childNode[0] = node->childNode[2];
		if (right->childNode[0] != NULL)
			right->childNode[0]->parent = right;
		right->childNode[1] = node->childNode[3];
		if (right->childNode[1] != NULL)
			right->childNode[1]->parent = right;
			
		string key = node->vecStrKey[1];
		int value = node->vecValue[1];

		node->vecStrKey.clear();
		node->vecValue.clear();
		node->vecStrKey.push_back(key);
		node->vecValue.push_back(value);

		node->childNode.clear();
		node->childNode.push_back(left);
		node->childNode.push_back(right);

		Node* parent = node->parent;
		if (parent == NULL)
			return;
		
		int pos = calcNodePos(parent, node->vecStrKey.front());
		parent->vecStrKey.insert(parent->vecStrKey.begin() + pos, node->vecStrKey.front());
		parent->vecValue.insert(parent->vecValue.begin() + pos, node->vecValue.front());

		parent->childNode.erase(parent->childNode.begin() + pos);
		
		node->childNode[1]->parent = parent;
		parent->childNode.insert(parent->childNode.begin() + pos, node->childNode[1]);

		node->childNode[0]->parent = parent;
		parent->childNode.insert(parent->childNode.begin() + pos, node->childNode[0]);
		
		delete node;

		Node3(parent);
	}
	else
	{
		// Do nothing
	}
}
