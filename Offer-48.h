#pragma once

/*
* author:haohaosong
* date:2017/4/13
* note:面试题-48-不能被继承的类
*/

//普通方法，将类的构造函数设置为私有
//缺点：只可以在堆上创建空间
class A
{
public:
	static A* GetObj()
	{
		return new A();
	}

	static void DestoryObj(A* a)
	{
		delete a;
	}
private:
	A()
	{}
};

//无法继承
//class B :public A
//{
//	
//};

void TestMethod1()
{
	A* pa = A::GetObj();
	A::DestoryObj(pa);
}

//私有成员可以访问构造函数
//但是由于是虚拟继承
template<typename T>
class AA
{
	friend T;

private:
	AA(){}
	~AA(){}
};

class BB :virtual public AA<BB>
{
public:
	BB(){}
	~BB(){}
};

//不可访问
class Try:public BB
{
public:
	Try(){}
	~Try(){}
};

void TestTry()
{
	Try t;
}