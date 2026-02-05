# Bài tập theo thứ tự tăng dần như sau

## 1. Moves Zeroes (Dễ)

Yêu cầu: Di chuyển tất cả số 0 về cuối mảng mà không làm thay đổi thứ tự các số khác. Phải thực hiện trực tiếp trên mảng cũ (In-place).

Gợi ý (C++): Sử dụng kỹ thuật Two Pointers (Hai con trỏ).

Một con trỏ chạy để duyệt mảng, một con trỏ giữ vị trí của phần tử không phải số 0 tiếp theo. Dùng hàm std::swap() để đổi chỗ.

## 2. Best Time to Buy and Sell Stock (Cấp độ: Tư duy tối ưu)

Yêu cầu: Tìm lợi nhuận lớn nhất có thể đạt được bằng cách mua vào một ngày và bán ra ở một ngày trong tương lai.

Gợi ý (C++):

Bạn không cần 2 vòng lặp. Chỉ cần 1 vòng lặp duy nhất: Duy trì một biến min_price (giá thấp nhất tính đến hiện tại) và một biến max_profit.

Với mỗi mức giá, cập nhật min_price và tính toán lợi nhuận nếu bán ở mức giá hiện tại.

## 3. Merge Sorted Array (Cấp độ: Xử lý mảng đã sắp xếp)

Yêu cầu: Gộp hai mảng đã sắp xếp thành một mảng duy nhất cũng được sắp xếp.

Gợi ý (C++):

Vì đề bài yêu cầu gộp vào mảng thứ nhất (có đủ khoảng trống ở cuối), hãy dùng Hai con trỏ chạy từ cuối mảng về đầu.

So sánh các phần tử lớn nhất của hai mảng và đặt chúng vào vị trí cuối cùng của mảng 1 để tránh việc phải dịch chuyển (shift) các phần tử nhiều lần.

## 4. Product of Array Except Self (Cấp độ: Trung bình - Khó)

Yêu cầu: Tạo một mảng mới sao cho mỗi phần tử tại i bằng tích của tất cả các phần tử khác trừ chính nó. Không được dùng phép chia.

Gợi ý (C++): Sử dụng kỹ thuật Prefix & Suffix Product.

Bước 1: Duyệt từ trái sang phải để tính tích các số đứng trước i.

Bước 2: Duyệt ngược từ phải sang trái để nhân thêm tích các số đứng sau i.
