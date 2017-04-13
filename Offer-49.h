#pragma once

/*
* author:haohaosong
* date:2017/4/13
* note:面试题-49-模拟实现atoi
*/

#include<iostream>
using namespace std;
#include<string>
pair<bool,long long> my_atoi(string& s)
{
	if (s.empty())
		return make_pair(false,0);

	bool hasSimbol = true;
	char fC = s[0];
	if (fC != '+' && fC != '-')
	{
		//第一个字符不为正负号，也不为数字
		//否则，将符号位置为FALSE，代表没有符号位
		if ((fC < '0') && (fC > '9'))
			return make_pair(false, 0);
		else
			hasSimbol = false;
	}

	long long ret = 0;
	int len = s.size();
	int index = len - 1;
	long long base = 1;
	for (; index >= 0; index--)
	{
		if (index == 0 && hasSimbol)
			break;

		char tmp = s[index];
		if (tmp < '0' || tmp > '9')
			return make_pair(false, 0);

		ret += (tmp - '0')*base;
		base *= 10;

		//判断是否越界

		if (fC == '-')
		{
			if (ret < (signed int)0x80000000)
				return make_pair(false, 0);
		}
		else
		{
			if (ret > 0x7FFFFFFF)
				return make_pair(false, 0);
		}
	}

	if (hasSimbol)
	{
		if (s[0] == '-')
			ret = (-ret);
	}

	return make_pair(true,ret);
} 

void TestMyAtoi()
{
	//测试正常情况
	string s1("123");
	pair<bool,long long> ret = my_atoi(s1);
	cout << "是否正常:" << ret.first << " 结果: " << ret.second << endl;

	//测试字符串为空的情况
	string s2;
	my_atoi(s2);
	ret = my_atoi(s2);
	cout << "是否正常:" << ret.first << " 结果: " << ret.second << endl;

	//测试字符串的前面有负号的情况
	string s3("-123");
	my_atoi(s3);
	ret = my_atoi(s3);
	cout << "是否正常:" << ret.first << " 结果: " << ret.second << endl;

	//测试字符串中间不符合的情况
	string s4("-1v3");
	my_atoi(s4);
	ret = my_atoi(s4);
	cout << "是否正常:" << ret.first << " 结果: " << ret.second << endl;

	//测试字符串越界的情况
	string s5("55555555555555555555555555555555555555");
	my_atoi(s5);
	ret = my_atoi(s5);
	cout << "是否正常:" << ret.first << " 结果: " << ret.second << endl;
}