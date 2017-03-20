#pragma once

/*
* author:haohaosong
* date:2017/3/10
* note:面试题之替换空格
*/

#include<iostream>
using namespace std;

#include<string>
#include<assert.h>

//替换空格
//src代表被替换的字符
//des是替换的目标字符串
void ReplaceChar(string& str,const char src = ' ', const string& des = "%20")
{
	assert(!str.empty());
	assert(!des.empty());

	//获得需要修改字符串的数量，从而求出拷贝的差值，以及拷贝后字符串的长度
	size_t count = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == src)
			count++;
	}

	size_t oldSize = str.length();
	size_t tmp = (des.length() - 1)*count;

	//将string扩容到对应大小
	str.resize(oldSize + tmp);

	//进行拷贝
	for (int i = oldSize; i >= 0; i--)
	{
		//如果碰到需要修改的字符，则用replace函数进行替换
		//如果不是需要修改的字符，则直接往后拷贝到对应的位置上
		if (str[i] == src)
		{
			//replace(size_t pos,size_t length,const string& s)
			str.replace(i + tmp - des.length() + 1,des.length(),des);

			//拷贝后，tmp减去相应的位数
			tmp -= (des.length()-1);
			if (tmp == 0)
				return;
		}
		else
		{
			str[i + tmp] = str[i];
		}
	}
}

void TestReplaceChar()
{
	string s("We are human");
	ReplaceChar(s);
	cout << s << endl;
}

int main()
{
	TestReplaceChar();
	return 0;
}