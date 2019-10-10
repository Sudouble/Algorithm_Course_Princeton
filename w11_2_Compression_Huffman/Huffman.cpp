#include "Huffman.h"

Huffman::Huffman()
{
}

string Huffman::compress(string text)
{
	buildTries(text);
	buildCode(root);

	string strOut = writeTries(root);

	strOut += toByte(text.length());

	for (int i = 0; i < text.length(); i++)
	{
		strOut += stCode[text[i]];
	}
	return strOut;
}

string Huffman::expand(string s)
{
	s = readTries(s);

	int length = toChar(s, 0, 8);
	s = s.substr(8);

	string result = "";
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		Node *x = &root;		
		while (!x->isLeaf())
		{
			if (s[j] == '0')
				x = x->left;
			else
				x = x->right;
			j++;
		}
		result += x->value;
	}
	return result;
}

void Huffman::buildTries(string text)
{
	vector<int> vecCount;
	vecCount.resize(R, 0);
	for (int i = 0; i < text.length(); i++)
		vecCount[text[i]]++;

	priority_queue<Node, vector<Node>, greater<Node>> pqQ;
	for (int i = 0; i < vecCount.size(); i++)
	{
		if (vecCount[i] != 0)	
			pqQ.push(Node(i, vecCount[i], NULL, NULL));
	}

	// build trie
	while (pqQ.size() > 1)
	{
		Node x = pqQ.top();
		pqQ.pop();
		Node y = pqQ.top();
		pqQ.pop();

		Node* xx = new Node(x.value, x.freq, x.left, x.right);
		Node* yy = new Node(y.value, y.freq, y.left, y.right);

		pqQ.push(Node('\0', xx->freq + yy->freq, xx, yy));
	}

	root = pqQ.top();
}

void Huffman::buildCode(Node& root)
{
	stCode.resize(R);

	buildCode(stCode, &root, "");
}

void Huffman::buildCode(vector<string>& stCode, Node* x, string s)
{
	if (x->isLeaf())
	{
		stCode[x->value] = s;
		return;
	}
	buildCode(stCode, x->left, s + "0");
	buildCode(stCode, x->right, s + "1");
}

string Huffman::writeTries(Node& root)
{
	string str;
	writeTries(&root, str);
	return str;
}

void Huffman::writeTries(Node* node, string& s)
{
	if (node->isLeaf())
	{
		s += "1";
		s += toByte(node->value);
		return;
	}

	s += "0";
	writeTries(node->left, s);
	writeTries(node->right, s);
}

string Huffman::readTries(string& s)
{
	int i = 0;
	root = *readTries(s, i);
	return s.substr(i);
}

Node* Huffman::readTries(string& s, int &i)
{
	if (s[i] == '1')
	{
		char ch = toChar(s, i + 1, 8);
		i += 9;
		return new Node(ch, 0, NULL, NULL);
	}

	i++;

	Node* left = readTries(s, i);
	Node* right = readTries(s, i);

	return new Node('\0', 0, left, right);
}

char Huffman::toChar(string s, int begin, int count)
{
	string str = s.substr(begin, count);

	char ch = 0;
	for (int i = 0; i < count; i++)
	{
		char bit = str[i] == '1' ? 1 : 0;
		ch |= bit << (count-i-1);
	}
	return ch;
}

string Huffman::toByte(char c)
{
	string s;
	for (int i = 7; i >= 0; i--)
	{
		int bit = c >> i & 0x01;
		s += bit == 1 ? "1" : "0";
	}
	return s;
}
