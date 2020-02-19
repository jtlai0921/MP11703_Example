// 06_03.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include "stdio.h"
#include <vector>
#include <iostream>

using namespace std;

int binarySearch(const vector<int> & a, const int & x, int low, int high)
{
	if (low>high)
		return -1;

	int mid = (low + high) / 2;
	//�G���j�M�t��k�����j�֤߳���
	if (a[mid]<x)
		return binarySearch(a, x, mid + 1, high);
	else if (x<a[mid])
		return binarySearch(a, x, low, mid - 1);
	else
		return mid;
}

int Search(const vector<int> & a, const int & x)
{
	return binarySearch(a, x, 0, a.size() - 1);
}

void main()
{
	vector<int> box;

	box.push_back(1);
	box.push_back(4);
	box.push_back(6);
	box.push_back(7);
	box.push_back(8);
	box.push_back(10);
	box.push_back(13);
	box.push_back(21);
	box.push_back(22);
	box.push_back(30);

	const int searchValue = 22;

	int result = Search(box, searchValue);

	if (result == -1)
		cout << "�n�d���Ʀr���b�}�C���I" << endl;
	else
		cout << searchValue << "����m�b��" << ++result << "��" << endl;

	cout << endl;
	system("PAUSE");

}

