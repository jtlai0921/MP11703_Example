#pragma once
#ifndef LISTSET_H  
#define LISTSET_H  

#include <iostream>  

using namespace std;

template <class T> class ListSet;

template <class T>
class ListSetNode
{
	friend class ListSet<T>;
	T data;
	ListSetNode<T>* link;
public:
	ListSetNode() :link(NULL) {}
	ListSetNode(T value) :link(NULL), data(value) {}
};

template <class T>
class ListSet
{
	ListSetNode<T>* head;
	ListSetNode<T>* tail;

public:
	ListSet();
	~ListSet();
	ListSet(ListSet & lset);

	void Add(T add);
	void Del(T del);
	bool IsEmpty();
	void MakeEmpty();
	ListSet<T>& operator+(ListSet<T>& another);
	ListSet<T>& operator-(ListSet<T>& another);
	ListSet<T>& operator*(ListSet<T>& another);
	ListSet<T>& operator=(ListSet<T>& another);
	bool operator==(ListSet<T>& another);
	void Output();
	ListSetNode<T>* GetHead() { return head; }
};

template <class T>
ListSet<T>::ListSet()
{
	this->head = new ListSetNode<T>();
	this->tail = this->head;
}

template <class T>
ListSet<T>::~ListSet()
{
	MakeEmpty();
	delete head;
}

template <class T>
void ListSet<T>::Add(T value)
{
	ListSetNode<T>* add = new ListSetNode<T>(value);
	ListSetNode<T>* preCurrent = head;					//�O���ثe�`�I
	ListSetNode<T>* current = preCurrent->link;			//�O���ثe�`�I���e�@�`�I
	while (current != NULL && current->data < value)    //��M���J��m
	{
		preCurrent = current;
		current = preCurrent->link;
	}
	if (head == tail && current == NULL)                //��Ŧ�C���J�`�I
	{
		head->link = add;
		tail = add;
	}
	if (head != tail && current == NULL)                //���C�����J��add
	{
		preCurrent->link = add;
		add->link = NULL;
		tail = add;
	}
	if (current != NULL && current->data == value)      //��C���w�s�b��add
	{
		return;
	}
	if (current != NULL && current->data > value)
	{
		preCurrent->link = add;
		add->link = current;
	}
}

template <class T>
void ListSet<T>::Del(T del)
{
	ListSetNode<T>* preCurrent = head;
	ListSetNode<T>* current = preCurrent->link;
	while (current != NULL && current->data != del)			//�M��R���`�I
	{
		preCurrent = current;
		current = preCurrent->link;
	}
	if (current != NULL)
	{
		preCurrent->link = current->link;
		if (current->link == NULL) { tail = preCurrent; }	//��s��C������
		delete current;
	}
}

template <class T>
bool ListSet<T>::IsEmpty()
{
	return head == tail;                         //�P�_���X�O�_����
}

template <class T>
void ListSet<T>::MakeEmpty()
{
	ListSetNode<T>* current = head->link;
	ListSetNode<T>* del = NULL;
	while (head->link != NULL)                  //�`���R�����X��������
	{
		head->link = current->link;
		del = current;
		current = current->link;
		delete del;                             //�I�sdelete����ثe�`�I
	}
	tail = head;
}

template <class T>
ListSet<T>& ListSet<T>::operator=(ListSet<T>& another)
{
	MakeEmpty();
	ListSetNode<T>* current = another.head->link;
	while (current != NULL)
	{
		Add(current->data);
		current = current->link;
	}
	return *this;
}

template <class T>
ListSet<T>::ListSet(ListSet<T>& lset)
{
	this->head = new ListSetNode<T>();
	this->tail = this->head;

	ListSetNode<T>* current = lset.head->link;
	while (current != NULL)
	{
		Add(current->data);
		current = current->link;
	}

}

template <class T>
ListSet<T>& ListSet<T>::operator+(ListSet<T>& another)
{
	ListSet<T>* tmpSet = new ListSet(another);
	ListSetNode<T>* current = this->head->link;
	while (current != NULL)
	{
		tmpSet->Add(current->data);
		current = current->link;
	}

	return *tmpSet;                         //��^�ثe���X���ѷ�
}

template <class T>
ListSet<T>& ListSet<T>::operator-(ListSet<T>& another)
{
	ListSet<T>* tmpSet = new ListSet(*this);
	ListSetNode<T>* current = another.head->link;
	while (current != NULL)
	{
		tmpSet->Del(current->data);
		current = current->link;
	}
	return *tmpSet;
}

template <class T>
ListSet<T>& ListSet<T>::operator*(ListSet<T>& another)
{
	ListSet<T>* tmpSet = new ListSet(*this);
	*tmpSet = *this - another;
	*tmpSet = *this - *tmpSet;
	return *tmpSet;
}

template <class T>
bool ListSet<T>::operator==(ListSet<T>& another)
{
	ListSetNode<T>* current1 = head->link;
	ListSetNode<T>* current2 = another.head->link;
	while (current1 != NULL)
	{
		if (current2 == NULL) { return false; }
		if (current1->data != current2->data) { return false; }
		current1 = current1->link;
		current2 = current2->link;
	}
	if (current2 != NULL) { return false; }
	return true;
}

template <class T>
void ListSet<T>::Output()
{
	ListSetNode<T>* current = this->GetHead()->link;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->link;
	}
	cout << endl;
}

#endif  
