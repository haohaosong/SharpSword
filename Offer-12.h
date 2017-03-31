#pragma once

/*
* author:haohaosong
* date:2017/3/28
* note:打印1到N位最大数之间的数字
*/

#include<iostream>
using namespace std;

//打印数字
void PrintStrNum(char* str)
{
	bool IsBegin = true;
	size_t length = strlen(str);
	for (size_t i = 0; i < length; ++i)
	{
		//不打印之前的0
		if (IsBegin && str[i] != '0')
			IsBegin = false;

		if (IsBegin == false)
			printf("%c", str[i]);
	}
	
	//打印一个Table键
	printf("\t");
}

//递归调用该函数进行统计数字
void _PrintDigits(char* num,const size_t length,const size_t index)
{
	//所有位数统计完毕，可以打印
	//并返回
	if (index == length - 1)
	{
		PrintStrNum(num);
		return;
	}

	//没有统计完毕，递归统计数字
	for (size_t i = 0; i < 10; ++i)
	{
		num[index + 1] = i + '0';
		_PrintDigits(num, length, index + 1);
	}
}

//初始化及调用递归函数
void PrintDigits(const int length)
{
	if (length <= 0)
		return;

	char* num = new char[length + 1];
	num[length] = '\0';
	size_t index = 0;
	for (size_t i = 0; i < 10; ++i)
	{
		num[0] = i + '0';
		_PrintDigits(num, length, 0);
	}
	cout << endl;
}

void TestPrintDigits()
{
	cout << "两位数:" << endl;
	PrintDigits(2);

	cout << "三位数:" << endl;
	PrintDigits(3);

	cout << endl;
}