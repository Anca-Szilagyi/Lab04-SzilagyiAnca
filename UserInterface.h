#pragma once
#include "Project.h"
#include "RepositoryArray.h"
#include "Operations.h"

class UserInterface {
private:
	Service service;
	//int undo[100];
	//Project undoStergere[100], undoUpdate[100];
	//int sizeUndo, sizeUndoStergere, sizeUndoUpdate;
	void menu();
	//void undoFunction();
	void adaugare();
	void stergere();
	void update();
	void getAllProjects();
	void minimumNumbers();
	void eliminareProiecteCuRepoArray();

public:
	UserInterface();
	//Project gasesteDupaPozitie(int);

	//int dimensiune();
	void console();

	~UserInterface();
};
