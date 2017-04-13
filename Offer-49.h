#pragma once

/*
* author:haohaosong
* date:2017/4/13
* note:������-49-ģ��ʵ��atoi
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
		//��һ���ַ���Ϊ�����ţ�Ҳ��Ϊ����
		//���򣬽�����λ��ΪFALSE������û�з���λ
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

		//�ж��Ƿ�Խ��

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
	//�����������
	string s1("123");
	pair<bool,long long> ret = my_atoi(s1);
	cout << "�Ƿ�����:" << ret.first << " ���: " << ret.second << endl;

	//�����ַ���Ϊ�յ����
	string s2;
	my_atoi(s2);
	ret = my_atoi(s2);
	cout << "�Ƿ�����:" << ret.first << " ���: " << ret.second << endl;

	//�����ַ�����ǰ���и��ŵ����
	string s3("-123");
	my_atoi(s3);
	ret = my_atoi(s3);
	cout << "�Ƿ�����:" << ret.first << " ���: " << ret.second << endl;

	//�����ַ����м䲻���ϵ����
	string s4("-1v3");
	my_atoi(s4);
	ret = my_atoi(s4);
	cout << "�Ƿ�����:" << ret.first << " ���: " << ret.second << endl;

	//�����ַ���Խ������
	string s5("55555555555555555555555555555555555555");
	my_atoi(s5);
	ret = my_atoi(s5);
	cout << "�Ƿ�����:" << ret.first << " ���: " << ret.second << endl;
}