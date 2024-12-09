#include <bits/stdc++.h>

using namespace std;

bool isExist(int n, int m) {
  // 我tm套多层循环都给你试一遍不就行了？？？
  // 我是通过 m 还是 n 去找 x 还是 y ？不影响，套循环就行

  // 1 <= x, x < y, y <= m
  // n % x = n % y

  for (int y = 2; y <= m; ++y) { // y
    for (int x = 1; x < y; ++x) { // x
      if (n % y == n % x) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int count;
  cin >> count;

  vector<bool> answer;

  for (int i = 0; i < count; ++i) {
    int n, m;
    cin >> n >> m;
    bool result = isExist(n, m);
    answer.push_back(result);
  }

  for (bool result: answer) {
    cout << (result ? "Yes" : "No") << endl;
  }

  return 0;
}