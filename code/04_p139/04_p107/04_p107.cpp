// 04_p107.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include "CirList.h"  
#include <iostream>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CirList<int> jos; //�s�س�V�`����C�A��������Ұ��D

					  //�V��C�[�J1~15�A�N��s����1~15���H
	for (int i = 1; i<16; i++) {
		jos.AddTail(i);
	}

	jos.SetBegin();//�}�l��������Ұ��D

				   //�O����l��C���H�ơA�N���H�ƴ�@�Y�i�o��n�R�h�h�֤H  
				   //���ҭn�R��14�H
	int length = jos.GetCount();
	for (int i = 1; i<length; i++)
	{
		for (int j = 0; j<3; j++)
			jos.GetNext();
		jos.RemoveThis();
	}

	cout << jos.GetNext() << endl << endl;

	system("PAUSE");
	return 0;
}
