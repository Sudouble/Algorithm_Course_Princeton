#include "LZW.h"

void LZW::compress(string txt)
{
	TenarySearch ts;
	int startPos = 0x81;

	for (int i = 0; i < txt.length()-1; i++)
	{
		string key;
		key = txt[i];
		if (!ts.Contains(key))
		{
			ts.insert(key, txt[i]);
		}

		// Prefix
		string nextOne = key; 		
		int j = i + 1;
		while (ts.Contains(nextOne))
		{
			nextOne += txt[j];			
		}
		ts.insert(nextOne, startPos++);
	}
	return;
}
