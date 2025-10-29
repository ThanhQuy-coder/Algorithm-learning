#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &a) {
    for (auto& e : a){
        cout << e << " ";
    }
    cout << "\n";
}

void insertion_sort(vector<int> &a){  
    for (int i = 1; i < a.size(); i++){
        int holePosition = i;
        int valueToInsert  = a[i];

        while (holePosition > 0 && a[holePosition - 1] > valueToInsert){
            a[holePosition] = a[holePosition-1];
            --holePosition;
        }

        a[holePosition] = valueToInsert;
    }
}

void descending_insertion_sort(vector<int> &a){
    for (int i = 0; i < a.size(); i++){
        int holePosition = i;
        int valueToInsert = a[i];

        while(holePosition > 0 && a[holePosition - 1] < valueToInsert) {
            a[holePosition] = a[holePosition - 1];
            holePosition--;
        }

        a[holePosition] = valueToInsert;
    }
}

int main() {

    vector<int> array = {9, 3, 7, 1, 5, 2, 8, 4};

    insertion_sort(array);

    print(array);

    descending_insertion_sort(array);

    print(array);

    return 0;
}