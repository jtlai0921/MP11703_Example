// 05_p154.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  
#include <cstdlib>  
#include <queue>  

using namespace std;

bool existOrNot(int num, queue<int> myQueue)
{
	while (!myQueue.empty())
	{
		if (myQueue.front() == num)
			return true;
		else myQueue.pop();
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	queue<int> memQueue;

	int page[] = { 4, 3, 2, 1, 4, 3, 5, 4, 3, 2, 1, 5 };
	int times = 12;
	int tmpValue;

	for (int i = 0; i < 12; i++)
	{
		if (memQueue.size()<3)
			memQueue.push(page[i]);
		else
		{

			if (existOrNot(page[i], memQueue))
			{
				times--;
			}
			else
			{
				memQueue.pop();
				memQueue.push(page[i]);
			}
		}

		int size = memQueue.size();
		while (size>0)
		{
			cout << memQueue.front() << " ";
			tmpValue = memQueue.front();
			memQueue.pop();
			memQueue.push(tmpValue);
			size--;
		}

		cout << endl;
	}

	cout << "�ĥ�FIFO�����ɡA�@�o�ͯʭ����_" << times << "���I" << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
