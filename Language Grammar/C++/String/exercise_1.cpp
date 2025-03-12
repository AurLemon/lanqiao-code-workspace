#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1 = "abc";
    string str2 = str1;
    string str3 = str1 + str2;
    cout << str3 << endl;

    str1 = "hello ";
    str2 = "world";
    str3 = str1.append("abcd", 2);
    cout << str3 << endl;
}