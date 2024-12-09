#include <bits/stdc++.h>

using namespace std;

bool checkPlus(long long n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
  long long count;
  cin >> count;

  vector<bool> answer;

  for (long long i = 0; i < count; ++i) {
    long long n;
    cin >> n;
    bool result = checkPlus(n);
    answer.push_back(result);
  }

  long long resultCount = 0;
  for (long long i = 0; i < answer.size(); ++i) {
    if (answer[i] != false) ++resultCount;
  }

  cout << resultCount << endl;

  return 0;
}