// 04_p108.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include "CirList.h"  
#include <iostream>  
//#include "vld.h"  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CirList<int> poker;
	for (int i = 0; i<13; i++) {
		poker.AddTail(0);           //�إߴ`����C�A�x�s13�i���J�P 
	}
	cout << poker.GetCount() << endl;

	poker.SetBegin();
	poker.GetCur()->GetLink()->SetData(1);
	for (int i = 2; i<14; i++) {
		for (int j = 0; j<i; j++) {
			poker.GetNext();                //�M�䴡�P��m
			if (poker.GetCur()->GetData() != 0) {
				j--;            //�Y�ثe��m���w���P�A�h�̧ǧ�M�U�@�Ӧ�m 
			}
		}
		poker.GetCur()->SetData(i);
	}

	poker.SetBegin();
	for (int i = 0; i<13; i++) {
		cout << poker.GetNext() << "*";
	}
	cout << endl << endl;

	system("PAUSE");
	return 0;
}
