#pragma once
#include "avlnode.h"  

template <class T>
class AvlTree {

	AvlNode<T> *root;

	bool Insert(AvlNode<T> *& rt, T x, bool &taller);
	bool Remove(AvlNode<T> *& rt, T x, bool &shorter);

	void RotateLeft(AvlNode<T> * &node);  //���ۨ��
	void RotateRight(AvlNode<T> * &node); //�k�ۨ��

	void RightBalanceAfterInsert(AvlNode<T> * &sRoot, bool &taller);
	void LeftBalanceAfterInsert(AvlNode<T> * &sRoot, bool &taller);
	void RightBalanceAfterDelete(AvlNode<T> * &sRoot, bool &shorter);
	void LeftBalanceAfterDelete(AvlNode<T> * &sRoot, bool &shorter);

public:

	AvlTree() :root(NULL) {}
	AvlNode<T>* getRoot() const
	{
		return root;
	}

	bool Insert(T x)
	{
		bool taller = false;
		return Insert(root, x, taller);
	}

	bool Remove(T x)
	{
		bool shorter = false;
		return Remove(root, x, shorter);
	}

	//��X��ε��c
	void DisplayTree(AvlNode<T> *t, int layer) const;
};

template <typename T>
void AvlTree<T>::RotateLeft(AvlNode<T> * & node)
{
	if ((node == NULL) || (node->rightChild == NULL)) return;

	AvlNode<T> * tmpNode = new AvlNode<T>(node->data);
	if (tmpNode == NULL) return;

	tmpNode->leftChild = node->leftChild;
	node->leftChild = tmpNode;
	tmpNode->rightChild = node->rightChild->leftChild;

	AvlNode<T> *toDelete = node->rightChild;
	node->data = toDelete->data;
	node->rightChild = toDelete->rightChild;

	delete toDelete;
}

template <typename T>
void AvlTree<T>::RotateRight(AvlNode<T> * & node)
{
	if ((node == NULL) || (node->leftChild == NULL)) return;

	AvlNode<T> *tmpNode = new AvlNode<T>(node->data);
	if (tmpNode == NULL) return;

	tmpNode->rightChild = node->rightChild;
	node->rightChild = tmpNode;
	tmpNode->leftChild = node->leftChild->rightChild;

	AvlNode<T> *toDelete = node->leftChild;
	node->data = toDelete->data;
	node->leftChild = toDelete->leftChild;

	delete toDelete;
}

//�p�G���J�`�I��Art���k���׼W�[�A�h�I�s����ƶi�業�Ť�
template <typename T>
void AvlTree<T>::RightBalanceAfterInsert(AvlNode<T> *&sRoot, bool &taller)
{
	if ((sRoot == NULL) || (sRoot->rightChild == NULL)) return;
	AvlNode<T> *rightsub = sRoot->rightChild, *leftsub;
	switch (rightsub->balance) {
	case 1:
		sRoot->balance = rightsub->balance = 0;
		RotateLeft(sRoot);
		taller = false; break;
	case 0:
		cout << "��w�g���ŤơC" << endl; break;
	case -1:
		leftsub = rightsub->leftChild;
		switch (leftsub->balance) {
		case 1:
			sRoot->balance = -1; rightsub->balance = 0; break;
		case 0:
			sRoot->balance = rightsub->balance = 0; break;
		case -1:
			sRoot->balance = 0; rightsub->balance = 1; break;
		}
		leftsub->balance = 0;
		RotateRight(rightsub);
		RotateLeft(sRoot);
		taller = false; break;
	}
}

//�p�G���J�`�I��Art�������׼W�[�A�h�I�s����ƶi�業�Ť�
template <typename T>
void AvlTree<T>::LeftBalanceAfterInsert(AvlNode<T> *&sRoot, bool &taller)
{
	AvlNode<T> *leftsub = sRoot->leftChild, *rightsub;
	switch (leftsub->balance) {
	case -1:
		sRoot->balance = leftsub->balance = 0;
		RotateRight(sRoot);
		taller = false; break;
	case 0:
		cout << "��w�g���ŤơC" << endl; break;
	case 1:
		rightsub = leftsub->rightChild;
		switch (rightsub->balance) {
		case -1:
			sRoot->balance = 1; leftsub->balance = 0; break;
		case 0:
			sRoot->balance = leftsub->balance = 0; break;
		case 1:
			sRoot->balance = 0; leftsub->balance = -1; break;
		}
		rightsub->balance = 0;
		RotateLeft(leftsub);
		RotateRight(sRoot);
		taller = false; break;
	}
}

//�p�G�R���`�I��Art�������״�֡A�h�I�s����ƶi�業�Ť�
template <typename T>
void AvlTree<T>::RightBalanceAfterDelete(AvlNode<T> * &sRoot, bool &shorter)
{
	AvlNode<T> *rightsub = sRoot->rightChild, *leftsub;
	switch (rightsub->balance) {
	case 1: sRoot->balance = sRoot->balance = 0; RotateLeft(sRoot); break;
	case 0: sRoot->balance = 0; rightsub->balance = -1; RotateLeft(sRoot); break;
	case -1:
		leftsub = rightsub->leftChild;
		switch (leftsub->balance) {
		case -1: sRoot->balance = 0; rightsub->balance = 1; break;
		case 0: sRoot->balance = rightsub->balance = 0; break;
		case 1: sRoot->balance = -1; rightsub->balance = 0; break;
		}
		leftsub->balance = 0;
		RotateRight(rightsub);
		RotateLeft(sRoot);
		shorter = false; break;
	}
}

//�p�G�R���`�I��Art���k���״�֡A�h�I�s����ƶi�業�Ť�
template <typename T>
void AvlTree<T>::LeftBalanceAfterDelete(AvlNode<T> * &sRoot, bool &shorter)
{
	AvlNode<T> *leftsub = sRoot->leftChild, *rightsub;
	switch (leftsub->balance) {
	case 1: sRoot->balance = sRoot->balance = 0; RotateRight(sRoot); break;
	case 0: sRoot->balance = 0; leftsub->balance = -1; RotateRight(sRoot); break;
	case -1:
		rightsub = leftsub->rightChild;
		switch (rightsub->balance) {
		case -1: sRoot->balance = 0; leftsub->balance = 1; break;
		case 0: sRoot->balance = leftsub->balance = 0; break;
		case 1: sRoot->balance = -1; leftsub->balance = 0; break;
		}
		rightsub->balance = 0;
		RotateLeft(leftsub);
		RotateRight(sRoot);
		shorter = false; break;
	}
}

//���J�Ȭ�x���`�I�A��@�覡�ĥλ��j
template <typename T>
bool AvlTree<T>::Insert(AvlNode<T> *& rt, T x, bool &taller)
{
	bool success;

	//���j��ƪ��u�򥻱���v
	if (rt == NULL)
	{
		rt = new AvlNode<T>(x);
		success = rt != NULL ? true : false;
		if (success) taller = true;
	}
	//�p�Gx���Ȥp��rt������X
	else if (x < rt->data)
	{
		//Insert�����j�I�s�A�qrt�����l��M��X�A����m���J
		success = Insert(rt->leftChild, x, taller);

		if (taller) {//�p�G���J��ϱort�������׼W�[
			switch (rt->balance) {
			case -1: LeftBalanceAfterInsert(rt, taller); break;
			case 0:  rt->balance = -1; break;
			case 1:  rt->balance = 0;  taller = false; break;
			}
		}
	}
	//�p�Gx���Ȥj��rt������X
	else if (x > rt->data)
	{
		//Insert�����j�I�s�A�qrt���k�l��M��X�A����m���J
		success = Insert(rt->rightChild, x, taller);

		if (taller) {//�p�G���J��ϱort���k���׼W�[ 
			switch (rt->balance) {
			case -1:
				rt->balance = 0;
				taller = false;
				break;
			case 0:
				rt->balance = 1;
				break;
			case 1:
				RightBalanceAfterInsert(rt, taller);
				break;
			}
		}
	}
	return success;
}

//�R���Ȭ�x���`�I�A��@�覡�ĥλ��j
template <typename T>
bool AvlTree<T>::Remove(AvlNode<T> *& rt, T x, bool &shorter)
{
	bool success = false;
	if (rt == NULL) return false;

	//�p�Grt�N�O�n�R�����`�I
	if (x == rt->data) {
		if (rt->leftChild != NULL && rt->rightChild != NULL)
		{

			//�M��rt�����ǹM�����e�@�`�I�A�Hr���
			AvlNode<T> *r = rt->leftChild;
			while (r->rightChild != NULL) {
				r = r->rightChild;
			}

			//�洫rt�Mr����
			T temp = rt->data;
			rt->data = r->data;
			r->data = temp;

			//���j��ơA�qrt�����l�𤤧R������X��x���`�I
			success = Remove(rt->leftChild, x, shorter);
			if (shorter) {//�p�G�R����ް_rt�������״��
				switch (rt->balance) {
				case -1: rt->balance = 0; break;
				case 0: rt->balance = 1; shorter = 0; break;
				case 1: RightBalanceAfterDelete(rt, shorter); break;
				}
			}
		}
		else {//rt�̦h�u���@�Ӥl�k�A�o�O���j���X�f
			AvlNode<T> *p = rt;
			rt = rt->leftChild != NULL ? rt->leftChild : rt->rightChild;
			delete p;
			success = true;
			shorter = true;
		}
	}

	else if (x < rt->data) {
		//���j��ƩI�s�A�qrt�����l�𤤧R������X��x���`�I
		success = Remove(rt->leftChild, x, shorter);
		if (shorter) {//�p�G�R����ް_rt�������״��
			switch (rt->balance) {
			case -1: rt->balance = 0; break;
			case 0: rt->balance = 1; shorter = 0; break;
			case 1: RightBalanceAfterDelete(rt, shorter); break;
			}
		}
	}

	else if (x > rt->data) {
		//���j��ƩI�s�A�qrt���k�l�𤤧R������X��x���`�I
		success = Remove(rt->rightChild, x, shorter);
		if (shorter) {//�p�G�R����ް_rt���k���״��
			switch (rt->balance) {
			case -1: LeftBalanceAfterDelete(rt, shorter); break;
			case 0: rt->balance = -1; shorter = 0; break;
			case 1: rt->balance = 0; break;
			}
		}
	}
	return success;
}

template <typename T>
void AvlTree<T>::DisplayTree(AvlNode<T> *t, int layer) const
{
	if (t == NULL)
		return;
	if (t->rightChild)
		DisplayTree(t->rightChild, layer + 1);
	for (int i = 0; i<layer; i++)
		cout << "    ";
	cout << t->data << endl;
	if (t->leftChild)
		DisplayTree(t->leftChild, layer + 1);
}
