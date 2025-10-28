/**
 * Cho một mảng số nguyên gồm 8 phần tử: [9, 3, 7, 1, 5, 2, 8, 4]
 * Sử dụng thuật toán bubble sort để sắp xếp mảng này theo hướng tăng hoặc giảm dần
 */

#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - 1; j++){
            if (arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}



int main() {
    vector<int> arr = {9, 3, 7, 1, 5, 2, 8, 4};

    bubble_sort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}