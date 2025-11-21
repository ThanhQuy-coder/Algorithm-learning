#include <iostream>
using namespace std;

void print_floy_triangle(int n){
    int m = 1;
    for (int i = 1 ; i < n + 1; i++) {
        // in số
        for (int j = 1; j < i + 1; j++) {
            cout << m << " ";
            m += 1;
        }

        cout << endl;
    }
}

int main() {
    int n = 5;

    print_floy_triangle(n);

    return 0;
}