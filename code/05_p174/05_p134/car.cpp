#include "stdafx.h"
#include "car.h"  

using namespace std;

//�غc���
car::car(string license, int) :movedTimes(0), license(license) {}
//�Ѻc���
car::~car() {}
//��^�����Q���ʪ�����
int car::getMovedTimes()const
{
	return movedTimes;
}
//��^�������N��
string car::getLicense()const
{
	return license;
}
//���Q���ʮɡA�ݩ�movedTimes�۰ʥ[1
void car::move()
{
	movedTimes++;
}
