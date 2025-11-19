#include <iostream>
using namespace std;

/**
 * ? Cho một dãy số từ 1 đến n, Hãy:
 * ? Câu 1: Viết in ra một hình tam giác bên trái. Ví dụ
 * ? 1
 * ? 1   2
 * ? 1   2   3
 * ? 1   2   3   4
 * 
 * ? Câu 2: Viết in ra một hình tam giác bên trái đảo ngược (ngược luôn cả giá trị). Ví dụ:
 * ? 4  3  2  1
 * ? 4  3  2
 * ? 4  3
 * ? 4
 * 
 * * Mã giả
 * * Ghi chú: number là input người dùng nhập vào
 * * Câu 1:
 * *     Cho i chạy từ 1 đến khi i >= number:
 * *         Cho j chạy từ 1 đến khi j > i + 1:
 * *             In j + khoảng trắng;
 * *         In xuống dòng;
 * 
 * * Câu 2:
 * *      Cho i chạy từ 1 đến khi i >= number:
 * *          Cho j chạy từ number đến khi j < i:
 * *              In j + khoảng trắng;
 * *          In xuống dòng;
 */

void print_left_triangle(int number) {
    for (int i = 1; i <= number; i++) {
        // * In số
        for (int j = 1; j < i + 1; j++) { 
            cout << j << "  ";
        }

        // * Xuống dòng
        cout << endl;
    }
}

void print_inverted_left_triangle(int number) {
    for (int i = 1; i <= number; i++) {

        // * In số
        for (int j = number; j >= i; j--) {
            cout << j << "  ";
        }

        cout << endl;
    }
}

int main() {
    string choose;
    cout << "Do you want print inverted left triangle? (Y/n)" << endl;
    getline(cin, choose);

    if (choose == "n") {
        print_left_triangle(5);
    } else {
        print_inverted_left_triangle(5);
    }

    return 0;
}