#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int>& array) {
    int size = array.size();

    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;

        for (; j >= 0 && array[j] > key; --j) {
            array[j + 1] = array[j];
        }

        array[j + 1] = key;
    }
}

int main() {
    vector<int> array = {114, 514, 19, 1, 9, 81, 0};
    insertSort(array);
    for (int num: array)
        cout << num << endl;
    return 0;
}