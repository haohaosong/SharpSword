#pragma once

/*
* author:haohaosong
* date:2017/3/23
* note:面试题19-二叉树的镜像
*/

#include<iostream>
using namespace std;

//实现一个简单的树
//取自Offer-0
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

	Node* GetRoot()
	{
		return _root;
	}

	const Node* GetRoot()const
	{
		return _root;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
protected:
	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}

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

//二叉树的镜像
void TreeMirror(TreeNode* root)
{
	if (root == NULL)
		return;

	//交换每个节点的根节点
	std::swap(root->_left, root->_right);

	TreeMirror(root->_left);
	TreeMirror(root->_right);
}

void TestTreeMirror()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	Tree t(arr, sizeof(arr) / sizeof(arr[0]), '#');
	t.InOrder();
	
	TreeMirror(t.GetRoot());
	t.InOrder();
}