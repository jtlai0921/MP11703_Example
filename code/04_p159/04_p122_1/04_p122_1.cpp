// 04_p122_1.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include <iostream>  
#include <string>  
#include <cstdlib>  
#include <list>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	list<int> myList1;
	myList1.push_front(10);
	cout << myList1.size() << endl; //��C���׬� 1

	list<string> myList2(10);
	cout << myList2.size() << endl; //��C���׬� 10

	list<double> myList3(2, 4.6);   //��l�Ȭ� 4.6
	cout << myList3.back() << endl;
	myList3.pop_back();
	cout << myList3.empty() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
