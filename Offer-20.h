#pragma once 

/*
* author:haohaosong
* date:2017/3/24
* note:面试题20-输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
*/

#include<iostream>
using namespace std;

//col列
//row行

//打印单独的一圈
void PrintCricle(int matrix[], int columns, int rows, int start)
{
	//定义结束的坐标
	int EndX = columns - start;
	int EndY = rows - start;

	//从左向右进行打印，需要对其X坐标
	for (int j = start; j < EndX; ++j)
	{	
		int num = matrix[start*rows+j];
		cout << num << " ";
	}
	
	//从上向下进行打印，需要对其Y坐标
	//第二步的执行条件是，终止的行号要大于起始的行号
	if (start<EndY - 1)
	{
		for (int i = start + 1; i < EndY; ++i)
		{
			int num = matrix[i*columns + EndX - 1];
			cout << num << " ";
		}
	}

	//从右向左进行打印
	//至少需要两行两列
	if (start < EndX&&start<EndY)
	{
		for (int j = EndX - 2; j > start; --j)
		{
			int num = matrix[(EndY - 1)*columns + j];
			cout << num << " ";
		}
	}
	//从下往上进行打印
	//至少需要三行两列
	if (start < EndX - 1 && start<EndY - 1)
	{
		for (int i = EndY - 1; i > start; --i)
		{
			int num = matrix[i*columns + start];
			cout << num << " ";
		}
	}
	cout<<endl;
}

//调用上面的函数
void PrintMatrix(int matrix[], int columns, int rows)
{
	if (matrix == NULL || columns <= 0 || rows <= 0)
		return;

	int start = 0;

	while (columns > start * 2 && rows > start * 2)
	{
		PrintCricle(matrix, columns, rows, start);
		++start;
	}
}

void TestPrintMatrixCircle()
{
	/*const int rows = 4;
	const int columns = 4;
	int matrix[] = { 
					 1, 2, 3, 4 ,
					 5, 6, 7, 8 ,
					 9, 10, 11, 12 ,
					  13, 14, 15, 16 
					};*/

	//const int rows = 5;
	//const int columns = 5;
	//int matrix[] = {
	//	1, 2, 3, 4,5,
	//	5, 6, 7, 8,9,
	//	9, 10, 11, 12,13,
	//	13, 14, 15, 16,17
	//	,18, 19, 20, 21, 22
	//};

	const int rows = 3;
	const int columns = 5;
	int matrix[] = {
		1, 2, 3,4, 5,
		6,7, 8, 9,10,
		11, 12,13, 14, 15
		/*13, 14, 15, 16, 17
		, 18, 19, 20, 21, 22*/
	};

	PrintMatrix(matrix, columns, rows);
	cout << endl;
};