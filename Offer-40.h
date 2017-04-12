#pragma once

/*
* author:haohaosong
* date:2017/4/11
* note:��������ֻ���ֹ�һ�ε�����
*/

#include<iostream>
using namespace std;
#include<vector>

//����������������ֻ������һ��
void FunNumApperanceOnce(vector<int>& v, int& num1, int& num2)
{
	if (v.size() <= 2)
		return;

	int ret = 0;

	//�ҳ������������֮��Ľ��
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		int num = *it;
		ret = ret^num;
		++it;
	}

	//�ж����ұߵ�1�ǵڼ�λ
	size_t i = 0;
	for (; i < 32; ++i)
	{
		if ((ret << i) & 1 == 1)
			break;
	}

	//����λ���ֳ����飬�ֱ������������һ�ε�����
	it = v.begin();
	while (it != v.end())
	{
		int num = *it;
		if (num&(1 << i) == 1)
		{
			num1 ^= num;
		}
		else
		{
			num2 ^= num;
		}
		++it;
	}
}

void TestFunNumApperanceOnce()
{
	int data[] = { 1, 2, 2, 3, 4, 5, 1, 5 };
	vector<int> v;
	for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); ++i)
	{
		v.push_back(data[i]);
	}
	int num1 = 0;
	int num2 = 0;
	FunNumApperanceOnce(v, num1, num2);

	cout << "num1:" << num1 << endl;
	cout << "num2:" << num2 << endl;
}