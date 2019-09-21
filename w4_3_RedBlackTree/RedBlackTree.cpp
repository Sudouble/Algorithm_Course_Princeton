#include "RedBlackTree.h"

int RedBlackTree::size()
{
	return size(root);
}

int RedBlackTree::size(Node* x)
{
	if (x == NULL)
		return 0;
	return x->N;
}

int RedBlackTree::get(string key)
{
	return get(root, key);
}

int RedBlackTree::get(Node* x, string key)
{
	if (x == NULL)
		return NULL;
	if (key < x->key)
		return get(x->left, key);
	else if (key > x->key)
		return get(x->right, key);
	else
		return x->val;	
}

void RedBlackTree::put(string key, int val)
{
	root = put(root, key, val);
}

Node* RedBlackTree::put(Node* x, string key, int val)
{
	if (x == NULL)
		return new Node(key, val);
	if (key < x->key)
		x->left = put(x->left, key, val);
	else if (key > x->key)
		x->right = put(x->right, key, val);
	else
		x->val = val;

	x->N = 1 + size(x->left) + size(x->right);

	return x;
}

int RedBlackTree::min()
{
	return min(root)->key;
}

Node* RedBlackTree::min(Node* x)
{
	if (x->left == NULL)
	{
		return x;
	}
	return min(x->left);
}

int RedBlackTree::floor(string key)
{
	Node* x = floor(root, key);
	if (x == NULL)
	{
		return NULL;
	}
	return x->key;
}

Node* RedBlackTree::floor(Node* x, string key)
{
	if (x == NULL)
	{
		return NULL;
	}
	if (key == x->key)
		return x;

	if (key < x->key)
		return floor(x->left, key);

	Node* t = floor(x->right, key);
	if (t != NULL)
		return t;
	else
		return x;
}

int RedBlackTree::select(int k)
{
	return select(root, k)->key;
}

Node* RedBlackTree::select(Node* x, int k)
{
	if (x == NULL)
	{
		return NULL;
	}
	int t = size(x->left);
	if (t > k)
		return select(x->left, k);
	else if (t < k)
		return select(x->right, k - t - 1);
	else
		return x;
}

int RedBlackTree::rank(string key)
{
	return rank(key, root);
}

int RedBlackTree::rank(string key, Node* x)
{
	if (x == NULL)
		return 0;
	if (key < x->key)
		return rank(key, x->left);
	else if (key > x->key)
		return 1 + size(x->left) + rank(key, x->right);
	else
		return size(x->left);
}

void RedBlackTree::deleteMin()
{
	root = deleteMin(root);
}

Node* RedBlackTree::deleteMin(Node* x)
{
	if (x->left == NULL)
		return x->right;
	x->left = deleteMin(x->left);
	x->N = 1 + size(x->left) + size(x->right);
	return x;
}

void RedBlackTree::deleteMax()
{
	root = deleteMax(root);
}

Node* RedBlackTree::deleteMax(Node* x)
{
	if (x->right == NULL)
		return x->left;
	x->right = deleteMax(x->right);
	x->N = 1 + size(x->left) + size(x->right);
	
	return x;
}

void RedBlackTree::Delete(string key)
{
	root = Delete(root, key);
}

Node* RedBlackTree::Delete(Node* x, string key)
{
	if (x == NULL)
		return NULL;
	if (key < x->key)
		x->left = Delete(x->left, key);
	else if (key > x->key)
		x->right = Delete(x->right, key);
	else
	{
		if (x->right == NULL)
			return x->left;
		if (x->left == NULL)
			return x->right;
		Node* t = x;
		x = min(t->right);
		x->right = deleteMin(t->right);
		x->left = t->left;
	}
	x->N = 1 + size(x->left) + size(x->right);

	return x;
}

