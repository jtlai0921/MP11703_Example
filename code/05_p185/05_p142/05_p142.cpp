// 05_p142.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include "LinkQueue.h"  
#include <string>  
#include <iostream>  

using namespace std;

struct dancer {
	string name;
	char sex;
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "�п�J�R���`�ơG";
	int num;
	cin >> num;
	LinkQueue<dancer> Mdancer;
	LinkQueue<dancer> Fdancer;
	for (int i = 0; i<num; i++) {
		cout << "�п�J�R�̩ʧO(f or m)�Ωm�W�G";
		char sex;
		cin >> sex;
		string name;
		cin >> name;
		dancer newdancer;
		newdancer.name = name;
		newdancer.sex = sex;
		if (sex == 'f')
			Fdancer.EnQueue(newdancer);
		if (sex == 'm')
			Mdancer.EnQueue(newdancer);
	}

	while (!Mdancer.IsEmpty() && !Fdancer.IsEmpty()) {
		cout << Mdancer.DelQueue().name << "\t<---->\t" << Fdancer.DelQueue().name << endl;
	}

	if (!Mdancer.IsEmpty()) {
		cout << "Mr. " << Mdancer.GetFront().name << " is waiting!" << endl;
	}
	else if (!Fdancer.IsEmpty()) {
		cout << "Ms. " << Fdancer.GetFront().name << " is waiting!" << endl;
	}
	else
		cout << "OK!" << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
