// 02_p34.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  

using namespace std;

void fun(int* p)
{
	cout << "*p = " << *p << endl;
	(*p)++;
	cout << "*p = " << *p << endl;
}

int main(int argc, char** argv) {
	int x = 0;
	cout << "x = " << x << endl;
	fun(&x);
	cout << "x = " << x << endl << endl;

	system("PAUSE");
	return 0;
}
