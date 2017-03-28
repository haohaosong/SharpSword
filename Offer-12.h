#pragma once

/*
* author:haohaosong
* date:2017/3/28
* note:��ӡ1��Nλ�����֮�������
*/

#include<iostream>
using namespace std;

//��ӡ����
void PrintStrNum(char* str)
{
	bool IsBegin = true;
	size_t length = strlen(str);
	for (size_t i = 0; i < length; ++i)
	{
		//����ӡ֮ǰ��0
		if (IsBegin && str[i] != '0')
			IsBegin = false;

		if (IsBegin == false)
			printf("%c", str[i]);
	}
	
	//��ӡһ��Table��
	printf("\t");
}

//�ݹ���øú�������ͳ������
void _PrintDigits(char* num,const size_t length,const size_t index)
{
	//����λ��ͳ����ϣ����Դ�ӡ
	//������
	if (index == length - 1)
	{
		PrintStrNum(num);
		return;
	}

	//û��ͳ����ϣ��ݹ�ͳ������
	for (size_t i = 0; i < 10; ++i)
	{
		num[index + 1] = i + '0';
		_PrintDigits(num, length, index + 1);
	}
}

//��ʼ�������õݹ麯��
void PrintDigits(const int length)
{
	if (length <= 0)
		return;

	char* num = new char[length + 1];
	num[length] = '\0';
	size_t index = 0;
	for (size_t i = 0; i < 10; ++i)
	{
		num[0] = i + '0';
		_PrintDigits(num, length, 0);
	}
	cout << endl;
}

void TestPrintDigits()
{
	cout << "��λ��:" << endl;
	PrintDigits(2);

	cout << "��λ��:" << endl;
	PrintDigits(3);

	cout << endl;
}