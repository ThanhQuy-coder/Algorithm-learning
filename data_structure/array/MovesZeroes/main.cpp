#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int>& arr) {
    // Mảng có bao nhiêu phần tử
    int n = arr.size();
    if (n < 1) return; 

    // Số 0 đầu tiên của mảng
    int* end = &arr[0] + n;
    int* pi = &arr[0];
    while(*pi != 0 && pi < end) {
        pi++;
    }

    if (pi >= end) return;

    int* pj = pi + 1;

    while ((pj - &arr[0]) < arr.size()) {
        if (*pj != 0) {
            // Swap giá trị mà con trỏ pi và pj đang giữ
            swap(*pi, *pj);

            //  tăng index của pi
            pi++;
        } 

        pj++;
    }
}

void print(vector<int>&arr) {
    for (auto e : arr) {
        cout << e << " ";
    }
}

int main() {
    vector<int> array = {1,0,0,3,12};

    solution(array);
    print(array);

    return 0;
}