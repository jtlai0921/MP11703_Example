#pragma once
#ifndef _LIST_H_  
#define _LIST_H_  

#include "ListNode.h"  

template <class T> class List {

	ListNode<T>* head;
	ListNode<T>* tail;

public:

	List();
	virtual ~List();

	bool AddTail(T value);
	bool RemoveTail();
	bool InsertAt(int index, T value);
	bool RemoveAt(int index);

	T& GetAt(int index);
	bool IsEmpty();
	int GetCount();
	void RemoveAll();

	ListNode<T>* GetHead();
	ListNode<T>* GetTail();
	ListNode<T>* GetNodeAt(int index);
	ListNode<T>* GetCur();
	ListNode<T>* TowardCur();
};

template<class T>
List<T>::List()
{
	head = new ListNode<T>();
	tail = head;
	tail->SetLink(NULL);
}

template<class T>
List<T>::~List()
{
	RemoveAll();
	delete head;
}

template <class T>
bool List<T> ::AddTail(T value) {
	ListNode<T>* add = new ListNode<T>(value);
	tail->SetLink(add);			//��s�ظ`�I��[�J���A�����s���
	tail = tail->GetLink();		//���ʪ�����Цܷs����B
	tail->SetLink(NULL);
	if (tail != NULL)
		return true;
	else
		return false;
}

template <class T >
bool List< T >::InsertAt(int index, T value) {
	//�P�_���ޭȬO�_���T
	if (index > this->GetCount() - 1 || index<0) {
		cout << "A wrong position!\n";
		return false;
	}

	ListNode<T>* current = head;      //�q�Y�}�l�M��X�J�a�I

	while (index) {
		current = current->GetLink();  //�p�G�䤣��A�h�̧ǲ���cur
		--index;
	}

	ListNode<T>* add = new ListNode<T>(value);
	add->SetLink(current->GetLink());   //�N�s�ظ`�I��[�J�s����C
	current->SetLink(add);

	if (current->GetLink() != NULL)
		return true;
	else
		return false;
}

template <class T>
bool List<T>::RemoveTail() {//�R������`�I
							//�z�LRemoveAt�]int index�^����
	return RemoveAt(this->GetCount() - 1);
}

template <class T>
bool List<T>::RemoveAt(int index) { //�̷ӯ��ޭȧR���`�I
	if (index > this->GetCount() - 1 || index<0) {
		cout << "A wrong position!\n";
		return false;
	}

	//�Ψ�Ӹ`�I���Ш�@�����R���C�䤤�Acur���V�n�R���`�I���e�@�Ӹ`�I
	//preCur���V�n�R�����`�I
	ListNode<T>* cur, *curPre;
	cur = head;                 //�q����Y�}�l�M��index���쪺�`�I
	curPre = cur->GetLink();    //�mpreCur��cur��  

	while (index) {
		cur = cur->GetLink();   //�p�G�S���A�hcur �PpreCur�~��Ჾ 
		curPre = curPre->GetLink();
		--index;
	}

	//�p�G�n�R�����`�I��������A�h��cur �]���s�����
	if (tail == curPre)
		tail = cur;
	cur->SetLink(curPre->GetLink());  //�N�Q�R���`�I�q�������
	delete curPre;

	if (curPre != NULL)
		return true;
	else
		return false;
}

template <class T>
T&  List<T>::GetAt(int index) {    //��^���ޭȸ`�I����value
	if (index > this->GetCount() - 1 || index<0) {
		cout << "A wrong position!\n";
	}

	ListNode<T>* cur;
	cur = head->GetLink();
	while (index) {            //�p�G�S���Acur�̧ǫᲾ
		cur = cur->GetLink();
		--index;
	}
	return cur->GetData(); //��^�`�I����value
}

template <class T>
bool List< T >::IsEmpty() { //�P�Ũ��
	return head->GetLink() == NULL;
}

template <class T>
int List< T >::GetCount() {     //��^����`�I���Ӽơ]���Y�`�I���~�^  
	int count = 0;              //��count�O���`�I�Ӽ�
								//��l�ƫ��Ы���Ĥ@�Ӹ`�I�]���O���Y�`�I�^  
	ListNode<T>* current = head->GetLink();
	while (current != NULL) {
		++count;
		current = current->GetLink();  //�̧ǲ���cur
	}
	return count;
}

template <class T>
void List< T >::RemoveAll() { //�R���Ҧ��`�I
	ListNode<T>* cur;
	//����Y�`�I���٦���L�`�I�ɡA�R���o�Ǹ`�I  
	while (head->GetLink() != NULL) {
		cur = head->GetLink();
		head->SetLink(cur->GetLink());
		delete cur;
	}
	tail = head; //�N����]�����Y�B 
}

template <class T>
ListNode<T>* List<T>::GetHead() {//��^�Y���� 
	return head;
}

template <class T>
ListNode<T>* List<T>::GetTail() {//��^������  
	return tail;
}

//��^���V���ޭȬ�index���`�I������
template <class T >
ListNode< T >* List< T >::GetNodeAt(int index) {

	//�P�_���ޭȬO�_���T
	if (index > this->GetCount() - 1 || index<0) {
		cout << "A wrong position!\n";
	}
	//handle �Y���ҨD���СA�����V���ޭȬOindex���`�I 
	ListNode< T >* handle = head->GetLink();
	while (index) { //�M����ޭȬ�index���`�I
		handle = handle->GetLink();
		--index;
	}
	return handle;
}

template <class T>
ListNode<T>* List<T>::GetCur() {
	return cur;
}

template <class T>
ListNode<T>* List<T>::TowardCur() {
	cur = cur->GetLink();
	return cur
}

#endif  
