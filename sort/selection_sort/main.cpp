#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

int main() {
    vector<int> array = {9, 3, 7, 1, 5, 2, 8, 4};

    selection_sort(array);

    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }

    return 0;
}