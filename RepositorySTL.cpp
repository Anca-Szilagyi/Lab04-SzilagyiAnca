#include "RepositorySTL.h"
#include <stdio.h>

RepositorySTL::RepositorySTL()
{
}

void RepositorySTL::addElem(Aplicatie s) {
	//int ok = 1;
	//for (int i = 0; i < elem.size(); i++) 
		//if (strcmp(s.getNume(), elem[i].getNume()) == 0) ok = 0;
	elem.push_back(s);
	//aici de adaugat o eroare daca nu se adauga in lista.
	//va adauga la sf vectorului, elementul s;
}

list<Aplicatie> RepositorySTL::getAll() {
	return elem;
}
int RepositorySTL::dim() {
	return elem.size();
}

RepositorySTL::~RepositorySTL()
{}



/*void RepositorySTL::updateElem(Student s, char* gitPath, int v, int u) {
	for (int i = 0; i < elem.size(); i++)
		if (elem[i] == s) { elem[i].setGitPath(gitPath); elem[i].setNoOfBranches(v); elem[i].setNoOfCommits(u), return; }

}*/

/*void RepositorySTL::delElem(Project s) {
	vector<Project>::iterator it;
	//imi permite sa decuplez felul in care se parcurge o struct de date
	it = find(elem.begin(), elem.end(), s);
	//de la inceput pana la sfarsit il caut pe s
	//it va fi pozitia lui s daca exista. altfel - NULL.
	if (it != elem.end()) elem.erase(it);
	//daca il gasesc, il sterg

}

bool RepositorySTL::findElem(Project s) {
	vector<Project>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) return true;
	return false;

}*/
/*Student RepositorySTL::getItemFromPos(int i) {
	return elem[i];
}*/