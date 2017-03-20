#pragma once

/*
* author:haohaosong
* date:2017/3/9
* note:面试题2，创造一个类，使其只包含一个对象
*/

#include<iostream>
using namespace std;

//面试题2
//如何创造一个类，使其只包含一个对象
//这里进行延伸

//1、如何使一个类不能生成对象
//class A
//{
//private:
//	A()
//	{}
//  A(const A&)
//  {}
//};
//
//void Test()
//{
//	A a;//a无法生成
//}

//2、如何使一个类只能生成一个对象
//方法(1)利用友元函数来访问私有构造函数
//class A
//{
//public:
//	friend A& construct();
//private:
//	A()
//	{}
//	A(const A&)
//	{}
//};
//
//A& construct()
//{
//	static A a;
//	return a;
//}
//
//void Test()
//{
//	construct();
//}

//方法(2)使用静态成员来访问私有构造函数
//class A
//{
//public:
//	static A& construct();
//private:
//	A()
//	{}
//	A(const A&)
//	{}
//};
//
//A& A::construct()
//{
//	static A a;
//	return a;
//}
//
//void Test()
//{
//	A::construct();
//}

//3、如何控制一个类生成对象的数量在一定的范围之间
class A
{
public:
	A()
	{
		if (num >= maxsize)
		{
			throw string("The object is full");
		}
		++num;
	}
	~A()
	{
		--num;
	}
private:
	static size_t maxsize;
	static size_t num;
};

size_t A::maxsize = 10;
size_t A::num = 0;