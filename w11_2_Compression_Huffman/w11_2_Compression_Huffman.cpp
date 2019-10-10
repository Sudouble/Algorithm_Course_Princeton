// w11_2_Compression_Huffman.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

// the key of Huffman Compression:
// 1. read
// 2. count
// 3. build dictionary tree
// 4. encoding(compress)
// 5. format
// 6. tries tree rebuild
// 7. expanding

#include "Huffman.h"

int main()
{

	// 示例版，支持字符串长度小于255的！！
	string orgin = "ABRACADABRA!";

	Huffman huffman;
	string out = huffman.compress(orgin);

	cout << "Length:" << out.length()
		<< "  " << out << endl;

	// ====================================================
	cout << "Origin: " << orgin << endl;
	cout << "Restored: " << huffman.expand(out) << endl;

	return 0;
}

