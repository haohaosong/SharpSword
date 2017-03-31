#pragma once

/*
* author:haohaosong
* date:2017/3/28
* note:������13-��O(1)�������ɾ�������һ���ڵ�
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

	if (delNode->_next != NULL)//ɾ���Ľڵ㲻��β�ڵ�
	{
		Node* nextNode = delNode->_next;
		delNode->_next = nextNode->_next;
		delNode->_data = nextNode->_data;
		free(nextNode);
		nextNode = NULL;
	}
	else if (delNode == *phead)//ɾ���Ľڵ���Ψһ�Ľڵ�
	{
		free(delNode);
		delNode = NULL;
		*phead == NULL;
	}
	else//ɾ���Ľڵ���β�ڵ㣬���ǲ���Ψһ��
	{
		Node* cur = *phead;
		while (cur->_next != delNode)
			cur = cur->_next; 

		cur->_next = NULL;
		free(delNode);
		delNode = NULL;
	}
}