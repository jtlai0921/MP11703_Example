#pragma once
#include"BinaryTreeNode.h"  
#include<queue>  

using namespace std;

template<class T>
class BinaryTree
{
	BinaryTreeNode<T> *m_root;

public:

	BinaryTree() { m_root = NULL; };
	BinaryTree(T data) { m_root = new BinaryTreeNode<T>(data); };
	virtual ~BinaryTree();

	bool IsEmpty() const { return m_root == NULL ? true : false; }; //�P�_��O�_����

	//�P�_�Ӹ`�I�O�_�����Ĥl
	bool IsLeftChild(BinaryTreeNode<T> *p)
	{
		return p == GetParent(p)->GetLeftChild() ? true : false;
	};
	//�P�_�Ӹ`�I�O�_���k�Ĥl
	bool IsRightChild(BinaryTreeNode<T> *p)
	{
		return p == GetParent(p)->GetRightChild() ? true : false;
	};

	//���o��ʾ𪺾��
	BinaryTreeNode<T>* GetRoot() { return m_root; };
	//���o�Y�`�I�����`�I����
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T> *p) { return Parent(m_root, p); };
	//���o�Y�`�I�����l��ګ���
	BinaryTreeNode<T>* LeftChild(BinaryTreeNode<T> *root) const
	{
		return root == NULL ? NULL : root->GetLeftChild();
	};
	//���o�Y�`�I���k�l��ګ���
	BinaryTreeNode<T>* RightChild(BinaryTreeNode<T> *root) const
	{
		return root == NULL ? NULL : root->GetRightChild();
	};

	//���o�@�Ӹ`�I�����S�̫���
	BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T> *leftChild);
	//���o�@�Ӹ`�I���k�S�̫���
	BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T> *rightChild);

	//��^�@�Ӹ`�I�����
	T Retrieve(BinaryTreeNode<T> *p) const { return p->GetData(); };

	//�]�w�@�Ӹ`�I�����
	void Assign(BinaryTreeNode<T> *p, const T &d) const { p->SetData(d); };
	//���J�k�Ĥl��ثe�`�I�U
	void InsertRightChild(BinaryTreeNode<T> *p, const T &d) const;
	//���J���Ĥl��ثe�`�I�U
	void InsertLeftChild(BinaryTreeNode<T> *p, const T &d) const;

	//�R���ثe�`�I���k�Ĥl
	void DeleteRightChild(BinaryTreeNode<T> *p) { Destroy(p->GetRightChild()); };
	//�R���ثe�`�I�����Ĥl
	void DeleteLeftChild(BinaryTreeNode<T> *p) { Destroy(p->GetLeftChild()); };

	virtual void PreOrderTraverse(BinaryTreeNode<T> *root) const;	//���ǹM����ʾ�  
	virtual void InOrderTraverse(BinaryTreeNode<T> *root) const;	//���ǹM����ʾ�
	virtual void PostOrderTraverse(BinaryTreeNode<T> *root) const;	//��ǹM����ʾ�

	virtual void LevelOrderTraverse(BinaryTreeNode<T> *root) const;	//�v�h�M����ʾ�

protected:

	BinaryTreeNode<T>* Parent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *p);
	void Destroy(BinaryTreeNode<T> *p);
};

template<class T>
BinaryTree<T>::~BinaryTree(void)
{
	Destroy(m_root);
	m_root = NULL;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T> *p)
{
	BinaryTreeNode<T> *q;
	q = Parent(m_root, p);
	if ((NULL == q) || (p == q->GetRightChild()))
		return NULL;
	else
		return q->GetRightChild();
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T> *p)
{
	BinaryTreeNode<T> *q;
	q = Parent(m_root, p);
	if ((NULL == q) || (p == q->GetLeftChild()))
		return NULL;
	else
		return q->GetLeftChild();
}

template<class T>
void BinaryTree<T>::InsertLeftChild(BinaryTreeNode<T> *p, const T &d) const
{
	BinaryTreeNode<T> *q = new BinaryTreeNode<T>(d);
	q->SetLeftChild(p->GetLeftChild());
	p->SetLeftChild(q);
}

template<class T>
void BinaryTree<T>::InsertRightChild(BinaryTreeNode<T> *p, const T &d) const
{
	BinaryTreeNode<T> *q = new BinaryTreeNode<T>(d);
	q->SetRightChild(p->GetRightChild());
	p->SetRightChild(q);
}

template<class T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T> *p)
{
	if (NULL != p)
	{
		Destroy(p->GetLeftChild());
		Destroy(p->GetRightChild());
		delete p;
	}
}

template<class T> BinaryTreeNode<T>*
BinaryTree<T>::Parent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *p)
{
	BinaryTreeNode<T> *q;
	if (NULL == root)
		return NULL;

	if ((p == root->GetLeftChild()) || (p == root->GetRightChild()))
		return root;

	if (NULL != (q = Parent(root->GetLeftChild(), p)))
		return q;
	else
		return Parent(root->GetRightChild(), p);
}

template<class T>
void BinaryTree<T>::LevelOrderTraverse(BinaryTreeNode<T> *root) const
{
	queue<BinaryTreeNode<T> *> q;
	if (NULL != root)
		q.push(root);

	while (!q.empty())
	{
		root = q.front(), q.pop();
		cout << root->GetData();
		if (root->GetLeftChild())
			q.push(root->GetLeftChild());
		if (root->GetRightChild())
			q.push(root->GetRightChild());
	}
}

template<class T>
void BinaryTree<T>::PreOrderTraverse(BinaryTreeNode<T> *root) const
{

	if (NULL != root)
	{
		cout << root->GetData();

		PreOrderTraverse(root->GetLeftChild());
		PreOrderTraverse(root->GetRightChild());
	}
}

template<class T>
void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T> *root) const
{
	if (NULL != root)
	{
		InOrderTraverse(root->GetLeftChild());
		cout << root->GetData();
		InOrderTraverse(root->GetRightChild());
	}
}

template<class T>
void BinaryTree<T>::PostOrderTraverse(BinaryTreeNode<T> *root) const
{
	if (NULL != root)
	{
		PostOrderTraverse(root->GetLeftChild());
		PostOrderTraverse(root->GetRightChild());

		cout << root->GetData();
	}
}

/*
template<class T>
void BinaryTree<T>::PreOrderTraverse(BinaryTreeNode<T> *root) const
{
	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T> *p = root;
	while (!s.empty() || p != NULL)
	{
		while (p)
		{
			s.push(p);
			cout << p->GetData();
			p = p->GetLeftChild();
		}
		p = s.top();
		s.pop();
		p = p->GetRightChild();
	}
}

template<class T>
void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T> *root) const
{
	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T> *p = root;
	while (!s.empty() || p != NULL)
	{
		while (p)
		{
			s.push(p);
			p = p->GetLeftChild();
		}

		p = s.top();
		s.pop();
		cout << p->GetData();
		p = p->GetRightChild();
	}
}
*/

