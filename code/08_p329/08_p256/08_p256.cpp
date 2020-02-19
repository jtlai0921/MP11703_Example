// 08_p256.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>  
#include <cstdlib>  
#include <set>  
#include <vector>  
#include <list>  
#include <stack>  
#include <queue>  

using namespace std;

//BFS  
void bfs(vector< list<int> >& adj_lists, int start_node) {

	queue<int> not_yet_explored;
	set<int> discovered;

	// �аO�_�l�`�I���w�Q�o�{�A�ñN��m���C���}�l����
	not_yet_explored.push(start_node);
	discovered.insert(start_node);

	while (!not_yet_explored.empty()) {

		// ���o�@�ӷs�`�I�è̦��@�����I�i�汴��
		int node_to_explore = not_yet_explored.front();
		not_yet_explored.pop();
		// �˴��Ӹ`�I���Ҧ���
		list<int>::iterator edges = adj_lists[node_to_explore].begin();
		for (; edges != adj_lists[node_to_explore].end(); edges++) {

			if (discovered.count(*edges) == 0) {

				// �o�{�s�`�I�A�N��[�J��C
				discovered.insert(*edges);
				not_yet_explored.push(*edges);

				cout << "Found " << *edges << " from " << node_to_explore << endl;

			}
		}
	}
}

//DFS  
void dfs_helper(vector< list<int> >& adj_lists, set<int>& discovered, int node) {

	// �˴��Ӹ`�I���Ҧ���
	list<int>::iterator edges = adj_lists[node].begin();
	for (; edges != adj_lists[node].end(); edges++) {
		// �˴��Y��O�_�t�����o�{�����I
		if (discovered.count(*edges) == 0) {
			discovered.insert(*edges);
			cout << "Found " << *edges << " from " << node << endl;
			dfs_helper(adj_lists, discovered, *edges);
		}
	}
}

void dfs(vector< list<int> >& adj_lists, int start_node) {

	//�аO�_�l���I���w�Q�o�{
	set<int> discovered;
	discovered.insert(start_node);
	dfs_helper(adj_lists, discovered, start_node);
}


int _tmain(int argc, _TCHAR* argv[])
{
	//��l�ƹϸ�T
	vector< list<int> > g(7, list<int>());

	g[0].push_back(2);
	g[0].push_back(1);

	g[1].push_back(0);
	g[1].push_back(2);

	g[2].push_back(4);
	g[2].push_back(3);
	g[2].push_back(0);
	g[2].push_back(1);

	g[3].push_back(2);
	g[3].push_back(4);
	g[3].push_back(5);

	g[4].push_back(6);
	g[4].push_back(5);
	g[4].push_back(3);
	g[4].push_back(2);

	g[5].push_back(4);
	g[5].push_back(3);

	g[6].push_back(4);

	cout << "BFS" << endl;
	bfs(g, 0);

	cout << endl << "DFS" << endl;
	dfs(g, 0);

	cout << endl;
	system("PAUSE");
	return 0;
}
