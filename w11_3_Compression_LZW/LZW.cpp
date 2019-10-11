#include "LZW.h"

string LZW::compress(string txt)
{
	TenarySearch ts;	

	int R = 'A' + 26;
	for (int i = 'A'; i < R; i++)
	{
		string add;
		add = char(i);
		ts.insert(add, i);
	}
	
	string result;
	int startPos = R + 1;
	while (txt.length() > 0)
	{
		string s = ts.LongestPrefixOf(txt);
		result += toByte(ts.get(s));

		int t = s.length();
		if (t < txt.length())
		{
			ts.insert(txt.substr(0, t + 1), startPos++);
		}
		txt = txt.substr(t);
	}
	result += toByte(R);
	
	return result;
}

string LZW::expand(string txt)
{	
	int R = 'A' + 26;
	int startPos = R + 1;

	vector<string> vecChs;
	vecChs.resize(2048);
	int i;
	for (i = 'A'; i < R; i++)
	{
		string ss;
		ss = char(i);
		vecChs[i] = ss;
	}
	vecChs.push_back(" ");
	i++;

	int codeword = toChar(txt, 0, 8);
	txt = txt.substr(8);
	string val = vecChs[codeword];

	string result = val;
	while (1)
	{
		codeword = toChar(txt, 0, 8);
		txt = txt.substr(8);
		if (codeword == R)
			break;
			
		string s = vecChs[codeword];
		if (i == codeword)
			s = val + val[0];
		if (i < 2048)
			vecChs[i++] = val + s[0];

		val = s;
		result += val;
	}
	return result;
}


char LZW::toChar(string s, int begin, int count)
{
	string str = s.substr(begin, count);

	char ch = 0;
	for (int i = 0; i < count; i++)
	{
		char bit = str[i] == '1' ? 1 : 0;
		ch |= bit << (count - i - 1);
	}
	return ch;
}

string LZW::toByte(char c)
{
	string s;
	for (int i = 7; i >= 0; i--)
	{
		int bit = c >> i & 0x01;
		s += bit == 1 ? "1" : "0";
	}
	return s;
}
