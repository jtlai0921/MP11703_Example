#pragma once
#ifndef _ITEM_H_  
#define _ITEM_H_  

#include <iostream>  
#include <string.h>  

using namespace std;

class Item {
	string english;
	string chinese;
	Item*  link;

public:

	Item() : link(NULL) {}
	Item(string en, string ch) : link(NULL), english(en), chinese(ch) {}
	~Item() {};
	void SetLink(Item* next);
	Item*  GetLink();
	string GetIndex();
	string GetValue();
};

void Item::SetLink(Item* next) {
	link = next;
}

Item* Item::GetLink() {
	return link;
}

string Item::GetIndex() {//��^�`�I�������
	return english;
}

string Item::GetValue() {//��^�`�I�������
	return chinese;
}

#endif  
