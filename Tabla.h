#pragma once
#include<vector>
#include <iostream>
using namespace std;
class Tabla {
private:
	int linii;
	int coloane;
	char tabla[100][100];
public:
	Tabla();
	Tabla(int l, int c, char p[100][100]);
	Tabla(const Tabla&);
	~Tabla();
	//Tabla(string, string);
	//string toStringCSV();
	//string toStringHTML();
	char getPatrat(int linie, int coloana);
	int getLinii();
	int getColoane();
	//char **getTabla();
	void setPatrat(int, int, const char);
	void setLinii(int);
	void setTabla(const char tablaDeJoc[100][100], int l, int c);
	void setColoane(int);
	Tabla& operator=(const Tabla&);
	bool operator==(const Tabla&);
	friend ostream& operator<<(ostream& os, const Tabla& c);
};