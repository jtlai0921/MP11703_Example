#pragma once
#ifndef _DOULISTNODE_H  
#define _DOULISTNODE_H  

template <class T > class DouListNode {

	T data;
	DouListNode<T>* link;
	DouListNode<T>* prior;

public:

	DouListNode() : link(NULL), prior(NULL) {}
	DouListNode(T value) : link(NULL), prior(NULL), data(value) {}
	~DouListNode() {};
	void SetLink(DouListNode<T>* next);
	void SetPrior(DouListNode<T>* pre);
	DouListNode<T>* GetLink();
	DouListNode<T>* GetPrior();
	T& GetData();
};


template <class T >
void DouListNode< T >::SetLink(DouListNode<T>* next) { //�]�wlink��
	link = next;
}

template <class T >
void DouListNode< T >::SetPrior(DouListNode<T>* pre) { //�]�wprior��
	prior = pre;
}

//��^����ثe�`�I����@�`�I������
template <class T >
DouListNode<T>* DouListNode< T >::GetLink() {
	return link;
}

//��^����ثe�`�I���e�@�`�I������
template <class T >
DouListNode<T>* DouListNode< T >::GetPrior() {
	return prior;
}

template <class T >
T& DouListNode< T >::GetData() {//��^�`�I���O�s�����
	return data;
}

#endif  
