# Moves Zeroes

## Vấn đề cần giải quyết

**Đề:** Di chuyển tất cả số 0 về cuối mảng mà không làm thay đổi thứ tự các số khác. Phải thực hiện trực tiếp trên mảng cũ

Yêu cầu bài này cũng khá rõ ràng và không cần nói gì thêm.

## Ý tưởng cốt lõi của thuật toán

Bài toán này đã được giải theo phương pháp sử dụng 2 con trỏ (two pointers) cho việc di dời tất cả các số 0 về vị trí cuối của mảng.

Cách thực hiện, 1 con trỏ tạm gọi là (flag) được canh giữ tại vị trí có giá trị 0 đầu tiên trong mảng tức là:

```console
a = [1,2,0,2,0,1]; // mảng có giá trị 0 đầu tiên trong chương trình nằm ở vị trí số 2
```

1 con trỏ tiếp theo được đặt ở ngay sau `flag`, tạm gọi con trỏ này là `patrol`.

Nếu trong trường hợp `patrol` có giá trị lớn hơn 0 thì sẽ thực hiện đổi giá trị của con trỏ `flag` và `patrol` cho nhau nhằm đưa số 0 về cuối; đồng thời cũng cho con trỏ `flag` đứng tại vị trí `patrol` đang đứng nhằm bỏ qua đường đi mà `patrol` đã đi qua thỏa điều kiện. tăng `patrol` để nó luôn nằm sau `flag`.

Trường hợp nếu bằng 0 thì tiếp tục cho `patrol` đi đến cuối mảng.

## Chạy từng bước

> Lưu ý phần này chỉ tập trung vào thuật toán chính và bỏ qua các bước kiểm tra thông thường

Input: a = [1,2,0,2,0,1];
Output: a = [1,2,2,1,0,0];

Bước 1: Khởi tạo `flag` và `patrol`

`flag` -> a[2] = 0;
`patrol` -> `flag` + 1 : tương ứng với a[3] = 2;

Bước 2: Kiểm tra điều kiện `patrol` != 0 (Tìm thấy số không bằng 0)

Thỏa mãn

Bước 3: Đổi giá trị 2 con trỏ, đặt lại vị trí chúng

`flag` và `patrol` đổi giá trị cho nhau <=> a[2] đổi với a[3] <=> a[2] = 2 và a[3] = 0

`flag` -> a[3]
`patrol` -> a[4]

Bước 4: Kiểm tra điều kiện `patrol` != 0 (Tìm thấy số không bằng 0)

Không thỏa tiếp tục tăng `patrol` -> a[5]

Bước 5: Kiểm tra điều kiện `patrol` != 0 (Tìm thấy số không bằng 0)

Thỏa mãn

Bước 6: Đổi giá trị 2 con trỏ, đặt lại vị trí chúng

`flag` và `patrol` đổi giá trị cho nhau <=> a[3] đổi với a[5] <=> a[3] = 1 và a[5] = 0

`flag` -> a[5]
`patrol` -> a[6] => quá giới hạn DỪNG

Kết quả: [1,2,2,1,0,0]

## Độ phức tạp

Thuật toán này chỉ duyệt mảng tối đa 2 lần,
mỗi phần tử chỉ bị đụng tới một số lần cố định,
nên khi mảng lớn gấp đôi thì thời gian cũng tăng gấp đôi → O(n).
