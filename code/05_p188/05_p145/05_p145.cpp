// 05_p145.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include <queue>  
#include <iostream>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	queue<int> picture;
	char a;
	float pow = 0;
	float oriSize;
	cout << "�п�J01�ǦC(�H#����)�G";
	do {
		cin >> a;
		if (a != '#')
			picture.push(a);
	} while (a != '#');

	char pic = picture.front();
	picture.pop();
	int size = picture.size() + 1;
	oriSize = size;

	cout << "�s�X��G";
	while (!picture.empty()) {
		if (pic == picture.front()) {
			pic = picture.front();
			picture.pop();
		}
		else {
			cout << size - picture.size();
			pow++;
			size = picture.size();
			pic = picture.front();
			picture.pop();
		}
	}
	cout << size << endl;
	pow++;
	cout << "���Y�v���G" << pow / oriSize << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
