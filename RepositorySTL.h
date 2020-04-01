#pragma once
#include "Aplicatie.h"
#include <list>
#include<iterator>

using namespace std;

class RepositorySTL
{
private:
	list<Aplicatie> elem;

public:
	RepositorySTL();
	void addElem(Aplicatie);
	//bool findElem(Aplicatie);
	//void delElem(Project);
	//void updateElem(Project, char*, int, int);
	//Project getItemFromPos(int);
	list<Aplicatie> getAll();
	int dim();
	~RepositorySTL();
};
