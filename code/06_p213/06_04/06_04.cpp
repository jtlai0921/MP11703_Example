// 06_04.cpp : �w�q�D���x���ε{�����i�J�I�C
//
#include "stdafx.h"

#include "stdio.h"
#include <conio.h>
#include <iostream>

using namespace std;

void recursiveFunction1(int num)
{
	if (num < 5)
	{
		printf("%d \n", num);
		recursiveFunction1(num + 1);
	}
}

void recursiveFunction2(int num)
{
	if (num < 5)
	{
		recursiveFunction2(num + 1);
		printf("%d \n", num);
	}
}

void main()
{
	recursiveFunction1(0);
	recursiveFunction2(0);

	cout << endl;
	system("PAUSE");

}
