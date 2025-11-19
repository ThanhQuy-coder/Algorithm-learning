#include <iostream>
using namespace std;

// ? Đề bài yêu cầu in dãy số từ 1 đến n thành hình kim tự tháp
/**
 * * Mã giả
 * * Cho i chạy từ 1 đến n:
 * *      Cho space chạy từ 0 đến n - i:
 * *          In khoảng trắng;
 * *      Cho j chạy từ 1 đến khi j > i + 1:
 * *          In j và khoảng trắng phía sau
 * *      In xuống dòng
 * 
 * * Gợi ý: 
 * * Bài này sẽ có vấn đề ở phần căn lề cho kim tự tháp.
 * * ==> Vậy nên giải pháp chúng ta là phải tập chung vào các phần in khoảng trắng (có 2 nơi).
 * * Tôi khuyến khích mọi người sử dụng khoảng trắng theo cách truyền thống này trước khi sử dụng
 * * những cách khác từ các thư viện như String, iomanip
 */

void print_pyramid(int n) {
    for (int i = 1; i <= n; i++) {
        
        // * In khoảng trắng
        for (int space = 0; space < n - i; space++) {
            cout << "  ";
        }

        // * In số (1,2,...,n)
        for (int j = 1; j < i + 1; j++) {
            cout << j << "   ";
        }

        cout << endl;
    }
}

int main() {
    print_pyramid(5);
    return 0;
}