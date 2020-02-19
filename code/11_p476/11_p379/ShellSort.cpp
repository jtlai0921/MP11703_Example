#include "stdafx.h"
#include "ShellSort.h"  
#include <iostream>  

using namespace std;

ShellSort::ShellSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}

//3 �ƺ��Ƨ�------------------------------------------------------------
void ShellSort::shell_sort()
{
	int insertNum;
	int gap = len / 2;						//��l�W�q
	while (gap)                             //��gap>=1
	{
		for (int i = gap; i<len; i++)       //��gap���j�l�ǦC�i�洡�J�Ƨ�
		{
			insertNum = list[i];            //�ݴ��J����
			int j = i;
			while (j >= gap && insertNum<list[j - gap])
			{                               //�M�䴡�J��m
				list[j] = list[j - gap];
				j -= gap;
			}
			list[j] = insertNum;            //���J
		}

		gap = gap / 2;                      //�Y�p�W�q
	}

}

void ShellSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
