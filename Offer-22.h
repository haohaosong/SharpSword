/*
* author:haohaosong
* date:2017/3/23
* note:������22-ջ��ѹ��͵�������
*/

#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>
bool IsPopOrder(const int* pPush,const int* pPop, size_t length)
{
	assert(length);//����0
	assert(pPush && pPop);

	bool possible = false;

	const int* NextPush = pPush;
	const int* NextPop = pPop;

	stack<int> s;
	
	while (NextPop - pPop < length)
	{
		//��ջΪ�ջ���ջ��Ԫ�ز�Ϊ��Ҫ��ջ��Ԫ��ʱ����ջ
		while (s.empty() || s.top() != *NextPop)
		{
			//�����ջ����û��Ԫ�أ�break����
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