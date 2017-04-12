#pragma once

/*
* author:haohaosong
* date:2017/4/12
* note:������-46-�� 1+2+...+n
*/

#include<iostream>
using namespace std;

//����1:���ù��캯��
class A
{
public:
	A()
	{
		++N;
		Sum += N;
	}

	static int GetNum()
	{
		return Sum;
	}
public:
	static int N;
	static int Sum;
};

int A::N = 0;
int A::Sum = 0;

void TestGetValueByConStruct()
{
	A* pa = new A[5];
	cout << A::GetNum() << endl;
}

//����2
//�����麯�����
class AA;
AA* Array[2];

class AA
{
public:
	virtual size_t Sum(size_t n)
	{
		return 0;
	}
};

class BB :public AA
{
public:
	virtual size_t Sum(size_t n)
	{
		return Array[!n]->Sum(n-1) + n;
	}
};

int GetValueByVirtual(size_t n)
{
	AA a;
	BB b;
	Array[0] = &b;
	Array[1] = &a;

	int value = Array[0]->Sum(n);
	return value;
}

void TestGetValueByVirtual()
{
	cout << GetValueByVirtual(5) << endl;
}


//����3
//����ָ�����

typedef size_t (*pfun)(size_t n);

size_t FunPointer1(size_t n)
{
	return 0;
}

size_t FunPointer2(size_t n)
{
	pfun pF[2] = { FunPointer2, FunPointer1};
	return pF[!n](n-1) + n;
}

size_t GetValueByFunPointer(size_t n)
{
	return FunPointer2(n);
}

void TestGetValueByFunPointer()
{
	cout<< GetValueByFunPointer(5) << endl;
}

//����4����ģ���������
template<size_t N>
size_t F()
{
	return N + F<N - 1>();
};

template<>
size_t F<1>()
{
	return 1;
};

void TestGetValueByTemplate()
{
	cout << F<5>() << endl;
}