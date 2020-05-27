#pragma once
#include<map>
#include<iostream>
#include "Avion.h"
#include "Joc.h"
using namespace std;
class Repo {
protected:

	map<int, Joc> elem = {};
	int key = 0;
public:
	Repo();
	~Repo();
	//virtual void addElem(Joc)=0;
	int delElem(int i);
	int updateElem(int i, const Joc nou);
	int getSize();
	map<int, Joc> getAll();
	void clearMap();
	Joc find(int i);
	Joc addAvion(Joc& t, Avion a);
	void findAvion(Joc& t, int x, int y, int poz);

};
