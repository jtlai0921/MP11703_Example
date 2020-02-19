// 02_p52.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  
#include <iomanip>  
#include <memory.h>  

using namespace std;

int main()
{
	cout << "�п�J�ۤ誺�j�p n (n�O�@�Ӥj��1���_��)�G";
	int n = 1;
	cin >> n;
	cout << endl;
	int **a = new int*[n];
	for (int i = 0; i<n; ++i) {
		a[i] = new int[n];
		memset(a[i], 0, n * sizeof(int));
	}

	int row = 0;
	int col = n / 2;

	for (int i = 1; i <= n*n; i++) {
		a[row][col] = i;
		row--;
		col++;

		if (row<0 && col >= n)
		{
			col--;
			row += 2;
		}
		else if (row<0)
		{
			row = n - 1;
		}
		else if (col >= n)
		{
			col = 0;
		}
		else if (a[row][col] != 0)
		{
			col--;
			row += 2;
		}
	}

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cout << setw(6) << a[i][j];
		}
		cout << endl;
	}

	for (int i = n; i > 0;)
		delete[] a[--i];
	delete[] a;

	cout << endl << endl;
	system("PAUSE");
	return 0;
}
