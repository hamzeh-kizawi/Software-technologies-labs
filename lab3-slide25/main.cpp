#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<int, string> studentMap;
    studentMap[101] = "hamzeh";
    studentMap[102] = "mark";
    studentMap[103] = "alex";
    studentMap[104] = "diana";
    studentMap[105] = "matei";

    cout << "the initial map contents:" << endl;
    for (const auto& entry : studentMap) {
        cout << "ID: " << entry.first << ", Name:" << entry.second << endl;
    }
    cout << endl;

    cout << "adding entry with existing key 103.." << endl;
    studentMap[103] = "armand";

    cout << "\nMap after adding duplicate key:" << endl;
    for (const auto& entry : studentMap) {
        cout << "ID: " << entry.first << ", Name: " << entry.second << endl;
    }
    cout << endl;

    string searchName = "diana";
    cout << "we search for student with name '" << searchName << "'..." << endl;

    bool found = false;
    for (const auto& entry : studentMap) {
        if (entry.second == searchName) {
            cout << "found! ID: " << entry.first << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "student was not found in map" << endl;
    }

    searchName = "tiegen";
    cout << "\nSearching for student with name'" << searchName << "'..." << endl;

    found = false;
    for (const auto& entry : studentMap) {
        if (entry.second == searchName) {
            cout << "found! ID: " << entry.first << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "the student was not found in map." << endl;
    }

    return 0;
}