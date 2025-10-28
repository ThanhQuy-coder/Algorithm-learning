# Bubble Sort – Thuật toán sắp xếp nổi bọt

## 1. Mục tiêu bài học

- Giúp người học hiểu cách hoạt động của Bubble Sort
- Phân tích độ phức tạp và ứng dụng
- So sánh với các thuật toán khác

## 2. Ý tưởng thuật toán

Bubble Sort (sắp xếp nổi bọt) hoạt động dựa trên ý tưởng rất trực quan:

> Liên tục so sánh hai phần tử liền kề, nếu phần tử trước lớn hơn phần tử sau thì đổi chỗ cho nhau.

Quá trình này được lặp lại nhiều lần, khiến các phần tử lớn “nổi dần lên trên” (về cuối mảng) — giống như bọt nước nổi lên mặt nước, nên mới có tên là “Bubble”.

## 3. Quy trình thực hiện

Mã giả:

```pseudocode
for i from 1 to n:
    for j from 0 to n-1:
        if a[j] > a[j+1]
            swap(a[j], a[j+1])
```

## 4. Độ phức tạp của thuật toán

| Trường hợp | Số bước                   | Độ phức tạp |
| ---------- | ------------------------- | ----------- |
| Tốt nhất   | Không cần hoán đổi        | O(n)        |
| Trung bình | So sánh và hoán đổi nhiều | O(n²)       |
| Xấu nhất   | Mảng đảo ngược hoàn toàn  | O(n²)       |

## 5. Ví dụ minh họa

Ví dụ: một mảng đơn giản [5,8,1], mong muốn tăng dần, thuật toán sẽ được biểu diễn như sau:

- Vòng lặp `i = 1` và `j = 0`:
  `j = 5`, `j + 1 = 8`.
  Kiểm tra thấy điều kiện `j < j + 1` **thỏa mãn** --> tiếp tục vòng lặp `j` tăng lên 1.
- Vòng lặp `i = 1` và `j = 1`:
  `j = 8` và `j + 1 = 1`.
  Kiểm tra thấy điều kiện `j < j + 1` **không thỏa mãn**.
  Thực hiện hoán đổi `j` và `j + 1` --> `j = 1` và `j + 1 = 8`.
  Tiếp tục vòng lặp `j` tăng lên 1.
- Vòng lặp `i = 1` và `j = 2`:
  Thoát vòng lặp `j` vì `j < n-1` không thỏa.
- Vòng lặp `i = 2` và `j = 0`:
  `j = 5`, `j + 1 = 1`.
  Kiểm tra thấy điều kiện `j < j + 1` **không thỏa mãn**.
  Thực hiện hoán đổi `j` và `j + 1` --> `j = 1` và `j + 1 = 5`.
  Tiếp tục vòng lặp `j` tăng lên 1.
- Vòng lặp `i = 2` và `j = 1`:
  `j = 5`, `j + 1 = 8`.
  Kiểm tra thấy điều kiện `j < j + 1` **thỏa mãn** --> tiếp tục vòng lặp `j` tăng lên 1.
- Vòng lặp `i = 2` và `j = 2`:
  Thoát vòng lặp `j` vì `j < n-1` không thỏa.
- Vòng lặp `i = 3`:
  Thoát vòng lặp `i` vì `i < n` không thỏa.

## 6. Ưu điểm & nhược điểm

### a. Ưu điểm

- Dễ hiểu, dễ cài đặt — phù hợp cho người mới học thuật toán.
- Ổn định — giữ nguyên vị trí tương đối của các phần tử bằng nhau.
- Có thể dừng sớm — nếu trong một vòng không có lần đổi chỗ nào → dãy đã được sắp xếp → tiết kiệm thời gian.
- Không cần bộ nhớ phụ (in-place) — chỉ đổi chỗ trực tiếp trong mảng.

### b. Nhược điểm

- Hiệu suất thấp: O(n²) khiến nó cực kỳ chậm với dữ liệu lớn.
- So sánh và hoán đổi nhiều lần → tốn thời gian xử lý.
- Không phù hợp thực tế cho các bài toán sắp xếp cần hiệu năng cao.

## So sánh với các thuật toán khác

| Tiêu chí          | **Bubble Sort**            | **Selection Sort**            | **Insertion Sort**           | **Quick Sort**          | **Merge Sort**             |
| ----------------- | -------------------------- | ----------------------------- | ---------------------------- | ----------------------- | -------------------------- |
| Ý tưởng           | So sánh và đổi chỗ liền kề | Tìm phần tử nhỏ nhất mỗi vòng | Chèn phần tử vào đúng vị trí | Chia để trị, chọn pivot | Chia đôi & trộn dãy đã sắp |
| Độ phức tạp TB    | O(n²)                      | O(n²)                         | O(n²)                        | O(n log n)              | O(n log n)                 |
| Hiệu năng thực tế | ❌ Chậm                    | ❌ Chậm                       | ⚪ Trung bình                | ✅ Nhanh                | ✅ Nhanh                   |
| Ổn định           | ✅ Có                      | ❌ Không                      | ✅ Có                        | ❌ Không                | ✅ Có                      |
| Dễ cài đặt        | ✅ Rất dễ                  | ✅ Dễ                         | ✅ Dễ                        | ⚠️ Trung bình           | ⚠️ Khá phức tạp            |

## Ứng dụng thực tế

- Giáo dục: Thường dùng trong giảng dạy lập trình nhập môn để học về vòng lặp, so sánh, và logic sắp xếp.
- Minh họa trực quan: Dễ biểu diễn bằng hoạt ảnh (animation sorting), giúp người học hiểu cơ chế “nổi dần lên”.
- Hệ thống nhỏ, không yêu cầu tốc độ: Khi chỉ có vài chục phần tử, hoặc khi đơn giản là cần minh họa thuật toán.
