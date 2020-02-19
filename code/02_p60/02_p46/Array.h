#pragma once
#ifndef ARRAY_H  
#define ARRAY_H  

#include <iostream>  

using namespace std;

const int DefaultSize = 20;

template <class Type>
class Array
{
	Type *elements;         //�}�C�s��Ŷ�
	int ArraySize;          //�ثe����
public:
	Array(int Size = DefaultSize);                  //�غc���
	Array(const Array<Type>& x);                    //�ƻs�غc��� 
	~Array() { delete[]elements; }                  //�غc���
	Array<Type> & operator = (const Array<Type> & rhs);     //�ƻs�}�C  
	Type& operator [] (int i);						//��������  
	int Length() const { return ArraySize; }        //���}�C����  
	void ReSize(int sz);							//�X�R�}�C
};

template <class Type>
Array<Type>& Array<Type >::operator= (const Array<Type >& rhs)
{
	int n = rhs.ArraySize;			// ��rhs���}�C�j�p
	if (ArraySize != n)
	{
		delete[] elements;			// �R���}�C�즳�O����  
		elements = new Type[n];     // ���s���tn�Ӥ������O���� 
		if (elements == NULL)       // �p�G���t�O���餣���\�A�h��X���~�T�� 
		{
			ArraySize = 0;
			cerr << "�O������t���~�I" << endl;
			exit(1);
		}
		ArraySize = n;          //�O�������Y���}�C�j�p  
	}
	// �qrhs�V������ƨ��
	Type* destptr = elements;
	Type* srcptr = rhs.elements;
	while (n--)
		*destptr++ = *srcptr++;
	return *this; // ��^�ثe���󪺰ѷ�  
}

template <class Type>
Array<Type> ::Array(int sz)
{
	if (sz <= 0) {
		ArraySize = 0;
		cerr << "�D�k�}�C�j�p" << endl;
		return;
	}
	elements = new Type[sz];
	if (elements == NULL) {
		ArraySize = 0;
		cerr << "�O������t���~�I" << endl;
		exit(1);
	}
	ArraySize = sz;
}


template <class Type>
Array<Type> ::Array(const Array<Type> & x)
{
	int n = x.ArraySize;
	ArraySize = n;
	elements = new Type[n];
	if (elements == NULL) {
		ArraySize = 0;
		cerr << "�O������t���~�I" << endl;
		exit(1);
	}
	Type *srcptr = x.elements;
	Type *destptr = elements;
	while (n--) * destptr++ = *srcptr++;
}

template <class Type>
Type& Array<Type> :: operator [] (int i) {
	if (i < 0 || i > ArraySize - 1) {
		cerr << "�W�X�}�C�U�СI" << endl;
		exit(1);
	}
	return elements[i];
}

template <class Type>
void Array<Type> ::ReSize(int sz) {
	if (sz >= 0 && sz != ArraySize) {
		Type * newarray = new Type[sz];         //�إ߷s�}�C  
		if (newarray == NULL) {
			cerr << "�O������t���~�I" << endl;
			return;
		}
		int n = (sz <= ArraySize) ? sz : ArraySize;  //���ӷs���j�p�T�w�ǰe�����Ӽ�  
		Type *srcptr = elements;            //�ӷ��}�C����
		Type *destptr = newarray;           //�ت��}�C����   
		while (n--) * destptr++ = *srcptr++;
		delete[] elements;
		elements = newarray;
		ArraySize = sz;
	}
}

#endif  
