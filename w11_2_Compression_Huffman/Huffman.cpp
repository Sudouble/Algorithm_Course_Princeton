#include "Huffman.h"

Huffman::Huffman()
{
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

void Huffman::compress(string text)
{
	//if ()
}
