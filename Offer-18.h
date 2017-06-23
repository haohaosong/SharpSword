#pragma once

/*
* author:haohaosonhg
* date:2017/3/24
* note:面试题18-查找一颗树是否为另一棵树的子树
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

bool DoesTree1HasTree2(const TreeNode* srcT, const TreeNode* subT)
{
	//如果子树到了叶子节点，表示成功
	if (subT == NULL)
		return true;

	//表示没有匹配成功
	if (srcT == NULL)
		return false;

	if(srcT->_data != subT->_data)
		return false;
	
	bool retLeft = DoesTree1HasTree2(srcT->_left, subT->_left);
	bool retRight = DoesTree1HasTree2(srcT->_right, subT->_right);

	return retLeft && retRight;
}

bool HasSubTree(const TreeNode* srcT, const TreeNode* subT)
{
	if (subT == NULL)
		return false;

	bool ret = false;
	if (srcT != NULL)
	{
		if (srcT->_data == subT->_data)
		{
			ret = DoesTree1HasTree2(srcT, subT);
		}

		if (!ret)
			ret = HasSubTree(srcT->_left, subT);

		if (!ret)
			ret = HasSubTree(srcT->_right, subT);
	}
	return ret;
}

void TestHasSubTree()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	Tree t(arr, sizeof(arr) / sizeof(arr[0]), '#');
	
	int arrSub[] = { 4, 5, '#', '#', 8 };
	Tree subT(arrSub, sizeof(arrSub) / sizeof(arrSub[0]));
	
	cout << "是否为子树?:" << HasSubTree(t.GetRoot(), subT.GetRoot()); 
}