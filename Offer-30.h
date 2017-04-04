#pragma once

/*
* author:haohaosong
* date:2017/4/4
* note:面试题-30-求最小的K个数字
*/

#include<iostream>
using namespace std;

//方法一
//排序，排成升序
//前K个数即为最小的前K个数字

//快速排序
//左右指针法
int PartSort(int* arr,int left, int right)
{
	while (left < right)
	{
		while (left < right && arr[left] <= arr[right])
			left++;

		while (left < right && arr[right] >= arr[left])
			right--; 

		std::swap(arr[left], arr[right]);
	}
	return left;
}

void PrintMinKNums(int* arr, size_t n)
{
	cout << "最小的前 " << n << " 位数是:" << endl;
	for (size_t i = 0; i < n; ++i)
		cout << arr[i] << " ";

	cout << endl;
}

void QuickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int mid = PartSort(arr, left, right);
		QuickSort(arr, left, mid - 1);
		QuickSort(arr, mid + 1, right);
	}
}

void TestFindMinKNums1()
{
	int a[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0])-1);
	PrintMinKNums(a, 4);
}

//方法2
//利用快排的思想，找到最小的那位(利用PartSort)
void FindMinKNums2(int* arr,int left, int right,const int index)
{
	if (left < right)
	{
		int mid = PartSort(arr, left, right);
		if (mid == (index - 1))
			return;
		else if (mid > (index-1))
			return FindMinKNums2(arr, left, mid - 1, index);
		else
			return FindMinKNums2(arr, mid + 1, right, index);
	}
}

void TestFindMinKNums2()
{
	int a[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	FindMinKNums2(a, 0, sizeof(a) / sizeof(a[0]) - 1, 4);
	PrintMinKNums(a, 4);
}


//方法3
//利用STL中的红黑树
#include<set>

struct greater
{
	bool operator()(const int& i1, const int& i2)
	{
		return i1 > i2;
	}
};

pair<bool, multiset<int, greater>> FindMinKNums3(int* arr, size_t n, int index)
{
	if (index < 1)
		return pair<bool, multiset<int, greater>>(false, multiset<int, greater>());


	multiset<int,greater> mSet;
	for (size_t i = 0; i < n; ++i)
	{
		if (mSet.size() < index)
		{
			mSet.insert(arr[i]);
		}
		else
		{
			if (arr[i] < *mSet.begin())
			{
				mSet.erase(mSet.begin());
				mSet.insert(arr[i]);
			}
		}
	}

	if (mSet.size() < index)
		return pair<bool, multiset<int, greater>>(false, mSet);
	return pair<bool, multiset<int, greater>>(true, mSet);
}

void TestFindMinKNums3()
{
	int a[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	pair<bool,multiset<int, greater>> ret = FindMinKNums3(a,sizeof(a) / sizeof(a[0]), 4);
	if (ret.first)
	{
		multiset<int, greater>::iterator it = ret.second.begin();
		while (it != ret.second.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	else
	{
		cout << "数组有误！" << endl;
	}
}
