// 09_p317.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  
#include <cstring>  

using namespace std;

const int num_chars = 26;

class Trie {

protected:
	struct Trie_node {
		char* word;     //�x�s���r��
		Trie_node* branch[num_chars];
		Trie_node();
	};
	Trie_node* root;

public:
	Trie();
	int search(const char* word) const; //��M�r��
	int insert(const char* word);   //���J�r��
	int remove(const char* word);
	void printall(char *pre, Trie_node *p); //�L�X�Ҧ��r��
	void printpre(char *pre);       //�L�X�ŦX���󪺦r��
};

Trie::Trie() :root(NULL)
{
}

Trie::Trie_node::Trie_node()
{
	word = NULL;
	for (int i = 0; i<num_chars; ++i)      //���s����Tire��
		branch[i] = NULL;
}

int Trie::search(const char* word) const
{
	char char_code;
	Trie_node *location = root;
	while (location != NULL && *word != 0)
	{//�v�ŧ�M�аO��
		if (*word >= 'A' && *word <= 'Z')
			char_code = *word - 'A';
		else if (*word >= 'a' && *word <= 'z')
			char_code = *word - 'a';
		else
			return 0;
		location = location->branch[char_code];
		word++;
	}

	if (location != NULL && location->word != NULL)
		return 1;
	else
		return 0;       //�S�����
}

int Trie::insert(const char* word)
{
	cout << "���J" << word << endl;
	int result = 1;
	if (root == NULL) root = new Trie_node;
	char char_code;
	Trie_node *location = root;

	while (location != NULL && *word != 0)
	{   //�z�L�аO���M
		if (*word >= 'A' && *word <= 'Z')
			char_code = *word - 'A';
		else if (*word >= 'a' && *word <= 'z')
			char_code = *word - 'a';
		else
			return 0;   //�S�����X�A��m�A���J����
		if (location->branch[char_code] == NULL)
			location->branch[char_code] = new Trie_node;
		location = location->branch[char_code];
		word++;
	}

	if (location->word != NULL)
		result = 0;
	else
	{
		location->word = new char[strlen(word) + 1];
		strcpy(location->word, word);
	}
	return result;
}

int Trie::remove(const char* word)
{
	cout << "�R��" << word << endl;
	int result = 1;
	char char_code;
	Trie_node *location = root;

	while (location != NULL && *word != 0)
	{
		if (*word >= 'A' && *word <= 'Z')
			char_code = *word - 'A';
		else if (*word >= 'a' && *word <= 'z')
			char_code = *word - 'a';
		else
			return 0;
		location = location->branch[char_code];  //�R���e�m�r���A�ק�аO
		word++;
	}

	if (location)
	{
		delete location->word;
		location->word = NULL;
	}
	else
		result = 0; //�R������

	return result;
}

//�w��諸�����`�I�A�L�X�e�m�r��
void Trie::printall(char *pre, Trie_node *p)
{
	if (p->word != NULL) {
		cout << pre << endl;
	}

	for (int i = 0; i<num_chars; ++i)
	{
		if (p->branch[i] != NULL)
		{
			char ch = 'a' + i;
			char *prestr = new char[strlen(pre) + 2];
			sprintf(prestr, "%s%c", pre, ch);
			printall(prestr, p->branch[i]);
			delete[] prestr;       //����O����
		}
	}
}

void Trie::printpre(char *pre)
{
	char char_code;
	char *p = pre;
	Trie_node *location = root;

	while (location != NULL && *pre != 0)
	{   //�P�_�O�_�ŦX�e�m�r��
		if (*pre >= 'A' && *pre <= 'Z')
			char_code = *pre - 'A';
		else if (*pre >= 'a' && *pre <= 'z')
			char_code = *pre - 'a';
		else
			return;     //�D�k�r��
		location = location->branch[char_code];
		pre++;
	}
	if (location != NULL)
		printall(p, location);
	return;
}

int main(int argc, char** argv) {

	Trie t;
	t.insert("blue");
	t.insert("blur");
	t.insert("car");
	t.insert("cat");
	t.insert("caw");
	t.insert("coin");
	t.insert("coim");
	t.remove("coim");
	cout << endl;

	cout << "�L�X�𤤩Ҧ��`�I" << endl;
	t.printpre("");
	cout << endl;

	cout << "�}�l�j�M" << "cat" << endl;
	if (t.search("cat"))
		cout << "cat" << " was found." << endl;
	else
		cout << "cat" << " was not found." << endl;

	cout << "�L�X�e�m�r����ca����r�G" << endl;
	t.printpre("ca");

	cout << endl;
	system("PAUSE");
	return 0;
}
