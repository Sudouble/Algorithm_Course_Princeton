// w5_1_2-3SearchTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "BalancedSearchTree.h"

int main()
{
	//	A
	// / \
	//E	  S
	BalancedSearchTree bst1;
	bst1.Insert("A", 1);
	bst1.Insert("E", 2);
	bst1.Insert("S", 3);


	//		     M
	//		 /      \
	//	    E        R
	//	   /  \     / \
	//  (A C)(H L) P  (S X)
	//  / |\  /|\  /\  /|\

	// 见算法第四版，p274
	BalancedSearchTree bst2;
	bst2.Insert("S");
	bst2.Insert("E");
	bst2.Insert("A");
	bst2.Insert("R");
	bst2.Insert("C");
	bst2.Insert("H");
	bst2.Insert("X");
	bst2.Insert("M");
	bst2.Insert("P");
	bst2.Insert("L");

	//		     H
	//		 /       \
	//	    C       (M R)
	//	   /  \     /  |  \
	//	  A    E   L   P (S X)
	//   / \  / \  /\ /\  /|\
	// 见算法第四版，p274
	BalancedSearchTree bst3;
	bst3.Insert("A");
	bst3.Insert("C");
	bst3.Insert("E");
	bst3.Insert("H");
	bst3.Insert("L");
	bst3.Insert("M");
	bst3.Insert("P");
	bst3.Insert("R");
	bst3.Insert("S");
	bst3.Insert("X");

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
