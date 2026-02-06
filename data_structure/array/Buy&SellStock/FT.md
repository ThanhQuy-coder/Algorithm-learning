# Best Time to Buy and Sell Stock

## Vấn đề giải quyết

### **Đề**: Tìm lợi nhuận lớn nhất có thể đạt được bằng cách mua vào một ngày và bán ra ở một ngày trong tương lai.

Giải thích đơn giản như sau trong một tuần hoặc một tháng sẽ có những ngày giá cổ phần khác nhau và bản thân người giải quyết bài toán phải làm sao mua được cổ phiếu rẻ nhất và bán ra có lợi nhuận cao nhất. Tuy nhiên người bán chúng ta không được quay ngược lại ngày đã trải qua trước đó để bán.

Ví dụ mua thứ 2 thì chỉ có thể bán được các ngày còn lại trong tuần ngoại trừ ngày thứ 2 đã mua, nhiệm vụ phải tìm được lợi nhuận bán cao nhất.

## Ý tưởng cốt lõi của thuật toán

Tìm được một ngày có giá mua rẻ nhất từ đó bán ra sao cho lợi nhuận là cao nhất

Cách thực hiện: Giải theo phương pháp 2 con trỏ (two pointers), gọi 1 con trỏ là `min_price` tượng trưng cho ngày mua rẻ nhất trong tuần/tháng. Tiếp tục gọi tiếp 1 con trỏ là `p` tượng trưng một người đi trinh sát duyệt qua mảng nhằm tìm giá trị mua rẻ hơn và tìm giá trị lợi nhuận cao nhất. Lợi nhuận cao nhất được tính như sau giá trị của `min_price` trừ cho giá trị của `p`.

## Chạy từng bước

> Lưu ý phần này chỉ tập trung vào thuật toán chính và bỏ qua các bước kiểm tra thông thường

Input: [7, 1, 5, 3, 6, 4];
Output: 5;

Bước 1: `min_price` -> a[0] = 7 và `p` -> a[1] = 1 và `max_profit` = 0

Bước 2: Kiểm tra giá trị `min_price` > giá trị `p` (Mục đích kiểm tra xem p có phải là ngày mua rẻ nhất không)

Thỏa mãn

`min_price` -> `p` -> a[1] = 1

`p` tăng lên 1 => `p`-> a[2] = 5

Bước 2: Kiểm tra giá trị `min_price` > giá trị `p`

Không thỏa

Thực hiện việc tính lợi nhuận: `max_profit` = max(`max_profit`, `p` - `min_price`) = max(0, 4) = 4

`p` tăng lên 1 => `p`-> a[3] = 3

Bước 3: Kiểm tra giá trị `min_price` > giá trị `p`

Không thỏa

Thực hiện việc tính lợi nhuận: `max_profit` = max(`max_profit`, `p` - `min_price`) = max(4, 2) = 4

`p` tăng lên 1 => `p`-> a[4] = 6

Bước 4: Kiểm tra giá trị `min_price` > giá trị `p`

Không thỏa

Thực hiện việc tính lợi nhuận: `max_profit` = max(`max_profit`, `p` - `min_price`) = max(4, 5) = 5

`p` tăng lên 1 => `p`-> a[5] = 4

Bước 5: Kiểm tra giá trị `min_price` > giá trị `p`

Không thỏa

Thực hiện việc tính lợi nhuận: `max_profit` = max(`max_profit`, `p` - `min_price`) = max(5, 3) = 5

`p` tăng lên 1 => `p`-> a[6] = `dữ liệu rác ` => vượt quá vòng lặp nên DỪNG

## Độ phức tạp

Độ phức tạp thời gian (Time Complexity): $O(n)$. Ta chỉ duyệt mảng đúng một lần duy nhất từ đầu đến cuối bằng con trỏ p. Mọi thao tác bên trong vòng lặp (so sánh, gán, tính max) đều là các thao tác hằng số $O(1)$.
