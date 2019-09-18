// w4_5_ConvecHull.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <stack>
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

int calcArea(PointF a, PointF b, PointF c)
{
	double area = (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
	if (area < 0)
		return -1;
	else if (area > 0)
		return 1;
	else
		return 0;
}

stack<PointF> GrahamScan( vector<PointF> &vecIn )
{
	// 遍历
	//	   stack存点等

	stack<PointF> stackPoint;
	stackPoint.push(vecIn[0]);
	stackPoint.push(vecIn[1]);

	for (int i = 2; i < vecIn.size();)
	{
		PointF b = stackPoint.top();
		stackPoint.pop();

		PointF a = stackPoint.top();
		stackPoint.pop();

		PointF c = vecIn[i];

		int nResult = calcArea(a, b, c);
		if (nResult > 0)
		{
			stackPoint.push(a);
			stackPoint.push(b);
			stackPoint.push(c);

			i++;
		}
		else
		{
			stackPoint.push(a);
		}
	}
	return stackPoint;
}

stack<PointF> ConvecHull(vector<PointF> &vecIn)
{
	CalcPolar(vecIn);

	// 排序
	sort(vecIn.begin(), vecIn.end());

	return GrahamScan(vecIn);

}

void Print(stack<PointF> stack_)
{
	while (!stack_.empty())
	{
		PointF point = stack_.top();
		stack_.pop();

		cout << "(" << point.x << "," << point.y << "),";
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "(-2,-3),(2,1),(3,3),(2,6),(0,6),(-3,3)" << endl;
	vector<PointF> vecPoints;
	Init(vecPoints);

	stack<PointF> result = ConvecHull(vecPoints);
	Print(result);

	return 0;
}

