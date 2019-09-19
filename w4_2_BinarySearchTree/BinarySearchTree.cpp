#include "StdAfx.h"
#include "BinarySearchTree.h"


BinarySearchTree::BinarySearchTree(void) :
	root(NULL)
{	
}


BinarySearchTree::~BinarySearchTree(void)
{
}

bool BinarySearchTree::IsEmpty()
{
	return root==NULL || root->size == 0;
}

Node* BinarySearchTree::search(string str)
{
	return get(root, str);
}

void BinarySearchTree::insert(string key, int value)
{
	if (IsEmpty())
	{
		root = new Node(key, value, 1);
	}
	else
	{
		root = put(root, key, value);
	}	
}

void BinarySearchTree::DeleteMin()
{
	if (IsEmpty())
	{
		throw "Error";
	}
	
	DeleteMin(root);
}

void BinarySearchTree::DeleteMax()
{
	if (IsEmpty())
	{
		throw "Error";
	}

	DeleteMax(root);
}

void BinarySearchTree::Delete(string key)
{
	if (IsEmpty())
	{
		throw "Error";
	}

	root = Delete(root, key);
}

Node* BinarySearchTree::put(Node* node, string str, int value)
{
	if (node == NULL)
	{
		return new Node(str, value, 1);
	}

	if (str < node->key)
	{
		node->left = put(node->left, str, value);
	}
	else if (str > node->key)
	{
		node->right= put(node->right, str, value);
	}
	else
	{
		node->value = value;
	}

	node->size = 1 + size(node->left) + size(node->right);
	return node;
}

int BinarySearchTree::size(Node* node)
{
	if (node == NULL)
		return 0;

	return 1 + size(node->left) + size(node->right);
}

Node* BinarySearchTree::get(Node* node, string str)
{
	if (node == NULL)
		return NULL;

	if (node->key > str)
		return get(node->left, str);
	else if (node->key < str)
		return get(node->right, str);
	else
		return node;
}

Node* BinarySearchTree::DeleteMin(Node* node)
{
	if (node->left == NULL)
	{
		Node* nodeRight = node->right;
		delete node;

		return nodeRight;
	}
	node->left = DeleteMin(node->left);
	node->size = 1 + size(node->left) + size(node->right);
	return node;
}

Node* BinarySearchTree::DeleteMax(Node* node)
{
	if (node->right == NULL)
	{
		Node* nodeLeft = node->left;
		delete node;

		return nodeLeft;
	}

	node->right = DeleteMax(node->right);
	node->size = 1 + size(node->left) + size(node->right);
	return node;
}

Node* BinarySearchTree::Delete(Node* node, string key)
{	
	if (node == NULL)
		return NULL;

	if (key < node->key)
	{
		node->left = Delete(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = Delete(node->right, key);
	}
	else
	{
		if (node->right == NULL)
			return node->left;
		if (node->left == NULL)
			return node->right;
		
		Node* t = node;
		node = GetMin(node->right);
		node->right = DeleteMin(node->right);
		node->left = t->left;
	}

	node->size = 1 + size(node->left) + size(node->right);
	return node;
}

Node* BinarySearchTree::GetMin(Node* node)
{
	if (node->left == NULL)
	{
		return node;
	}
	return GetMin(node->left);
}

