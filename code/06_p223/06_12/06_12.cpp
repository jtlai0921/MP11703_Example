// 06_12.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

//�L�l���ƥ�
#define numOfDisks 10

//�b��r��out.txt����X���G
ofstream fout("out.txt");

void Move(int n, char x, char y)
{
	fout << "move " << n << " from " << x << " to " << y << endl;
}

//���j�D��
void Hannoi(int n, char a, char b, char c)
{
	if (n == 1)
		Move(1, a, c);
	else
	{
		Hannoi(n - 1, a, c, b);
		Move(n, a, c);
		Hannoi(n - 1, b, a, c);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	fout << "The solution for Hanoi, when the number of disks is " <<
		numOfDisks << endl;
	Hannoi(numOfDisks, 'a', 'b', 'c');
	fout.close();
	cout << "The End! Please Check out.txt." << endl << endl;
	system("pause");
	return 0;
}
