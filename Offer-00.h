#pragma once

/*
* author:haohaosong
* date:2017/3/18
* note:�������ĵݹ������ǵݹ����
*/

#include<iostream>
using namespace std;


struct TreeNode
{
	int _data;
	TreeNode* _left;
	TreeNode* _right;

	//���캯��
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
	
	//��������ݹ�
	void PreOrder()
	{
		_PreOrder(_root);
		cout << endl;
	}

	//ǰ������ݹ�
	void PreOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			//�ݹ����������
			while (cur)
			{
				cout << cur->_data << " ";

				s.push(cur);
				cur = cur->_left;
			}

			Node* top = s.top();
			//����������
			cur = top->_right;
			s.pop();
		}
		cout << endl;
	}

	//��������ǵݹ�
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	//��������ݹ�
	void InOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			//�ݹ����������
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			//��ǰ������𣬴�ӡ˳�����˱仯
			Node* top = s.top();
			cout << top->_data << " ";
			cur = top->_right;
			s.pop();
		}
		cout << endl;
	}

	//��������ǵݹ�
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
			//�������Ѿ������ʹ���
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