// 08_p251.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include "conio.h"  
#include <iostream>  

using namespace std;

class Board
{
private:
	int board[8][8];	//�ѽL
	int step;			//�ثe�����B��
	int No;				//�ثe�Ѫ��s��
	int direct[8][2];	//�U�e�i��V�����а���
	int wayCount[8][8];	//�ѽL�W�C�Ӧ�m�i���X����V�ƥ�
	int startX;         //�_�l�I����x
	int startY;         //�_�l�I����y
	int dir[8][8][8];   //�O�s�̨Ϊ��j����V����


	void init()
	{
		int i, j, k;
		int x, y;
		//�T�w�q�ѽL�W�C�Ӧ�m�i���X����V�ƥ�
		for (j = 0; j<8; j++)
		{
			for (i = 0; i<8; i++)
			{
				wayCount[j][i] = 0;
				for (k = 0; k<8; k++)
				{
					x = i + direct[k][0];
					y = j + direct[k][1];
					if (check(x, y))
						wayCount[j][i]++;
				}
			}
		}

		//���ѽL�W�C�Ӧ�m�T�w�j������V����
		for (y = 0; y<8; y++)
		{
			for (x = 0; x<8; x++)
			{
				//�w�]�j�����Ǭ����ɰw��V
				for (k = 0; k<8; k++)
				{
					dir[y][x][k] = k;
				}
				//�M��̨Ϊ��j������
				for (i = 0; i<7; i++)
				{
					k = i;
					int x1 = x + direct[dir[y][x][k]][0];
					int y1 = y + direct[dir[y][x][k]][1];
					//���U�j����V�̳W�h�Ƨ�
					//�Ʊ�j�����u����F�U�@�B�i��ʸ��֪���m
					for (j = i + 1; j<8; j++)
					{
						int x2 = x + direct[dir[y][x][j]][0];
						int y2 = y + direct[dir[y][x][j]][1];
						//�p�G�q�ثe��m�X�o�A��Vj�u���Vk�A�h�Nk������j
						if ((!check(x1, y1) && check(x2, y2))
							|| (check(x1, y1) && check(x2, y2) &&
								wayCount[x1][y1]>wayCount[x2][y2]))
						{
							k = j;
							x1 = x + direct[dir[y][x][k]][0];
							y1 = y + direct[dir[y][x][k]][1];
						}
					}
					j = dir[y][x][k];
					dir[y][x][k] = dir[y][x][i];
					dir[y][x][i] = j;
				}
			}
		}
	}

	//�ˬdx,y�O�_���X�k��m  
	int check(int x, int y)
	{
		if (x<0 || x>7 || y<0 || y>7)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	//�q���w��m(x,y)�X�o�M����|  
	void dg(int x, int y)
	{
		int i, nx, ny;
		//�p�G�ثe���̫�@�B�A�h�פ�j  
		if (step == 64)
		{
			printPath();
			return;
		}

		//�̷ӳ̨Ϊ��j����V���ǡA�̧ǦV�U�i���V�j�M
		for (i = 0; i<8; i++)
		{
			nx = x + direct[dir[y][x][i]][0];
			ny = y + direct[dir[y][x][i]][1];
			if (nx >= 0 && nx<8 && ny >= 0 && ny<8)
			{
				//�p�G���\��F�U�@��m�A�h�q�s��m�}�l�~��j��
				if (board[ny][nx]<0)
				{
					board[ny][nx] = step;
					step++;
					dg(nx, ny);
					board[ny][nx] = -1;
					step--;
				}
			}
		}
	}

	void printPath()
	{
		int i, j;
		No++;
		cout << "No" << No << ":" << endl;
		for (j = 0; j<8; j++)
		{
			for (i = 0; i<8; i++)
			{
				cout << board[j][i] << " ";
				if (board[j][i]<10)
					cout << " ";
			}
			cout << endl;
		}
		cout << "Press q to exit, other key to continue...";
		//getch();
		if (getchar() == 'q')
			exit(0);

		cout << endl;
	}
	void printwc()
	{
		int i, j;
		No++;
		cout << "No" << No << ":" << endl;
		for (j = 0; j<8; j++)
		{
			for (i = 0; i<8; i++)
			{
				cout << wayCount[j][i] << " ";
				if (wayCount[j][i]<10)
					cout << " ";
			}
			cout << endl;
		}
		cout << "Press q to exit, other key to continue...";
		//getch();
		if (getchar() == 'q')
			exit(0);

		cout << endl;
	}

public:
	Board(int x, int y)
	{
		int i, j;
		startX = x;
		startY = y;
		direct[0][0] = 1;     direct[0][1] = -2;
		direct[1][0] = 2;     direct[1][1] = -1;
		direct[2][0] = 2;     direct[2][1] = 1;
		direct[3][0] = 1;     direct[3][1] = 2;
		direct[4][0] = -1;    direct[4][1] = 2;
		direct[5][0] = -2;    direct[5][1] = 1;
		direct[6][0] = -2;    direct[6][1] = -1;
		direct[7][0] = -1;    direct[7][1] = -2;
		step = 1;
		No = 0;
		for (j = 0; j<8; j++)
		{
			for (i = 0; i<8; i++)
			{
				board[j][i] = -1;
			}
		}
		board[y][x] = 0;
	}

	void GetPath()
	{
		init();
		dg(startX, startY);
		if (No == 0)
		{
			cout << "no result" << endl;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int x, y;
	cout << "Please input the start point (x,y)."
		<< endl << "x=";
	cin >> x;
	getchar();
	cout << "y=";
	cin >> y;
	getchar();
	Board board(x, y);
	board.GetPath();

	return 0;
}
