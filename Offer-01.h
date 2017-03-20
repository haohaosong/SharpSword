#pragma once

/*
* author:haohaosong
* date:2017/3/7
* note:��Ŀ1-��ֵ���������
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//ģ��ʵ��String
class String
{
public:
	//���캯��
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

	//�������캯��
	//String(String s) �����Ǵ����д�����ᵼ�����޵ݹ����
	String(const String &s)
	{
		//�������������
		if (this != &s)
		{
			delete[] pstr;
			pstr = new char[strlen(s.pstr)];
			strcpy(pstr, s.pstr);
		}
	}

	//ע���1:����ֵΪString�����ã���֤�������������ֵ
	//ע���2:�������Ϊs�����ã���������ÿ������캯������ɵĿ���
	//ע���3:�ǵ���delete�ͷ�����Ŀռ䣬��ֹ�����ڴ�й©
	//ע���4:�Ƿ��жϴ���Ĳ����������Ƿ�Ϊͬһ��ʵ��
	//ע���5:�м��������ʱ����tmp���������tmp�����ͷ���ԭ���Ŀռ䣻�����ʱ����
	//       �ڴ治�������new�������׳��쳣ʱ��pstr�����һ����ָ��

	//�������1:����char*����ʱ�������ͷź�ֵ��pstr
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

	//�������2:�����һ���µı����������this���н���
	//������һ�ι��캯����һ����������
	/*String& operator=(const String&s)
	{
		if (this != &s)
		{
			String tmp(s.pstr);
			std::swap(pstr, tmp.pstr);
		}
		return *this;
	}*/

	//�������3:����ֵ���룬ֱ�ӽ���
	//������һ�ο������캯����һ����������
	String& operator=(String s)
	{
		std::swap(pstr, s.pstr);
	}

	//ע���:�ͷſ�ָ�벻�ᵼ�³������ռ䲻�����ͷŶ��
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