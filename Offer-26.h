#pragma once

/*
* author:haohaosong
* date:2017/3/20
* note:面试题26:复杂链表的复制
*/

#include<iostream>
using namespace std;

#include<assert.h>

struct ComplexNode
{
	int _data;
	ComplexNode* _next;
	ComplexNode* _complex;

	ComplexNode(int data)
		:_data(data)
		, _next(NULL)
		, _complex(NULL)
	{}
};

typedef ComplexNode Node;

void InitComplexList(Node*& phead)
{
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);

	phead = node1;
	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	node4->_next = node5;

	node1->_complex = node3;
	node2->_complex = node5;
	node3->_complex = NULL;
	node4->_complex = node2;
	node5->_complex = NULL;
}

Node* CopyComplexList(Node*& phead)
{	
	assert(phead);

	//步骤1:拷贝一份节点在每个原来节点的后面
	Node* pCur = phead;
	Node* tmp = NULL;
	while (pCur)
	{
		tmp = pCur;
		pCur = pCur->_next;

		Node* newnode = new Node(tmp->_data);
		tmp->_next = newnode;
		newnode->_next = pCur;
	}

	//步骤2:遍历一遍,将complex赋值
	pCur = phead;
	Node* newNode = NULL;
	while (pCur)
	{
		newNode = pCur->_next;
		if (pCur->_complex)//小心复杂指针为空的情况
			newNode->_complex = pCur->_complex->_next;

		pCur = newNode->_next;
	}

	//步骤3:进行拆分
	pCur = phead;
	Node* pnewHead = NULL;
	if (pCur)
		pnewHead = pCur->_next;

	Node* pnewCur = pnewHead;

	while (pCur)
	{
		pnewCur = pCur->_next;
		pCur->_next = pnewCur->_next;
		pCur = pCur->_next;
	}

	return pnewHead;
}


void PrintComplex(Node* phead)
{
	Node* cur = phead;
	while (cur)
	{
		cout << "Data:" << cur->_data;
		if (cur->_complex)
		{
			cout<< " Complex:" << cur->_complex->_data << endl;
		}
		else
		{
			cout << " Complex:" << "NULL" << endl; 
		}
		cur = cur->_next;
	}
}

void TestComplex()
{
	Node* phead = NULL;
	InitComplexList(phead);
	Node* pnewHead = CopyComplexList(phead);

	cout << "Complex:" << endl;
	PrintComplex(phead);
	cout << "CopyComplex:" << endl;
	PrintComplex(pnewHead);
}