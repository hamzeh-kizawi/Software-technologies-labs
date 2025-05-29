#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int NUM_GRADES = 10;

struct Student {
    string name;
    int year;
    double grades[NUM_GRADES];
    double average;
};

double getAverage(double grades[]) {
    double total = 0;
    for (int i = 0; i < NUM_GRADES; i++) {
        total += grades[i];
    }
    return total / NUM_GRADES;
}

Student readStudent() {
    Student s;
    cout << " enter name: ";
    cin >> s.name;

    cout << " enter year: ";
    cin >> s.year;

    cout << " enter " << NUM_GRADES << " grades:\n";
    for (int i = 0; i < NUM_GRADES; i++) {
        cout << " grade " << (i + 1) << ": ";
        cin >> s.grades[i];
    }

    s.average = getAverage(s.grades);
    return s;
}

void addStudent(vector<Student>& list) {
    Student s = readStudent();
    list.push_back(s);
}

void showAll(vector<Student>& list) {
    for (int i = 0; i < list.size(); i++) {
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << " name: " << list[i].name << "\n";
        cout << " year: " << list[i].year << "\n";
        cout << " grades: ";
        for (int j = 0; j < NUM_GRADES; j++) {
            cout << list[i].grades[j] << " ";
        }
        cout << " \nAverage: " << list[i].average << "\n";
    }
}

void showAverages(vector<Student>& list) {
    for (int i = 0; i < list.size(); i++) {
        cout << " name: " << list[i].name << ", average: " << list[i].average << "\n";
    }
}

void sortByAverage(vector<Student>& list) {
    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = i + 1; j < list.size(); j++) {
            if (list[j].average > list[i].average ||
                (list[j].average == list[i].average && list[j].name < list[i].name)) {
                swap(list[i], list[j]);
            }
        }
    }

    for (int i = 0; i < list.size(); i++) {
        cout << " name: " << list[i].name << ", avg: " << list[i].average << ", year: " << list[i].year << "\n";
    }
}

void showYear3High(vector<Student>& list) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].year == 3 && list[i].average > 8.0) {
            cout << " name: " << list[i].name << ", year: " << list[i].year << ", average: " << list[i].average << "\n";
        }
    }
}

void insertStudent(vector<Student>& list) {
    int k;
    cout << " enter position to insert after (note: 0 for custom): ";
    cin >> k;

    Student newStu = readStudent();

    if (k >= 1 && k <= list.size()) {
        list.insert(list.begin() + k, newStu);
    } else {
        int choice;
        cout << " insert at (1) beginning or (2) end? ";
        cin >> choice;
        if (choice == 1) {
            list.insert(list.begin(), newStu);
        } else {
            list.push_back(newStu);
        }
    }
}
void removeFailed(vector<Student>& list) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].average < 5.0) {
            list.erase(list.begin() + i);
            i--;
        }
    }
}

void menu() {
    cout << "\n1. add student\n";
    cout << "2. show all students\n";
    cout << "3. show averages\n";
    cout << "4. sort by average\n";
    cout << "5. show year 3 with avg > 8\n";
    cout << "6. insert student at position\n";
    cout << "7. remove failed students\n";
    cout << "8. exit\n";
}
int main() {
    vector<Student> students;
    int choice;

    do {
        menu();
        cout << " enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: showAll(students); break;
            case 3: showAverages(students); break;
            case 4: sortByAverage(students); break;
            case 5: showYear3High(students); break;
            case 6: insertStudent(students); break;
            case 7: removeFailed(students); break;
            case 8: cout << " goodbye\n"; break;
            default: cout << " invalid option\n";
        }

    } while (choice != 8);

    return 0;
}
