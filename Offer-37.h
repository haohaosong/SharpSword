#pragma once

/*
* author:haohaosong
* date:2017/4/9
* note:求两个链表的第一个公共节点
*/

#include<iostream>
using namespace std;
#include<assert.h>

struct ListNode
{
	int data;
	ListNode* next;
};

void ListInit(ListNode** head)
{
	*head = NULL;
}

void ListPushBack(ListNode** head, int data)
{
	assert(head);
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;
	ListNode* cur = (*head);
	ListNode* prev = NULL;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
	}

	if (prev == NULL)
		*head = newNode;
	else
		prev->next = newNode;
}

ListNode* Find(ListNode* phead, int data)
{
	assert(phead);
	ListNode* cur = phead;
	while (cur)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

int ListLength(ListNode* phead)
{
	int count = 0;
	ListNode* cur = phead;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

//假定两条链表是一定相交的
ListNode* FindCommonNode(ListNode** phead1,ListNode** phead2)
{
	int l1_length = ListLength(*phead1);
	int l2_length = ListLength(*phead2);
	ListNode* cur1 = *phead1;
	ListNode* cur2 = *phead2;

	if (l1_length > l2_length)
	{
		int tmp = l1_length - l2_length;
		while (tmp--)
			cur1 = cur1->next;
	}

	if (l1_length < l2_length)
	{
		int tmp = l2_length - l1_length;
		while (tmp--)
			cur2 = cur2->next;
	}

	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	return cur1;
}
void TestFindCommonNode()
{
	ListNode* phead1;
	ListInit(&phead1);
	ListPushBack(&phead1, 1);
	ListPushBack(&phead1, 3);
	ListPushBack(&phead1, 5);
	ListPushBack(&phead1, 7);

	ListNode* phead2;
	ListInit(&phead2);
	ListPushBack(&phead2, 2);
	ListPushBack(&phead2, 4);
	ListPushBack(&phead2, 6);
	ListPushBack(&phead2, 8);

	ListNode* tmp_l1 = Find(phead1, 7);
	ListNode* tmp_l2 = Find(phead2, 4);
	tmp_l1->next = tmp_l2;

	ListNode* ret = FindCommonNode(&phead1, &phead2);
	cout << ret->data << endl;
}
