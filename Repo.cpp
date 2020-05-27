#include "Repo.h"

Repo::Repo() {
}
Repo::~Repo() {
}
//void Repo::addElem(Joc e) {

	//elem.insert(pair<int, Joc>(key++, e));


//}
int Repo::delElem(int i) {
	auto itr = elem.find(i);
	if (itr != elem.end()) {
		elem.erase(itr);
		return 0;
	}
	else
		return -1;
}
int Repo::updateElem(int i, const Joc nou) {

	if (i >= 0 && i < elem.size()) {
		delElem(i);
		elem.emplace(i, nou);
		return 0;
	}
	else
		return -1;
}
int Repo::getSize() {

	return elem.size();

}
map<int, Joc> Repo::getAll() {

	return elem;
}
void Repo::clearMap() {

	elem.clear();
	key = 0;
}
Joc Repo::find(int i)
{
	int poz = 0;
	for (auto itr = elem.begin(); itr != elem.end(); itr++) {
		if (poz == i) { return itr->second; }
		else { itr++; poz++; }
	}
	//return 0;
}
Joc Repo::addAvion(Joc& t, Avion a) {

	return t.addAvion(a);
}
void Repo::findAvion(Joc& t, int x, int y, int poz) {

	updateElem(poz, t.findAvion(x, y));

}

