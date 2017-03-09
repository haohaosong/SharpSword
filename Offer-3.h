#pragma once

/*
* author:haohaosong
* date:2017/3/9
* note:һ��M*N���飬������ϵ��£�������Ϊ�ֱ�Ϊ���򣬸�һ��������ο����ж���治����
*/

//��ָ������
#include<iostream>
using namespace std;
#include<assert.h>
const int M = 3;
const int N = 3;

//�ݹ�ʵ��
//ȱ�㣬���ܵ���ջ���
bool IsExist(const int* martix, int x, int y, int key)
{
	assert(martix);

	if (x < M && x >= 0 && y < N && y >= 0)
	{
		int num = martix[x*M + y];
		
		if (num > key)
			return IsExist(martix, x, y - 1, key);
		else if (num < key)
			return IsExist(martix, x + 1, y, key);
		else
			return true;
	}
	return false;
}

//�ǵݹ����ʵ��
bool IsExistNonR(const int* martix, int x, int y, int key)
{
	assert(martix);

	while (x < M && x >= 0 && y < N && y >= 0)
	{
		int num = martix[x*M + y];
		if (num > key)
			y--;
		else if (num < key)
			x++;
		else
			return true;
	}
	return false;
}

//���Ժ���
void TestFindNum()
{
	const int martix[] = { 1, 4, 6, 
						   2, 5, 7, 
						   3, 6, 9  };
	int num = 0;
	cout << "������Ҫ���ҵ���:";
	cin >> num;
	cout << "IsExist:" << IsExist(martix, 0, M - 1, num) << endl;
	cout << "IsExist:" << IsExistNonR(martix, 0, M - 1, num) << endl;
}