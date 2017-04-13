#pragma once

/*
* author:haohaosong
* date:2017/4/13
* note:面试题47-不用加减乘除来求两个数字相加
*/

//采用位运算来求解
//0+0=0，1+1=0,1+0=1，0+1=1 异或可以算出没有进位的结果
//与运算算出需要进位的是哪些位，然后左移一位求出需要进位的对应位
//循环，继续相加

int Add(int x, int y)
{
	int sum = 0;
	int tmp = 0;
	do
	{
		sum = x^y;
		tmp = (x&y) << 1;

		x = sum;
		y = tmp;
	} while (y != 0);

	return x;
}