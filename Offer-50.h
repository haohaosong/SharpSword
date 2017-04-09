#pragma once

/*
* author:haohaosong
* date:2017/4/9
* note:������50-�������ڵ�������������
*/

#include<iostream>
using namespace std;
#include<stack>
#include<assert.h>
struct BTNode
{
	int data;
	BTNode* left;
	BTNode* right;

	BTNode(int data)
		:data(data)
		, left(NULL)
		, right(NULL)
	{}

};

//����һ����
BTNode* CreatTree(int* arr, const size_t size, size_t& index, const int invalid = '#')
{
	if (index < size && arr[index] != invalid)
	{
		BTNode* root = new BTNode(arr[index]);
		root->left = CreatTree(arr, size, ++index, invalid);
		root->right = CreatTree(arr, size, ++index, invalid);
		return root;
	}
	return NULL;
}

//����һ���ڵ��·��
//����ת���ɽڵ�ָ��
bool FindPath(BTNode* root, int data, stack<int>& Path)
{
	if (root == NULL)
		return false;

	Path.push(root->data);
	if (root->data == data)
		return true;

	if (FindPath(root->left, data, Path))
		return true;

	if (FindPath(root->right, data, Path))
		return true;

	Path.pop();
	return false;
}

//��Ϊx1,x2�Ѿ�������root����
//int TheCommonNode(BTNode* root, BTNode* x1, BTNode* x2)
//���Դ�ָ�룬���Դ����ݣ�����Ҫ��֤���ݲ��ظ�
int TheCommonNode(BTNode* root, int x1, int x2)
{
	if (root == NULL)
		return NULL;

	assert(x1);
	assert(x2);

	stack<int> s1;
	stack<int> s2;

	/*FindPath(root, x1->data, s1);
	FindPath(root, x2->data, s2);*/

	FindPath(root, x1, s1);
	FindPath(root, x2, s2);

	int Size1 = s1.size();
	int Size2 = s2.size();

	if (Size1 > Size2)
	{
		int tmp = Size1 - Size2;
		while (tmp--)
			s1.pop();
	}
	if (Size1 < Size2)
	{
		int tmp = Size2 - Size1;
		while (tmp--)
			s2.pop();
	}

	while (1)
	{
		if (s1.top() == s2.top())
			return s1.top();

		s1.pop();
		s2.pop();
	}

	assert(false);
}

void TestTheCommonNode()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	size_t index = 0;
	BTNode* root = CreatTree(arr, sizeof(arr) / sizeof(arr[0]), index, '#');
	cout << TheCommonNode(root, 5, 8) << endl;
	cout << TheCommonNode(root, 1, 8) << endl;
	cout << TheCommonNode(root, 3, 6) << endl;
}