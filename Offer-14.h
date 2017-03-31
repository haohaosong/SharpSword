#pragma once

/*
* author:haohaosong
* date:2017/23/26
* note:������14-��������˳��ʹ����λ��ż����ǰ��
*/

#include<iostream>
using namespace std;
#include<assert.h>

//�ж�һ�����Ƿ�Ϊż��
bool IsEven(int num)
{
	if (num % 2 == 0)
		return true;

	return false;
}

//����
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

//��ӡ
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