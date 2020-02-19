#pragma once
#ifndef BINARYTREENODE_H  
#define BINARYTREENODE_H  

#include "iostream"  

using namespace std;

template <class Type>
class BinaryTreeNode
{
	Type m_data;      // �x�s�Ӹ`�I�����  
	BinaryTreeNode<Type> *m_leftChild; // �x�s�Ӹ`�I�����Ĥl����
	BinaryTreeNode<Type> *m_rightChild;// �x�s�Ӹ`�I���k�Ĥl����

public:
	BinaryTreeNode() { m_leftChild = m_rightChild = NULL; };
	BinaryTreeNode(const Type &data,
		BinaryTreeNode *leftChild = NULL,
		BinaryTreeNode *rightChild = NULL)
	{
		m_data = data;
		m_leftChild = leftChild;
		m_rightChild = rightChild;
	};

	Type & GetData() { return m_data; };       // ��^�Ӹ`�I�����

	// ��^�Ӹ`�I�����Ĥl����
	BinaryTreeNode<Type>* GetLeftChild() { return m_leftChild; };

	// ��^�Ӹ`�I���k�Ĥl����
	BinaryTreeNode<Type>* GetRightChild() { return m_rightChild; };

	// �]�w�Ӹ`�I�����
	void SetData(const Type & data) { m_data = data; };

	// �]�w�Ӹ`�I�����Ĥl���а�
	void SetLeftChild(BinaryTreeNode<Type> *leftChild) { m_leftChild = leftChild; };

	// �]�w�Ӹ`�I���k�Ĥl���а�
	void SetRightChild(BinaryTreeNode<Type> *rightChild) { m_rightChild = rightChild; };
};

#endif  
