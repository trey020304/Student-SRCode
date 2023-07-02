#include <iostream>
#include <string>
using namespace std;

class Stud {
private:
    string name;
    string SRCODE;
    string* subjects;
    int subj;

public:
    Stud* next;

    Stud(const string& name, const string& SRCODE, int subj) {
        this->name = name;
        this->SRCODE = SRCODE;
        this->subj = subj;
        subjects = new string[subj];
    }

    ~Stud() {
        delete[] subjects;
    }

    string getName() const {
        return name;
    }

    string getSRCODE() const {
        return SRCODE;
    }

    int getSubj() const {
        return subj;
    }

    string getSubject(int index) const {
        if (index >= 0 && index < subj) {
            return subjects[index];
        }
        return "";
    }

    void setSubject(int index, const string& subject) {
        if (index >= 0 && index < subj) {
            subjects[index] = subject;
        }
    }
};

void cdisplayorsearch(Stud* head);

void insertNode(Stud*& head, const string& name, const string& SRCODE, int subj) {
    Stud* newNode = new Stud(name, SRCODE, subj);
    newNode->next = head;
    head = newNode;
}

void displayStudents(Stud* head) {
    system("cls");
    cout << "Name\t\tSRCODE\t\tSubjects" << endl;
    Stud* current = head;
    while (current != nullptr) {
        cout << current->getName() << "\t\t" << current->getSRCODE() << "\t";
        for (int j = 0; j < current->getSubj(); j++) {
            cout << current->getSubject(j);
            if (j != current->getSubj() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        current = current->next;
    }
    cout << endl << endl << endl;
    cdisplayorsearch(head);
}

void searchStudent(Stud* head) {
    system("cls");
    cout << "Enter the SRCODE of the student you want to search\n\n";
    Stud* current = head;
    cout << "Available SRCODES:";
    while (current != nullptr) {
        cout << endl << current->getSRCODE();
        current = current->next;
    }
    cout << endl << "Input: ";
    string searchSRCODE;
    cin >> searchSRCODE;

    current = head;
    while (current != nullptr) {
        if (current->getSRCODE() == searchSRCODE) {
            cout << endl << endl << endl;
            cout << "Name: " << current->getName() << endl;
            cout << "SRCODE: " << current->getSRCODE() << endl;
            cout << "Subjects: ";
            for (int j = 0; j < current->getSubj(); j++) {
                cout << current->getSubject(j);
                if (j != current->getSubj() - 1) {
                    cout << ", ";
                }
            }
            cout << endl << endl << endl;
            cdisplayorsearch(head);
            return;
        }
        current = current->next;
    }
    cout << endl << endl << endl;
    cout << "Student with SRCODE " << searchSRCODE << " not found." << endl;
    cdisplayorsearch(head);
}

void cdisplayorsearch(Stud* head) {
    cout << "\nChoose between 1, 2, and 3 to continue with the Program.\n1 = Display the Whole List\n2 = Search for Student\n3 = Terminate the Program\nInput: ";
    string choiceyn;
    cin >> choiceyn;

    if (choiceyn == "1") {
        try {
            displayStudents(head);
        } catch (...) {
            cout << "An error occurred while displaying the student list." << endl;
        }
    } else if (choiceyn == "2") {
        try {
            searchStudent(head);
        } catch (...) {
            cout << "An error occurred while searching for the student." << endl;
        }
    } else if (choiceyn == "3") {
        exit(0);
    } else {
        cout << "Invalid choice." << endl;
        cdisplayorsearch(head);
    }
}

int main() {
    cout << "Enter the number of user inputs: ";
    int choice;
    cin >> choice;

    Stud* head = nullptr;

    for (int i = 0; i < choice; i++) {
        cout << "\nStudent No. " << i + 1 << endl;
        cout << "Enter the Name of Student: ";
        string name;
        cin >> name;

        string srcode;
        bool srcodeExists = false;
        do {
            cout << "Enter the SRCODE of the Student Number: ";
            cin >> srcode;
            Stud* current = head;
            while (current != nullptr) {
                if (current->getSRCODE() == srcode) {
                    srcodeExists = true;
                    cout << "SRCODE " << srcode << " already exists. Please enter a different SRCODE." << endl;
                    break;
                }
                current = current->next;
            }
        } while (srcodeExists);

        int subj;
        cout << "Enter the Number of Subjects of the Student: ";
        cin >> subj;

        insertNode(head, name, srcode, subj);

        Stud* current = head;
        for (int j = 0; j < subj; j++) {
            cout << "Enter the name of Subject " << j + 1 << ": ";
            string subject;
            cin >> subject;
            current->setSubject(j, subject);
        }
        cout << endl;
    }
    system("cls");

    cdisplayorsearch(head);

    // Deallocate the memory
    Stud* current = head;
    while (current != nullptr) {
        Stud* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
