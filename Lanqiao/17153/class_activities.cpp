#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // 例如 1, 2, 3, 3, 4, 7, 7, 8, 8, 8, 9, 9 ,9, 0

  // 首先去掉 id 数量偶数的 id 数 1, 2, 4, 8, 9, 9, 9, 0

  // 然后再去重（出现次数大于 2 的倍数 + 1）的去掉 1, 2, 4, 8, 9, 0

  // 最终数组的数字 / 2 就是次数

  // 需要考虑的边界情况：erase删除后影响遍历的索引！

  int count; // 正整数
  vector<int> index; // a1, a2, a3, ..., an

  cin >> count;

  for (int i = 0; i < count; ++i) {
    int n;
    cin >> n;
    index.push_back(n);
  }

  // 去掉 id 数量偶数的 id 数
  int size = index.size();

  for (int i = 0; i < size;) {
    int evenCount = 0;

    for (int j = 0; j < size;) {
      if (index[j] == index[i]) ++evenCount;
      else ++j;
    }

    if (evenCount % 2 == 0) {
      index.erase(remove(index.begin(), index.end(), index[i]), index.end());
      size = index.size();
    } else ++i;
  }

  // 然后再去重
  index.erase(unique(index.begin(), index.end()), index.end());

  // 输出结果
  size = index.size() + 1;
  cout << (size % 2 != 0 ? 0 : size / 2) << endl;

  return 0;
}