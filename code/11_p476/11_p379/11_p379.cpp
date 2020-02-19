// 11_p379.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  
#include <vector>  
#include "InsertSort.h"  
#include "BinaryInsertSort.h"  
#include "ShellSort.h"  
#include "SelectSort.h"  
#include "BubbleSort.h"  
#include "HeapSort.h"  
#include "ShakerSort.h"  
#include "QuickSort.h"  
#include "MergeSort.h"  
#include "CountingSort.h"  

#define MAX 1000  

using namespace std;

int main()
{
	//Ū���L�Ǫ�-----------------------------
	vector<int> list;
	int len, inp;
	cout << "�п�J�ǦC�Ӽ�(0�h�X)�G";
	cin >> len;
	if (len == 0) exit(0);
	cout << "�п�J�ݱƧǦC�G";
	for (int i = 0; i<len; i++)
	{
		cin >> inp;
		list.push_back(inp);
	}

	//�H�U�O�Q�ر`�Χֳt�Ƨ�----------------
	//1. �������J�Ƨ�
	//2. �G�����J�Ƨ�
	//3. �ƺ��Ƨ�
	//4. ������ܱƧ�
	//5. ��Ƨ�
	//6. ��w�Ƨ�
	//7. Shaker�Ƨ�
	//8. �ֳt�Ƨ�
	//9. �X�ֱƧ�
	//10.�p�ƱƧ�
	InsertSort sort1(list, len);
	sort1.insert_sort();
	sort1.out();

	BinaryInsertSort sort2(list, len);
	sort2.binary_insert_sort();
	sort2.out();

	ShellSort sort3(list, len);
	sort3.shell_sort();
	sort3.out();

	SelectSort sort4(list, len);
	sort4.select_sort();
	sort4.out();

	HeapSort sort5(list, len);
	sort5.heap_sort();
	sort5.out();

	BubbleSort sort6(list, len);
	sort6.bubble_sort();
	sort6.out();

	ShakerSort sort7(list, len);
	sort7.shaker_sort();
	sort7.out();

	QuickSort sort8(list, len);
	sort8.quick_sort(0, len - 1);
	sort8.out();

	MergeSort sort9(list, len);
	sort9.merge_sort(1, len);
	sort9.out();

	CountingSort sort10(list, len, MAX); //MAX���ϥΪ̴��Ѫ��L�Ǫ�̤j�d��
	sort10.counting_sort();
	sort10.out();

	cout << endl << endl;
	system("PAUSE");
}
