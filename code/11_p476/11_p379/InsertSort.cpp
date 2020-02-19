#include "stdafx.h"
#include "InsertSort.h"
#include <iostream>

using namespace std;

InsertSort::InsertSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}

//1 �������J�Ƨ�
void InsertSort::insert_sort()
{
	int insertNum;
	for (int i = 0; i<len; i++)
	{
		insertNum = list[i];	//�ݴ��J����
		int j = i;
		while (j>0 && insertNum<list[j - 1])	//�M�䴡�J��m
		{
			list[j] = list[j - 1];
			j--;
		}
		list[j] = insertNum;
	}
}

void InsertSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
