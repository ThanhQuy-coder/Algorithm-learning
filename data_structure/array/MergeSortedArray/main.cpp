#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int> &arr1, int n1, vector<int> &arr2, int n2)
{
    // Tăng kích thước cho mảng 1 để đủ với mảng 2
    arr1.resize(n1 + n2);

    // Khai báo chính
    int i = n1 - 1;
    int j = n2 - 1;
    int k = n1 + n2 - 1;

    while(i >= 0 && j >= 0) {
        if (arr1[i] >= arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }

    // Nếu arr2 vẫn còn phần tử (arr1 hết trước)
    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }
}

void print(vector<int> &arr) {
    for (auto& e : arr) {
        cout << e << " ";
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 5, 7, 44};
    vector<int> nums2 = {2, 4, 6, 8};

    solution(nums1, nums1.size(), nums2, nums2.size());
    print(nums1);

    return 0;
}