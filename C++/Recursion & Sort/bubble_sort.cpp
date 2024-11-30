#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& array) {
    int size = array.size();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> array = {114, 514, 19, 1, 9, 81, 0};
    bubbleSort(array);
    for (int num: array)
        cout << num << endl;
    return 0;
}