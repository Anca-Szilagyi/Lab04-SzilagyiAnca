#include "Tests.h"
#include "Project.h"
#include "Operations.h"
#include "assert.h"
#include "RepositoryArray.h"
#include <iostream>
using namespace std;

void repositoryArrayTests() {
	Project p1("Laborator05 - student 007", 7, 3);
	Project p2("Laborator05 - student 014", 5, 3);
	Project p3("Laborator05 - student 015", 6, 0);
	Project p4("Laborator05 - student 017", 7, 4);
	Project p5("Laborator05 - student 009", 12, 5);
	assert(p2.getNoOfBranches() == 5);
	assert(p3.getNoOfCommits() == 0);
	RepositoryArray repo;
	repo.addElem(p1);
	repo.addElem(p2);
	assert(repo.dim() == 2);

	repo.addElem(p3);
	repo.addElem(p4);
	assert(repo.findElem(p3) == 2);
	repo.delElem(p1);
	assert(repo.dim() == 3);

	assert(repo.getAll()[0] == p4);
	p4.setNoOfBranches(6);
	assert(p4.getNoOfBranches() == 6);
}


void testeService() {
	Project p1("Laborator05 - student 007", 0, 3);
	Project p2("Laborator05 - student 014", 5, 0);
	Project p3("Laborator05 - student 015", 6, 0);
	Project p4("Laborator05 - student 017", 7, 4);
	Project p5("Laborator05 - student 009", 12, 5);
	Service serv;
	serv.addProject(p1);
	serv.addProject(p2);
	serv.addProject(p3);
	serv.addProject(p4);
	serv.addProject(p5);
	
	assert(serv.getAllProjects()[0] == p1);
	assert(serv.getItemFromPosition(1) == p2);
	assert(serv.findProject(p3) == 2);
	assert(serv.sizeee() == 5);

	serv.delProject(p5);
	assert(serv.sizeee() == 4);
	serv.addProject(p5);

	serv.eliminareProiecteCuRepoArray();
	assert(serv.findProject(p1)==-1);
	assert(serv.getItemFromPosition(1) == p4);
}


