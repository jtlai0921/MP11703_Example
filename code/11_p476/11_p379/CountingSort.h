#pragma once
#ifndef COUNTINGSORT_H  
#define COUNTINGSORT_H  

#include <vector>  
using namespace std;

class CountingSort
{
private:
	int len;
	int max;
	vector<int> list;
	vector<int> result;		//�O�s���G  
public:
	CountingSort(vector<int> _list, int _len, int _max);
	void counting_sort();
	void out();
};

#endif  
