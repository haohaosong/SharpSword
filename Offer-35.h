#pragma once

/*
* author:haohaosong
* date:2017/4/10
* note:���һ������һ�ε��ַ�
*/

#include<iostream>
using namespace std;

char FindFisrtNum1Char(const char* str)
{
	assert(str);

	//ͳ��ÿ���ַ����ֵĸ���
	char hash[256] = {0};
	const char* pstr = str;
	while (*pstr != '\0')
	{
		hash[*pstr]++;
		pstr++;
	}

	pstr = str;

	while (*pstr != '\0')
	{
		if (hash[*pstr] == 1)
			return *pstr;

		pstr++;
	}

	return 0;
}

void TestFindFisrtNum1Char()
{
	char* str = "abcdacd";
	cout << FindFisrtNum1Char(str) << endl;
}