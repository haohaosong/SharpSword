#pragma once

/*
* author:haohaosong
* date:2017/4/5
* note:������-31-���������������ĺ�
*/

#include<iostream>
using namespace std;

pair<bool,int> MaxArrOfNum(int* arr, size_t n)
{
	if (arr == NULL || n == 0)
		return make_pair(false, 0);
	
	//�ж��ǲ���ȫ�Ǹ���
	//ȫ�Ǹ�������������ĿҪ��
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
		//���С��0��ֱ�Ӹ���tmpSum
		//�������0���ӵ�tmpSum��
		if (tmpSum <= 0)
			tmpSum = arr[i];
		else
			tmpSum += arr[i];

		//��maxSum��ΪtmpSum��maxSum�е����ֵ
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
		cout << "�������������ֵ:" << retNum << endl;
	}
	else
	{
		cout << "�������������" << endl;
	}
}