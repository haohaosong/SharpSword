#pragma once

/*
* author:haohaosong
* date:2017/3/28
* note:面试题13-在O(1)的情况下删除链表的一个节点
*/

#include<iostream>
using namespace std;

struct ListNode
{
	int _data;
	ListNode* _next;
};

typedef ListNode Node;

void DeleteNode(Node** phead,Node* delNode)
{
	if (phead == NULL || delNode == NULL)
		return;

	if (delNode->_next != NULL)//删除的节点不是尾节点
	{
		Node* nextNode = delNode->_next;
		delNode->_next = nextNode->_next;
		delNode->_data = nextNode->_data;
		free(nextNode);
		nextNode = NULL;
	}
	else if (delNode == *phead)//删除的节点是唯一的节点
	{
		free(delNode);
		delNode = NULL;
		*phead == NULL;
	}
	else//删除的节点是尾节点，但是不是唯一的
	{
		Node* cur = *phead;
		while (cur->_next != delNode)
			cur = cur->_next; 

		cur->_next = NULL;
		free(delNode);
		delNode = NULL;
	}
}