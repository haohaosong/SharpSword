#pragma once

/*
* author:haohaosong
* date:2017/3/12
* note:面试题6-二叉树的重建
*/

#include<iostream>
using namespace std;

#include<assert.h>

//定义二叉树节点
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

	//定义根节点
	Node* root = new Node(*preorder);

	//count用来计数左子树的节点个数
	//用length-count-1表示右子树的节点个数
	int* pre_tmp = preorder;
	int* in_tmp = inorder;
	int leftTreeNum = 0;
	int protecte = length;
	//进行左子树个数的统计，并根据此来求出右子树的根节点pre_tmp+1
	while (*in_tmp != *preorder)
	{
		leftTreeNum++;
		in_tmp++;
		pre_tmp++;
		protecte--;

		if (protecte == 1 && *in_tmp != *preorder)
			throw string("前序遍历和中序遍历异常");
	}

	//划分出左子树和右子树的前序遍历和中序遍历
	//并统计出左子树和右子树的节点个数
	int* leftPreOrder = preorder + 1;
	int* rightPreOrder = pre_tmp + 1;
	int* leftOrder = inorder;
	int* rightOrder = in_tmp + 1;
	int rightTreeNum = length - leftTreeNum - 1;

	//进行递归构建左子树和右子树
	root->pLeft = ReConstruct(leftPreOrder, leftOrder, leftTreeNum);
	root->pRight = ReConstruct(rightPreOrder, rightOrder, rightTreeNum);

	//返回根节点
	return root;
}

//中序遍历
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