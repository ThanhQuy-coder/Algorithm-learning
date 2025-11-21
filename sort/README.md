# Các loại sắp xếp

- [x] 1. Bubble Sort (Sắp xếp nổi bọt)
- [x] 2. Selection Sort (Sắp xếp chọn)
- [x] 3. Insertion Sort (Sắp xếp chèn)
- [x] 4. Merge Sort (Sắp xếp trộn)
- [x] 5. Quick Sort (Sắp xếp nhanh)
- [x] 6. Heap Sort (Sắp xếp bằng heap)
- [x] 7. Counting Sort (Sắp xếp đếm)
- [ ] 8. Radix Sort (Sắp xếp theo chữ số)
- [ ] 9. Bucket Sort (Sắp xếp theo nhóm)
- [ ] 10. Shell Sort (Sắp xếp vỏ)
- [ ] 11. Tim Sort (Sắp xếp lai giữa merge và insertion — dùng trong Python/Java)

## 📊 Bảng đánh giá các thuật toán sắp xếp

| #   | Thuật toán            | Ưu điểm                                                                                                                    | Nhược điểm                                                                                      |
| --- | --------------------- | -------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------- |
| 1   | Bubble Sort (Nổi bọt) | - Cài đặt đơn giản<br>- Dễ hiểu, dễ nhớ<br>- Có thể dừng sớm nếu mảng đã sắp xếp                                           | - Hiệu suất thấp: \(O(n^2)\)<br>- Không dùng cho dữ liệu lớn                                    |
| 2   | Selection Sort (Chọn) | - Dễ cài đặt<br>- Ít hoán đổi hơn Bubble Sort<br>- Hoạt động tốt trên mảng nhỏ                                             | - Vẫn chậm: \(O(n^2)\)<br>- Không ổn định                                                       |
| 3   | Insertion Sort (Chèn) | - Hiệu quả với mảng nhỏ hoặc gần như đã sắp xếp<br>- Ổn định<br>- Cài đặt đơn giản                                         | - Trung bình và xấu nhất vẫn \(O(n^2)\)<br>- Không phù hợp cho dữ liệu lớn                      |
| 4   | Merge Sort (Trộn)     | - Độ phức tạp \(O(n \log n)\) ổn định<br>- Ổn định<br>- Phù hợp cho dữ liệu lớn<br>- Hoạt động tốt với linked list         | - Tốn bộ nhớ phụ<br>- Cài đặt phức tạp hơn                                                      |
| 5   | Quick Sort (Nhanh)    | - Trung bình rất nhanh: \(O(n \log n)\)<br>- Ít dùng bộ nhớ phụ<br>- Thường nhanh hơn Merge Sort trong thực tế             | - Trường hợp xấu nhất \(O(n^2)\) nếu chọn pivot kém<br>- Không ổn định                          |
| 6   | Heap Sort (Heap)      | - Độ phức tạp \(O(n \log n)\) ổn định<br>- Không cần nhiều bộ nhớ phụ<br>- Đảm bảo hiệu suất trong mọi trường hợp          | - Không ổn định<br>- Thực tế thường chậm hơn Quick Sort và Merge Sort                           |
| 7   | Counting Sort (Đếm)   | - Rất nhanh: \(O(n + k)\) với \(k = \text{max} - \text{min} + 1\)<br>- Không dựa vào so sánh<br>- Ổn định nếu cài đặt đúng | - Chỉ áp dụng cho số nguyên hoặc dữ liệu có phạm vi nhỏ<br>- Tốn bộ nhớ nếu phạm vi giá trị lớn |
