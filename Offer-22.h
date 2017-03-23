/*
* author:haohaosong
* date:2017/3/23
* note:面试题22-栈的压入和弹出序列
*/

#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>
bool IsPopOrder(const int* pPush,const int* pPop, size_t length)
{
	assert(length);//大于0
	assert(pPush && pPop);

	bool possible = false;

	const int* NextPush = pPush;
	const int* NextPop = pPop;

	stack<int> s;
	
	while (NextPop - pPop < length)
	{
		//当栈为空或者栈顶元素不为需要出栈的元素时，入栈
		while (s.empty() || s.top() != *NextPop)
		{
			//如果入栈序列没有元素，break跳出
			if (NextPush - pPush == length)
				break;

			s.push(*NextPush);
			NextPush++;
		}

		if (s.top() != *NextPop)
			break;

		s.pop();
		NextPop++;
	}

	if (s.empty() && NextPop - pPop == length)
		possible = true;

	return possible;
}