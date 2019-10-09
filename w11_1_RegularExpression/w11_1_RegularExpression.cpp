// w11_1_RegularExpression.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "NFA.h"

int main()
{
	string pattern = "((A*B|AC)D";
	
	NFA nfa(pattern);
	cout << "AABD: " << nfa.recoginze("AABD") << endl;

	cout << "ACCBD: " << nfa.recoginze("ACCBD") << endl;
}
