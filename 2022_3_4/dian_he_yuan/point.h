#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include"point.h"
class Point
{
public:
	//����x
	void setX(int x);

	int getX();

	void setY(int y);

	int getY();

private:
	int m_X;
	int m_Y;
};