// w10_2_TenarySearch.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "TenarySearch.h"

int main()
{
	TenarySearch ts;
	ts.insert("by", 4);
	ts.insert("sea", 6);
	ts.insert("sells", 1);
	ts.insert("she", 0);
	ts.insert("shells", 3);
	ts.insert("shore", 7);
	ts.insert("the", 5);

	cout << "Contain: by ? " << ts.Contains("by") << endl;
	cout << "Contain: bys ? " << ts.Contains("bys") << endl;
	cout << "tries size:" << ts.size() << endl;

	ts.insert("the", 7);

	cout << "Longest prefix: " << ts.LongestPrefixOf("selslakak boom") << endl;
	cout << "Longest prefix: " << ts.LongestPrefixOf("shellsort") << endl;
	cout << "Longest prefix: " << ts.LongestPrefixOf("shk") << endl;
	
	cout << "PrefixWith 's':" << endl;
	vector<string> vecString = ts.keysWithPrefixOf("s");
	for (size_t i = 0; i < vecString.size(); i++)
	{
		cout << vecString[i] << endl;
	}

	cout << "PrefixWith 'b':" << endl;
	vecString.clear();
	vecString = ts.keysWithPrefixOf("b");
	for (size_t i = 0; i < vecString.size(); i++)
	{
		cout << vecString[i] << endl;
	}
	return 0;
}
