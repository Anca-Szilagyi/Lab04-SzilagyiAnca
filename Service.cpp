#include"Service.h"



Service::~Service() {

}
//void Service::addElem(Joc t) {

	//r.addElem(t);
//}
Joc Service::addAvion(Joc& t, Avion a) {

	return r.addAvion(t, a);
}
int Service::delElem(int i)
{
	r.delElem(i);
	return 0;
}
//int Service::updateElem(int i, Joc t) {

//	r.updateElem(i, t);

	//return 0;
//}
int Service::getSize() {

	return r.getSize();
}
map<int, Joc>Service::showElem() {

	return r.getAll();
}
//Joc Service::find(int i) {

	//return r.find(i);
//}
void Service::findAvion(Joc& t, int x, int y, int poz) {

	r.findAvion(t, x, y, poz);
}
void Service::clear() {

	r.clearMap();
}



/*#include "Service.h"
Service::Service() {
}
Service::Service(Joc jocCalculator, Joc jocPlayer) {
}
Service::~Service() {

}
int Service::gata() {
	if (jocCalculator.gameOver() == 0 && jocPlayer.gameOver() == 0) return 0;
	//adica nu e gata;
	else if (jocCalculator.gameOver()) return 1;
	//playerul a castigat
	else if (jocPlayer.gameOver()) return 2;
	//calculatorul a castigat.
	return 0;
}
void Service::addPlane(Avion plane) {
	jocPlayer.addAvion(plane);
}

int Service::hit(int x, int y) {


	if (jocCalculator.getItemFromPos(x, y) == '.') return 0;
	// 0 = ratat;
	else if (jocCalculator.getItemFromPos(x, y) == '<') {
		if (jocCalculator.getItemFromPos(x, y - 1) == '.')
			if (jocCalculator.getItemFromPos(x + 1, y) == '.' && jocCalculator.getItemFromPos(x - 1, y) == '.') {
				jocCalculator.deleteAvion(x, y, 'l');
				return 2;
				//a lovit varful
			}
			else {
				jocCalculator.setPatrat(x, y, '.');
				return 1;
				//a lovit alta parte a avionului
			}
		else {
			jocCalculator.setPatrat(x, y, '.');
			return 1;
			//a lovit alta parte a avionului
		}
	}
	else if (jocCalculator.getItemFromPos(x, y) == '>') {
		if (jocCalculator.getItemFromPos(x, y + 1) == '.')
			if (jocCalculator.getItemFromPos(x + 1, y) == '.' && jocCalculator.getItemFromPos(x - 1, y) == '.') {
				jocCalculator.deleteAvion(x, y, 'r');
				return 2;
				//a lovit varful
			}
			else {
				jocCalculator.setPatrat(x, y, '.');
				return 1;
				//a lovit alta parte a avionului
			}
		else {
			jocCalculator.setPatrat(x, y, '.');
			return 1;
			//a lovit alta parte a avionului
		}
	}
	else if (jocCalculator.getItemFromPos(x, y) == '^') {
		if (jocCalculator.getItemFromPos(x + 1, y) == '.')
			if (jocCalculator.getItemFromPos(x, y - 1) == '.' && jocCalculator.getItemFromPos(x, y + 1) == '.') {
				jocCalculator.deleteAvion(x, y, 'u');
				return 2;
				//a lovit varful
			}
			else {
				jocCalculator.setPatrat(x, y, '.');
				return 1;
				//a lovit alta parte a avionului
			}
		else {
			jocCalculator.setPatrat(x, y, '.');
			return 1;
			//a lovit alta parte a avionului
		}
	}
	else if (jocCalculator.getItemFromPos(x, y) == 'v') {
		if (jocCalculator.getItemFromPos(x - 1, y) == '.')
			if (jocCalculator.getItemFromPos(x, y - 1) == '.' && jocCalculator.getItemFromPos(x, y + 1) == '.') {
				jocCalculator.deleteAvion(x, y, 'd');
				return 2;
				//a lovit varful
			}
			else {
				jocCalculator.setPatrat(x, y, '.');
				return 1;
				//a lovit alta parte a avionului
			}
		else {
			jocCalculator.setPatrat(x, y, '.');
			return 1;
			//a lovit alta parte a avionului
		}
	}
	return 0;
}


void Service::randomPCGame() {
	Avion plane1(3, 1, "l");
	Avion plane2(1, 7, "u");
	Avion plane3(4, 8, "r");
	jocCalculator.addAvion(plane2);
	jocCalculator.addAvion(plane3);
	jocCalculator.addAvion(plane1);
}


int Service::pcHit() {
	int x = rand() % 10 + 1;
	int y = rand() % 10 + 1;
	if (jocPlayer.getItemFromPos(x, y) == '.') return 0;
	// 0 = ratat;
	else if (jocPlayer.getItemFromPos(x, y) == '<') {
		if (jocPlayer.getItemFromPos(x, y - 1) == '.')
			if (jocPlayer.getItemFromPos(x + 1, y) == '.' && jocPlayer.getItemFromPos(x - 1, y) == '.') {
				jocPlayer.deleteAvion(x, y, 'l');
				return 2;
				//a lovit varful
			}
			else {
				jocPlayer.setPatrat(x, y, '.');
				return 1;
				//a lovit alta parte a avionului
			}
		else {
			jocPlayer.setPatrat(x, y, '.');
			return 1;
			//a lovit alta parte a avionului
		}
	}
	else if (jocPlayer.getItemFromPos(x, y) == '>') {
		if (jocPlayer.getItemFromPos(x, y + 1) == '.')
			if (jocPlayer.getItemFromPos(x + 1, y) == '.' && jocPlayer.getItemFromPos(x - 1, y) == '.') {
				jocPlayer.deleteAvion(x, y, 'r');
				return 2;
				//a lovit varful
			}
			else {
				jocPlayer.setPatrat(x, y, '.');
				return 1;
				//a lovit alta parte a avionului
			}
		else {
			jocPlayer.setPatrat(x, y, '.');
			return 1;
			//a lovit alta parte a avionului
		}
	}
	else if (jocPlayer.getItemFromPos(x, y) == '^') {
		if (jocPlayer.getItemFromPos(x + 1, y) == '.')
			if (jocPlayer.getItemFromPos(x, y - 1) == '.' && jocPlayer.getItemFromPos(x, y + 1) == '.') {
				jocPlayer.deleteAvion(x, y, 'u');
				return 2;
				//a lovit varful
			}
			else {
				jocPlayer.setPatrat(x, y, '.');
				return 1;
				//a lovit alta parte a avionului
			}
		else {
			jocPlayer.setPatrat(x, y, '.');
			return 1;
			//a lovit alta parte a avionului
		}
	}
	else if (jocPlayer.getItemFromPos(x, y) == 'v') {
		if (jocPlayer.getItemFromPos(x - 1, y) == '.')
			if (jocPlayer.getItemFromPos(x, y - 1) == '.' && jocPlayer.getItemFromPos(x, y + 1) == '.') {
				jocPlayer.deleteAvion(x, y, 'd');
				return 2;
				//a lovit varful
			}
			else {
				jocPlayer.setPatrat(x, y, '.');
				return 1;
				//a lovit alta parte a avionului
			}
		else {
			jocPlayer.setPatrat(x, y, '.');
			return 1;
			//a lovit alta parte a avionului
		}
	}
	//cout << jocPlayer;
	return 0;
}*/

