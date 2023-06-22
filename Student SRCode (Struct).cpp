#include <iostream>
#include <string>
using namespace std;

string searchSRCODE;
string searchChoice;
int choice;
string choiceyn;

struct stud {
    string name;
    string SRCODE;
    string* subjects;
    int books;
};

void cdisplayorsearch(stud* s, int choice);

bool isSRCODEExist(stud* s, int choice, const string& SRCODE) {
    for (int i = 0; i < choice; i++) {
        if (s[i].SRCODE == SRCODE) {
            return true;
        }
    }
    return false;
}

void displayStudents(stud* s, int choice) {
    system("cls");
    cout << endl << endl << endl;
    cout << "Name\t\tSRCODE\t\tSubjects" << endl;
    for (int i = 0; i < choice; i++) {
        cout << s[i].name << "\t\t" << s[i].SRCODE << "\t";
        for (int j = 0; j < s[i].books; j++) {
            cout << s[i].subjects[j];
            if (j != s[i].books - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    cout << endl << endl << endl;
    cdisplayorsearch(s, choice);
}

void searchStudent(stud* s, int choice) {
    system("cls");
    cout << "\n\n\nEnter the SRCODE of the student you want to search: ";
    cout << "Available SRCODES:";
    for (int i = 0; i < choice; i++) {
        cout << endl << s[i].SRCODE;
    }
    cout << endl << "Input: ";
    cin >> searchSRCODE;

    for (int i = 0; i < choice; i++) {
        if (s[i].SRCODE == searchSRCODE) {
            cout << endl << endl << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "SRCODE: " << s[i].SRCODE << endl;
            cout << "Subjects: ";
            for (int j = 0; j < s[i].books; j++) {
                cout << s[i].subjects[j];
                if (j != s[i].books - 1) {
                    cout << ", ";
                }
            }
            cout << endl << endl << endl;
            cdisplayorsearch(s, choice);
            return;
        }
    }
    cout << endl << endl << endl;
    cout << "Student with SRCODE " << searchSRCODE << " not found." << endl;
    cdisplayorsearch(s, choice);
}

void cdisplayorsearch(stud* s, int choice) {
    cout << "\nChoose between 1, 2, and 3 to continue with the Program.\n1 = Display the Whole List\n2 = Search for Student\n3 = Terminate the Program\nInput: ";
    cin >> choiceyn;

    if (choiceyn == "1") {
        try {
            displayStudents(s, choice);
        } catch (...) {
            cout << "An error occurred while displaying the student list." << endl;
        }
    } else if (choiceyn == "2") {
        try {
            searchStudent(s, choice);
        } catch (...) {
            cout << "An error occurred while searching for the student." << endl;
        }
    } else if (choiceyn == "3") {
        exit(0);
    } else {
        cout << "Invalid choice." << endl;
        cdisplayorsearch(s, choice);
    }
}

int main() {
    cout << "Enter the number of user inputs: ";
    cin >> choice;

    stud* s = new stud[choice];

    for (int i = 0; i < choice; i++) {
        cout << "\nStudent No. " << i + 1 << endl;
        cout << "Enter the Name of Student: ";
        cin >> s[i].name;

        string srcode;
        bool srcodeExists = false;
        do {
            cout << "Enter the SRCODE of the Student Number: ";
            cin >> srcode;
            srcodeExists = isSRCODEExist(s, i, srcode);
            if (srcodeExists) {
                cout << "SRCODE " << srcode << " already exists. Please enter a different SRCODE." << endl;
            }
        } while (srcodeExists);
        s[i].SRCODE = srcode;

        cout << "Enter the Number of Subjects of the Student: ";
        cin >> s[i].books;

        s[i].subjects = new string[s[i].books];

        for (int j = 0; j < s[i].books; j++) {
            cout << "Enter the Subject of Book " << j + 1 << ": ";
            cin >> s[i].subjects[j];
        }
        cout << endl;
    }
    system("cls");

    cdisplayorsearch(s, choice);

    for (int i = 0; i < choice; i++) {
        delete[] s[i].subjects;
    }
    delete[] s;

    return 0;
}
