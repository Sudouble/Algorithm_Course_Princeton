#pragma once

#include <string>
#include "..//w10_2_TenarySearch/TenarySearch.h"
using namespace std;

class LZW
{
public:
	string compress(string txt);
	string expand(string txt);

private:
	char toChar(string s, int begin, int count);
	string toByte(char c);

private:

};

