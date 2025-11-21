#include <iostream>
using namespace std;

/**
**    THUẬT TOÁN COUNTING_SORT(A, n):
**    // A là mảng cần sắp xếp, n là số phần tử
**
**    // Bước 1: Tìm giá trị lớn nhất (max) và nhỏ nhất (min)
**    min ← A[0]
**    max ← A[0]
**    cho i từ 1 đến n-1:
**        nếu A[i] < min thì min ← A[i]
**        nếu A[i] > max thì max ← A[i]
**
**    // Bước 2: Tạo mảng đếm (count) có kích thước (max - min + 1)
**    tạo mảng count với tất cả phần tử = 0
**
**    // Bước 3: Đếm số lần xuất hiện
**    cho i từ 0 đến n-1:
**        count[A[i] - min] ← count[A[i] - min] + 1
**
**    // Bước 4: Tính tổng tích lũy
**    cho i từ 1 đến (max - min):
**        count[i] ← count[i] + count[i - 1]
**
**    // Bước 5: Tạo mảng kết quả (output)
**    tạo mảng output có kích thước n
**    cho i từ n-1 xuống 0:   // duyệt ngược để giữ tính ổn định
**        output[count[A[i] - min] - 1] ← A[i]
**        count[A[i] - min] ← count[A[i] - min] - 1
**
**    // Bước 6: Copy kết quả về mảng A
**    cho i từ 0 đến n-1:
**        A[i] ← output[i]
**
 */

void print(int a[], int n){
    for (int i = 0; i <= n - 1; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void counting_sort(int a[], int n) {
    // * Tìm số lớn nhất và số bé nhất trong mảng
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }


    // * Tạo mảng đếm
    // * max - min + 1: cách tính độ bao phủ của một dãy số
    int count[max - min + 1] = {0};

    // * Đếm số lần xuất hiện
    // * a[i] - min: cách lấy vị trí trong mảng count 
    // * --> việc lấy phần từ trong mảng a - min thì sẽ ánh xạ được tới vị trí tương ứng trong mảng count
    for (int i = 0; i <= n - 1; i++) {
        count[a[i] - min] = count[a[i] - min] + 1;
    }

    // * Tính tổng tích lũy
    for (int i = 1; i <= (max - min); i++) {
        count[i] = count[i] + count[i-1];
    }

    // * tạo mảng trung gian
    int output[n] = {0};

    // * Tạo mảng kết quả
    // * count[a[i] - min] - 1: công thức "Vị trí cuối cùng của v = count[v - min] - 1"
    for (int i = n - 1; i >= 0; i--) {
        output[count[a[i] - min] - 1] = a[i];
        count[a[i] - min] = count[a[i] - min] - 1;
    }

    // * Gán lại cho mảng chính
    // * Giảm dần
    for (int i = n - 1; i >= 0; i--) {
        a[i] = output[n - i - 1];
    }

    // * Tăng dần
    // for (int i = 0; i <= n - 1; i++) {
    //     a[i] = output[i];
    // }
}

int main() {
    int a[] = {1,3,2,5,2,6,2,1,5,1,2,5};
    int n = sizeof(a) / sizeof(a[0]);

    counting_sort(a, n);
    print(a,n);

    return 0;
}
