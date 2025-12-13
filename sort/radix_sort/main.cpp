/**
**  THUẬT TOÁN RADIX_SORT(A, n):
**      // A là mảng cần sắp xếp, n là số phần tử
**  
**      // Bước 1: Tìm giá trị lớn nhất để biết số chữ số cần xét
**      max ← A[0]
**      cho i từ 1 đến n-1:
**          nếu A[i] > max thì max ← A[i]
**  
**      // Bước 2: Sắp xếp theo từng chữ số (bắt đầu từ LSD)
**      exp ← 1   // exp là 1, 10, 100, ... (chữ số hàng đơn vị, chục, trăm,...)
**      trong khi (max / exp > 0):
**          COUNTING_SORT_THEO_CHU_SO(A, n, exp)
**          exp ← exp * 10
**  
**  
**  THUẬT TOÁN COUNTING_SORT_THEO_CHU_SO(A, n, exp):
**      tạo mảng output có kích thước n
**      tạo mảng count[10] = {0}   // vì chữ số từ 0 → 9
**  
**      // Bước 1: Đếm số lần xuất hiện của từng chữ số
**      cho i từ 0 đến n-1:
**          digit ← (A[i] / exp) % 10
**          count[digit] ← count[digit] + 1
**  
**      // Bước 2: Tính tổng tích lũy
**      cho i từ 1 đến 9:
**          count[i] ← count[i] + count[i-1]
**  
**      // Bước 3: Tạo mảng output (duyệt ngược để ổn định)
**      cho i từ n-1 xuống 0:
**          digit ← (A[i] / exp) % 10
**          output[count[digit] - 1] ← A[i]
**          count[digit] ← count[digit] - 1
**  
**      // Bước 4: Copy về mảng A
**      cho i từ 0 đến n-1:
**          A[i] ← output[i]
**  
*/