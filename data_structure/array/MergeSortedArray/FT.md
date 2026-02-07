# Merge Sorted Array

## Vấn đề giải quyết

### **Đề**: Yêu cầu: Gộp hai mảng đã sắp xếp thành một mảng duy nhất cũng được sắp xếp.

**Giải thích:** Đề tài này yêu cầu người dùng trộn 2 mảng đã sắp xếp thành 1 mà không dùng một mảng nào khác ngoài hai mảng đã cho. Cả 2 mảng có thể có kích thước ngang nhau hoặc lớn hơn hoặc bé hơn.

## Ý tưởng cốt lõi

Để giải quyết bài toán này ta sẽ sử dụng kỹ thuật **Three-Pointers Technique**.

Trước tiên ta phải biết rằng để trộn được hai mảng mà không qua mảng trung gian thì ta buộc phải sử dụng một trong hai mảng làm nơi chứa, ở đây sẽ dùng mảng 1 cho thuận tiện. Ta phải cho mảng 1 có kích thước vừa đủ với mảng 2.

Gọi 3 con trỏ lần lượt là `i`,`j`,`k` và trỏ lần lượt tới `vị trí cuối cùng có giá trị khác 0 của mảng 1`, `vị trí cuối cùng có giá trị của mảng 2`, ` vị trí cuối cùng có giá trị bằng 0 của mảng 1`

Ta lần lượt duyệt ngược cả hai mảng và so sánh giá trị của 2 con trỏ `i` và `j` nếu lớn hơn thì sẽ được đưa vào giá trị con trỏ `k` đồng thời `k` giảm vị trí đi 1 tức (k--) và `i` hoặc `j` giảm đi 1 tức (i-- hoặc j--); Tiếp tục duyệt đến khi hết cả 2 mảng.

## Chạy từng bước như sau

> Lưu ý phần này chỉ tập trung vào thuật toán chính và bỏ qua các bước kiểm tra thông thường

Input:

arr1 = [1, 2, 5, 7, 44, 0, 0, 0, 0]

arr2 = [2, 4, 6, 8]

Output: arr1 = [1, 2, 2, 4, 5, 6, 7, 8, 44]

Bước 1: Kiểm tra giá trị của `i` >= `j` => 44 >= 8 => gán `*k` = `*i` = 44

`i--` và `k--`

mảng hiện tại [1, 2, 5, 7, 44, 0, 0, 0, 44]

Bước 2: Kiểm tra giá trị của `i` >= `j` => 7 >= 8 => gán `*k` = `*j` = 8

`j--` và `k--`

mảng hiện tại [1, 2, 5, 7, 44, 0, 0, 8, 44]

Bước 3: Kiểm tra giá trị của `i` >= `j` => 7 >= 6 => gán `*k` = `*i` = 7

`i--` và `k--`

mảng hiện tại [1, 2, 5, 7, 44, 0, 7, 8, 44]

Bước 4: Kiểm tra giá trị của `i` >= `j` => 5 >= 6 => gán `*k` = `*j` = 6

`j--` và `k--`

mảng hiện tại [1, 2, 5, 7, 44, 6, 7, 8, 44]

Bước 5: Kiểm tra giá trị của `i` >= `j` => 5 >= 4 => gán `*k` = `*i` = 5

`i--` và `k--`

mảng hiện tại [1, 2, 5, 7, 5, 6, 7, 8, 44]

Bước 6: Kiểm tra giá trị của `i` >= `j` => 2 >= 4 => gán `*k` = `*j` = 4

`j--` và `k--`

mảng hiện tại [1, 2, 5, 4, 5, 6, 7, 8, 44]

Bước 7: Kiểm tra giá trị của `i` >= `j` => 2 >= 2 => gán `*k` = `*i` = 2

`i--` và `k--`

mảng hiện tại [1, 2, 2, 7, 5, 6, 7, 8, 44]

Bước 8: Kiểm tra giá trị của `i` >= `j` => 1 >= 2 => gán `*k` = `*j` = 2

`j--` và `k--`

mảng hiện tại [1, 2, 2, 7, 5, 6, 7, 8, 44]

Lúc này mảng j đã hết nên DỪNG.

> Nếu trong trường hợp mảng j còn nhưng mảng i hết thì chỉ việc gán toàn bộ mảng j vào mảng i từ vị trí k còn đang đứng.
> Ví dụ: arr1 = [10, 0, 0, 0] và arr2 = [2, 5, 8]
>
> Chạy nhanh
>
> arr1 = [10, 0, 0, 0]
>
> arr1 = [0, 0, 0, 10]
>
> Mảng arr1 i đã hết nên sẽ đưa các giá trị mà con trỏ j đang trỏ còn lại vào vị trí k giảm dần
>
> arr1 = [0, 0, 8, 10]
>
> arr1 = [0, 5, 8, 10]
>
> arr1 = [2, 5, 8, 10]

## Độ phức tạp của thuật toán

Độ phức tạp thời gian (Time Complexity): $O(n + m)$. Ta chỉ duyệt qua mỗi phần tử của hai mảng đúng một lần duy nhất.
