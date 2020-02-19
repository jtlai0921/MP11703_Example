// 08_p281.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include "iostream"  

using namespace std;

#define MaxNumVer 10  
#define MaxWeight 100  

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "�Ъ`�N�G" << endl;
	cout << "\t���{���w�]���̤j���I�Ƭ�10" << endl;
	cout << "\t���v�Ȫ����Ƚd��O����0��99����" << endl << endl;

	int G[MaxNumVer][MaxNumVer], in[MaxNumVer] = { 0 }, path[MaxNumVer][2];
	int i, j, k, min = MaxWeight;
	int v1, v2, num, tmpValue, status = 0, start = 0;

	//��J���I�`���ƥ�  
	while (true)
	{
		cout << "�п�J�Ϥ����I���ƥءG" << endl;
		cin >> num;
		if (num <= MaxNumVer&&num>0)
			break;
		cout << "���~�I�нT�{�᭫�s��J�C" << endl << endl;
	}

	//�إ߹ϨèϥξF���x�}G�x�s��
	for (j = 0; j<num; j++)
		for (k = 0; k<num; k++)
		{
			if (j == k)
				G[j][k] = MaxWeight;
			else if (j<k)
			{
				while (true)
				{
					cout << "�п�J��(" << j + 1 << "," << k + 1 << ")���v�ȡA�p�G���ܤ��s�b�п�J-1:" << endl;
					cin >> tmpValue;
					if (tmpValue >= -1 && tmpValue<MaxWeight)break;
					cout << endl << "��J�L�I�нT�{�᭫�s��J�C" << endl;
				}

				if (tmpValue == -1)
					tmpValue = MaxWeight;

				G[j][k] = G[k][j] = tmpValue;//�x�}�O��٪�
			}
		}

	for (j = 0; j<num; j++)
	{
		status = 0;
		for (k = 0; k<num; k++)
			if (G[j][k]<MaxWeight)
			{
				status = 1;
				break;
			}
		if (status == 0)
			break;
	}

	//�p�G�ϬO�D�s�q���h�h�X�{��
	if (!status) {
		cout << "�L�k�B�z�A�]���ӹϬO�D�s�q���I" << endl;
		return -1;
	}

	//��ܺt��k���_�l�I
	while (true) {
		cout << "�п��Prim�t��k���_�l�I�G" << endl;
		cin >> start;

		if (start>0 && start <= num)
			break;

		cout << "���~�I�нT�{�᭫�s��J�C" << endl << endl;
	}

	//Prim�t��k�D�̤p���ͪ���
	in[start - 1] = 1; //�аO

	for (i = 0; i<num - 1; i++)
	{
		for (j = 0; j<num; j++)
			for (k = 0; k<num; k++)
				if (G[j][k]<min&&in[j] && (!in[k]))
				{
					v1 = j;
					v2 = k;
					min = G[j][k];
				}

		if (!in[v2])
		{
			path[i][0] = v1;
			path[i][1] = v2;

			//�аO
			in[v1] = 1;
			in[v2] = 1;

			min = MaxWeight;
		}

	}

	//��X���G
	cout << "�̤p���ͪ���p�U�G" << endl;
	for (i = 0; i<num - 1; i++)
		cout << "(" << path[i][0] + 1 << ", " << path[i][1] + 1 << ")" << endl;

	system("PAUSE");
	return 0;
}
