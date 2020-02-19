// 06_17.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include <conio.h>
#include <iostream>

using namespace std;
//�����n�D�ӦZ���Ĭ�A����C�C�u�঳�@�ӬӦZ
//�Hqueens[]�}�C�x�s�C�ӬӦZ����m
//�Ҧp�Gqueens[m] = n�A��ܲ�m�C���ӦZ��b��n��W

#define MAX 8

int sum = 0;
class QueenPuzzle
{
	int queens[MAX]; //�x�s�C�C�ӦZ����s��

public:
	void printOut(); //�L�X���G
	int IsValid(int n); //�P�_��W��n�ӬӦZ����O�_�X�k
	void placeQueen(int i); //���j�B��A�\��ӦZ
};

void QueenPuzzle::printOut()
{
	for (int i = 0; i<MAX; i++)
	{
		for (int j = 0; j<MAX; j++)
		{
			if (j == queens[i])
				cout << "Q ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
	cout << endl << "��q��h�X�A����L���~��" << endl << endl;

	if (getch() == 'q')
		exit(0);
}

//�b��i�C�\��ӦZ
void QueenPuzzle::placeQueen(int i)
{
	for (int j = 0; j<MAX; j++)
	{
		//�p�G�����񧹡A�h��X���G
		if (i == MAX)
		{
			sum++;
			cout << "��" << sum << "�ոѡG" << endl;
			printOut();

			return;
		}

		//�\��ӦZ
		queens[i] = j;

		//����m�����\��ӦZ�A�~����դU�@��m
		if (IsValid(i))
			placeQueen(i + 1);
	}
}

//�P�_��W��n�ӬӦZ����O�_�X�k�A��Y�O�_�L�Ĭ�
int QueenPuzzle::IsValid(int n)
{
	//�N��n�ӬӦZ����m�̧ǻP�e��n-1�ӬӦZ����m���
	for (int i = 0; i < n; i++)
	{
		//��ӬӦZ�b�P�@��A��^0
		if (queens[i] == queens[n])
			return 0;

		//��ӬӦZ�b�P�@�﨤�u�W�A��^0
		if (abs(queens[i] - queens[n]) == (n - i))
			return 0;
	}

	//�S���Ĭ�A��^1
	return 1;
}

void main()
{
	QueenPuzzle queen;
	queen.placeQueen(0);
	cout << "�@" << sum << "�ո�" << endl;
}
