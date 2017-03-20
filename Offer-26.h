#pragma once

/*
* author:haohaosong
* date:2017/3/20
* note:������26:��������ĸ���
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

	//����1:����һ�ݽڵ���ÿ��ԭ���ڵ�ĺ���
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

	//����2:����һ��,��complex��ֵ
	pCur = phead;
	Node* newNode = NULL;
	while (pCur)
	{
		newNode = pCur->_next;
		if (pCur->_complex)//С�ĸ���ָ��Ϊ�յ����
			newNode->_complex = pCur->_complex->_next;

		pCur = newNode->_next;
	}

	//����3:���в��
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