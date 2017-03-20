#pragma once

/*
* author:haohaosong
* date:2017/3/10
* note:������֮�滻�ո�
*/

#include<iostream>
using namespace std;

#include<string>
#include<assert.h>

//�滻�ո�
//src�����滻���ַ�
//des���滻��Ŀ���ַ���
void ReplaceChar(string& str,const char src = ' ', const string& des = "%20")
{
	assert(!str.empty());
	assert(!des.empty());

	//�����Ҫ�޸��ַ������������Ӷ���������Ĳ�ֵ���Լ��������ַ����ĳ���
	size_t count = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == src)
			count++;
	}

	size_t oldSize = str.length();
	size_t tmp = (des.length() - 1)*count;

	//��string���ݵ���Ӧ��С
	str.resize(oldSize + tmp);

	//���п���
	for (int i = oldSize; i >= 0; i--)
	{
		//���������Ҫ�޸ĵ��ַ�������replace���������滻
		//���������Ҫ�޸ĵ��ַ�����ֱ�����󿽱�����Ӧ��λ����
		if (str[i] == src)
		{
			//replace(size_t pos,size_t length,const string& s)
			str.replace(i + tmp - des.length() + 1,des.length(),des);

			//������tmp��ȥ��Ӧ��λ��
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