#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Please input numbers to find average." << endl;
        return 0;
    }

    vector<double> numbers;

    for (int i = 1; i < argc; ++i) {
        istringstream iss(argv[i]);
        double num;
        if (iss >> num) {
            numbers.push_back(num);
        } else {
            cerr << "Invalid input detected, skipping: " << argv[i] << endl;
        }
    }

    double sum = 0;
    for (double num : numbers) {
        sum += num;
    }
    int average = static_cast<int>(sum / numbers.size());

    cout << "---------------------------------" << endl;
    cout << "Average of " << numbers.size() << " numbers = " 
         << average << endl;
    cout << "---------------------------------" << endl;

    return 0;
}
