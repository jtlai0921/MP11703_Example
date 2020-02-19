#include "stdafx.h"
#include "CountingSort.h"
#include <iostream>

using namespace std;

CountingSort::CountingSort(vector<int> _list, int _len, int _max)
{
	this->max = _max;
	this->len = _len;

	for (int i = 0; i<_len; i++)
	{
		list.push_back(_list[i]);
		result.push_back(0);
		if (_list[i] > max)
		{
			cout << "��ƶW�X�d��I" << endl;
			return;
		}
	}

}

//10 �p�ƱƧ�
void CountingSort::counting_sort()
{

	int* mark = new int[max];               //�аO�L�Ǫ�����
	memset(mark, 0, max * sizeof(int));
	for (int i = 0; i < len; i++) mark[list[i]]++;
	//�έp�����X�{����
	for (int i = 1; i < max; i++) mark[i] += mark[i - 1];
	//�p�⤸���b���Ǫ���m
	for (int i = len - 1; i >= 0; i--)
	{
		//�z�Lmark[]�����Nlist[i]���Ǧa�s�Jresult[]
		result[mark[list[i]] - 1] = list[i];
		mark[list[i]]--;
	}
	delete[]mark;
}

void CountingSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << result[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
