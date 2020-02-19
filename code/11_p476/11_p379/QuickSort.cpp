#include "stdafx.h"
#include "QuickSort.h"
#include <iostream>

using namespace std;

QuickSort::QuickSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}

//8 �ֳt�Ƨ�------------------------------------------------------------
void QuickSort::quick_sort(int left, int right)
{
	int i = left;
	int j = right;
	int pivot = list[left];

	while (i<j)
	{
		while (i<j && list[j] >= pivot) j--; //�����Ƥp������
		if (i < j) swap(i, j);
		while (i<j && list[i] <= pivot) i++; //�����Ƥj������
		if (i < j) swap(i, j);
	}

	if (i != left) quick_sort(left, i - 1);    //��list[left...i-1]�Ƨ�
	if (j != right) quick_sort(j + 1, right);  //��list[j+1...right]�Ƨ�
}

void QuickSort::swap(int i, int j)
{
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

void QuickSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
