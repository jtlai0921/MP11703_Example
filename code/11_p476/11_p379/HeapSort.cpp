#include "stdafx.h"
#include "HeapSort.h"
#include <iostream>

using namespace std;

HeapSort::HeapSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}
// ��Ƨ�
void HeapSort::heap_sort()
{
	for (int i = (len - 2) / 2; i >= 0; i--) filterDown(i, len - 1);//�إ߰�

	for (int i = len - 1; i>0; i--)
	{
		swap(0, i);
		filterDown(0, i - 1);			//���_�վ�אּ�̤j��
	}

}
// �諸�إߩνվ�
void HeapSort::filterDown(int current, int last)
{
	int child = 2 * current + 1;		//child��current���Ĥl��m
	int temp = list[current];           //�Ȧs�l��ڸ`�I
	while (child <= last)               //�P�_�O�_��̫ᵲ��
	{
		if (child<last && list[child]<list[child + 1]) child++;
		//�Nchild���V��Ĥl�����j��
		if (temp >= list[child]) break; //temp������X�j�h�����վ�
		else                             //�_�h�Ĥl�����j�̤W��
		{
			list[current] = list[child];
			current = child;
			child = 2 * child + 1;
		}
	}
	list[current] = temp;               //temp���Ȧs�������X�A��m
}

void HeapSort::swap(int i, int j)
{
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}


void HeapSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
