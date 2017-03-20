#pragma once

/*
* author:haohaosong
* date:2017/3/20
* note:������-24�ж�һ�������ǲ���ĳ�Ŷ������ĺ������
*/

//����ǣ�����true
//������ǣ�����FALSE
bool isBST(int seq[], int length)
{
	if (seq == NULL || length < 0)
		return false;

	//��λ���ڵ�
	int root = seq[length - 1];

	//�ҳ��������ĸ�
	int i = 0;
	for (; i < length - 1; ++i)
	{
		if (seq[i] > root)
			break;
	}

	//�ж��������Ƿ���ȷ��������ȷ������FALSE
	int j = i;
	for (; j < length-1; ++j)
	{
		if (seq[j] < root)
			return false;
	}

	//�ݹ��ж����������������Ƿ���������
	bool isBST_Left = true;
	if (i > 0)
		isBST_Left = isBST(seq, i);

	bool isBST_Right = true;
	if (j < length - 1)
		isBST_Right = isBST(seq + i, length - i - 1);

	return (isBST_Left && isBST_Right);
}

void TestIsBST()
{
	int seq[] = { 5, 7, 6, 9, 11, 10, 8 };
	cout << "�Ƿ���һ�Ŷ���������?:" << isBST(seq,sizeof(seq)/sizeof(seq[0])) << endl;

	int seq2[] = {7,4,6,5};
	cout << "�Ƿ���һ�Ŷ���������?:" << isBST(seq2, sizeof(seq2) / sizeof(seq2[0])) << endl;
}