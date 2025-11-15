#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& a) {
    for (auto e : a) cout << e << " ";
    cout << '\n';
}

// Thực hiện trộn
/**
 * @param a : mảng hiện tại được thực hiện trộn
 * @param left: vị trí phần tử bên trái cuối của mảng
 * @param mid: vị trí phần tử giữa của mảng
 * @param right: vị trí phần tử bên phải cuối cùng của mảng
*/
void merge(vector<int>& a, int left, int mid, int right) {
    // * tạo mảng phụ
    vector<int> temp;

    // * i: tượng trưng cho việc xét các phần tử dãy bên trái (0 --> mid)
    // * j: tượng trưng cho việc xét các phần tử dãy bên phải (mid + 1 --> right)
    int i = left, j = mid + 1;

    // * Vòng lặp so sánh với điều kiện (i <= mid && j <= right)
    // * Xét 2 trường hợp
    // * TH1: a[i] < a[j] thỏa mãn => push a[i]
    // * TH2: a[i] < a[j] không thỏa => push a[j]
    // ! lưu ý: sẽ có phần tử cuối cùng sót lại
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }

    // * Thực hiện lấy phần tử cuối cùng
    // * TH1: PT cuối nằm bên trái
    // * TH2: PT cuối nằm bên phải
    while (i <= mid) temp.push_back(a[i++]);
    while (j <= right) temp.push_back(a[j++]);

    // * Thực hiện gán lại cho mảng chính
    for (int k = 0; k < temp.size(); k++)
        a[left + k] = temp[k];
}

void descending_merge(vector<int>& a, int left, int mid, int right) {
    vector<int> tmp;
    int i = left, j = mid + 1;

    while(i <= mid && j <= right){
        if (a[i] >= a[j]) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }

    while (i <= mid) tmp.push_back(a[i++]);
    while (j <= right) tmp.push_back(a[j++]);

    for (int k = 0; k < tmp.size(); k++){
        a[left + k] = tmp[k];
    }
}

void merge_sort(vector<int>& a, int left, int right, string &gd) {
    if (left >= right) return;

    // *Lấy giá trị trung tâm
    int mid = (left + right) / 2;

    // *xét nhánh bên trái
    merge_sort(a, left, mid, gd);

    // * xét nhánh bên phải
    merge_sort(a, mid + 1, right, gd);

    if (gd == "Y") {
        descending_merge(a, left, mid, right);
    } else {
        // * trộn
        merge(a, left, mid, right);
    }
}

int main() {
    // * Yêu cầu muốn sắp xếp giảm dần (gradually decrease)
    string gd;
    cout << "Do you want array gradually decrease? (Y/n)" << endl;
    getline(cin, gd);

    vector<int> array = {9, 3, 7, 1, 5, 2, 8};

    merge_sort(array, 0, array.size() - 1, gd);

    print(array);

    return 0;
}
