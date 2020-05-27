#include "UI.h"
/*
char calculator[13][13];
int lin, col;
char tablaPlayer[13][13];
*/
using namespace std;
int op;
int main() {
	/*vector<Avion> planes;
	//Tabla t1(12, 12, tab);
	cout << "All good in here!" << endl;
	cout<<"1. incepe jocul"<<endl;
	cout << "2. adaugare avion" << endl;
	cin >> op;
	if (op == 1) {
		Avion a1(3, 1, "l");
		planes.push_back(a1);

		Joc game(12, 12, tablaPlayer, planes);
		game.addAvion(a1);
		cout << game;

	}
	else {
		cout << "X varf: ";
		int xVarf, yVarf;
		string poz;
		cin >> xVarf;
		cout << "yVarf: ";
		cin >> yVarf;
		cout << "directia(l, r, u, d) ";
		cin >> poz;
		Avion a2(xVarf, yVarf, poz);
		planes.push_back(a2);
		Joc game(12, 12, tablaPlayer, planes);
		game.addAvion(a2);
		cout << game;
	}*/
	//for(int i=1; i<=game.t1.getLinii(); i++)
		//for
	//cout << game;*/

	/*
	vector<Avion> pcPlanes;
	Avion plane1(3, 1, "l");
	Avion plane2(1, 7, "u");
	Avion plane3(4, 8, "r");
	pcPlanes.push_back(plane1);
	pcPlanes.push_back(plane2);
	pcPlanes.push_back(plane3);
	Repo<Avion> playerPlanes;
	Joc jocCalculator(10, 10, calculator, pcPlanes);
	Joc jocPlayer(10, 10, tablaPlayer, playerPlanes.getAll());
	//Service s;
	Service s(jocCalculator, jocPlayer);
	UI ui(s);
	ui.PrintMenu();
	return 0;*/



	Repo r;
	Service s{ r };
	UI u{s};
	u.showUI();
	return 0;
}


