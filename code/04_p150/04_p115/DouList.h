#pragma once
#ifndef _DOULIST_H  
#define _DOULIST_H  

#include "DouListNode.h"  

template <class T> class DouList {
	DouListNode<T>* head;
	DouListNode<T>* tail;
	DouListNode<T>* cur;

public:
	DouList();
	~DouList();

	bool AddTail(T value);
	bool AddHead(T value);
	void RemoveThis(bool direction);
	void RemoveAll();
	void SetBegin();
	int GetCount();
	void TowardCur();
	void BackCur();
	DouListNode<T>* GetCur();
	DouListNode<T>* GetHead();
	DouListNode<T>* GetTail();
	void InsertAfter(T value);

	bool IsEmpty();
	T GetNext();
	T GetPrior();
};


template <class T>
DouList<T>::DouList() {//�w�]���غc���

					   //�إߦ�C�Y�I�Y�A�ê�l��head���лPtail����   
	head = tail = new DouListNode<T>;
	cur = head;
	head->SetLink(head); //�إߪ�l�j��
	head->SetPrior(tail);
}

template <class T>
DouList<T>::~DouList() {
	RemoveAll();
	delete head;
}

template <class T>
bool DouList<T>::AddTail(T value) { //�b��C�����J�@�ӷs�`�I

									//�إ߷s�`�I�A�`�I�x�s����ƥ�value�M�w 
	DouListNode<T>* add = new DouListNode<T>(value);
	tail->SetLink(add);		//�Ϸs�`�I������C���`�I����@�`�I
	add->SetPrior(tail);
	tail = tail->GetLink();
	tail->SetLink(head);	//�Ϧ�C���`�I�����C���`�I

	//�]�w��C�Y�`�I���e�@�`�I�����ݸ`�I�A�ܦ����J�ާ@����
	head->SetPrior(add);
	//�p�G�s����C���`�I���Ь��šA�h���J����
	if (tail != NULL) {
		return true;
	}
	else
		return false;
}

//����ƥΨӦV��C�Y�`�I�P��C���Ĥ@�Ӹ`�I�������J�s�`�I 
template <class T>
bool DouList<T>::AddHead(T value) {

	//�إ߷s�`�I�A�O�s���value
	DouListNode<T>* add = new DouListNode<T>(value);
	add->SetPrior(head);
	add->SetLink(head->GetLink());

	//�N��C���Ĥ@�Ӹ`�I���e�X�]��add
	//����add������C���Ĥ@�Ӹ`�I
	head->GetLink()->SetPrior(add);
	head->SetLink(add);

	//�p�G��Ŧ�C���Φ���ơA�h���ӧ�s���ݫ���tail
	if (tail == head) {
		tail = head->GetLink();
	}
	if (add != NULL) {
		return true;
	}
	else
		return false;
}

//��ثecur���쪺�`�I�R���A�R����cur�����ʤ�V��direction�M�w
template <class T>
void DouList<T>::RemoveThis(bool direction) {
	//�p�G�ثecur����C�Y�A�ѩ󤣯�R����C�Y�`�I�A
	//�]���̧ǲ���cur��U�@�Ӧ�m  
	if (cur == head) {
		//�p�Gdirection==0�A����link��V����cur
		if (direction == 0)
			cur = cur->GetLink();
		//�p�Gdirection==1�A����prior��V����cur
		if (direction == 1)
			cur = cur->GetPrior();
	}

	//�s�ث���preCu �PnextCur
	//preCur����cur���e�@�`�I
	//nextCur����cur����@�`�I  
	DouListNode<T>* preCur = NULL;
	DouListNode<T>* nextCur = NULL;
	preCur = cur->GetPrior();
	nextCur = cur->GetLink();
	DouListNode<T>* node_del = cur;
	preCur->SetLink(cur->GetLink());	//��cur���e�@�`�I���������@�`�I
	nextCur->SetPrior(cur->GetPrior());	//��cur����@�`�I��������e�@�`�I

	//�ھ�direction���ȧP�_cur�����ʤ�V
	//�Ydirection ==0�A�h��link��V����cur
	if (direction == 0)
		cur = nextCur;
	//�Ydirection ==1�A�h��prior��V����cur
	if (direction == 1)
		cur = preCur;
	delete node_del;
}

template <class T >
void DouList<T>::RemoveAll() {//�R���Ҧ��`�I�]�O�d��C�Y�`�I�^

	SetBegin();            //�q�Y�}�l�R��
	int length = GetCount();  //�O���ثe��C����
	for (int i = 0; i<length; i++) { //�`���R��
		RemoveThis(0);
	}
	cur = head;
}

template <class T >
void DouList<T>::SetBegin() {//�mcur���C�Y�B
	cur = head;
}

//���o�ثe��C���`�I�Ӽơ]���p��C�Y�`�I�^
template <class T >
int DouList<T>::GetCount() {
	int num = 0;   //�O����C���ת��ܼ�
	DouListNode<T>* here = cur; //��here���Ч�����C���M��
	while (cur->GetLink() != here) { //�M����C
		cur = cur->GetLink();
		++num;
	}

	cur = cur->GetLink();    //�M��������A�mcur���Ӫ���m  
							 //��^��C����
	return num;
}

template <class T>
void DouList<T>::TowardCur() {//��cur��link��V���� 
	cur = cur->GetLink();
}

template <class T >
void DouList<T>::BackCur() {//��cur��prior��V���� 
	cur = cur->GetPrior();
}

template <class T >
DouListNode<T>* DouList<T>::GetCur() {//��^����cur
	return cur;
}

template <class T > DouListNode<T>* DouList<T>::GetHead() {
	return head;
}

template <class T > DouListNode<T>* DouList<T>::GetTail() {
	return tail;
}

//�P�_��C�O�_���� 
template <class T >
bool DouList<T>::IsEmpty() {
	//��C���Ū�����O�Ȧ���C�Y�`�I
	return
		head->GetLink() == head;
}

//�Vcur���쪺�`�I�ᴡ�J�@�Ӹ�Ʀ�����value���s�`�I
//���Ŧ�C���Φ���ƮɡA�@�ά۷��AddTail�] T value �^
template <class T >
void DouList<T>::InsertAfter(T value) {

	DouListNode<T>* add = new DouListNode<T>(value);
	DouListNode<T>* nextCur = cur->GetLink();  //���ocur����@�`�I 
	cur->SetLink(add);    //�]�wcur���@��`�I���n�[�J���`�I
	add->SetLink(nextCur);
	nextCur->SetPrior(add); //�]�wcur��@�`�I���e�@�`�I���s�[�J�`�I
	add->SetPrior(cur);

	if (cur == tail) {
		tail = cur->GetLink();
	}
}

//���ocur���V�`�I������ơA�ñNcur��link��V����  
template <class T >
T DouList<T>::GetNext() {
	//�p�Gcur����C�Y�A�h�̧ǲ���cur
	if (cur == head) {
		cur = cur->GetLink();
	}
	T num = cur->GetData();  //��^�ثe�`�I�������
	cur = cur->GetLink();//��^��ƫᲾ��cur�]link��V�^
	return
		num;
}

//���ocur���V�`�I������ơA�ñNcur��prior��V����
template <class T >
T DouList<T>::GetPrior() {
	//�p�Gcur����C�Y�A�h�̧ǲ���cur
	if (cur == head) {
		cur = cur->GetPrior();
	}
	T num = cur->GetData();	//��^�ثe�`�I�������
	cur = cur->GetPrior();	//��^��ƫᲾ��cur�]prior��V�^ 
	return
		num;
}

#endif  
