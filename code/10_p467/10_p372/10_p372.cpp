// 10_p372.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include<set>  
#include<iostream>  
#include<iterator>  
#include<algorithm>  

using namespace std;

int main(int argc, char** argv) {

	set<int> mySet2;
	set<int> mySet3;

	set<int>::iterator i;

	int a[] = { 1, 2, 3, 4, 5 };

	set<int> mySet1(a, a + 5);

	cout << mySet1.size() << endl;

	i = mySet1.begin();
	cout << "mySet1 : ";
	//�M����X
	while (i != mySet1.end())
	{
		cout << *i << " ";
		++i;
	}

	mySet2.insert(2);
	mySet2.insert(3);
	mySet2.insert(5);
	mySet2.insert(7);

	cout << endl;

	i = mySet2.begin();
	cout << "mySet2 : ";
	//�M����X
	while (i != mySet2.end())
	{
		cout << *i << " ";
		++i;
	}

	cout << endl;

	if (mySet2.find(5) != mySet2.end()) {
		cout << "mySet2 contains 5" << endl;
	}

	ostream_iterator<int> out(cout, " ");
	//�D���XmySet1�PmySet2���涰
	cout << "\nmySet1�PmySet2���涰�G";
	set_intersection(mySet1.begin(), mySet1.end(),
		mySet2.begin(), mySet2.end(), out);
	//�D���XmySet1�PmySet2���p��
	cout << "\nmySet1�PmySet2���p���G";
	set_union(mySet1.begin(), mySet1.end(),
		mySet2.begin(), mySet2.end(), out);
	//�D���XmySet1�PmySet2���t��
	cout << "\nmySet1�PmySet2���t���G";
	set_difference(mySet1.begin(), mySet1.end(),
		mySet2.begin(), mySet2.end(), out);
	//�D���XmySet1�PmySet2����ٮt
	set_symmetric_difference(mySet1.begin(), mySet1.end(),
		mySet2.begin(), mySet2.end(),
		inserter(mySet3, mySet3.begin()));

	cout << "\nmySet1�PmySet2����ٮt�G";
	i = mySet3.begin();
	while (i != mySet3.end())
	{
		cout << *i << " ";
		++i;
	}

	cout << endl << endl;
	system("PAUSE");
	return 0;
}
