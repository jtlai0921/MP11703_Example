// 08_p261.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#pragma warning (disable:4786)  
#pragma warning (disable:4503)  

#include "stdafx.h"
#include <iostream>  
#include <fstream>  
#include <string>  
#include <list>  
#include <map>  
#include <queue>  

#include "City.h"  
#include "Road.h"  
#include "RoadSystem.h"  

using namespace std;

int main() {

	try {

		RoadSystem rs("MapInformation.txt");

		while (true) {

			cerr << endl << "�п�J�_�I�����M���I�����G(�h�X�п�J'quit')" << endl;

			string from, to;
			cin >> from;
			if (from == "quit") break;
			cin >> to;

			if (rs.is_valid_city(from) && rs.is_valid_city(to)) {
				rs.output_cheapest_route(from, to, cout);
			}
			else {
				cout << "�L�������A�нT�{�᭫�աI" << endl << endl;
			}

		}

		return EXIT_SUCCESS;

	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "�{���X�{���`�A�аh�X�{���᭫�աC" << endl;
	}

	return EXIT_FAILURE;
}
