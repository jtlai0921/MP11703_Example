// 04_p109.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include "CirList.h"  
#include <iostream>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	cout << "�п�J�ԤB�趥��(2 <= N <= 9):";
	cin >> num;
	CirList<int> latin;
	for (int i = 1; i <= num; i++) {
		latin.AddTail(i);               //�إߴ`����C  
	}

	latin.SetBegin();
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			cout << latin.GetNext() << " ";     //��X�`����C�������
		}
		cout << endl;
		latin.GetNext();                //�̧ǲ��ʴ`����C�����Ҧ����
	}

	cout << endl;
	system("PAUSE");
	return 0;
}
