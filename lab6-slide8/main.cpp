#include <iostream>
#include <string>
using namespace std;


class Car {
public:
    string model;
    bool hasDriverLicense;

    Car(string m, bool license) {
        model = m;
        hasDriverLicense = license;
    }
};

class Book {
public:
    string title;

    Book(string t) {
        title = t;
    }
};

template <typename T>
class RentService {
public:
    void rentService(T service, string renterName) {
        cout << renterName << " rented the service" << endl;

    }
};
template <>
class RentService<Car> {
public:
    void rentService(Car car, string renterName) {
        if (car.hasDriverLicense) {

            cout << renterName << " rented a car : " << car.model << endl;
        } else {
            cout << "Error: " << renterName << " does not have a valid driver license " << endl;
        }
    }
};

int main() {
    Car car1("Toyota", true);
    Car car2("BMW", false);
    Book book1("1984");
    RentService<Car> carRental;
    RentService<Book> bookRental;

    carRental.rentService(car1, "Hamzeh");
    carRental.rentService(car2, "Mark");
    bookRental.rentService(book1, "Alex");
    return 0;
}
