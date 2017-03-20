#pragma once

/*
* author:haohaosong
* date:2017/3/20
* note:������27:�������������ϳ�һ�������˫������
*/

#include<iostream>
using namespace std;

//**********************��������ʵ��**************************//
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

//***********************ת���Ĵ���***************************//

void _Convert(TreeNode* root,TreeNode*& lastTreeNode)
{
	if (root == NULL)
		return;

	//�ݹ��ҵ������������һ���ڵ�
	if (root->_left)
		_Convert(root->_left, lastTreeNode);

	//����ǰ�ڵ�������������һ���ڵ��������
	root->_left = lastTreeNode;

	if (lastTreeNode)//������Ҫע��������Ϊ�յ����
		lastTreeNode->_right = root;

	lastTreeNode = root;
	if (root->_right)
		_Convert(root->_right, lastTreeNode);
}

TreeNode* Convert(TreeNode* root)
{
	TreeNode* lastTreeNode = NULL;
	_Convert(root,lastTreeNode);

	//lastTreeNodeָ�����˫�������е����һ���ڵ�
	//����������Ҫ�ҵ���һ���ڵ�
	//����˫�������ͷ�ڵ�
	TreeNode* phead = lastTreeNode;
	while (phead->_left)
		phead = phead->_left;

	return phead;
}

void TestConvert()
{
	//��������һ�Ŷ���������
	int arr[] = { 10, 6, 4, '#', '#', 8, '#', '#', 14, 12, '#', '#', 16 }; 
	Tree t(arr,sizeof(arr)/sizeof(arr[0]));
	TreeNode* pnewHead = Convert(t.GetRoot());
	TreeNode* cur = pnewHead;
	
	//��ӡ����˫������
	//����������
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->_right;
	}
	cout << endl;
}