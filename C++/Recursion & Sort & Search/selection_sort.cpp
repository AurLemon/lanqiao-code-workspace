#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& array) {
    int size = array.size();

    for (int i = 0; i < size; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        swap(array[i], array[minIndex]);
    }
}

int main() {
    vector<int> array = {114, 514, 19, 1, 9, 81, 0};
    selectionSort(array);
    for (int num: array)
        cout << num << endl;
    return 0;
}