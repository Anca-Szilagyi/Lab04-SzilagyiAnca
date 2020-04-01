#include "UserInterface.h"
#include <iostream>
using namespace std;

UserInterface::UserInterface() { 
    //sizeUndo = 0;
//sizeUndoStergere = 0;
//sizeUndoUpdate = 0;
}

void UserInterface::menu() {
    cout << "Welcome!" << endl;
    cout << "1. Add a project" << endl;
    cout << "2. Delete a project" << endl;
    cout << "3. Update a project" << endl;
    cout << "4. Show all the projects" << endl;
    cout << "5. Show all the projects with a minimum no of branches and commits" << endl;
    cout << "6. Delete all the projects with branches*commits=0" << endl;
    cout << "7. Exit program" << endl;
}

/*void UserInterface::createProject(char*& gitPath, int& branches, int& commits, Project& p) {
    cout << "Git PATH: ";
    char* gitPath = new char[10];
    cin >> gitPath;
    cout << "Number of branches: ";
    cin >> branches;
    cout << "Number of commits: ";
    cin >> commits;
    p = Project(gitPath, branches, commits);
    delete[] gitPath;
}*/

void UserInterface::adaugare() {
	cout << "Introduce info about the project: " << endl;
    cout << "Git path: ";
    char* gitPath = new char[10];
    cin >> gitPath;

    cout << "No of branches: ";
    int branches;
    cin >> branches;
    
	cout << "No of commits: ";
	int commits;
	cin >> commits;

	Project p = Project(gitPath, branches, commits);
    service.addProject(p);
    cout << "The project has been added!" << endl;
}

void UserInterface::stergere() {
	cout << "Git path: ";
	char* gitPath = new char[10];
	cin >> gitPath;

	cout << "No of branches: ";
	int branches;
	cin >> branches;

	cout << "No of commits: ";
	int commits;
	cin >> commits;

	Project p = Project(gitPath, branches, commits);
    //undoStergere[++sizeUndoStergere] = p;
    service.delProject(p);
    cout << "The project has been deleted!" << endl;
}

void UserInterface::update() {
	cout << "Current datas: " << endl;
	cout << "Git path: ";
	char* path = new char[10];
	cin >> path;
	cout << "No of branches: ";
	int branches;
	cin >> branches;
	cout << "No of commits: ";
	int commits;
	cin >> commits;

	Project p = Project(path, branches, commits);
    //undoUpdate[++sizeUndoUpdate] = p;

	cout << "New datas: " << endl;
	cout << "New git path: ";
	char* newPath = new char[10];
	cin >> newPath;

	cout << "New number of branches: ";
	int newBranches;
	cin >> newBranches;

	cout << "New no of commits: ";
	int newCommits;
	cin >> newCommits;
    service.updateProject(p, newPath, newBranches, newCommits);
    cout << "The project has been updated!" << endl;
	delete[] path;
	delete[] newPath;
}
/*void UserInterface::undoFunction() {
    for (int i = 0; i < sizeUndo; i++) cout << undo[i] << " ";
    if (sizeUndo==0) cout << "There is no more undos to do." << endl;

    else if (undo[sizeUndo - 1] == 1) {
        int size = service.sizeee();
        Project proj = service.getItemFromPosition(size);
        service.delProject(proj);
        cout << "The project that has just been added was deleted!" << endl;
    }
    else if (undo[sizeUndo - 1] == 2) {
        Project p = undoStergere[sizeUndoStergere - 1];
        service.addProject(p);
        cout << "The project has been added again!" << endl;
        sizeUndoStergere--;
    }
    else if (undo[sizeUndo - 1] == 3) {
        cout << "We don't have this option yet!" << endl;
    }
    sizeUndo--;
}*/

//returneaza toate elementele din vector
void UserInterface::getAllProjects() {
    for (int i = 0; i < service.sizeee(); i++) {
        cout << service.getItemFromPosition(i).getGitPath() << " ";
        cout << service.getItemFromPosition(i).getNoOfBranches() << " ";
        cout << service.getItemFromPosition(i).getNoOfCommits() << endl;
    }
}

//destructor
UserInterface::~UserInterface() {
}

void UserInterface::minimumNumbers() {
    cout << "Introduce the minimum no of branches: ";
    int k;
    cin >> k;
    cout << "Introduce the minimum no of commits: ";
    int l;
    cin >> l;

    Project finalList[100];
    int m=0;
    service.minimumNumbers(k, l, finalList, m);
    for (int i = 0; i < m; i++) {
        cout << finalList[i].getGitPath() << " ";
        cout<<finalList[i].getNoOfBranches()<<" ";
        cout << finalList[i].getNoOfCommits() << endl;
    }
}

void UserInterface::eliminareProiecteCuRepoArray() {
    service.eliminareProiecteCuRepoArray();
}



void UserInterface::console() {
    bool ok = 1;
    int option;
    menu();

    while (ok) {
        cout <<endl<< "Your option: ";
        cin >> option;
        cout << endl;
        switch (option) {
        case 1: {
			adaugare();
            //undo[++sizeUndo] = 1;
			break;
        }
        case 2: {
            cout << "Introduce info about project you want to remove from list: " << endl;
			stergere();
            //undo[++sizeUndo] = 2;
			break;
        }
        case 3: {
			update();
            //undo[++sizeUndo] = 3;
			break;
		}
        case 4: {
            getAllProjects();
			break;
        }
        case 5: {
            minimumNumbers();
            break;
        }
        case 6:{
            eliminareProiecteCuRepoArray();
            cout << "The projects were eliminated!" << endl;
            break;
        }
        /*case 7: {
            cout << "The undo function works only for options 1, 2 and 3 for now." << endl;
            cout << "Press 1 if you want to continue and 0 if you want to choose another option: ";
            int op = 0;
            cin >> op;
            if (op==1) undoFunction();
            break;
        }*/
        case 7: {
            cout << "Thank you!" << endl;
            ok = 0;
            break;
        }
        default: {
            cout << "This is not an option from our menu!" << endl;
            break;
        }
        }
    }
}