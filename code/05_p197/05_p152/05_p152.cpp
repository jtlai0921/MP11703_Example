// 05_p152.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  
#include <fstream>  
#include <string>  
#include <cstdlib>  
#include <stack>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	ifstream inf;
	inf.open("temp.txt");

	if (!inf) {
		cerr << "cannot open file for input!" << endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}

	stack<string> s;
	string line;

	while (getline(inf, line)) {
		s.push(line);
	}

	inf.close();

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;
	system("PAUSE");
	return 0;
}
