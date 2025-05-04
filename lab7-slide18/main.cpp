#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

struct Car {
    string brand_;
    string model_;
    double profit_;
    int productionYear_;

    bool operator<(const Car& other) const {
        return tie(brand_, model_, productionYear_, profit_) < tie(other.brand_, other.model_, other.productionYear_, other.profit_);
    }
};

int main() {
    set<Car> carSales = {

            {"BMW", "X5", 12000, 2020},
            {"Toyota", "Corolla", 8000, 2019},
            {"BMW", "M3", 15000, 2021},
            {"Ford", "Focus", 6000, 2018},
            {"Audi", "A4", 9000, 2020},
            {"BMW", "320i", 11000, 2019},
            {"Toyota", "Camry", 8500, 2021},
            {"Ford", "Fiesta", 5000, 2019},
            {"Audi", "A6", 9500, 2021},
            {"Hyundai", "Elantra", 7000, 2020}

    };

    bool foundBMW = false;
    for (const auto& car : carSales) {
        if (car.brand_ == "BMW") {
            foundBMW = true;
            break;
        }
    }
    if (foundBMW)
        cout << "yes BMW cars were sold" << endl;
    else
        cout << "no the BMW cars were sold " << endl;
    map<int,vector<Car>> carsByYear;
    for (const auto& car : carSales) {
        carsByYear[car.productionYear_].push_back(car);
    }
    int mostProfitableYear = 0;
    double maxProfit = 0;
    for (const auto& pair : carsByYear) {
        double yearProfit = 0;
        for (const auto& car : pair.second) {
            yearProfit += car.profit_;
        }
        if (yearProfit > maxProfit) {
            maxProfit = yearProfit;
            mostProfitableYear = pair.first;
        }
    }

    cout << "the most profitable production year was: " << mostProfitableYear << " with total profit of $" << maxProfit << endl;
    return 0;
}
