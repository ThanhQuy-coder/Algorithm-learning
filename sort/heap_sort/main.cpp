#include <iostream>
using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int &n1, int &n2){
    int t = n1;
    n1 = n2;
    n2 = t;
}

void heapify_reverse(int a[], int n, int i) {
    // * vị trí giá trị lớn nhất
    int largest = i;

    // * vị trí node trái và phải
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // * Lấy giá trị lớn nhất của node trái / phải
    if (left < n && a[left] <= a[largest]) {
        largest = left;
    }

    if (right < n && a[right] <= a[largest]) {
        largest = right;
    }

    // * Hoán đổi vị trí giá trị lớn nhất lên root
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify_reverse(a, n, largest);
    }
}

void heapify(int a[], int n, int i) {
    // * vị trí giá trị lớn nhất
    int largest = i;

    // * vị trí node trái và phải
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // * Lấy giá trị lớn nhất của node trái / phải
    if (left < n && a[left] >= a[largest]) {
        largest = left;
    }

    if (right < n && a[right] >= a[largest]) {
        largest = right;
    }

    // * Hoán đổi vị trí giá trị lớn nhất lên root
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort_reverse(int a[], int n) {
    // * Tạo cấu trúc heap
    for (int i = (n/2) - 1; i >= 0 ; i--) {
        heapify_reverse(a, n, i);
    }

    // * Sắp xếp cấu trúc heap
    for (int i = n - 1; i >= 1; i--) {
        swap(a[0], a[i]);
        heapify_reverse(a, i, 0);
    }
}

void heap_sort(int a[], int n) {
    // * Tạo cấu trúc heap
    for (int i = (n/2) - 1; i >= 0 ; i--) {
        heapify(a, n, i);
    }

    // * Sắp xếp cấu trúc heap
    for (int i = n - 1; i >= 1; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    int a[] = {14,24,33,2,66,3,19,3,25};
    int n = sizeof(a) / sizeof(a[0]);

    heap_sort(a, n);
    print(a,n);

    int a_r[] = {14,24,33,2,66,3,19,3,25};
    heap_sort_reverse(a_r, n);
    print(a_r,n);

    return 0;
}