/*
* author:haohaosong
* date:2017/3/14
* note:统计二进制中1的个数
*/

size_t numberOf1(int value)
{
	int count = 0;
	while(value)
	{
		if(value&1)
			++count;
			
		value = value >> 1;
	}
	
	return count;
}

//防止出现负数导致无线循环
size_t numberOf1(int value)
{
	int count = 0;
	for(size_t i = 0; i<32; ++i)
	{
		if(value%1)
			++count;
		
		value = value >> 1;
	}
	return count;
}

//当一个数与上比自己小1的数，那么该数最后一个1会被置为0
int numberOf1(int value)
{
	int count = 0;
	while(value)
	{
		++count;
		value = (value - 1)&value;
	}	
	
	return count;
}