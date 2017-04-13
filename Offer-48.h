#pragma once

/*
* author:haohaosong
* date:2017/4/13
* note:������-48-���ܱ��̳е���
*/

//��ͨ����������Ĺ��캯������Ϊ˽��
//ȱ�㣺ֻ�����ڶ��ϴ����ռ�
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

//�޷��̳�
//class B :public A
//{
//	
//};

void TestMethod1()
{
	A* pa = A::GetObj();
	A::DestoryObj(pa);
}

//˽�г�Ա���Է��ʹ��캯��
//��������������̳�
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

//���ɷ���
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