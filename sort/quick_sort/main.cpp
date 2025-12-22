#include<iostream>
#include<vector>
using namespace std;

/**
 * * Mã giả
  **  Thuật toán QuickSort(A, left, right):
  **  Nếu left >= right:
  **      Dừng (mảng con có 0 hoặc 1 phần tử)
**
  **  Chọn pivot từ A (có thể là phần tử giữa, ngẫu nhiên, hoặc median-of-three)
**
  **  Khởi tạo i = left, j = right
**
  **  Trong khi i <= j:
  **      - Di chuyển i sang phải cho đến khi A[i] >= pivot
  **      - Di chuyển j sang trái cho đến khi A[j] <= pivot
  **      - Nếu i <= j:
  **          Hoán đổi A[i] và A[j]
  **          Tăng i, giảm j
**
  **  Gọi QuickSort(A, left, j)   // sắp xếp nửa bên trái
  **  Gọi QuickSort(A, i, right)  // sắp xếp nửa bên phải
 */

 void print(vector<int> &a) {
    int i = 0;

    while (i < a.size()) {
        cout << a[i] << " ";
        i++;
    }
 }

void quick_sort(vector<int> &a, int left, int right) {

    // * Điều kiện dừng
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    int pivot = a[mid];
    int i = left, j = right;
    
    while (i <= j){
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if (i <= j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++; j--;
        }
    }

    quick_sort(a, left, j);
    quick_sort(a, i, right);
}

void quick_sort_descending(vector<int> &a, int left, int right) {
    if (left >= right){
        return;
    }

    int mid = (left + right) /2;
    int pivot = a[mid];
    int i = left, j = right;

    while (i <= j) {
        while (a[i] > pivot) i++;
        while (a[j] < pivot) j--;
        if (i <= j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++; j--;
        }
    }

    quick_sort_descending(a, left, j);
    quick_sort_descending(a, i, right);
}

int main(){
    vector<int> array = {9, 3, 7, 1, 5, 2, 8};

    cout << "Quick sort: ";
    quick_sort(array, 0, array.size() - 1);

    print(array);

    cout << "\nQuick sort descending:";
    quick_sort_descending(array, 0, array.size() - 1);

    print(array);

    return 0;
}
