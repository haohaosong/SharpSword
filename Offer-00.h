#pragma once

/*
* author:haohaosong
* date:2017/3/18
* note:二叉树的递归遍历与非递归遍历
*/

#include<iostream>
using namespace std;


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

#include<stack>
class Tree
{
	typedef TreeNode Node;
public:
	Tree()
		:_root(NULL)
	{}

	Tree(int* arr, const size_t size,const int invalid = '#')
	{
		for (size_t i = 0; i < size; ++i)
		{
			size_t index = 0;
			_root = CreatTree(arr,size,index,invalid); 
		}
	}
	
	//先序遍历递归
	void PreOrder()
	{
		_PreOrder(_root);
		cout << endl;
	}

	//前序遍历递归
	void PreOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			//递归遍历左子树
			while (cur)
			{
				cout << cur->_data << " ";

				s.push(cur);
				cur = cur->_left;
			}

			Node* top = s.top();
			//遍历右子树
			cur = top->_right;
			s.pop();
		}
		cout << endl;
	}

	//中序遍历非递归
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	//中序遍历递归
	void InOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			//递归遍历左子树
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			//与前序的区别，打印顺序发生了变化
			Node* top = s.top();
			cout << top->_data << " ";
			cur = top->_right;
			s.pop();
		}
		cout << endl;
	}

	//后序遍历非递归
	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}

	void PostOrderNonR()
	{
		Node* prev = NULL;
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left; 
			}

			Node* top = s.top();
			//右子树已经被访问过了
			if (top->_right == NULL || top->_right == prev)
			{
				cout << top->_data << " ";
				prev = top;
				s.pop();
			}
			else
			{
				cur = top->_right;
			}
		}
	}
protected:
	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;

		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}


	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}

	void _PreOrder(Node* root)
	{
		if (root == NULL)
			return;

		cout << root->_data << " ";
		_PreOrder(root->_left);
		_PreOrder(root->_right);
	}

	Node* CreatTree(int* arr, const size_t size, size_t& index,const int invalid = '#')
	{
		if (index < size && arr[index] != invalid)
		{
			Node* root = new Node(arr[index]);
			root->_left = CreatTree(arr,size,++index,invalid);
			root->_right = CreatTree(arr, size, ++index,invalid);
			return root;
		}
		return NULL;
	}
protected:
	Node* _root;
};

void TestBinaryTree()
{
	//int arr[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int arr[] = { 1, 2, '#', 3, '#','#', 4,5, '#', 6 ,'#', 7,'#','#',8};
	Tree t(arr, sizeof(arr) / sizeof(arr[0]), '#');
	t.PreOrder();
	t.PreOrderNonR();

	t.InOrder();
	t.InOrderNonR();
	t.PostOrder();
	t.PostOrderNonR();
}