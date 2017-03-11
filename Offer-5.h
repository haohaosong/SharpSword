#pragma once

/*
* author:haohaosong
* date:2017/3/11
* note:面试题5 逆序打印单链表
*/

#include<iostream>
using namespace std;
#include<assert.h>
//节点的定义
struct ListNode
{
	int m_data;
	ListNode* m_pNext;
};

void InitList(ListNode** phead)
{
	*phead = NULL;
}

ListNode* BuyNewNode(int data)
{
	ListNode* newNode = NULL;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->m_data = data;
	newNode->m_pNext = NULL;
	return newNode;
}

void PushBack(ListNode** phead, int data)
{
	assert(phead);
	ListNode* newNode = BuyNewNode(data);
	if (*phead == NULL)
	{
		*phead = newNode;
		return;
	}

	ListNode* cur = *phead;
	while (cur->m_pNext)
		cur = cur->m_pNext;

	cur->m_pNext = newNode;
}

void PrintList(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead;
	while (cur)
	{
		printf("%d ", cur->m_data);
		cur = cur->m_pNext;
	}
	printf("\n");
}

//非递归实现
#include<stack>
void ReversePrintNonR(ListNode* phead)
{
	assert(phead);

	stack<ListNode*> s;
	ListNode* cur = phead;
	while (cur)
	{
		s.push(cur);
		cur = cur->m_pNext;
	}

	while (!s.empty())
	{
		printf("%d ", s.top()->m_data);
		s.pop();
	}

	printf("\n");
}

//递归实现
void ReversePrint(ListNode* phead)
{
	if (phead == NULL)
		return;

	ReversePrint(phead->m_pNext);
	printf("%d ", phead->m_data);
}

void TestList()
{
	ListNode* phead;
	InitList(&phead);
	PushBack(&phead, 1);
	PushBack(&phead, 2);
	PushBack(&phead, 3);
	PushBack(&phead, 4);
	PrintList(phead);
	ReversePrintNonR(phead);
	ReversePrint(phead);
}