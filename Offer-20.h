#pragma once 

/*
* author:haohaosong
* date:2017/3/24
* note:������20-����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ������
*/

#include<iostream>
using namespace std;

//col��
//row��

//��ӡ������һȦ
void PrintCricle(int matrix[], int columns, int rows, int start)
{
	//�������������
	int EndX = columns - start;
	int EndY = rows - start;

	//�������ҽ��д�ӡ����Ҫ����X����
	for (int j = start; j < EndX; ++j)
	{	
		int num = matrix[start*rows+j];
		cout << num << " ";
	}
	
	//�������½��д�ӡ����Ҫ����Y����
	//�ڶ�����ִ�������ǣ���ֹ���к�Ҫ������ʼ���к�
	if (start<EndY - 1)
	{
		for (int i = start + 1; i < EndY; ++i)
		{
			int num = matrix[i*columns + EndX - 1];
			cout << num << " ";
		}
	}

	//����������д�ӡ
	//������Ҫ��������
	if (start < EndX&&start<EndY)
	{
		for (int j = EndX - 2; j > start; --j)
		{
			int num = matrix[(EndY - 1)*columns + j];
			cout << num << " ";
		}
	}
	//�������Ͻ��д�ӡ
	//������Ҫ��������
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

//��������ĺ���
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