#pragma once

/*
* author:haohaosong
* date:2017/3/7
* note:题目1-赋值运算符重载
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//模拟实现String
class String
{
public:
	//构造函数
	//String(const char* _pstr = NULL)
	String(const char* _pStr = "")
	{
		if (_pStr == NULL)
		{
			pstr = new char[1];
			*pstr = '\0';
		}
		else
		{
			pstr = new char[strlen(_pStr) + 1];
			strcpy(pstr, _pStr);
		}
	}

	//拷贝构造函数
	//String(String s) 这种是错误的写法，会导致无限递归调用
	String(const String &s)
	{
		//如果不是自身拷贝
		if (this != &s)
		{
			delete[] pstr;
			pstr = new char[strlen(s.pstr)];
			strcpy(pstr, s.pstr);
		}
	}

	//注意点1:返回值为String的引用，保证了其可以连续赋值
	//注意点2:穿入参数为s的引用，减少其调用拷贝构造函数而造成的开销
	//注意点3:记得用delete释放申请的空间，防止出现内存泄漏
	//注意点4:是否判断传入的参数和自身是否为同一个实例
	//注意点5:中间采用了临时变量tmp。如果不用tmp，先释放了原来的空间；如果此时由于
	//       内存不足而导致new不出来抛出异常时，pstr便成了一个空指针

	//解决方法1:申请char*的临时变量，释放后赋值给pstr
	/*String& operator=(const String&s)
	{
		if (&s != this)
		{
			char* tmp = new char[strlen(s.pstr)+1];
			strcpy(tmp, s.pstr);
			delete[] pstr;
			pstr = tmp;
		}
		return *this;
	}*/

	//解决方法2:构造出一个新的变量，将其和this进行交换
	//调用了一次构造函数和一次析构函数
	/*String& operator=(const String&s)
	{
		if (this != &s)
		{
			String tmp(s.pstr);
			std::swap(pstr, tmp.pstr);
		}
		return *this;
	}*/

	//解决方法3:进行值传入，直接交换
	//调用了一次拷贝构造函数和一次析构函数
	String& operator=(String s)
	{
		std::swap(pstr, s.pstr);
	}

	//注意点:释放空指针不会导致出错，但空间不允许释放多次
	~String()
	{
		if (pstr != NULL)
		{
			delete[] pstr;
			pstr = NULL;
		}
	}
protected:
	char* pstr;
};