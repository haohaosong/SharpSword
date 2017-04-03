#pragma once

/*
* author:haohaosong
* date:2017/4/3
* note:�ҳ�����һ�������
*/

#include<iostream>
using namespace std;

//����1�������ȡ�м�ֵ

//ֱ�Ӳ��������˼��
//�ֳ���������
//��һ������������ģ��ڶ����������
//��ʼ��ʱ��ֻ�е�һ�����ڵ�һ������
//����
void InsertSort(int* arr, size_t n)
{
	for (int i = 1; i < n; ++i)
	{
		int j = i - 1;
		int tmp = arr[i];
		for (; j >= 0; --j)
		{
			//���tmp�ȸ�λ�ô�
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


//����2
//�ÿ��ţ����м����


//����3
//�ü���
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
		cout << "��������" << endl;
	else
		cout << ret.second << endl;
}