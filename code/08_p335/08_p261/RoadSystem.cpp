#pragma warning (disable:4786)  
#pragma warning (disable:4503)  

#include "stdafx.h"
#include "RoadSystem.h"  

void RoadSystem::reset(void) {

	map<string, City*>::iterator it;
	for (it = cities.begin(); it != cities.end(); ++it) {
		it->second->visited = false;
		it->second->total_fee = INT_MAX;
		it->second->total_distance = INT_MAX;
		it->second->from_city = "";
	}
}

string RoadSystem::recover_route(const string& city) {

	string route;
	string current = city;

	while (current != "") {

		route = current + route;
		string prev = cities[current]->from_city;

		if (prev != "") {
			route = " -> " + route;
		}
		current = prev;
	}

	return route;
}


RoadSystem::RoadSystem(string const &filename) {

	load_roads(filename);
}

RoadSystem::~RoadSystem(void) {

	// ���񫰥���T
	map<string, City*>::iterator city_it = cities.begin();
	for (; city_it != cities.end(); city_it++) {
		delete city_it->second;
	}

	// ����D����T
	map<string, list<Road*> >::iterator roads_it =
		outgoing_roads.begin();
	for (; roads_it != outgoing_roads.end(); roads_it++) {

		list<Road*>::iterator road_it = roads_it->second.begin();
		for (; road_it != roads_it->second.end(); road_it++) {
			delete *road_it;
		}
	}
}

void RoadSystem::load_roads(string const &filename) {

	ifstream inf(filename.c_str());
	string from, to;
	int fee, distance;

	while (inf.good()) {

		// Ū���X�o�����B�ت������B�O�ΩM���{��T��
		inf >> from >> to >> fee >> distance;

		if (inf.good()) {

			Road* s = new Road(to, fee, distance);

			// �bcities�e�����[�J����
			if (cities.count(from) == 0) {
				cities[from] = new City(from);
				outgoing_roads[from] = list<Road*>();
			}

			if (cities.count(to) == 0) {
				cities[to] = new City(to);
				outgoing_roads[to] = list<Road*>();
			}

			// �������[�W�D��
			outgoing_roads[from].push_back(s);

		}
	}

	inf.close();
}

//��X���G
void RoadSystem::output_cheapest_route(const string& from,
	const string& to, ostream& out) {

	reset();
	pair<int, int> totals = calc_route(from, to);

	if (totals.first == INT_MAX) {
		out << "�q" << from << "��" << to << "�������s�b�i�F�����|�I" << endl;
	}
	else {
		out << "�q" << from << "��" << to << "�����̫K�y�����|�ݭn��O" << totals.first << "�D���C" << endl;
		out << "�Ӹ��u����" << totals.second << "�����C" << endl;
		cout << recover_route(to) << endl << endl;
	}
}

bool RoadSystem::is_valid_city(const string& name) {

	return cities.count(name) == 1;
}

//���J���S�Ժt��k�p��̵u���|
pair<int, int> RoadSystem::calc_route(string from, string to) {

	// ���u����C���o�U�@�ӶO�γ̧C������
	priority_queue<City*, vector<City*>, Cheapest> candidates;
	City* start_city = cities[from];

	// �N�_�l�����[�J��C��
	start_city->total_fee = 0;
	start_city->total_distance = 0;
	candidates.push(start_city);

	// �p�G�u����C�����ūh�`��
	while (!candidates.empty()) {

		City* visiting_city;
		visiting_city = candidates.top();
		candidates.pop();

		if (!visiting_city->visited) {
			visiting_city->visited = true;

			// �Ͻ��ˬd�P�ӫ����۳s���U������
			list<Road*>::iterator it;
			for (it = outgoing_roads[visiting_city->name].begin();
				it != outgoing_roads[visiting_city->name].end(); ++it) {

				City* next_city = cities[(*it)->destination];
				int next_fee = (*it)->fee + visiting_city->total_fee;

				// ���J���S�Ժt��k�ק�аO�B
				if ((next_fee < next_city->total_fee)
					&& next_city->name != from) {
					next_city->total_fee = next_fee;
					next_city->total_distance =
						(*it)->distance + visiting_city->total_distance;
					next_city->from_city = visiting_city->name;
					candidates.push(next_city);
				}
			}
		}
	}

	// ��^�`��O�ΩM�������|
	if (cities[to]->visited) {
		return pair<int, int>(cities[to]->total_fee, cities[to]->total_distance);
	}
	else {
		return pair<int, int>(INT_MAX, INT_MAX);
	}
}

