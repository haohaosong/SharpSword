#pragma once

/*
* author:haohaosong
* date:2017/3/23
* note:面试题23-二叉树的层序遍历
*/

#include<queue>
void LevelOrder(const TreeNode* root)
{
	if (root == NULL)
		return;

	queue<const TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		const TreeNode* top = q.front();
		q.pop();

		cout << top->_data <<" ";

		if (top->_left != NULL)
			q.push(top->_left);

		if (top->_right != NULL)
			q.push(top->_right);
	}
}

void TestLevelOrder()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	Tree t(arr, sizeof(arr) / sizeof(arr[0]), '#');
	LevelOrder(t.GetRoot());
	cout << endl;
}