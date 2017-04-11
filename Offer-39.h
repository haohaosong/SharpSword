#pragma once

/*
* author:haohaosong
* date:2017/4/11
* note:面试题39-求二叉树的深度，判断一颗树是不是平衡二叉树
*/

#include<iostream>
using namespace std;
#include<assert.h>

//实现一个简单的树
//取自Offer-0
struct BTNode
{
	int data;
	BTNode* left;
	BTNode* right;

	//构造函数
	BTNode(int data)
		:data(data)
		, left(NULL)
		, right(NULL)
	{}
};

class Tree
{
	typedef BTNode Node;
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

	Node* GetRoot()
	{
		return _root;
	}

	const Node* GetRoot()const
	{
		return _root;
	}
protected:

	Node* CreatTree(int* arr, const size_t size, size_t& index, const int invalid = '#')
	{
		if (index < size && arr[index] != invalid)
		{
			Node* root = new Node(arr[index]);
			root->left = CreatTree(arr, size, ++index, invalid);
			root->right = CreatTree(arr, size, ++index, invalid);
			return root;
		}
		return NULL;
	}
protected:
	Node* _root;
};

//求二叉树的深度
size_t Depth(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = Depth(root->left);
	int rightDepth = Depth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

void TestDepth()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	Tree t(arr, sizeof(arr) / sizeof(arr[0]), '#');
	cout << Depth(t.GetRoot()) << endl;
}

//判断一颗二叉树是否为平衡二叉树
bool IsBalance(BTNode* root, size_t& depth)
{
	if (root == NULL)
	{
		depth = 0;
		return true;
	}

	size_t leftDepth = 0;
	size_t rightDepth = 0;

	bool LeftIsBalance = IsBalance(root->left, leftDepth);
	bool RightIsBalance = IsBalance(root->right, rightDepth);

	bool CT_IsBalance = LeftIsBalance && RightIsBalance;

	if (CT_IsBalance)
	{
		depth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
		return (leftDepth - rightDepth)< 2;
	}

	return false;
}

void TestIsBalance()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	Tree t(arr, sizeof(arr) / sizeof(arr[0]), '#');
	size_t depth = 0;
	cout << IsBalance(t.GetRoot(), depth) << endl;
}












