#pragma once//防止头文件重复包含
#include<iostream>
using namespace std;
#include"point.h"
class Point
{
public:
	//设置x
	void setX(int x);

	int getX();

	void setY(int y);

	int getY();

private:
	int m_X;
	int m_Y;
};