// w3_3_ShellSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

// ����߾ֲ��������ԣ�����ʹȫ���ﵽ����
void ShellSort(vector<int> &vecIn)
{

	int h = 1;
	while (h < vecIn.size()/3)
		h = 3*h+1;

	while (h >= 1)
	{
		for (int i = h; i < vecIn.size(); i++)
		{
			for (int j = i; j >= h; j -= h) // ��ǰi-h���͵�i�����αȽ�
			{
				if (vecIn[j-h] > vecIn[j])
					swap(vecIn[j-h], vecIn[j]);
				else
					break;
			}
		}
		h = h/3;
	}
}

void Print(const vector<int> &vecIn)
{
	for (int i = 0; i < vecIn.size(); i++)
	{
		cout << vecIn[i] << ",";
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int index[] = {12,3,45,3,2,45,7,1,3,8,45,3,4,59,55};
	vector<int> vecIn;
	vecIn.assign(index, index+sizeof(index)/sizeof(int));	
	Print(vecIn);

	ShellSort(vecIn);
	Print(vecIn);

	return 0;
}
