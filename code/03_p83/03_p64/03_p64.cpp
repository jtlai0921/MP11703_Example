// 03_p64.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  
#include <iomanip>  
#include <string>  

using namespace std;

int main(int argc, char** argv) {

	string  str = "���w�� ���� �p�����Ǯa �p����{���]�p���N";
	string  str_temp = "";
	str_temp.assign(str);

	string result[4] = { "","","","" };

	int position = 0;

	for (int i = 0; i < 3; i++)
	{
		position = str_temp.find(" ");
		result[i] = str_temp.substr(0, position);
		str_temp = str_temp.substr(position + 1, str_temp.length() - position);
	}

	result[3] = str_temp;

	cout << "�m�W�G" << setw(8) << result[0] << endl;
	cout << "���y�G" << setw(6) << result[1] << endl;
	cout << "¾�~�G" << setw(14) << result[2] << endl;
	cout << "�N��@�G" << setw(18) << result[3] << endl;

	str_temp.swap(result[0]);

	for (int j = 1; j < 4; j++)
	{
		str_temp += " ";
		str_temp.append(result[j]);
	}

	int equal = str.compare(str_temp);

	cout << endl;
	if (equal == 0)
		cout << "�t�令�\�I" << endl;
	else
		cout << "�t�藍���\�I" << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
