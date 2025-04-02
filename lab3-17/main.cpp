#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int id;

    Student(string n, int i) : name(n), id(i) {}
    bool operator<(const Student& other) const {
        return name < other.name;
    }
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << s.name << " (ID: " << s.id << ")";
        return os;
    }
};

int main() {
    vector<Student> students;
    students.push_back(Student("hamzeh", 101));
    students.push_back(Student("mark", 102));
    students.push_back(Student("alex", 103));
    students.push_back(Student("emma", 104));
    students.push_back(Student("matei", 105));
    students.push_back(Student("malina", 106));
    students.push_back(Student("michael", 107));
    students.push_back(Student("armand", 108));
    students.push_back(Student("mihyar", 109));
    students.push_back(Student("danisa", 110));

    list<Student> selectedStudents;
    selectedStudents.push_back(students[1]);
    selectedStudents.push_back(students[3]);
    selectedStudents.push_back(students[5]);
    selectedStudents.push_back(students[7]);
    selectedStudents.push_back(students[9]);

    cout << "selected students befor sorting:" << endl;
    for (const auto& student : selectedStudents) {
        cout << student << endl;
    }
    cout << endl;

    string thirdName = students[2].name;
    cout << " the third student in the first container: " << thirdName << endl;

    selectedStudents.sort([thirdName](const Student& a, const Student& b) {
        if (a.name > thirdName && b.name > thirdName) {
            return a.name < b.name;
        }
        return false;
    });

    cout << "\n the selected students after the partial sorting:" << endl;
    for (const auto& student : selectedStudents) {
        cout << student << endl;
    }

    return 0;
}