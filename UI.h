#pragma once
#include "Service.h"
#include "Repo.h"
#include "Joc.h"
#include<map>
#include<vector>

class UI {
private:
	Service* s;
	Joc tablaJucator;
	Joc tablaComputer;
	void createTablaJ();
	void createTablaC();
	void printMenu();
	Avion ghicesteAvion();
	void playGame();
	///*void add();
	//void hit();
	////void PrintMenu();
	//void pcHit();

public:
	UI(Service& serv) :s(&serv) {  };
	~UI() {}
	void showUI();
};