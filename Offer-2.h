#pragma once

/*
* author:haohaosong
* date:2017/3/9
* note:������2������һ���࣬ʹ��ֻ����һ������
*/

#include<iostream>
using namespace std;

//������2
//��δ���һ���࣬ʹ��ֻ����һ������
//�����������

//1�����ʹһ���಻�����ɶ���
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
//	A a;//a�޷�����
//}

//2�����ʹһ����ֻ������һ������
//����(1)������Ԫ����������˽�й��캯��
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

//����(2)ʹ�þ�̬��Ա������˽�й��캯��
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

//3����ο���һ�������ɶ����������һ���ķ�Χ֮��
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