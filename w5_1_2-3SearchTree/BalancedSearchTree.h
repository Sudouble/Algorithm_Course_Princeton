#pragma once

#include <string>
#include <iostream>
using namespace std;

struct Node2D
{
	string key;
	int value;

	Node2D* left;
	Node2D* right;
	Node2D()
	{
		key = "";
		value = 0;
		left = NULL;
		right = NULL;
	}
};

struct Node3D
{
	string keyLeft;
	int valueLeft;

	string keyRight;
	int valueRight;

	Node3D* left;
	Node3D* middle;
	Node3D* right;
	Node3D()
	{
		key = "";
		value = 0;

		left = NULL;
		middle = NULL;
		right = NULL;
	}
};

class BalancedSearchTree
{
};

