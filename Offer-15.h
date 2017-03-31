#pragma once

/*
* author:haohaosong
* date:2017/3/25
* note:求倒数第K个节点
*/

#include<iostream>
using namespace std;
struct ListNode
{
	int _data;
	ListNode* _next;

	ListNode(int data)
		:_data(data)
		, _next(NULL)
	{}
};

typedef ListNode Node;

class List
{
public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{}
	void PushBack(int data)
	{
		Node* newNode = new Node(data);
		if (_head == NULL)
		{
			_head = _tail = newNode;
		}
		else
		{
			_tail->_next = newNode;
			_tail = newNode;
		}
	}

	List(Node* phead)
		:_head(phead)
		, _tail(NULL)
	{
		Node* cur = phead;
		Node* prev = NULL;
		while (cur)
		{
			prev = cur;
			cur = cur->_next;
		}
		_tail = prev;
	}

	void Print()
	{
		Node* cur = _head;
		while (cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}

	Node* GetHead()
	{
		return _head;
	}
protected:
	Node* _head;
	Node* _tail;
};

//注意传入的参数的问题
Node* FindLastK(Node* pHead, size_t n)
{
	if (pHead == NULL || n == 0)
		return NULL;

	Node* pFast = pHead;
	Node* pSlow = pHead;

	//pFast先走n步
	for (size_t i = 0; i < n; ++i)
	{
		if (pFast == NULL)
			return NULL;

		pFast = pFast->_next;
	}

	//pFast和pSlow同时走
	while (pFast != NULL)
	{
		pSlow = pSlow->_next;
		pFast = pFast->_next;
	}

	return pSlow;
}

void TestFindLastK()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);

	//正常的情况
	Node* ret1 = FindLastK(l.GetHead(), 3);

	//所求的数不够list的总数
	Node* ret2 = FindLastK(l.GetHead(), 6);

	//传入的是一个空的链表
	Node* ret3 = FindLastK(NULL, 3);
}