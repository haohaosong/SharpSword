#pragma once

/*
* author:haohaosong
* date:2017/3/19
* note:字符串的全排列
*/

//面试题28:字符串的全排列
//pstr表示要打印的字符串，pbegin表示从该位置开始交换字符
void _Per(char* pstr, size_t start, size_t end)
{
	//要交换的字符指针已经到末尾，此时可以打印pstr字符串了
	if (start == end - 1)
	{
		printf("%s\n", pstr);
		return;
	}

	//注意，这里pCh不能初始为pbegin+1
	for (size_t index = start; index != end; ++index)
	{
		//依次交换后面的一个字符
		std::swap(pstr[start], pstr[index]);
		//进行递归
		_Per(pstr, start + 1, end);
		//将该字符还原
		std::swap(pstr[start], pstr[index]);
	}
}

void Per(char* pstr)
{
	if (pstr == NULL)
		return;

	//进行递归调用
	_Per(pstr, 0, strlen(pstr));
}

void TestPer()
{
	char str[] = "abcd";
	Per(str);
	cout << endl;
}