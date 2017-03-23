#pragma once

/*
* author:haohaosong
* date:2017/3/23
* note:面试题21-包含Min元素的栈
*/

#include<iostream>
using namespace std;
#include<stack>
#include<assert.h>
template<typename T>
class StackWithMin
{
public:
	//特点，存元素的栈和最小元素栈的元素大小是相同的
	//这里可以优化，如果小的话就存，否则最小元素栈再存
	//改动后，出栈时判断出栈的元素和最小元素栈的栈顶元素大小关系，如果相等，最小元素栈要出栈
	void Push(const T& data)
	{
		s_Elem.push(data);

		//判断入栈的元素和最小元素栈的栈顶元素的大小关系
		//来判断最小元素栈入的元素的值
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