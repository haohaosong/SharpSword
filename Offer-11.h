/*
* author:haohaosong
* date:2017/3/31
* note:面试题11-模拟实现Power
*/

#include<iostream>
using namespace std;
#include<assert.h>

double PowerWithUnsignedExponent(double base, size_t exponent)
{
	//如果指数为0，那么返回1
	//如果指数为1，然会基数
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	//递归求指数的一半
	//求下来的返回值的平方既是当前的解
	double ret = PowerWithUnsignedExponent(base, exponent >> 1);
	ret *= ret;

	//这里要对基数幂做处理
	if ((exponent & 0x1) == 1)
		ret *= base;

	return ret;
}

//面试题11-求一个数的N次方
double Power(double base, int exponent)
{
	//如果基数为0并且指数小于0，断言报错
	assert(base != 0.0 || exponent >= 0);

	//先求出指数的绝对值
	size_t absExponent = (size_t)(exponent);

	//如果指数是小于0的，指数需要算成正数
	if (exponent < 0)
		absExponent = (size_t)(-exponent);

	//递归求解
	double ret = PowerWithUnsignedExponent(base, absExponent);

	//如果指数是小于0的，求倒
	if (exponent < 0)
		ret = 1.0 / ret;

	return ret;
}

void TestPower()
{
	cout << "Power(0, 2): " << Power(0, 2) << endl;
	cout << "Power(1, 2): " << Power(1, 2) << endl;
	cout << "Power(2, -1): " << Power(2, -1) << endl;
	cout << "Power(2, 0): " << Power(2, 0) << endl;
	cout << "Power(2, 1): " << Power(2, 1) << endl;
	cout << "Power(2, 2): " << Power(2, 2) << endl;
	cout << "Power(2, 3): " << Power(2, 3) << endl;

	//断言报错
	cout << "Power(0, -1): " << Power(0, -1) << endl;
}