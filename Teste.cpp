#include "Teste.h"
#include "Aplicatie.h"
#include "assert.h"
#include "RepositorySTL.h"
#include <iostream>
#include<stdio.h>
using namespace std;

void appTests() {
	Aplicatie app("GheorgheVasile", "BC95SAS", "ocupat");
	Aplicatie app5("AncaSzilagyi", "BC12ASZ", "liber");
	assert((app == app5)==0);

	assert(strcmp(app.getNume(),"GheorgheVasile")==0);
	assert(strcmp(app.getNrInmatriculare(), "BC95SAS") == 0);
	assert(strcmp(app.getStatus(), "ocupat") == 0);

	char* newName = new char[14];

	strcpy_s(newName, 14, "MariaPopovici");
	app.setNume(newName);
	assert(strcmp(app.getNume(),"MariaPopovici")==0);
}

void repositorySTLTests() {
	Aplicatie app1("GheorgheVasile", "BC95SAS", "ocupat");
	Aplicatie app2("MirceaConstantin", "B89RTR", "liber");
	Aplicatie app3("AlinIonescu", "CJ56OOP", "ocupat");
	Aplicatie app4("CiprianPop", "BC12AAS", "liber");

	RepositorySTL repo;

	repo.addElem(app1);
	assert(repo.dim() == 1);
	repo.addElem(app2);
	repo.addElem(app3);
	repo.addElem(app4);
	assert(repo.dim() == 4);


	list<Aplicatie> elem;
	elem = repo.getAll();
	assert(elem.front() == app1);
	assert(elem.back() == app4);
	//assert(elem.data()[1] == app2);
	//assert(elem.data()[2] == app3);
}
