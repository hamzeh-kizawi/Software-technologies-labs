#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

struct Pot {
    std::string type_;
    float capacity_;
    float price_;
    std::string deliveryDate_;

    bool operator<(const Pot& other) const {
        return deliveryDate_ < other.deliveryDate_ ||
               (deliveryDate_ == other.deliveryDate_ && price_ < other.price_);
    }
};
void checkOverFiveLiters(const std::set<Pot>& pots) {
    bool found = false;
    for (const auto& pot : pots) {
        if (pot.capacity_ > 5.0f) {
            found = true;
            break;
        }
    }
    if (found)
        std::cout << " there are pots exceeding 5 liters in capacity\n";
    else
        std::cout << " no pots exceeding 5 liters were sold\n";
}
void groupByDeliveryDate(const std::set<Pot>& pots, std::map<std::string, std::vector<Pot>>& grouped) {
    for (const auto& pot : pots) {
        grouped[pot.deliveryDate_].push_back(pot);
    }
}

void findMostProfitableWeek(const std::map<std::string, std::vector<Pot>>& grouped) {
    std::string bestDate;
    float maxProfit = 0.0f;

    for (const auto& entry : grouped) {
        float total = 0.0f;
        for (const auto& pot : entry.second) {
            total += pot.price_;
        }
        if (total > maxProfit) {
            maxProfit = total;
            bestDate = entry.first;
        }
    }

    std::cout << "\n the most profitable delivery date is: " << bestDate
              << " with  total profit of: " << std::fixed << std::setprecision(2) << maxProfit << "\n";
}

int main() {
    std::set<Pot> pots = {
            {"Vase", 3.2f, 12.5f, "2024-06-01"},
            {"Bowl", 5.5f, 15.0f, "2024-06-01"},
            {"Mug", 1.2f, 8.0f, "2024-06-02"},
            {"Jug", 6.3f, 20.0f, "2024-06-03"},
            {"Plate", 0.9f, 5.0f, "2024-06-03"},
            {"Vase", 2.5f, 10.5f, "2024-06-04"},
            {"Bowl", 4.8f, 13.0f, "2024-06-04"},
            {"Mug", 1.0f, 7.5f, "2024-06-04"},
            {"Jug", 6.8f, 22.0f, "2024-06-05"},
            {"Plate", 1.1f, 6.0f, "2024-06-05"}
    };
    checkOverFiveLiters(pots);
    std::map<std::string, std::vector<Pot>> grouped;
    groupByDeliveryDate(pots, grouped);

    std::cout << "\n pots grouped by the delivery date\n";
    for (const auto& entry : grouped) {
        std::cout << "- " << entry.first << ": " << entry.second.size() << " pots\n";
    }

    findMostProfitableWeek(grouped);

    return 0;
}
