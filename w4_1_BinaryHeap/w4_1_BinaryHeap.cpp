// w4_1_BinaryHeap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BinaryHeap.h"

void Print(vector<string> &vecStr)
{
	for (int i = 0; i < vecStr.size(); i++)
	{
		cout << vecStr[i];
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> vecStr;
	vecStr.push_back("-");
	vecStr.push_back("T");
	vecStr.push_back("P");
	vecStr.push_back("R");	
	vecStr.push_back("N");
	vecStr.push_back("H");
	vecStr.push_back("O");	
	vecStr.push_back("A");
	vecStr.push_back("E");
	vecStr.push_back("I");
	vecStr.push_back("G");

	BinaryHeap binaryHeap;
	binaryHeap.Init(vecStr);
	binaryHeap.Insert("S");

	vector<string> vecStrExpect;
	vecStrExpect.push_back("-");
	vecStrExpect.push_back("T");
	vecStrExpect.push_back("S");
	vecStrExpect.push_back("R");	
	vecStrExpect.push_back("N");
	vecStrExpect.push_back("P");
	vecStrExpect.push_back("O");	
	vecStrExpect.push_back("A");
	vecStrExpect.push_back("E");
	vecStrExpect.push_back("I");	
	vecStrExpect.push_back("G");
	vecStrExpect.push_back("H");

	Print(binaryHeap.GetTree());
	Print(vecStrExpect);

	//////////////////////////////////////////////////////////////////////////
	cout << "Head one:" << binaryHeap.delMax() << endl;
	Print(binaryHeap.GetTree());

	return 0;
}

