// 02_p35.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include <iostream>  

using namespace std;

void fun(int& r)
{
	cout << "r = " << r << endl;
	r++;
	cout << "r = " << r << endl;
}

int main(int argc, char** argv) {
	int x = 0;
	cout << "x = " << x << endl;
	fun(x);
	cout << "x = " << x << endl << endl;

	system("PAUSE");
	return 0;
}
