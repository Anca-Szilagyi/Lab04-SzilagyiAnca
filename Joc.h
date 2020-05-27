#pragma once
#include<string>
#include <vector>
#include<iostream>
#include "Tabla.h"
#include<map>
#include "Avion.h"
using namespace std;

class Joc{
private:
	//Tabla tablaJoc;
	char matrice[10][10] = {};
	char matriceUpdate[100][100];
	int nrAvioane;
	//std::map<std::int, int> mapOfCoord = {{1,1},{2,2},{3,3},{4,4},{5,5},
	//{6,6},{7,7},{8,8},{9,9},{10,10}};
	std::map<int, string> map = {{1,"A"},{2,"B"},{3,"C"},{4,"D"},{5,"E"},{6,"F"},
		{7,"G"},{8,"H"},{9,"I"},{10,"J"}};
	//int linii;
	//int coloane;
	char tabla[100][100];
	vector<Avion> avioane;
public:
	Joc();
	Joc(int linii, int coloane, char tab[100][100], vector<Avion> avioane);
	//Joc(const Tabla tabla, vector<Avion> av);
	~Joc();
	int getLinii();
	int getColoane();
	//int gameOver();
	Joc findAvion(int x, int y);

	bool verify();
	int getNrAvioane();
	bool validare(char);
	void showTablaAdversar();
	Joc addAvion(Avion);
	char getItemFromPos(int i, int j);
	void setPatrat(int i, int j, char item);
	void deleteAvion(int xVarf, int yVarf, char direction);
	friend ostream& operator<<(ostream& os, const Joc& c);
};