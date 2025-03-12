#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& array, int target) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            left = mid + 1;
        } else if (array[mid] > target) {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> array = {114, 514, 19, 1, 9, 81, 0};
    sort(array.begin(), array.end()); // 二分查找仅对有序数组有效，因为查找数据时的“二分”是建立在数组有序的前提下的

    int result = binarySearch(array, 114);
    if (result == -1) {
        cout << "没找到。" << endl;
    } else {
        cout << "找到了：" << array[result] << endl;
    }
    return 0;
}