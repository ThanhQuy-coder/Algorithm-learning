#include <iostream>
using namespace std;

void pascal_is_triangle(int number) {
    for (int i = 0; i < number; i++) {

        // * In khoảng trắng
        for (int space = 0; space <= number - i; space++) {
            cout << "  ";
        }
        
        int num = 1;

        // * In số
        for (int j = 0; j < i + 1; j++) {
            cout << num << "   ";
            num = num * (i-j) / (j + 1);
        }

        cout << endl;
    }
}

int main() {
    pascal_is_triangle(5);
    return 0;
}
