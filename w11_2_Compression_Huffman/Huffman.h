#pragma once
#include <string>
#include <queue>
#include <vector>
using namespace std;

// the key of Huffman Compression:
// 1. read
// 2. count
// 3. build dictionary tree
// 4. encoding(compress)
// 5. format
// 6. tries tree rebuild
// 7. expanding

struct Node {
	int freq;
	char value;
	Node* left;
	Node* right;

	Node() {
		freq = 0;
		value = 0;
		left = NULL;
		right = NULL;
	}

	Node(char value_, int freq_, Node* left_, Node* right_)
	{
		freq = freq_;
		value = value_;
		left = left_;
		right = right_;
	}

	bool isLead()
	{
		return left == NULL && right == NULL;
	}

	friend bool operator>(const Node& a, const Node& other)
	{
		if (a.freq > other.freq)
			return true;
		return false;
	}
};

class Huffman
{
public:
	Huffman();

	void buildTries(string text);
	void compress(string text);

private:
	Node root;
	const int R = 256;
};

