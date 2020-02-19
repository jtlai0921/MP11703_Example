// 09_p300.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <conio.h>  
#include <iostream>  
#include "avltree.h"  

using namespace std;

int main(int argc, char** argv) {

	AvlTree<int> tree;

	tree.Insert(21);
	tree.Insert(12);
	tree.Insert(35);
	tree.Insert(0);
	tree.Insert(15);
	tree.Insert(36);
	tree.Insert(14);
	tree.Insert(7);
	tree.Insert(28);
	tree.Insert(9);

	tree.DisplayTree(tree.getRoot(), 0);

	while (true)
	{
		int number;
		cout << "�п�J�n�R�����`�I�G" << endl;
		cin >> number;
		tree.Remove(number);
		cout << "�R���᪺�𬰡G" << endl;
		tree.DisplayTree(tree.getRoot(), 0);

		cout << "��ESC�h�X�A�Ϋ����N���~��K" << endl;
		int order = getch();
		if (order == 27)
		{
			break;
		}
	}

	return 0;
}
