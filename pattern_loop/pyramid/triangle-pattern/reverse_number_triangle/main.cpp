#include <iostream>
using namespace std;

void print_reverse_number_triangle(int n){
    for (int i = n; i > 0; i--) {
        for (int j = n; j >= i; j--){
            cout << i << " ";
        }
        
        cout << endl;
    }
}

int main() {
    int n = 5;

    print_reverse_number_triangle(n);

    return 0;
}