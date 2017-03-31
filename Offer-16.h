#pragma once

/*
* author:haohaosong
* date:2017/3/25
* note:面试题17-反转单链表
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

Node* ReverseList(Node* pHead)
{
	Node* pPrev = NULL;
	Node* pCur = pHead;
	Node* pReverseHead = NULL;
	while (pCur != NULL)
	{
		Node* pNext = pCur->_next;
		
		if (pNext == NULL)
			pReverseHead = pCur;

		pCur->_next = pPrev;

		pPrev = pCur;
		pCur = pNext;
	}
	return pReverseHead;
}

void TestReverseList()
{
		List l;
		l.PushBack(1);
		l.PushBack(2);
		l.PushBack(3);
		l.PushBack(4);

		List rl = ReverseList(l.GetHead());
		rl.Print();
}
