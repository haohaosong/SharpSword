#pragma once

/*
* author:haohaosong
* date:2017/3/20
* note:面试题27:将二叉搜索树合成一个排序的双向链表
*/

#include<iostream>
using namespace std;

//**********************二叉树的实现**************************//
struct TreeNode
{
	int _data;
	TreeNode* _left;
	TreeNode* _right;

	//构造函数
	TreeNode(int data)
		:_data(data)
		, _left(NULL)
		, _right(NULL)
	{}
};

class Tree
{
	typedef TreeNode Node;
public:
	Tree()
		:_root(NULL)
	{}

	Tree(int* arr, const size_t size, const int invalid = '#')
	{
		for (size_t i = 0; i < size; ++i)
		{
			size_t index = 0;
			_root = CreatTree(arr, size, index, invalid);
		}
	}

	Node* GetRoot()const
	{
		return _root;
	}
protected:
	Node* CreatTree(int* arr, const size_t size, size_t& index, const int invalid = '#')
	{
		if (index < size && arr[index] != invalid)
		{
			Node* root = new Node(arr[index]);
			root->_left = CreatTree(arr, size, ++index, invalid);
			root->_right = CreatTree(arr, size, ++index, invalid);
			return root;
		}
		return NULL;
	}
protected:
	Node* _root;
};

//***********************转换的代码***************************//

void _Convert(TreeNode* root,TreeNode*& lastTreeNode)
{
	if (root == NULL)
		return;

	//递归找到左子树的最后一个节点
	if (root->_left)
		_Convert(root->_left, lastTreeNode);

	//将当前节点和左子树的最后一个节点进行链接
	root->_left = lastTreeNode;

	if (lastTreeNode)//这里需要注意左子树为空的情况
		lastTreeNode->_right = root;

	lastTreeNode = root;
	if (root->_right)
		_Convert(root->_right, lastTreeNode);
}

TreeNode* Convert(TreeNode* root)
{
	TreeNode* lastTreeNode = NULL;
	_Convert(root,lastTreeNode);

	//lastTreeNode指向的是双向链表中的最后一个节点
	//现在我们需要找到第一个节点
	//返回双向链表的头节点
	TreeNode* phead = lastTreeNode;
	while (phead->_left)
		phead = phead->_left;

	return phead;
}

void TestConvert()
{
	//自主构造一颗二叉搜索树
	int arr[] = { 10, 6, 4, '#', '#', 8, '#', '#', 14, 12, '#', '#', 16 }; 
	Tree t(arr,sizeof(arr)/sizeof(arr[0]));
	TreeNode* pnewHead = Convert(t.GetRoot());
	TreeNode* cur = pnewHead;
	
	//打印最后的双向链表
	//结果是有序的
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->_right;
	}
	cout << endl;
}