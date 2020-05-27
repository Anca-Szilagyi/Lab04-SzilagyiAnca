#include "UI.h"


Avion UI::ghicesteAvion() {

	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v2 = { 1,2,3,4,5,6,7,8,9,10 };
	auto item = v2.begin();
	std::advance(item, rand() % v2.size());
	auto it = v1.begin();
	std::advance(it, rand() % v1.size());
	int x = *item;
	int y = *it;
	cout << y << " " << x << endl;
	Avion a(x, y, "\0");
	tablaJucator.findAvion(x, y);
	return a;
	//int y = rand() % 10 + 1;
}
void UI::createTablaC() {

	int contor = 0;
	while (contor < 3) {

		std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
		std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
		std::map<int, string> Map1 = { {1,"u"},{2,"d"},{3,"l"},{4,"r"} };
		auto item = v1.begin();
		std::advance(item, rand() % v1.size());
		auto it = v.begin();
		std::advance(it, rand() % v.size());
		auto item1 = Map1.begin();
		std::advance(item1, rand() % Map1.size());
		int x = *item;
		int y = *it;
		string orientare = item1->second;
		try {
			Avion a(x, y, orientare);
			s->addAvion(tablaComputer, a);
			contor++;
		}
		catch (...) {
		}
	}
}
void UI::createTablaJ() {

	int x;
	int y;
	string orientare;
	cout << " x: "; cin >> x;
	cout << " y: "; cin >> y;
	cout << " orientare: "; cin >> orientare;
	Avion a(x, y, orientare);
	s->addAvion(tablaJucator, a);
	cout << tablaJucator << endl;

}

void UI::playGame() {
	int y;
	int x;

	do {
		cout << "Your turn" << endl;
		cout << "Plane:" << endl;
		cout << "x: "; cin >> x;
		cout << "y: "; cin >> y;
		tablaComputer.findAvion(x, y);
		cout << "Enemy's game board: " << endl;
		tablaComputer.showTablaAdversar();
		cout << "Computers' turn" << endl;
		Avion a = ghicesteAvion();
		tablaJucator.findAvion(a.getX(), a.getY());

	} while (tablaComputer.getNrAvioane() > 0 && tablaJucator.getNrAvioane() > 0);

	if (tablaJucator.getNrAvioane() > 0) cout << "Ai castigat!!!";
	else
		cout << "Game over.";
}
void UI::printMenu() {

	int contor = 0;
	cout << endl;
	bool gata = false;
	while (!gata) {
		cout << endl;
		std::cout << "\n";
		std::cout << "1. Creeaza tabla de joc" << std::endl;
		std::cout << "2. Incepe jocul :)" << std::endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {
			try {
				cout << "E nevoie sa aplasezi pentru inceput 3 avioane." << endl;
				while (contor < 3) {
					cout << "Avion " << contor + 1 << endl;
					createTablaJ();

					contor++;
				}

				createTablaC();
			}
			catch (exception& e) { cout << "Uppsssss." << "->"; cout << e.what(); } break; }
		case 2: {
			if (tablaComputer.getNrAvioane() > 0 && tablaJucator.getNrAvioane() > 0)playGame();
			else {
				cout << "Jocul nu poate incepe. Construiti mai intai tabla de joc.";
			}
			gata = true;
			cout << endl;
			break;
		}
		default: {cout << "Optiunea nu exista. Alegeti una valida:" << endl; }
		}
	}
}
void UI::showUI() {

	bool gata = false;
	cout << endl;
	while (!gata) {
		std::cout << "(1): Start" << endl;
		std::cout << "(2): Exit" << endl;
		int opt; cin >> opt;
		switch (opt) {
		case 1: {
			tablaJucator = *new Joc();
			tablaComputer = *new Joc();
			printMenu(); break; }
		case 2: { exit(0); }
		}
	}
}

/*
//UI::UI(Service s) {  }
Avion UI::ghicesteAvion() {

	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v2 = { 1,2,3,4,5,6,7,8,9,10 };
	auto item = v1.begin();
	std::advance(item, rand() % v1.size());
	auto it = v2.begin();
	std::advance(it, rand() % v2.size());
	int x = *item;
	int y = *it;
	cout << y << " " << x << endl;
	Avion a(x, y, "\0");
	tablaJucatorucator.findAvion(x, y);
	return a;
	//int y = rand() % 10 + 1;
}

void UI::createTablaC() {

	int contor = 0;
	while (contor < 3) {

		std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
		std::vector<int> v2 = { 1,2,3,4,5,6,7,8,9,10 };
		std::map<int, string> Map1 = { {1,"u"},{2,"d"},{3,"l"},{4,"r"} };
		auto item = v1.begin();
		std::advance(item, rand() % v1.size());
		auto it = v2.begin();
		std::advance(it, rand() % v2.size());
		auto item1 = Map1.begin();
		std::advance(item1, rand() % Map1.size());
		int x = *item;
		int y = *it;
		string orientare = item1->second;
		try {
			Avion a(x, y, orientare);
			s->addAvion(tablaComputeromputer, a);
			contor++;
		}
		catch (...) {
		}
	}
}

void UI::createTablaJ() {

	int x;
	int y;
	string orientare;
	cout << " x: "; cin >> x;
	cout << " y: "; cin >> y;
	cout << " orientare: "; cin >> orientare;
	Avion a(x, y, orientare);
	s->addAvion(tablaJucatorucator, a);
	cout << tablaJucatorucator << endl;

}


void UI::playGame() {
	int y;
	int x;

	do {
		cout << "- Your turn -" << endl;
		cout << "Avion:" << endl;
		cout << "x: "; cin >> x;
		cout << "y: "; cin >> y;
		tablaComputeromputer.findAvion(x, y);
		cout << "Computer board: " << endl;
		tablaComputeromputer.showTablaAdversar();
		cout << "- Computers' turn -" << endl;
		Avion a = ghicesteAvion();
		tablaJucatorucator.findAvion(a.getX(), a.getY());

	} while (tablaComputeromputer.getNrAvioane() > 0 && tablaJucatorucator.getNrAvioane() > 0);

	if (tablaJucatorucator.getNrAvioane() > 0) cout << "Ai castigat!!!";
	else
		cout << "Game over.";
}

void UI::printMenu() {

	int contor = 0;
	cout << endl;
	bool gata = false;
	while (!gata) {
		cout << endl;
		std::cout << "\n";
		std::cout << "1. Adaugare avioane" << std::endl;
		std::cout << "2. Incepe jocul" << std::endl;
		int yourOption;
		cin >> yourOption;
		switch (yourOption) {
		case 1: {
			try {
				while (contor < 3) {
					cout << "Avion " << contor + 1 << endl;
					createTablaJ();
					contor++;
				}

				createTablaC();
			}
			catch (exception& e) { cout << "Uppsssss." << "->"; cout << e.what(); } break; }
		case 2: {
			if (tablaComputeromputer.getNrAvioane() > 0 && tablaJucatorucator.getNrAvioane() > 0)playGame();
			else {
				cout << "Jocul nu poate incepe.Creati mai intai tabla de joc.";
			}
			gata = true;
			cout << endl;
			break;
		}
		default: {cout << "Optiunea nu exista... alegeti alta:" << endl; }
		}
	}
}

void UI::showUI() {

	bool gata = false;
	cout << endl;
	while (!gata) {
		std::cout << "1. Start" << endl;
		std::cout << "2. Exit" << endl;
		int opt; cin >> opt;
		switch (opt) {
		case 1: {
			tablaJucatorucator = *new Joc();
			tablaComputeromputer = *new Joc();
			printMenu(); break; }
		case 2: { exit(0); }
		}
	}
}

//heeeeeeeeeeere















/*void UI::add() {

	int xVarf, yVarf;
	string direction;

	cout << "x varf: "; cin >> xVarf;
	cout << "y varf: "; cin >> yVarf;
	cout << "Direction (u, d, l, r): "; cin >> direction;
	Avion plane(xVarf, yVarf, direction);
	s->addPlane(plane);
}

void UI::hit() {
	cout << "Introduceti coordonatele punctului pe care doriti sa il loviti..." << endl;
	int x, y;
	string direction;
	cout << "x varf: "; cin >> x;
	cout << "y varf: "; cin >> y;
	cout << "Direction (u, d, l, r): "; cin >> direction;
	int response = s->hit(x, y);
	if (response == 0) cout << "aer" << endl;
	else if (response == 1) cout << "lovit" << endl;
	else if (response == 2) cout << "distrus" << endl;
}
void UI::afisare() {
	for (int i = 0; i <= s->jocPlayer.getLinii(); i++) {

		for (int j = 0; j <= s->jocPlayer.getColoane(); j++) {
			if (j == 0) {
				if (i != 0 && i != s->jocPlayer.getLinii()) {
					if (i < 10) cout << i << " ";
					else cout << i;
				}
			}
			cout << s->jocPlayer.getItemFromPos(i, j) << "  ";
		}
		cout << endl;
	}
}

void UI::pcHit() {
	int response = s->pcHit();
	if (response == 0) cout << "aer" << endl;
	else if (response == 1) cout << "lovit" << endl;
	else if (response == 2) cout << "distrus" << endl;
}

void UI::PrintMenu()
{
	cout << endl;
	while (true) {
		cout << endl;
		std::cout << "\n";
		std::cout << "--- Main Menu ---" << std::endl;
		std::cout << "Alegeti o optiune: " << std::endl;
		std::cout << "1: Adaugare avion" << std::endl;
		std::cout << "2: Incepe jocul" << std::endl;
		std::cout << "3: Exit" << std::endl;
		int yourOption;
		cin >> yourOption;
		switch (yourOption) {
		case 1: {add(); break; }
		case 2: {
			//while (s->gata()==0) 
			//{
				hit();
				pcHit();
				afisare();
			//}
			//if (s->gata() == 1) cout << "Ati castigat!!!" << endl;
			//else if (s->gata() == 2) cout << "Calculatorul a castigat... :(" << endl;
			break;
		}
		case 3: {  cout << "O zi minunata! :)" << endl; exit(0); }
		default: {cout << "Optiunea cu exista! Va rugam sa alegeti una dintre cele existente. :)" << endl; }
		}
	}
}*/
