// 02_p49.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include <iostream>  
#include <iomanip>  

using namespace std;

#define SIZE 8  

int main(int argc, char** argv) {
	int matrix[SIZE][SIZE] = { 0 };
	int a[SIZE][SIZE] = { 0 };

	int i, j, x, y, value = 0;

	int * p;
	p = &matrix[0][0];
	//��l�Ưx�}  
	for (i = 0; i<SIZE * SIZE; i++)
		*p++ = i;

	//�L�X��l�x�}  
	cout << "��l�x�}�p�U�G" << endl;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			cout << setw(4) << *(*(matrix + i) + j);
		cout << endl;
	}

	i = 0; j = 0;
	//�i��Z�r�s��
	for (x = 0; x < SIZE; x++)
		for (y = 0; y < SIZE; y++)
		{
			*(*(a + i) + j) = *(*(matrix + x) + y);

			if ((i == SIZE - 1 || i == 0) && j % 2 == 0)
			{
				j++;
				continue;
			}

			if ((j == 0 || j == SIZE - 1) && i % 2 == 1)
			{
				i++;
				continue;
			}

			if ((i + j) % 2 == 0)
			{
				i--;
				j++;
			}
			else if ((i + j) % 2 == 1)
			{
				i++;
				j--;
			}
		}

	cout << endl << "�g�LZ�r�s�ƫ᪺�x�}�p�U�G" << endl;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			cout << setw(4) << *(*(a + i) + j);
		cout << endl;
	}

	cout << endl;
	system("PAUSE");
	return 0;
}
