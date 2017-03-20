#pragma once

/*
* author:haohaosong
* date:2017/3/12
* note:������6-���������ؽ�
*/

#include<iostream>
using namespace std;

#include<assert.h>

//����������ڵ�
struct TreeNode
{
	int pValue;

	TreeNode* pLeft;
	TreeNode* pRight;

	TreeNode(int data)
		:pValue(data)
		, pLeft(NULL)
		, pRight(NULL)
	{}
};

typedef TreeNode Node;

Node* ReConstruct(int* preorder, int* inorder, int length)
{
	assert(preorder);
	assert(inorder);
	if (length <= 0)
		return NULL;

	//������ڵ�
	Node* root = new Node(*preorder);

	//count���������������Ľڵ����
	//��length-count-1��ʾ�������Ľڵ����
	int* pre_tmp = preorder;
	int* in_tmp = inorder;
	int leftTreeNum = 0;
	int protecte = length;
	//����������������ͳ�ƣ������ݴ�������������ĸ��ڵ�pre_tmp+1
	while (*in_tmp != *preorder)
	{
		leftTreeNum++;
		in_tmp++;
		pre_tmp++;
		protecte--;

		if (protecte == 1 && *in_tmp != *preorder)
			throw string("ǰ���������������쳣");
	}

	//���ֳ�����������������ǰ��������������
	//��ͳ�Ƴ����������������Ľڵ����
	int* leftPreOrder = preorder + 1;
	int* rightPreOrder = pre_tmp + 1;
	int* leftOrder = inorder;
	int* rightOrder = in_tmp + 1;
	int rightTreeNum = length - leftTreeNum - 1;

	//���еݹ鹹����������������
	root->pLeft = ReConstruct(leftPreOrder, leftOrder, leftTreeNum);
	root->pRight = ReConstruct(rightPreOrder, rightOrder, rightTreeNum);

	//���ظ��ڵ�
	return root;
}

//�������
void InOrderPrint(Node* root)
{
	if (root == NULL)
		return;

	InOrderPrint(root->pLeft);
	cout << root->pValue << " ";
	InOrderPrint(root->pRight);
}

void TestReConstruct()
{
	const int M = 8;
	const int PreOrder[M] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	const int InOrder[M] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int* preorder = const_cast<int*>(PreOrder);
	int* inorder = const_cast<int*>(InOrder);

	Node* root = ReConstruct(preorder, inorder, M);
	InOrderPrint(root);
	cout << endl;
}