// w10_1_Tries.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Tries.h"

int main()
{
	Tries tries;
	tries.insert("by", 4);
	tries.insert("sea", 6);
	tries.insert("sells", 1);
	tries.insert("she", 0);
	tries.insert("shells", 3);
	tries.insert("shore", 7);
	tries.insert("the", 5);

	cout << "Contain: by ? " << tries.Contains("by") << endl;
	cout << "Contain: bys ? " << tries.Contains("bys") << endl;
	cout << "tries size:" << tries.size() << endl;

	tries.Delete("by");
	tries.Delete("bys");
	cout << "After Delete" << endl;
	cout << "Contain: by ? " << tries.Contains("by") << endl;
	cout << "Contain: bys ? " << tries.Contains("bys") << endl;
	cout << "tries size:" << tries.size() << endl;

	tries.Delete("the");
	cout << "tries size:" << tries.size() << endl;

	cout << "Longest prefix: " << tries.LongestPrefixOf("selslakak boom") << endl;

	cout << "PrefixWith 'sh':" << endl;	 
	vector<string> vecString = tries.keysWithPrefixOf("sh");
	for (size_t i = 0; i < vecString.size(); i++)
	{
		cout << vecString[i] << endl;
	}
	return 0;
}
