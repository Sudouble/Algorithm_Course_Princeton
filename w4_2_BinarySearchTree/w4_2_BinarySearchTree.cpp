// w4_2_BinarySearchTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BinarySearchTree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	BinarySearchTree bst;
	bst.insert("S", 1);
	bst.insert("E", 2);
	bst.insert("X", 3);
	bst.insert("A", 4);
	bst.insert("C", 1);
	bst.insert("R", 1);
	bst.insert("H", 1);
	bst.insert("M", 1);

	////////////////////////////
	bst.DeleteMin();
	
	bst.DeleteMax();
	///////////////////////////
	bst.insert("A", 1);
	bst.insert("X", 1);
	///////////////////////////
	bst.Delete("E");

	return 0;
}

