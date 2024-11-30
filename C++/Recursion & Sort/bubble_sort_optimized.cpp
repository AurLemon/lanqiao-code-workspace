#include <iostream>
#include <vector>

using namespace std;

void bubbleSortOptimized(vector<int>& array) {
    int size = array.size();

    for (int i = 0; i < size; ++i) {
        bool isSwapped = false;
        for (int j = 0; j < size - i; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped) {
            break;
        }
    }
}

int main() {
    vector<int> array = {114, 514, 19, 1, 9, 81, 0};
    bubbleSortOptimized(array);
    for (int num: array)
        cout << num << endl;
    return 0;
}