#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Bài toán: Tìm lợi nhuận lớn nhất khi mua và bán cổ phiếu (chỉ 1 lần giao dịch).
 * Chiến thuật: "Mỏ neo và Trinh sát" (Two Pointers).
 */
int solution(vector<int>& arr) {
    int n = arr.size();
    // Điều kiện biên: Nếu không có ít nhất 2 ngày thì không thể mua và bán.
    if (n < 2) return 0;

    // min_price (Mỏ neo): Giữ địa chỉ của ngày có giá thấp nhất tính tới thời điểm hiện tại.
    int* min_price = &arr[0];
    
    // p (Trinh sát): Chạy dọc mảng để tìm cơ hội bán hoặc tìm đáy mới thấp hơn.
    int* p = min_price + 1;
    
    int max_profit = 0;

    // Vòng lặp duyệt mảng bằng cách so sánh địa chỉ con trỏ hiện tại với địa chỉ bắt đầu.
    while((p - &arr[0]) < n) {
        
        // TRƯỜNG HỢP 1: Tìm thấy đáy mới.
        // Nếu giá ngày hiện tại (p) thấp hơn giá đáy cũ (min_price), ta dời mỏ neo về p.
        // Lưu ý: min_price = p là thay đổi ĐỊA CHỈ, không phải thay đổi GIÁ TRỊ mảng.
        if (*min_price > *p) {
            min_price = p; 
        } 
        // TRƯỜNG HỢP 2: Giá hiện tại cao hơn đáy.
        // Ta tính thử lợi nhuận nếu bán vào ngày hôm nay và cập nhật kỷ lục (max_profit).
        else {
            max_profit = max(max_profit, *p - *min_price);
        }
        
        // Luôn tiến trinh sát p về phía trước.
        p++;
    }

    return max_profit;
}

void print(vector<int>& arr) {
    for (auto e : arr) cout << e << " ";
    cout << endl;
}

int main() {
    // Test case 1: Lãi đạt được từ 1 lên 6 là 5.
    vector<int> week1 = {7, 1, 5, 3, 6, 4};
    // Test case 2: Giá giảm dần, không có lãi (0).
    vector<int> week2 = {7, 6, 4, 3, 1};
    // Test case 3: Đáy mới xuất hiện muộn (số 1), vẫn tính lãi từ đáy cũ trước đó.
    vector<int> week3 = {4, 6, 1, 3, 2, 0};

    cout << "Lãi tuần 1: " << solution(week1) << endl;
    cout << "Lãi tuần 2: " << solution(week2) << endl;
    cout << "Lãi tuần 3: " << solution(week3) << endl;

    return 0;
}