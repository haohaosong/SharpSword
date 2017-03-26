#pragma once

/*
* author:haohaosong
* date:2017/23/26
* note:面试题14-调整数组顺序使奇数位于偶数的前面
*/

#include<iostream>
using namespace std;
#include<assert.h>

//判断一个数是否为偶数
bool IsEven(int num)
{
	if (num % 2 == 0)
		return true;

	return false;
}

//交换
void ReOrder(int* arr, size_t length)
{
	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		while (left < right && IsEven(arr[left]))
			left++;

		while (left < right && !IsEven(arr[right]))
			right--;

		std::swap(arr[left], arr[right]);
		left++;
		right--;
	}
}

//打印
void PrintArr(int* arr, size_t length)
{
	assert(arr);

	for (size_t i = 0; i < length; ++i)
		cout << arr[i] << " ";

	cout << endl;
}

void TestReOrder()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	ReOrder(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}