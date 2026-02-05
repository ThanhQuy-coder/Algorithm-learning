#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
**    |--------------------------------------------------------------------|
**    | Cách tiếp cận  | Tốc độ     | Bộ nhớ     | Đánh giá                |
**    | -------------- | ---------- | ---------- | ----------------------- |
**    | Vũ phu         | Chậm       | Thấp       | Dễ hiểu, không hiệu quả |
**    | Bảng băm 2 lần | Nhanh      | Trung bình | Tốt                     |
**    | Bảng băm 1 lần | Nhanh nhất | Trung bình | **Tối ưu nhất**         |
**    |--------------------------------------------------------------------|
*/

class Solution {
    public:
        // * Brute Force => TC: O(N^2) ; SC: O(1)
        // * Target = phần tử 1 + phần tử 2 => phần tử 2 = target - phần tử 1
        // * Nếu biết được phần tử 2 thì cũng biết được index phần tử 2
        vector<int> TwoSum1(vector<int>& nums, int target) {
            for(int i = 0; i < nums.size() - 1; i++) {
                for (int j = i + 1; j < nums.size(); j++){
                    if (nums[j] == target - nums[i]) return {i, j};
                }
            }
            return {};
        }

        // * Two-pass hash table => TC: O(N) ; SP: O(N)
        // *
        // * Giải thích:
        // * Vấn kế thừa một phần của bài trên là tính chất của target
        // * Tạo một map không sắp xếp để lưu vị trí tương ứng với phần tử cần tìm cần tìm
        // * Tức là phần tử có giá trị X ánh xạ tới vị trí x 
        // * 
        // * Lúc tìm vị trí tổng hai phần tử bằng target => tìm index nhanh hơn nhờ map không sắp xếp
        // * Điều kiện kiểm tra: cặp key-value có tồn tại và index của phần tử cần tìm đó không được trùng 
        // * (ví dụ: target = 6 và nums = [3,3] => bị trùng vì và cho ra {0,0})
        // *
        vector<int> TwoSum2(vector<int>& nums, int target) {
            // * Khởi tạo và nạp vào bảng bắm
            unordered_map<int,int> hash;
            for (int i = 0; i < nums.size(); i++) {
                hash[nums[i]] = i;
            }

            // * Tìm vị trí tổng hai phần tử bằng target
            for (int i = 0; i < nums.size(); i++) {
                int complement = target - nums[i];
                if (hash.find(complement) != hash.end() && hash[complement] != i) return {i, hash[complement]};
            }
            return {};
        }

        // * One-pass hash table => TC: O(N) ; SC: O(N)
        // * Kế thừa Two-pass hash table tuy nhiên sẽ gộp hành động nạp lúc đầu và tìm kiếm lại thành 1
        // * Điều kiện tìm kiếm: vẫn như cũ tuy nhiên không cần kiểm tra index số cần tìm có trùng hay không.
        // *
        vector<int> TwoSum3(vector<int>& nums, int target) {
            unordered_map<int,int> hash;
            for (int i = 0 ; i < nums.size() ; i++) {
                int complements = target - nums[i];
                if (hash.find(complements) != hash.end()) return {hash[complements], i};
                hash[nums[i]] = i;
            }
            return {};
        }

        // * One-pass hash table - Nhưng được tối ưu tốt nhất
        vector<int> TwoSum(vector<int>& nums, int target) {
            unordered_map<int,int> hash;
            int complements = 0; // Khai báo ngoài vòng lặp
            for (int i = 0 ; i < nums.size() ; i++) {
                complements = target - nums[i];

                // Sử dụng count thay vì find vì sẽ giúp tìm kiếm nhanh hơn
                // .count(): Tìm kiếm có khóa hay không. Ví dụ .count(2) => true/false // Có hoặc không khóa 2
                // .find(): Tìm kiếm khóa và trả kèm them giá trị. Ví dụ: .find(2) => {2,0} // khóa 2 có giá trị 0
                if (hash.count(complements)) return {hash[complements], i}; 


                hash[nums[i]] = i;
            }
            return {};
        }
};

// Hàm hiển thị phần tử trong mảng
void print(vector<int>& nums) {
    cout << "\nResult: ";
    if (nums.empty()) {
        cout << "Array empty";
    }
    for (auto const& e : nums) {
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    vector<int> nums = {3,3};
    vector<int> result;
    int target = 6, choice;

    cout << "Do you want choose solution? (1-3)" << endl;
    cout << "1. Brute Force" << endl;
    cout << "2. Two-pass hash table" << endl;
    cout << "3. One-pass hash table" << endl;
    cout << "4. One-pass hash table Ultimate" << endl;
    cout << "--> "; cin >> choice;

    switch(choice) {
        case 1:
            result = solution.TwoSum1(nums, target);
            print(result);
            break;
        case 2:
            result = solution.TwoSum2(nums, target);
            print(result);
            break;
        case 3:
            result = solution.TwoSum3(nums, target);
            print(result);
            break;
        case 4:
            result = solution.TwoSum(nums, target);
            print(result);
            break;
        default:
            cout << "Error" << endl;
            break;
    }

    return 0;
}


