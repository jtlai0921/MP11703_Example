// 07_p193.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include "BinaryTreeNode.h"  
#include "BinaryTree.h"  
#include "iostream"  

using namespace std;

int main()
{

	BinaryTree<char> myBinTree('a');

	myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'D');
	myBinTree.InsertRightChild(myBinTree.GetRoot(), 'G');

	myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'B');
	myBinTree.InsertRightChild(myBinTree.GetRoot()->GetLeftChild(), 'E');

	myBinTree.InsertRightChild(myBinTree.GetRoot(), 'C');
	myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetRightChild(), 'F');


	cout << "�ӤG����O�_���šG" << myBinTree.IsEmpty() << endl;
	cout << "�ӤG���𪺮ڸ`�I���x�s����ƬO�G"
		<< myBinTree.Retrieve(myBinTree.GetRoot());
	cout << endl << "�N�G���𪺮ڸ`�I������ƫ��w�� A�I";
	myBinTree.Assign(myBinTree.GetRoot(), 'A');
	cout << "�ثe�G���𪺮ڸ`�I���x�s����ƬO�G"
		<< myBinTree.Retrieve(myBinTree.GetRoot()) << endl;

	cout << endl << "�v�h�M�������G�p�U�G" << endl;
	myBinTree.LevelOrderTraverse(myBinTree.GetRoot());

	cout << endl << endl;
	system("PAUSE");

	return 0;
}
