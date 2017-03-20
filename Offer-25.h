#pragma once

/*
* author:haohaosong
* date:2017/3/20
* note:�������к�Ϊĳһ·����ֵ
*/

#include<iostream>
using namespace std;

//ʵ��һ���򵥵���
//ȡ��Offer-0
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
			root->_left = CreatTree(arr, size, ++index, invalid);
			root->_right = CreatTree(arr, size, ++index, invalid);
			return root;
		}
		return NULL;
	}
protected:
	Node* _root;
};

//ʹ��vector���洢·����ֵ
//ʹ�õݹ�������������
#include<vector>

//���ﴫ�����ã���һ������ݻ�ı���һ�������
//ע��currentSumҲ���Բ������ã��������ص�ʱ�򲻱ؼ�ȥcurrentSum��ֵ
void _FindPath(const TreeNode* pRoot, const int expectNum, vector<int>& v, int& currentSum)
{
	if (currentSum > expectNum)
		return;

	//���ýڵ���vector������currentNum����ֵ
	v.push_back(pRoot->_data);
	currentSum += pRoot->_data;

	bool isLeaf = pRoot->_left == NULL && pRoot->_right == NULL;

	if (currentSum == expectNum)
	{
		//�����Ҷ�ӽ��,���ҵ���·��������
		//���򣬲�Ҫ������ȥ��ֻ���˷�ʱ�䣬�ݹ鷵��
		if (isLeaf)
		{
			//��ӡ·���е�ֵ
			vector<int>::iterator it = v.begin();
			while (it != v.end())
			{
				cout << *it << " ";
				++it;
			}
			return;
		}
		else//��������ȥ��pop����ȥ��������
		{
			v.pop_back();
			currentSum -= pRoot->_data;
			return;
		}
	}

	//�����Ϊ�գ���ݹ������������������
	if (pRoot->_left != NULL )
		_FindPath(pRoot->_left, expectNum, v, currentSum);

	if (pRoot->_right != NULL)
		_FindPath(pRoot->_right, expectNum, v, currentSum);

	//������һ��ǰ���Ƚ�vector��������������ǵ�ǰ�ڵ��ֵ��pop��
	//��current��ȥ��Ӧ��ֵ
	v.pop_back();
	currentSum -= pRoot->_data;
}

//FindPath�����õݹ麯��
void FindPath(const TreeNode* pRoot, const int num)
{
	//����vector��sum
	vector<int> v;
	int sum = 0;
	
	//���õݹ麯��
	_FindPath(pRoot, num, v, sum);
}

void TestFindPath()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	Tree t(arr, sizeof(arr) / sizeof(arr[0]), '#');
	FindPath(t.GetRoot(),23);
	cout << endl;
}