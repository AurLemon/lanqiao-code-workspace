#include <iostream>

using namespace std;

int factorial(int number) {
    if (number == 0) {
        return 1;
    } else {
        return number * factorial(number - 1);
    }
}

int main() {
    int number;
    cout << "Please enter a number: ";
    cin >> number;

    int result = factorial(number);

    cout << "The factorial is " << result << endl;
}