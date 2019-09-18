// w4_5_ConvecHull.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Graham scan implement — O(n log n)

#define PI 3.14159265

struct PointF{
	double x;
	double y;

	double angle;
	double length;

	PointF(double x_, double y_) {
		x = x_;
		y = y_;

		angle = 0.0;
		length = 0.0;
	}

	void setPolar(double angle_, double length_)
	{
		angle = angle_;
		length = length_;
	}

	bool operator<(const PointF &other)
	{
		if (this->angle < other.angle)
			return true;
		return false;
	}
};

void Init(vector<PointF> &vecIn)
{
	vecIn.clear();

	vecIn.push_back(PointF(0, 0));
	vecIn.push_back(PointF(2, 1));
	vecIn.push_back(PointF(2, 3));
	vecIn.push_back(PointF(3, 3));
	vecIn.push_back(PointF(2, 6));
	vecIn.push_back(PointF(0, 5));
	vecIn.push_back(PointF(0, 6));
	vecIn.push_back(PointF(-3, 3));
	vecIn.push_back(PointF(-2, 3));
	vecIn.push_back(PointF(-2, -3));
}

int FindMinYPoint(const vector<PointF> &vecIn)
{
	int index_min = 0;
	for (int i = 1; i < vecIn.size(); i++)
	{
		if (vecIn[index_min].y > vecIn[i].y)
		{
			index_min = i;
		}
	}
	return index_min;
}

void CalcPolar(const PointF &src, PointF &dest)
{
	double deltaX = dest.x - src.x;
	double deltaY = dest.y - src.y;

	double length = sqrt(deltaX*deltaX + deltaY*deltaY);
	double angle = asin(abs(deltaY)/length);
	if (deltaX < 0 && deltaY > 0)
	{
		angle = PI - asin(abs(deltaY)/length);
	}
	else if (deltaX < 0 && deltaY < 0)
	{
		angle = PI + asin(abs(deltaY)/length);
	}
	else if (deltaX > 0 && deltaY < 0)
	{
		angle = 2*PI - angle;
	}

	dest.angle = angle;
	dest.length = length;
}

void CalcPolar(vector<PointF> &vecIn)
{
	int minYIndex = FindMinYPoint(vecIn);
	for (int i = 0; i < vecIn.size(); i++)
	{
		if (i == minYIndex)
			continue;

		CalcPolar(vecIn[minYIndex], vecIn[i]);
	}
}

bool isCounterClockWise(PointF newOne, PointF lastOne, PointF lastTwo)
{
	CalcPolar(newOne, lastOne);
	CalcPolar(newOne, lastTwo);

	if (lastOne.angle < lastTwo.angle)
		return false;
	return true;
}

void ConvecHull(vector<PointF> &vecIn)
{
	CalcPolar(vecIn);
	
	// 排序
	sort(vecIn.begin(), vecIn.end());
	// 遍历
	//	   stack存点等
}



int _tmain(int argc, _TCHAR* argv[])
{
	vector<PointF> vecPoints;
	Init(vecPoints);

	//

	return 0;
}

