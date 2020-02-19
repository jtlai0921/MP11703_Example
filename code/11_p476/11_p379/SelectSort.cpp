#include "stdafx.h"
#include "SelectSort.h"
#include <iostream>

using namespace std;

SelectSort::SelectSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}

//4 ������ܱƧ� -------------------------------------------------------
void SelectSort::select_sort()
{
	int k;
	for (int i = 0; i<len; i++)
	{
		k = i;
		for (int j = i + 1; j<len; j++)		//��̤p����
			if (list[j] < list[k]) k = j;
		swap(i, k);							//�N�̤p�����m��i��m
	}
}

void SelectSort::swap(int i, int j)
{
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

void SelectSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
