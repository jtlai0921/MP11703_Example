// 04_p94.cpp : �w�q�D���x���ε{�����i�J�I�C
//
#include "stdafx.h"  
#include "List.h"  
#include <iostream>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	List<int> list;
	for (int i = 0; i <9; i++)
		list.AddTail(i);

	cout << list.GetCount() << endl;

	cout << list.GetAt(3) << endl;

	list.RemoveAt(3);

	cout << list.GetCount() << endl;
	cout << list.GetAt(3) << endl;

	list.RemoveAll();
	cout << list.GetCount() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
