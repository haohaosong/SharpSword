#pragma once

/*
* author:haohaosong
* date:2017/4/10
* note:求第一个出现一次的字符
*/

#include<iostream>
using namespace std;

char FindFisrtNum1Char(const char* str)
{
	assert(str);

	//统计每个字符出现的个数
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