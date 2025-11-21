#include <iostream>
using namespace std;

/**
 * 
    **THUẬT TOÁN HEAP_SORT(A, n):
    **    // Bước 1: Xây dựng Max-Heap
    **    XÂY_DỰNG_HEAP(A, n)
**
    **    // Bước 2: Trích dần phần tử lớn nhất
    **    cho i từ n-1 xuống 1:
    **        hoán_đổi(A[0], A[i])      // đưa phần tử lớn nhất về cuối
    **        HEAPIFY(A, i, 0)          // duy trì tính chất heap cho phần còn lại
**
**
    **THUẬT TOÁN XÂY_DỰNG_HEAP(A, n):
    **    cho i từ ⌊n/2⌋ - 1 xuống 0:
    **        HEAPIFY(A, n, i)
**
**
    **THUẬT TOÁN HEAPIFY(A, n, i):
    **    largest ← i
    **    left ← 2*i + 1
    **    right ← 2*i + 2
**
    **    nếu left < n và A[left] > A[largest]:
    **        largest ← left
    **    nếu right < n và A[right] > A[largest]:
    **        largest ← right
**
    **    nếu largest ≠ i:
    **        hoán_đổi(A[i], A[largest])
    **        HEAPIFY(A, n, largest)
 */

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