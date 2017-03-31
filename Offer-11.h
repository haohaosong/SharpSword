/*
* author:haohaosong
* date:2017/3/31
* note:������11-ģ��ʵ��Power
*/

#include<iostream>
using namespace std;
#include<assert.h>

double PowerWithUnsignedExponent(double base, size_t exponent)
{
	//���ָ��Ϊ0����ô����1
	//���ָ��Ϊ1��Ȼ�����
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	//�ݹ���ָ����һ��
	//�������ķ���ֵ��ƽ�����ǵ�ǰ�Ľ�
	double ret = PowerWithUnsignedExponent(base, exponent >> 1);
	ret *= ret;

	//����Ҫ�Ի�����������
	if ((exponent & 0x1) == 1)
		ret *= base;

	return ret;
}

//������11-��һ������N�η�
double Power(double base, int exponent)
{
	//�������Ϊ0����ָ��С��0�����Ա���
	assert(base != 0.0 || exponent >= 0);

	//�����ָ���ľ���ֵ
	size_t absExponent = (size_t)(exponent);

	//���ָ����С��0�ģ�ָ����Ҫ�������
	if (exponent < 0)
		absExponent = (size_t)(-exponent);

	//�ݹ����
	double ret = PowerWithUnsignedExponent(base, absExponent);

	//���ָ����С��0�ģ���
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

	//���Ա���
	cout << "Power(0, -1): " << Power(0, -1) << endl;
}