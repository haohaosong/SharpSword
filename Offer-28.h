#pragma once

/*
* author:haohaosong
* date:2017/3/19
* note:�ַ�����ȫ����
*/

//������28:�ַ�����ȫ����
//pstr��ʾҪ��ӡ���ַ�����pbegin��ʾ�Ӹ�λ�ÿ�ʼ�����ַ�
void _Per(char* pstr, size_t start, size_t end)
{
	//Ҫ�������ַ�ָ���Ѿ���ĩβ����ʱ���Դ�ӡpstr�ַ�����
	if (start == end - 1)
	{
		printf("%s\n", pstr);
		return;
	}

	//ע�⣬����pCh���ܳ�ʼΪpbegin+1
	for (size_t index = start; index != end; ++index)
	{
		//���ν��������һ���ַ�
		std::swap(pstr[start], pstr[index]);
		//���еݹ�
		_Per(pstr, start + 1, end);
		//�����ַ���ԭ
		std::swap(pstr[start], pstr[index]);
	}
}

void Per(char* pstr)
{
	if (pstr == NULL)
		return;

	//���еݹ����
	_Per(pstr, 0, strlen(pstr));
}

void TestPer()
{
	char str[] = "abcd";
	Per(str);
	cout << endl;
}