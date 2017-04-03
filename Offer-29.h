#pragma once

/*
* author:haohaosong
* date:2017/4/3
* note:找出出现一半的数字
*/

#include<iostream>
using namespace std;

//方法1：排序后取中间值

//直接插入排序的思想
//分成两个数组
//第一个数组是有序的，第二个是无序的
//开始的时候，只有第一个数在第一个数组
//升序
void InsertSort(int* arr, size_t n)
{
	for (int i = 1; i < n; ++i)
	{
		int j = i - 1;
		int tmp = arr[i];
		for (; j >= 0; --j)
		{
			//如果tmp比该位置大
			if (tmp > arr[j])
				break; 

			arr[j + 1] = arr[j];
		}
		arr[j+1] = tmp;
	}
}

int MoreThanHalf1(int* arr, size_t n)
{
	InsertSort(arr, n);
	int midIndex = n >> 1;
	return arr[midIndex];
}


//方法2
//用快排，找中间的数


//方法3
//用技巧
pair<bool,int> MoreThanHalf3(int* arr, size_t n)
{
	int num = arr[0];
	int count = 1;

	for (size_t i = 1; i < n; ++i)
	{
		if (num == arr[i])
			count++;
		else
			count--; 

		if (count == 0)
		{
			if (i >= n - 1)
				return make_pair(false,0);
			num = arr[i + 1];
		}
	}
	return make_pair(true, num);
}

void TestMoreThanHalf1()
{
	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int ret = MoreThanHalf1(arr, sizeof(arr) / sizeof(arr[0]));
	cout << ret << endl;
}

void TestMoreThanHalf3()
{
	int arr[] = { 1, 2, 3, 5, 4, 2 };
	pair<bool, int> ret = MoreThanHalf3(arr, sizeof(arr) / sizeof(arr[0]));
	if (ret.first == false)
		cout << "数组有误！" << endl;
	else
		cout << ret.second << endl;
}