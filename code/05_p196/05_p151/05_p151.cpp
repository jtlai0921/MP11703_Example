// 05_p151.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  
#include <cstdlib>  
#include <stack>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	stack<int> myStack;

	//�m�J�P�u�X���|
	myStack.push(5);
	myStack.push(6);
	myStack.push(7);
	myStack.pop();

	cout << myStack.top() << endl;
	cout << myStack.size() << endl;
	cout << myStack.empty() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
