#include <iostream>

using namespace std;

void f(int n) {
    if (n == 10)
        return;
    f(n / 10);
    cout << n % 10 << '-';
}

int main() {
    int n;
    cin >> n;
    f(n);
    return 0;
}