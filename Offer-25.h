#pragma once

/*
* author:haohaosong
* date:2017/3/20
* note:二叉树中和为某一路径的值
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

//使用vector来存储路径的值
//使用递归来遍历整颗树
#include<vector>

//这里传入引用，这一层的数据会改变上一层的数据
//注：currentSum也可以不传引用，这样返回的时候不必减去currentSum的值
void _FindPath(const TreeNode* pRoot, const int expectNum, vector<int>& v, int& currentSum)
{
	if (currentSum > expectNum)
		return;

	//将该节点入vector，并让currentNum加上值
	v.push_back(pRoot->_data);
	currentSum += pRoot->_data;

	bool isLeaf = pRoot->_left == NULL && pRoot->_right == NULL;

	if (currentSum == expectNum)
	{
		//如果是叶子结点,则找到该路径，返回
		//否则，不要再找下去，只会浪费时间，递归返回
		if (isLeaf)
		{
			//打印路径中的值
			vector<int>::iterator it = v.begin();
			while (it != v.end())
			{
				cout << *it << " ";
				++it;
			}
			return;
		}
		else//不在找下去，pop，减去，并返回
		{
			v.pop_back();
			currentSum -= pRoot->_data;
			return;
		}
	}

	//如果不为空，则递归访问左子树和右子树
	if (pRoot->_left != NULL )
		_FindPath(pRoot->_left, expectNum, v, currentSum);

	if (pRoot->_right != NULL)
		_FindPath(pRoot->_right, expectNum, v, currentSum);

	//返回上一层前，先将vector的最后存的数（就是当前节点的值）pop了
	//并current减去对应的值
	v.pop_back();
	currentSum -= pRoot->_data;
}

//FindPath来调用递归函数
void FindPath(const TreeNode* pRoot, const int num)
{
	//定义vector和sum
	vector<int> v;
	int sum = 0;
	
	//调用递归函数
	_FindPath(pRoot, num, v, sum);
}

void TestFindPath()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	Tree t(arr, sizeof(arr) / sizeof(arr[0]), '#');
	FindPath(t.GetRoot(),23);
	cout << endl;
}