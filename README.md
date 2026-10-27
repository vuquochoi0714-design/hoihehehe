# BÀI BÁO CÁO GIỮA KỲ
# QUẢN LÝ DANH MỤC SẢN PHẨM BẰNG CÂY NHỊ PHÂN TÌM KIẾM (BST)

## Thông tin sinh viên

- Họ và tên: Vũ Quốc Hội
- Mã sinh viên: A54806
- Môn học: Cấu trúc dữ liệu và Giải thuật
- Lớp TC3801
- Ngôn ngữ lập trình: C++

---

# 1. Giới thiệu

Trong các hệ thống quản lý dữ liệu, việc lưu trữ và tìm kiếm thông tin một cách hiệu quả là yêu cầu quan trọng. Cây nhị phân tìm kiếm (Binary Search Tree - BST) là một cấu trúc dữ liệu cho phép thực hiện các thao tác thêm, tìm kiếm và xóa dữ liệu với hiệu suất cao trong trường hợp cây cân bằng.

Trong bài tập này, BST được sử dụng để quản lý danh mục sản phẩm. Mỗi sản phẩm được quản lý thông qua mã sản phẩm, tên sản phẩm, số lượng và đơn giá.

---

# 2. Mục tiêu bài toán

- Hiểu nguyên lý hoạt động của cây nhị phân tìm kiếm (BST).
- Xây dựng BST bằng ngôn ngữ C++.
- Thực hiện các thao tác thêm, tìm kiếm, xóa dữ liệu trên BST.
- Duyệt cây theo thứ tự LNR.
- Thống kê số lượng nút và chiều cao cây.
- Áp dụng kiến thức cấu trúc dữ liệu vào bài toán quản lý sản phẩm.

---

# 3. Phân tích bài toán

Mỗi sản phẩm gồm các thông tin:

- Mã sản phẩm
- Tên sản phẩm
- Số lượng
- Đơn giá

Trong đó:

- Mã sản phẩm được dùng làm khóa để xây dựng BST.
- Nếu mã sản phẩm nhỏ hơn nút hiện tại thì chèn sang cây con trái.
- Nếu mã sản phẩm lớn hơn nút hiện tại thì chèn sang cây con phải.
- Không cho phép tồn tại hai sản phẩm có cùng mã.

---

# 4. Cấu trúc dữ liệu sử dụng

## Cấu trúc Product

```cpp
struct Product {
    int maSP;
    string tenSP;
    int soLuong;
    double donGia;
};
```

## Cấu trúc Node

```cpp
struct Node {
    Product data;
    Node* left;
    Node* right;
};
```

Trong đó:

- data: chứa thông tin sản phẩm
- left: con trái
- right: con phải

---

# 5. Minh họa cây BST

Dữ liệu mẫu:

| Mã sản phẩm | Tên sản phẩm |
|------------|-------------|
| 50 | Bút bi |
| 30 | Vở ô ly |
| 70 | Bìa hồ sơ |
| 20 | Thước kẻ |
| 40 | Tẩy |
| 60 | Sổ tay |
| 80 | Bút chì |

BST được tạo ra:

```text
            50
          /    \
        30      70
       /  \    /  \
     20   40 60   80
```

---

# 6. Các chức năng của chương trình

## 6.1 Thêm sản phẩm

Cho phép người dùng nhập thông tin sản phẩm và thêm vào BST.

Điều kiện:

- Mã sản phẩm không được trùng.
- Nếu trùng sẽ thông báo lỗi.

Ví dụ:

```text
Ma san pham da ton tai!
```

---

## 6.2 Tìm kiếm sản phẩm

Chương trình cho phép tìm kiếm sản phẩm theo mã sản phẩm.

Ví dụ:

```text
Nhap ma can tim: 60
```

Kết quả:

```text
Ma SP: 60
Ten SP: So tay
So luong: 25
Don gia: 25000
```

---

## 6.3 Xóa sản phẩm

Chương trình xử lý đầy đủ ba trường hợp:

### Trường hợp 1: Xóa nút lá

Ví dụ:

```text
Xóa mã 20
```

### Trường hợp 2: Xóa nút có một con

Ví dụ:

```text
Xóa mã 30
```

### Trường hợp 3: Xóa nút có hai con

Ví dụ:

```text
Xóa mã 70
```

---

## 6.4 Duyệt cây theo LNR

Thuật toán:

```text
Left → Node → Right
```

Mục đích:

Hiển thị các sản phẩm theo thứ tự mã sản phẩm tăng dần.

Ví dụ:

```text
20
30
40
50
60
70
80
```

---

## 6.5 Thống kê

Chương trình hỗ trợ:

### Đếm số nút

Ví dụ:

```text
So nut: 7
```

### Tính chiều cao cây

Ví dụ:

```text
Chieu cao cay: 3
```

---

# 7. Thuật toán cài đặt

## Hàm insert()

Chức năng:

- Thêm sản phẩm vào BST.
- Kiểm tra trùng mã sản phẩm.

Nguyên lý:

- Nhỏ hơn → cây trái.
- Lớn hơn → cây phải.
- Bằng nhau → báo trùng.

---

## Hàm search()

Chức năng:

- Tìm kiếm một sản phẩm theo mã.

Nguyên lý:

- So sánh với nút hiện tại.
- Tiếp tục tìm ở cây trái hoặc cây phải.

---

## Hàm deleteNode()

Chức năng:

Xóa một sản phẩm khỏi cây.

Các trường hợp:

1. Nút lá.
2. Nút có một con.
3. Nút có hai con.

---

## Hàm inorder()

Chức năng:

Hiển thị danh sách sản phẩm theo thứ tự tăng dần của mã sản phẩm.

---

## Hàm countNodes()

Chức năng:

Đếm tổng số nút hiện có trên cây.

---

## Hàm height()

Chức năng:

Xác định chiều cao lớn nhất của cây BST.

---

# 8. Kết quả kiểm thử

Sau khi nhập dữ liệu mẫu:

```text
50
30
70
20
40
60
80
```

Kết quả duyệt LNR:

```text
20
30
40
50
60
70
80
```

Tìm kiếm:

```text
60
```

Kết quả:

```text
Tim thay san pham
```

Tìm kiếm:

```text
99
```

Kết quả:

```text
Khong tim thay san pham
```

Thống kê:

```text
So nut: 7
Chieu cao cay: 3
```

Tất cả hình ảnh minh chứng được lưu trong thư mục:

```text
evidence/
```

---

# 9. Độ phức tạp thuật toán

| Thao tác | Trung bình | Trường hợp xấu nhất |
|-----------|-----------|-------------------|
| Thêm | O(log n) | O(n) |
| Tìm kiếm | O(log n) | O(n) |
| Xóa | O(log n) | O(n) |

Nguyên nhân:

Nếu dữ liệu được thêm theo thứ tự tăng hoặc giảm liên tục, BST có thể bị suy biến thành danh sách liên kết, làm giảm hiệu suất xử lý.

---

# 10. Hướng dẫn biên dịch và chạy chương trình

Biên dịch:

```bash
g++ main.cpp -o bst
```

Chạy chương trình:

```bash
./bst
```

---

# 11. Kết luận

Qua bài tập này, em đã xây dựng thành công chương trình quản lý sản phẩm bằng cây nhị phân tìm kiếm (BST) bằng ngôn ngữ C++. Chương trình thực hiện đầy đủ các chức năng thêm, tìm kiếm, xóa, duyệt cây theo thứ tự LNR, đếm số lượng nút và tính chiều cao cây.

Thông qua quá trình thực hiện, em hiểu rõ hơn về cách tổ chức dữ liệu bằng BST, phương pháp quản lý bộ nhớ động và phân tích độ phức tạp của các thuật toán trên cây nhị phân tìm kiếm. Đây là nền tảng quan trọng cho việc nghiên cứu các cấu trúc dữ liệu nâng cao trong tương lai.