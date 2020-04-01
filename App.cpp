#include <iostream>
#include "Tests.h"
#include "Project.h"
//#include "Operations.h"
#include "UserInterface.h"
using namespace std;
int option, commits,branches;
char gitPath;
Project p;

int main() {
	cout << "Checking all the tests... " << endl;
	repositoryArrayTests();
	testeService();
	cout << "Tests are ok!" << endl;
	cout << endl;

	UserInterface user;
	user.console();
	
	return 0;
}