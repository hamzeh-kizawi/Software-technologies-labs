#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numbers[] = {2, 7, 5, 9, 5, 3};
    int size = 6;
    bool found5 = false;
    int position = -1;

    for(int i = 0; i < size; i++) {
        if(numbers[i] == 5) {
            found5 = true;
            position = i;
            break;
        }
    }

    if(found5) {
        cout << "first 5 found at position: " << position << endl;
    } else {
        cout << "5 was not found in the array" << endl;
    }

    vector<int> nums(numbers, numbers + size);

    cout << "all the odd elements;: ";

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] % 2 != 0) {
            cout << nums[i] << " ";
        }
    }
    cout << endl;

    return 0;
}