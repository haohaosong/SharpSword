#pragma once

/*
* author:haohaosong
* date:2017/3/20
* note:面试题-24判断一个数组是不是某颗二叉树的后序遍历
*/

//如果是，返回true
//如果不是，返回FALSE
bool isBST(int seq[], int length)
{
	if (seq == NULL || length < 0)
		return false;

	//定位根节点
	int root = seq[length - 1];

	//找出左子树的根
	int i = 0;
	for (; i < length - 1; ++i)
	{
		if (seq[i] > root)
			break;
	}

	//判断右子树是否正确，若不正确，返回FALSE
	int j = i;
	for (; j < length-1; ++j)
	{
		if (seq[j] < root)
			return false;
	}

	//递归判断左子树和右子树是否满足条件
	bool isBST_Left = true;
	if (i > 0)
		isBST_Left = isBST(seq, i);

	bool isBST_Right = true;
	if (j < length - 1)
		isBST_Right = isBST(seq + i, length - i - 1);

	return (isBST_Left && isBST_Right);
}

void TestIsBST()
{
	int seq[] = { 5, 7, 6, 9, 11, 10, 8 };
	cout << "是否是一颗二叉搜索树?:" << isBST(seq,sizeof(seq)/sizeof(seq[0])) << endl;

	int seq2[] = {7,4,6,5};
	cout << "是否是一颗二叉搜索树?:" << isBST(seq2, sizeof(seq2) / sizeof(seq2[0])) << endl;
}