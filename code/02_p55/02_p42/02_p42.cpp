// 02_p42.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  

using namespace std;

int main(int argc, char* argv[]) {

	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int * p;
	p = &a[0];

	cout << a[0] << endl;
	cout << &a[0] << endl;
	cout << &a << endl;
	cout << a << endl;
	cout << p << endl;
	cout << *p << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
