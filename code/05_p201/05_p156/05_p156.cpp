// 05_p156.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include "stdafx.h"  
#include <iostream>  
#include <cstdlib>  
#include <queue>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	priority_queue<int> Q;
	Q.push(1);
	Q.push(5);
	Q.push(2);
	Q.push(4);
	Q.push(6);
	Q.push(3);

	int size = Q.size();

	for (int i = 0; i< size; i++)
	{
		cout << Q.top() << endl;
		Q.pop();
	}

	cout << endl << Q.empty() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
