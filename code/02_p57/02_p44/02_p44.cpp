// 02_p44.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>  

using namespace std;

int main(int argc, char* argv[]) {
	int a[3][3] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	int * p;
	p = &a[0][0];

	for (int i = 0; i<9; i++)
		cout << *p++ << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
