// 04_p101.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

#include "List.h"  
#include <iostream>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//�إߨ�ӳs����ClistFirst, listSecond  
	List<int> listFirst;
	List<int> listSecond;

	//��l�Ƴs����ClistFirst  
	listFirst.AddTail(1);
	listFirst.AddTail(6);
	listFirst.AddTail(8);
	listFirst.AddTail(9);
	listFirst.AddTail(13);

	//��l�Ƴs����ClistSecond  
	listSecond.AddTail(0);
	listSecond.AddTail(3);
	listSecond.AddTail(4);
	listSecond.AddTail(6);
	listSecond.AddTail(11);
	listSecond.AddTail(17);

	while (listSecond.GetCount() != 0) { //��listSecond�D�Ůɫ���`��  
		int indexFirst = 0;
		//�C����listSecond�����Ĥ@�Ӽƨ̧Ǵ��JlistFirst��
		//��while�j�鵲�c�M�䴡�J��m
		while (listSecond.GetAt(0)>listFirst.GetAt(indexFirst)) {
			++indexFirst;
			//�p�GlistFirst�w���C���ݡA�h���������j��
			if (indexFirst == listFirst.GetCount()) {
				break;
			}
		}
		if (indexFirst == listFirst.GetCount()) {//���J��m�blistFirst��C����
			listFirst.AddTail(listSecond.GetAt(0));
			listSecond.RemoveAt(0);
		}
		else {//���J��m�blistFirst��C��
			listFirst.InsertAt(indexFirst, listSecond.GetAt(0));
			listSecond.RemoveAt(0);
		}
	}

	ListNode<int> * curNode = listFirst.GetHead();
	while (curNode != listFirst.GetTail())
	{
		curNode = curNode->GetLink();
		cout << curNode->GetData() << endl;
	}

	cout << endl;
	system("PAUSE");

	return 0;
}
