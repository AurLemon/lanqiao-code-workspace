#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;
    int count;
    cout << "请输入查询次数" << endl;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int operateNumber;
        int number;
        cin >> operateNumber >> number;

        switch (operateNumber) {
            case 1:
                s.insert(number);
                break;
            
            case 2:
                s.erase(number);
                break;

            case 3:
                s.count(number) ? cout << "YES" << endl : cout << "NO" << endl;
                break;
            
            default:
                return -1;
        }
    }

    return 0;
}