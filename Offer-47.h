#pragma once

/*
* author:haohaosong
* date:2017/4/13
* note:������47-���üӼ��˳����������������
*/

//����λ���������
//0+0=0��1+1=0,1+0=1��0+1=1 ���������û�н�λ�Ľ��
//�����������Ҫ��λ������Щλ��Ȼ������һλ�����Ҫ��λ�Ķ�Ӧλ
//ѭ�����������

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