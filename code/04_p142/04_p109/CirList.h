#pragma once
//#ifndef _CIRLIST_H_  
//#define _CIRLIST_H_  

#include "ListNode.h"  

template <class T > class CirList {

	ListNode<T>* head;
	ListNode<T>* tail;
	ListNode<T>* cur;

public:
	CirList();
	~CirList();

	bool AddTail(T value);
	void RemoveThis();
	void RemoveAll();
	void SetBegin();
	int GetCount();
	ListNode<T>* GetCur();

	bool IsEmpty();
	T GetNext();
};

template <class T >
CirList<T>::CirList() {//�w�]���غc���  
	head = tail = new ListNode<T>; //�s�ظ`�I�A�ê�l��head�Ptail
	cur = head;
	head->SetLink(head);
}

template <class T>
CirList<T>::~CirList() {
	RemoveAll();
	delete head;
}

template <class T>
bool CirList< T >::AddTail(T value) { //�b��C���ݴ��J�s�`�I
									  //�s�ظ`�I�A�x�s���value
	ListNode<T>* add = new ListNode<T>(value);

	tail->SetLink(add);          //��s�`�I�]�J��C
	tail = tail->GetLink();      //����tail�ܷs��C���B
	tail->SetLink(head);     //�N��C�����Ы��V��C�Y

	if (tail != NULL)
		return true;
	else
		return false;
}

template <class T>
void CirList<T>::RemoveThis() {//�R��cur���쪺�`�I  
	if (cur == head) {
		//�p�G�ثecur�bhead�B�A�ѩ��C�Y�`�I���i�R���A�̧ǲ���cur�ܤU�@�`�I�B
		cur = cur->GetLink();
	}

	//�Ϋ���preCur�аOcur���e�@�`�I�Anode_del�аO�n�R�����`�I  
	ListNode<T>* node_del = cur;
	ListNode<T>* preCur = cur;
	//�M��cur���e�@�`�I�A�å�preCur�O���U��
	for (int i = 0; i<this->GetCount(); i++) {
		preCur = preCur->GetLink();
	}

	//��cur�e�@�`�I�����Ы���cur��@�`�I�A��Y���Lcur�Ҧb���`�I  
	preCur->SetLink(cur->GetLink());
	delete node_del;
	//�R����cur�̧ǲ��ʤ@�Ӹ`�I
	cur = preCur->GetLink();
	preCur = NULL;
}

template <class T>
void CirList< T >::RemoveAll() {//�R���Ҧ��Y�I  
	SetBegin();//�}�l�q�Ĥ@�Ӹ`�I�R��
	int length = GetCount();//�����C���  
	for (int i = 0; i<length; i++) {
		RemoveThis();
	}
	cur = head;  //�Ncur�]��head�B
}

template <class T>
void CirList< T >::SetBegin() {//�Ncur�]��head�B�A��ܦ�C���}�l  
	cur = head;
}

template <class T>
int CirList<T>::GetCount() {//���o��C����
	int num = 0;
	if (cur == NULL)
		this->SetBegin();
	ListNode<T>* here = cur;  //�O���ثe�`�I��m
	while (cur->GetLink() != here) { //�M����Ӧ�C�A�O���`�I�Ӽ�  
		cur = cur->GetLink();
		++num;
	}
	//cur = cur->GetLink();//��cur�^��M���e����m
	cur = here;
	return
		num;
}

template <class T>
ListNode<T>* CirList< T >::GetCur() {//��^�ثe����cur  
	return cur;
}

template <class T >
bool CirList< T >::IsEmpty() {//�P�_��C�O�_����
	return
		head->GetLink() == head;
}

//��^�ثe�`�I������ơA�è�cur�̧ǲ��ʤ@�Ӧ�m
template <class T>
T CirList< T >::GetNext() {
	if (cur == head) {
		//���L��C�Y�`�I�A�]���Ӹ`�I�����x�s���ĸ�� 
		cur = cur->GetLink();
	}
	T num = cur->GetData();  //���o���
	cur = cur->GetLink();    //�̧ǲ���cur�ܤU�@�Ӹ`�I 
	return
		num;
}

//#endif  
