﻿#include<iostream>
using namespace std;
//动物类
class Animal
{
public:
	int m_Age;

};
//羊类
//利用虚继承可以解决菱形继承问题
//继承之前 加上关键字virtual变为虚继承
//Animal类成为虚基类
class Sheep :virtual public Animal {};
//鸵类
class Tuo :virtual public Animal {};
//羊驼类
class SheepTuo :public Sheep, public Tuo {};
void test01()
{
	SheepTuo st;
	//利用虚继承可以解决菱形继承问题
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	//当菱形继承，两个父类拥有相同的数据，需要加以作用域区分 
	cout << "st.sheep::m_Age=" << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age=" << st.Tuo::m_Age << endl;
	cout << "st.m_Age=" << st.m_Age << endl;
	//这份数据我们知道只要有一份就可以了，菱形继承导致数据有两份，资源浪费

}
int main()
{
	test01();
}