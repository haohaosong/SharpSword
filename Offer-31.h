#pragma once

/*
* author:haohaosong
* date:2017/4/5
* note:面试题-31-求最大连续子数组的和
*/

#include<iostream>
using namespace std;

pair<bool,int> MaxArrOfNum(int* arr, size_t n)
{
	if (arr == NULL || n == 0)
		return make_pair(false, 0);
	
	//判断是不是全是负数
	//全是负数，不满足题目要求
	size_t i = 0;
	while (i < n)
	{
		if (arr[i] > 0)
			break;
		++i;
	}

	if (i == n)
		return make_pair(false, 0);

	int maxSum = 0;
	int tmpSum = 0;
	for (size_t i = 0; i < n; ++i)
	{
		//如果小于0，直接覆盖tmpSum
		//如果大于0，加到tmpSum上
		if (tmpSum <= 0)
			tmpSum = arr[i];
		else
			tmpSum += arr[i];

		//将maxSum置为tmpSum和maxSum中的最大值
		if (tmpSum > maxSum)
			maxSum = tmpSum;
	}

	return make_pair(true, maxSum);
}

void TestMaxArrOfNum()
{
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	//int arr[] = { -1, -1, -1, -1 };
	pair<bool, int> ret = MaxArrOfNum(arr, sizeof(arr) / sizeof(arr[0]));
	if (ret.first == true)
	{
		int retNum = ret.second;
		cout << "最大的连续数组的值:" << retNum << endl;
	}
	else
	{
		cout << "输入的数组有误！" << endl;
	}
}