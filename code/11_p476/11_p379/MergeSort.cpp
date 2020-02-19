#include "stdafx.h"
#include "MergeSort.h"
#include <iostream>

using namespace std;

MergeSort::MergeSort(vector<int> _list, int _len)
{
	list.push_back(0);
	link.push_back(0);
	for (int i = 0; i<_len; i++) {
		list.push_back(_list[i]);
		link.push_back(0);
	}
	this->len = _len;
}

//9 �X�ֱƧǡG���j-----------------------------------------------------------
//�����k�G�Hmerger_link[]���Ѧ�C�\��Cmerger_link[i]�����즳�Ǥl�ǦC��
//merger_list[i]��@�Ӹ`�I�b��merger_list[]�����мСF
//merger_link[0]�`�O��ܦ��Ǥl�ǦC�}�l���`�I�bmerge_list[]�����U�СF
//st1,st2����Ӧ��ǧǦC���Ĥ@�Ӹ`�I�F
//�N��X�֫�A�ê�^�Ĥ@�Ӹ`�I���U�СA��Ymerger_link[0]

int MergeSort::list_merge(int st1, int st2)
{
	int k = 0, i = st1, j = st2;
	while (i && j)                  //���˴�����ǦC��
		if (list[i] <= list[j])		//�Nmerge_list[i]�Mmerge_list[j]��
		{                           //�p���s����merger_link[k]��
			link[k] = i;
			k = i;
			i = link[i];
		}
		else
		{
			link[k] = j;
			k = j;
			j = link[j];
		}
	if (!i) link[k] = j;            //�N�Ѿl���˴�����merge_list[]
	else link[k] = i;               //�s����merger_link[k]��
	return link[0];
}

int MergeSort::merge_sort(int left, int right)
{
	if (left >= right) return left;
	int middle = (left + right) / 2;
	//�索�k��l�ǦC�i��X��
	return list_merge(merge_sort(left, middle), merge_sort(middle + 1, right));
}

void MergeSort::out()
{
	int i = link[0];
	int j = 0;
	while (i)
	{
		j++;
		cout << list[i] << " ";
		i = link[i];
		if (j % 18 == 0) cout << endl;
	}
	cout << endl;
}
