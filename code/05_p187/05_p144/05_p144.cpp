// 05_p144.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include "LinkQueue.h"  
#include <iostream>  

using namespace std;

template<class T>
void evaluate(LinkQueue<T>& ori, LinkQueue<T>& target) {
	ori.MakeEmpty();
	while (!target.IsEmpty()) {
		int tmp_value = target.DelQueue();
		ori.EnQueue(tmp_value);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "�п�J�����T��������i (i>2)�G";
	int num;
	cin >> num;
	LinkQueue<int> ori;

	int ini_value = 1;
	ori.EnQueue(ini_value);
	ori.EnQueue(ini_value);
	LinkQueue<int> next;
	for (int i = 0; i<num - 2; i++) {
		next.EnQueue(ini_value);
		while (!ori.IsEmpty()) {
			int i = ori.DelQueue();
			if (!ori.IsEmpty())
			{
				int tmp = i + ori.GetFront();
				next.EnQueue(tmp);
			}
			if (ori.IsEmpty())
				next.EnQueue(i);
		}
		evaluate(ori, next);
	}
	cout << "�����T����" << num << "�C�����e�p�U�G" << endl;
	while (!ori.IsEmpty()) {
		cout << ori.DelQueue() << " ";
	}
	cout << endl << endl;

	system("PAUSE");
	return 0;
}
