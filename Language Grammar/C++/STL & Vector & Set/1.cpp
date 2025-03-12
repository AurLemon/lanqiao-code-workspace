#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> v;

    // cout 不带 endl 会咋样？ - 不会自己换行。endl 是换行符，换行以后还会刷新缓冲区（临时内存，用来存储数据）。

    cout << "请输入数字个数" << endl;
    cin >> n;

    cout << "请输入数组，用空格分隔" << endl;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 这种写法和 int value: v 有什么区别？
    // - int value: v 是 范围 for 循环。直接访问容器中的元素值，而不是迭代器。无法对容器进行操作（比如删除元素）。
    //   下意识错误的认为迭代器存在数组索引 也就是比如 v[index] 的方式来删除，但实际上是通过 v.begin() + it 的方式再通过 erase。

    for (auto it = v.begin(); it != v.end();) {
        // 为啥 ++it 不丢上面？因为会导致迭代器失效，如果删掉了是负数的数据，不会往后指向
        if (*it < 0) {
            // 使用 v.erase(it) 删除元素时，erase 会返回一个新的迭代器，这个迭代器指向被删除元素的下一个位置
            // 如果用 it = v.erase(it) 来更新迭代器 容易 UB
            it = v.erase(it);
        } else {
            ++it;
        }
    }

    // 这种写法写完直接能排序了？没有返回值？我以为要 v = sort(v.begin(), v.end()) sort函数接受
    // - 确实。这是原地排序。
    sort(v.begin(), v.end());

    cout << "调整后的数据是：" << endl;
    for (int value: v) {
        cout << value << endl;
    }

    return 0;
}