// 10_p336.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  
#include "Dictionary.h"  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Dictionary dic;

	dic.Add("box", "���l");
	dic.Add("apple", "ī�G");
	dic.Add("tree", "��");
	dic.Add("good", "�n��");
	dic.Add("swim", "��a");
	dic.Add("interesting", "���쪺");

	cout << dic.Search("good").c_str() << endl;
	cout << dic.Search("interesting").c_str() << endl;

	dic.Del("box");
	dic.Del("interesting");

	cout << dic.Search("box").c_str() << endl;
	cout << dic.Search("interesting").c_str() << endl;
	cout << dic.Search("apple").c_str() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
