#pragma once
#ifndef LINKSTACK_H  
#define LINKSTACK_H  

#include <iostream>  
#include <assert.h>  
using namespace std;

template <class T>
class LinkStackNode {

public:
	T data;
	LinkStackNode<T>* link;
	LinkStackNode(T& value) :link(NULL), data(value) {}
};

template <class T>
class LinkStack {

	LinkStackNode<T>* tos;

public:
	LinkStack() :tos(NULL) {}
	void Push(T& value);
	T& GetTop();
	T Pop();
	bool IsEmpty();
	void MakeEmpty();
};

template<class T>
void LinkStack<T>::Push(T& value) {
	LinkStackNode<T>* add = new LinkStackNode<T>(value);
	add->link = tos;
	tos = add;
}

template<class T>
T& LinkStack<T>::GetTop() {
	return tos->data;
}

template<class T>
T LinkStack<T>::Pop() {

	assert(tos != NULL);
	LinkStackNode<T>* old = tos;
	tos = tos->link;
	T data = old->data;
	delete old;
	return data;
}

template<class T>
bool LinkStack<T>::IsEmpty()
{
	return tos == NULL;
}

template<class T>
void LinkStack<T>::MakeEmpty()
{
	while (!this->IsEmpty()) {
		this->Pop();
	}
}

#endif  
