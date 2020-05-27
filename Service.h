#pragma once
#include "Repo.h"
#include "Joc.h"
#include "Avion.h"
#include<iostream>

class Service {
private:
	Repo& r;

public:
	Service(Repo& repo) :r(repo) { r = repo; };
	~Service();
	//void addElem(Joc t);
	Joc addAvion(Joc& t, Avion a);
	int delElem(int);
	//int updateElem(int, Joc);
	int getSize();
	void findAvion(Joc&, int, int, int);
	//Joc find(int i);
	map<int, Joc> showElem();
	void clear();
};

