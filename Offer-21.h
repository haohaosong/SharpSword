#pragma once

/*
* author:haohaosong
* date:2017/3/23
* note:������21-����MinԪ�ص�ջ
*/

#include<iostream>
using namespace std;
#include<stack>
#include<assert.h>
template<typename T>
class StackWithMin
{
public:
	//�ص㣬��Ԫ�ص�ջ����СԪ��ջ��Ԫ�ش�С����ͬ��
	//��������Ż������С�Ļ��ʹ棬������СԪ��ջ�ٴ�
	//�Ķ��󣬳�ջʱ�жϳ�ջ��Ԫ�غ���СԪ��ջ��ջ��Ԫ�ش�С��ϵ�������ȣ���СԪ��ջҪ��ջ
	void Push(const T& data)
	{
		s_Elem.push(data);

		//�ж���ջ��Ԫ�غ���СԪ��ջ��ջ��Ԫ�صĴ�С��ϵ
		//���ж���СԪ��ջ���Ԫ�ص�ֵ
		if (s_Min.empty() || data < s_Min.top())
			s_Min.push(data);
		else
			s_Min.push(s_Min.top());
	}

	void Pop()
	{
		assert(!s_Min.empty() && !s_Elem.empty());

		s_Min.pop();
		s_Elem.pop();
	}

	const T& Min()const
	{
		return s_Min.top();
	}
protected:
	stack<T> s_Elem;
	stack<T> s_Min;
};