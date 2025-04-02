#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int grade;
    int age;
};

// first rule
bool isHighAchiever(const Student& s) {
    return s.grade > 85;
}

// second rule check if student age is between age 13-19 (teenager)
bool isTeenager(const Student& s) {
    return s.age >= 13 && s.age <= 19;
}

int main() {
    std::vector<Student> students = {
            {"hamzeh", 92, 18},
            {"mark", 78, 20},
            {"anton", 88, 16},
            {"malina", 95, 19},
            {"gabi", 82, 17}
    };

    auto it = std::find_if(students.begin(), students.end(), isHighAchiever);
    if (it != students.end()) {
        std::cout << "first high achiever: " << it->name
                  << " (Grade: " << it->grade << ")\n";
    } else {
        std::cout << "no high achievers found.\n";
    }

    it = std::find_if(students.begin(), students.end(), isTeenager);
    if (it != students.end()) {
        std::cout << "first teenager: " << it->name
                  << " (Age: " << it->age << ")\n";
    } else {
        std::cout << "no teenagers found.\n";
    }

    it = std::find_if(students.begin(), students.end(), [](const Student& s) {
        return isHighAchiever(s) && isTeenager(s);
    });

    if (it != students.end()) {
        std::cout << "first high achieving teenager: " << it->name
                  << " (grade: " << it->grade << ",Age: " << it->age << ")\n";
    } else {
        std::cout << "no high achieving teenagers found \n";
    }

    return 0;
}