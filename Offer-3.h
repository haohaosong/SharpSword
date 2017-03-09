#pragma once

/*
* author:haohaosong
* date:2017/3/9
* note:一个M*N数组，数组从上到下，从左到右为分别为增序，给一个数，如何快速判断其存不存在
*/

//剑指第三题
#include<iostream>
using namespace std;
#include<assert.h>
const int M = 3;
const int N = 3;

//递归实现
//缺点，可能导致栈溢出
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

//非递归进行实现
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

//测试函数
void TestFindNum()
{
	const int martix[] = { 1, 4, 6, 
						   2, 5, 7, 
						   3, 6, 9  };
	int num = 0;
	cout << "请输入要查找的数:";
	cin >> num;
	cout << "IsExist:" << IsExist(martix, 0, M - 1, num) << endl;
	cout << "IsExist:" << IsExistNonR(martix, 0, M - 1, num) << endl;
}