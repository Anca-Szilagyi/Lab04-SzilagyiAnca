#include"Joc.h"
#include <string.h>

Joc::Joc() {
	this->nrAvioane = 0;
	for (int i = 1; i < getLinii(); i++)
		for (int j = 1; j <= 10; j++)
			this->tabla[i][j] = '.';
}
Joc::~Joc() {
	
}
int Joc::getLinii() {
	return 10;
}
void Joc::setPatrat(int i, int j, char item) {
	this->tabla[i][j] = item;
}
int Joc::getColoane() {
	return 10;
}
Joc::Joc(int linii, int coloane, char tab[100][100], vector<Avion> av)  {
	Avion a;
	while (av.size() > 0) {
		a = av.front();
		this->avioane.push_back(a);
		av.erase(av.begin());
	} 
	//planes integrations part;
	if (this->avioane.size() > 0) {
		Avion thisOne;
		do {
			thisOne = this->avioane.back();
			this->tabla[thisOne.getX()][thisOne.getX()] = '<';
			if (thisOne.getOrientareCoada() == "l") {
				this->tabla[thisOne.getX()][thisOne.getY()] ='<';
				this->tabla[thisOne.getX()][thisOne.getY() + 1] = '<';
				this->tabla[thisOne.getX() - 1][thisOne.getY() + 1] = '<';
				this->tabla[thisOne.getX() + 1][thisOne.getY() + 1] = '<';
				this->tabla[thisOne.getX() - 2][thisOne.getY() + 1] = '<';
				this->tabla[thisOne.getX() + 2][thisOne.getY() + 1] = '<';
				this->tabla[thisOne.getX()][thisOne.getY() + 2] = '<';
				this->tabla[thisOne.getX()][thisOne.getY() + 3] = '<';
				this->tabla[thisOne.getX() - 1][thisOne.getY() + 3] = '<';
				this->tabla[thisOne.getX() + 1][thisOne.getY() + 3] = '<';

			}
			else if (thisOne.getOrientareCoada() == "r") {
				this->tabla[thisOne.getX()][thisOne.getY()] = '>';
				this->tabla[thisOne.getX()][thisOne.getY() - 1] = '>';
				this->tabla[thisOne.getX() - 1][thisOne.getY() - 1] = '>';
				this->tabla[thisOne.getX() + 1][thisOne.getY() - 1] = '>';
				this->tabla[thisOne.getX() - 2][thisOne.getY() - 1] = '>';
				this->tabla[thisOne.getX() + 2][thisOne.getY() - 1] = '>';
				this->tabla[thisOne.getX()][thisOne.getY() - 2] = '>';
				this->tabla[thisOne.getX()][thisOne.getY() - 3] = '>';
				this->tabla[thisOne.getX() - 1][thisOne.getY() - 3] = '>';
				this->tabla[thisOne.getX() + 1][thisOne.getY() - 3] = '>';

			}
			else if (thisOne.getOrientareCoada() == "u") {

				this->tabla[thisOne.getX()][thisOne.getY()]= '^';
				this->tabla[thisOne.getX() + 1][thisOne.getY()] = '^';
				this->tabla[thisOne.getX() + 1][thisOne.getY() - 1] = '^';
				this->tabla[thisOne.getX() + 1][thisOne.getY() + 1] = '^';
				this->tabla[thisOne.getX() + 1][thisOne.getY() - 2] = '^';
				this->tabla[thisOne.getX() + 1][thisOne.getY() + 2] = '^';
				this->tabla[thisOne.getX() + 2][thisOne.getY()] = '^';
				this->tabla[thisOne.getX() + 3][thisOne.getY()] = '^';
				this->tabla[thisOne.getX() + 3][thisOne.getY() - 1] = '^';
				this->tabla[thisOne.getX() + 3][thisOne.getY() + 1] = '^';

			}
			else if (thisOne.getOrientareCoada() == "d") {
				this->tabla[thisOne.getX()][thisOne.getY()]= 'v';
				this->tabla[thisOne.getX() - 1][thisOne.getY()] = 'v';
				this->tabla[thisOne.getX() - 1][thisOne.getY() - 1] = 'v';
				this->tabla[thisOne.getX() - 1][thisOne.getY() + 1] = 'v';
				this->tabla[thisOne.getX() - 1][thisOne.getY() - 2] = 'v';
				this->tabla[thisOne.getX() - 1][thisOne.getY() + 2] = 'v';
				this->tabla[thisOne.getX() - 2][thisOne.getY()] = 'v';
				this->tabla[thisOne.getX() - 3][thisOne.getY()] = 'v';
				this->tabla[thisOne.getX() - 3][thisOne.getY() - 1] = 'v';
				this->tabla[thisOne.getX() - 3][thisOne.getY() + 1] = 'v';
			}

			avioane.pop_back();
		} while (this->avioane.size() > 0);
		for (int x = 1; x < 10; x++) {
			for (int y = 1; y < this->getColoane(); y++)
				if (this->tabla[x][y] != '<' && this->tabla[x][y] != '^' && this->tabla[x][y] != '>' && this->tabla[x][y] != 'v')
					this->tabla[x][y] = '.';
		}
	}
	
}



void Joc::deleteAvion(int xVarf, int yVarf, char direction) {
	this->tabla[xVarf][yVarf] = '.';
	if (direction == 'd') {
		this->tabla[xVarf - 1][yVarf]='.';
		this->tabla[xVarf - 1][yVarf - 1] = '.';
		this->tabla[xVarf - 1][yVarf + 1] = '.';
		this->tabla[xVarf - 1][yVarf - 2] = '.';
		this->tabla[xVarf - 1][yVarf + 2]= '.';
		this->tabla[xVarf - 2][yVarf] = '.';
		this->tabla[xVarf - 3][yVarf] = '.';
		this->tabla[xVarf - 3][yVarf - 1] = '.';
		this->tabla[xVarf - 3][yVarf + 1] = '.';
	}
	else if (direction == 'u') {
		this->tabla[xVarf + 1][yVarf] = '.';
		this->tabla[xVarf + 1][yVarf - 1] = '.';
		this->tabla[xVarf + 1][yVarf + 1] = '.';
		this->tabla[xVarf + 1][yVarf - 2] = '.';
		this->tabla[xVarf + 1][yVarf + 2] = '.';
		this->tabla[xVarf + 2][yVarf] = '.';
		this->tabla[xVarf + 3][yVarf] = '.';
		this->tabla[xVarf + 3][yVarf - 1] = '.';
		this->tabla[xVarf + 3][yVarf + 1] = '.';
	}
	else if (direction == 'l') {
		this->tabla[xVarf][yVarf + 1] = '.';
		this->tabla[xVarf - 1][yVarf + 1] = '.';
		this->tabla[xVarf + 1][yVarf + 1] = '.';
		this->tabla[xVarf - 2][yVarf + 1] = '.';
		this->tabla[xVarf + 2][yVarf + 1] = '.';
		this->tabla[xVarf][yVarf + 2] = '.';
		this->tabla[xVarf][yVarf + 3] = '.';
		this->tabla[xVarf - 1][yVarf + 3] = '.';
		this->tabla[xVarf + 1][yVarf + 3] = '.';

	}
	else if (direction == 'r') {
		this->tabla[xVarf][yVarf - 1] ='.';
		this->tabla[xVarf - 1][yVarf - 1] = '.';
		this->tabla[xVarf + 1][yVarf - 1] = '.';
		this->tabla[xVarf - 2][yVarf - 1] = '.';
		this->tabla[xVarf + 2][yVarf - 1] = '.';
		this->tabla[xVarf][yVarf - 2] = '.';
		this->tabla[xVarf][yVarf - 3] = '.';
		this->tabla[xVarf - 1][yVarf - 3] = '.';
		this->tabla[xVarf + 1][yVarf - 3] = '.';

	}
}

Joc Joc::addAvion(Avion a) {


	int x = a.getX();
	int y = a.getY();

	if (matrice[x][y] == '.') {
		matrice[x][y] = '*';
	}
	else throw(exception("Avionul nu poate fi incadrat in tabla de joc.Incercati din nou!"));

		

	//std::map<std::string, int> mapOfStrings = { {"d",1},{"u",2},{"r",3},{"l",4} };
	//switch (mapOfStrings.at(a.getOrientareCoada())) {

	if (a.getOrientareCoada()=="d") {
			if (validare(matrice[x - 1][y - 1]) == true
				&& validare(matrice[x - 1][y - 2]) == true
				&& validare(matrice[x - 1][y + 1]) == true
				&& validare(matrice[x - 1][y + 2] == true)
				&& validare(matrice[x - 1][y]) == true
				&& validare(matrice[x - 2][y]) == true
				&& validare(matrice[x - 3][y]) == true
				&& validare(matrice[x - 3][y - 1]) == true
				&& validare(matrice[x - 3][y + 1]) == true
				&& (x - 1) >= 1
				&& (x - 2) >= 1
				&& (x - 3) >= 1
				&& (y - 1) >= 1
				&& (y + 1) <= 10
				&& (y - 2) >= 1
				&& (y + 2) <= 10) {

				matrice[x - 1][y - 1] = matrice[x - 1][y - 2] = 'v'; // aripa stanga
				matrice[x - 1][y + 1] = matrice[x - 1][y + 2] = 'v'; // aripa dreapta
				matrice[x - 1][y] = matrice[x - 2][y] = matrice[x - 3][y] = 'v'; // corp
				matrice[x - 3][y - 1] = matrice[x - 3][y + 1] = 'v'; // coada
			}

			else {
				matrice[x][y] = '.';
				throw(exception("Avionul nu poate fi incadrat in tabla de joc.Incercati din nou!"));
			}
			//break;
		}
	
	else if(a.getOrientareCoada()=="u"){
		if (validare(matrice[x + 1][y - 1]) == true
			&& validare(matrice[x + 1][y - 2]) == true
			&& validare(matrice[x + 1][y + 1]) == true
			&& validare(matrice[x + 1][y + 2]) == true
			&& validare(matrice[x + 1][y]) == true
			&& validare(matrice[x + 2][y]) == true
			&& validare(matrice[x + 3][y]) == true
			&& validare(matrice[x + 3][y - 1]) == true
			&& validare(matrice[x + 3][y + 1]) == true
			&& (x + 1) <= 10
			&& (x + 2) <= 10
			&& (x + 3) <= 10
			&& (y - 1) >= 1
			&& (y + 1) <= 10
			&& (y - 2) >= 1
			&& (y + 2) <= 10) {

			matrice[x + 1][y - 1] = matrice[x + 1][y - 2] = '^'; // aripa stanga
			matrice[x + 1][y + 1] = matrice[x + 1][y + 2] = '^'; // aripa dreapta
			matrice[x + 1][y] = matrice[x + 2][y] = matrice[x + 3][y] = '^'; // corp
			matrice[x + 3][y - 1] = matrice[x + 3][y + 1] = '^'; // coada
		}
		else {
			matrice[x][y] = '.';
			throw(exception("Avionul nu poate fi incadrat in tabla de joc.Incercati din nou!"));
		}
		//break;
	}
	else if (a.getOrientareCoada() == "l") {
		if (validare(matrice[x + 1][y + 1]) == true
			&& validare(matrice[x + 2][y + 1]) == true
			&& validare(matrice[x + 1][y + 1]) == true
			&& validare(matrice[x + 1][y + 2]) == true
			&& validare(matrice[x][y + 1]) == true
			&& validare(matrice[x][y + 2]) == true
			&& validare(matrice[x][y + 3]) == true
			&& validare(matrice[x - 1][y + 3]) == true
			&& validare(matrice[x + 1][y + 3]) == true
			&& (x - 1) >= 1
			&& (x + 1) <= 10
			&& (x - 2) >= 1
			&& (x + 2) <= 10
			&& (y + 1) <= 10
			&& (y + 3) <= 10) {

			matrice[x + 1][y + 1] = matrice[x + 2][y + 1] = '>'; // aripa stanga
			matrice[x - 1][y + 1] = matrice[x - 2][y + 1] = '>'; // aripa dreapta
			matrice[x][y + 1] = matrice[x][y + 2] = matrice[x][y + 3] = '>'; // corp
			matrice[x - 1][y + 3] = matrice[x + 1][y + 3] = '>'; // coada
		}
		else {
			matrice[x][y] = '.';
			throw(exception("Avionul nu poate fi incadrat in tabla de joc.Incercati din nou!"));
		}
		//break;
	}
	else if (a.getOrientareCoada() == "r") {
		if (validare(matrice[x - 1][y - 1]) == true
			&& validare(matrice[x - 2][y - 1]) == true
			&& validare(matrice[x + 1][y - 1]) == true
			&& validare(matrice[x + 2][y - 1]) == true
			&& validare(matrice[x][y - 1]) == true
			&& validare(matrice[x][y - 2]) == true
			&& validare(matrice[x][y - 3]) == true
			&& validare(matrice[x - 1][y - 3]) == true
			&& validare(matrice[x + 1][y - 3]) == true
			&& (x - 1) >= 1
			&& (x + 1) <= 10
			&& (x - 2) >= 1
			&& (x + 2) <= 10
			&& (y - 1) >= 1
			&& (y - 3) >= 1) {

			matrice[x - 1][y - 1] = matrice[x - 2][y - 1] = '<'; // aripa stanga
			matrice[x + 1][y - 1] = matrice[x + 2][y - 1] = '<'; // aripa dreapta
			matrice[x][y - 1] = matrice[x][y - 2] = matrice[x][y - 3] = '<'; // corp
			matrice[x - 1][y - 3] = matrice[x + 1][y - 3] = '<'; // coada
		}
		else {
			matrice[x][y] = '.';
			throw(exception("Avionul nu poate fi incadrat in tabla de joc.Incercati din nou!"));
		}
		//break;
	}
	//default: {
		//cout << " out";
	//}

	
	nrAvioane++;
	return *this; 
}


	/*int x = thisOne.getX();
	int y = thisOne.getY();
	
	
	if (thisOne.getOrientareCoada() == "l") {
		if (this->tabla[x][y] == '.') {
			this->tabla[thisOne.getX()][thisOne.getY()] = '<';
			this->tabla[thisOne.getX()][thisOne.getY() + 1] = '<';
			this->tabla[thisOne.getX() - 1][thisOne.getY() + 1] = '<';
			this->tabla[thisOne.getX() + 1][thisOne.getY() + 1] = '<';
			this->tabla[thisOne.getX() - 2][thisOne.getY() + 1] = '<';
			this->tabla[thisOne.getX() + 2][thisOne.getY() + 1] = '<';
			this->tabla[thisOne.getX()][thisOne.getY() + 2] = '<';
			this->tabla[thisOne.getX()][thisOne.getY() + 3] = '<';
			this->tabla[thisOne.getX() - 1][thisOne.getY() + 3] = '<';
			this->tabla[thisOne.getX() + 1][thisOne.getY() + 3] = '<';
		}
	}
	else if (thisOne.getOrientareCoada() == "r") {
		this->tabla[thisOne.getX()][thisOne.getY()] = '>';
		this->tabla[thisOne.getX()][thisOne.getY() - 1] = '>';
		this->tabla[thisOne.getX() - 1][thisOne.getY() - 1] = '>';
		this->tabla[thisOne.getX() + 1][thisOne.getY() - 1] = '>';
		this->tabla[thisOne.getX() - 2][thisOne.getY() - 1] = '>';
		this->tabla[thisOne.getX() + 2][thisOne.getY() - 1] = '>';
		this->tabla[thisOne.getX()][thisOne.getY() - 2] = '>';
		this->tabla[thisOne.getX()][thisOne.getY() - 3] = '>';
		this->tabla[thisOne.getX() - 1][thisOne.getY() - 3] = '>';
		this->tabla[thisOne.getX() + 1][thisOne.getY() - 3] = '>';

	}
	else if (thisOne.getOrientareCoada() == "u") {

		this->tabla[thisOne.getX()][thisOne.getY()] = '^';
		this->tabla[thisOne.getX() + 1][thisOne.getY()] = '^';
		this->tabla[thisOne.getX() + 1][thisOne.getY() - 1] = '^';
		this->tabla[thisOne.getX() + 1][thisOne.getY() + 1] = '^';
		this->tabla[thisOne.getX() + 1][thisOne.getY() - 2] = '^';
		this->tabla[thisOne.getX() + 1][thisOne.getY() + 2] = '^';
		this->tabla[thisOne.getX() + 2][thisOne.getY()] = '^';
		this->tabla[thisOne.getX() + 3][thisOne.getY()] = '^';
		this->tabla[thisOne.getX() + 3][thisOne.getY() - 1] = '^';
		this->tabla[thisOne.getX() + 3][thisOne.getY() + 1] = '^';

	}
	else if (thisOne.getOrientareCoada() == "d") {
		this->tabla[thisOne.getX()][thisOne.getY()] = 'v';
		this->tabla[thisOne.getX() - 1][thisOne.getY()] = 'v';
		this->tabla[thisOne.getX() - 1][thisOne.getY() - 1] = 'v';
		this->tabla[thisOne.getX() - 1][thisOne.getY() + 1] = 'v';
		this->tabla[thisOne.getX() - 1][thisOne.getY() - 2] = 'v';
		this->tabla[thisOne.getX() - 1][thisOne.getY() + 2] = 'v';
		this->tabla[thisOne.getX() - 2][thisOne.getY()] = 'v';
		this->tabla[thisOne.getX() - 3][thisOne.getY()] = 'v';
		this->tabla[thisOne.getX() - 3][thisOne.getY() - 1] = 'v';
		this->tabla[thisOne.getX() - 3][thisOne.getY() + 1] = 'v';
	}
	this->nrAvioane++;
	return *this;*/

bool Joc::verify() {

	if (this->nrAvioane == 0)
		return false;
	return true;
}
bool Joc::validare(char item) {

	if (item == '.')
		return true;
	else
		return false;
}

Joc Joc::findAvion(int x, int y) {

	if (this->matrice[x][y] == '.') {

		matriceUpdate[x][y] = 'A';
	}
	else
		if (matrice[x][y] == '<' || matrice[x][y] == '>' || matrice[x][y] == 'v' || matrice[x][y] == '^') {
			matriceUpdate[x][y] = 'L';
		}
		else {
			matriceUpdate[x][y] = 'D';
			nrAvioane--;
		}
	return *this;
}

char Joc::getItemFromPos(int i, int j) {
	return this->tabla[i][j];
}

/*int Joc::gameOver() {
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			if (this->tabla[i][j] == '<' || this->tabla[i][j] == '>' || this->tabla[i][j] == 'v' || this->tabla[i][j] == '^')
			
				return 0;
			
	
	return 1;
}*/

/*int Joc::getLin() {
	return this->getLinii();
}
int Joc::getCol() {
	return this->getColoane();
}*/


ostream& operator<<(ostream& os, const Joc& t) {

	os << "   " << 1 << "|" << 2 << "|" << 3 << "|" << 4 << "|" << 5 << "|" << 6 << "|" << 7 << "|" << 8 << "|" << 9 << "|" << 10 << "|" << endl;
	os << endl;
	int k = 0;
	for (int i = 1; i <= 10; i++) {
		os << i << " " << "|";

		for (int j = 1; j <= 10; j++) {
			if (j == 10) { os << t.matrice[i][j] << " " << "|"; }
			else
				os << t.matrice[i][j] << "|";
		}
		cout << endl;
	}

	return os;
}
void Joc::showTablaAdversar() {

	cout << "   " << 1 << "|" << 2 << "|" << 3 << "|" << 4 << "|" << 5 << "|" << 6 << "|" << 7 << "|" << 8 << "|" << 9 << "|" << 10 << "|" << endl;
	cout << endl;
	int k = 0;
	for (int i = 1; i <= 10; i++) {
		cout << i << " " << "|";

		for (int j = 1; j <= 10; j++) {
			if (j == 10) { cout << matriceUpdate[i][j] << " " << "|"; }
			else
				cout << matriceUpdate[i][j] << "|";
		}
		cout << endl;
	}

}
int Joc::getNrAvioane() {
	return this->nrAvioane;
}



/*ostream& operator<<(ostream& os, Joc& a) {
	for (int i = 0; i <= a.getLinii(); i++) {

		for (int j = 0; j <= a.getColoane(); j++) {
			
			if (j == 0) {
				if (i != 0 && i != a.getLinii()) {
					if (i < 10) cout << i << " ";
					else cout << i;
				}
			}
			os << a.getItemFromPos(i, j) << "  ";
		}
		os << endl;
	}

	return os;
	
	//os << "Coordonata X: " << a.xVarf << "|" << " Coordonata Y: " << a.yVarf << "|" << " Orientare coada:" << a.orientare;
}*/








/*Joc::Joc(int linii, int coloane, char tab[100][100], vector<Avion> av):Tabla(linii, coloane, tab) {
	//this->tablaJoc = tabla;
	Avion a;
	do {
		a = av.back();
		this->avioane.push_back(a);
		av.pop_back();
	} while (av.size()>0);
	//planes integrations part;

	Avion thisOne;
	do {
		thisOne = this->avioane.back();
		this->tabla[thisOne.getX(), thisOne.getY(), '<');
		if (thisOne.getOrientareCoada() == "l") {
			this->tabla[thisOne.getX(), thisOne.getY(), '<');
			this->tabla[thisOne.getX(), thisOne.getY() + 1, '<');
			this->tabla[thisOne.getX() - 1, thisOne.getY() + 1, '<');
			this->tabla[thisOne.getX() + 1, thisOne.getY() + 1, '<');
			this->tabla[thisOne.getX() - 2, thisOne.getY() + 1, '<');
			this->tabla[thisOne.getX() + 2, thisOne.getY() + 1, '<');
			this->tabla[thisOne.getX(), thisOne.getY() + 2, '<');
			this->tabla[thisOne.getX(), thisOne.getY() + 3, '<');
			this->tabla[thisOne.getX() - 1, thisOne.getY() + 3, '<');
			this->tabla[thisOne.getX() + 1, thisOne.getY() + 3, '<');

		}
		else if (thisOne.getOrientareCoada() == "r") {
			this->tabla[thisOne.getX(), thisOne.getY(), '>');
			this->tabla[thisOne.getX(), thisOne.getY() - 1, '>');
			this->tabla[thisOne.getX() - 1, thisOne.getY() - 1, '>');
			this->tabla[thisOne.getX() + 1, thisOne.getY() - 1, '>');
			this->tabla[thisOne.getX() - 2, thisOne.getY() - 1, '>');
			this->tabla[thisOne.getX() + 2, thisOne.getY() - 1, '>');
			this->tabla[thisOne.getX(), thisOne.getY() - 2, '>');
			this->tabla[thisOne.getX(), thisOne.getY() - 3, '>');
			this->tabla[thisOne.getX() - 1, thisOne.getY() - 3, '>');
			this->tabla[thisOne.getX() + 1, thisOne.getY() - 3, '>');

		}
		else if (thisOne.getOrientareCoada() == "u") {

			this->tabla[thisOne.getX(), thisOne.getY(), '^');
			this->tabla[thisOne.getX() + 1, thisOne.getY(), '^');
			this->tabla[thisOne.getX() + 1, thisOne.getY() - 1, '^');
			this->tabla[thisOne.getX() + 1, thisOne.getY() + 1, '^');
			this->tabla[thisOne.getX() + 1, thisOne.getY() - 2, '^');
			this->tabla[thisOne.getX() + 1, thisOne.getY() + 2, '^');
			this->tabla[thisOne.getX() + 2, thisOne.getY(), '^');
			this->tabla[thisOne.getX() + 3, thisOne.getY(), '^');
			this->tabla[thisOne.getX() + 3, thisOne.getY() - 1, '^');
			this->tabla[thisOne.getX() + 3, thisOne.getY() + 1, '^');

		}
		else if (thisOne.getOrientareCoada() == "d") {
			this->tabla[thisOne.getX(), thisOne.getY(), 'v');
			this->tabla[thisOne.getX() - 1, thisOne.getY(), 'v');
			this->tabla[thisOne.getX() - 1, thisOne.getY() - 1, 'v');
			this->tabla[thisOne.getX() - 1, thisOne.getY() + 1, 'v');
			this->tabla[thisOne.getX() - 1, thisOne.getY() - 2, 'v');
			this->tabla[thisOne.getX() - 1, thisOne.getY() + 2, 'v');
			this->tabla[thisOne.getX() - 2, thisOne.getY(), 'v');
			this->tabla[thisOne.getX() - 3, thisOne.getY(), 'v');
			this->tabla[thisOne.getX() - 3, thisOne.getY() - 1, 'v');
			this->tabla[thisOne.getX() - 3, thisOne.getY() + 1, 'v');
		}

		avioane.pop_back();
	} while (this->avioane.size()>0);
	for (int x = 1; x < this->getLinii(); x++) {
		for (int y = 1; y < this->getColoane(); y++)
			if (this->getPatrat(x, y) != '<' && this->getPatrat(x, y) != '^' && this->getPatrat(x, y) != '>' && this->getPatrat(x, y) != 'v')
				this->tabla[x, y, '.');
	}

}*/