# SORTING ALGORITHMS PROJECT

---

## 1. Giới thiệu

Chương trình cài đặt và so sánh 11 thuật toán sắp xếp khác nhau.  

**Mục tiêu:**
- Hiểu cách hoạt động của từng thuật toán
- So sánh hiệu năng thông qua:
  - Thời gian chạy (Running time)
  - Số phép so sánh (Comparisons)

**Danh sách thuật toán:**
- Insertion Sort
- Binary Insertion Sort
- Selection Sort
- Bubble Sort
- Shaker Sort
- Shell Sort
- Heap Sort
- Merge Sort
- Quick Sort
- Counting Sort
- Radix Sort

---

## 2. Yêu cầu hệ thống

- C++ compiler (g++ hoặc tương đương)
- Hệ điều hành: Windows / Linux

---

## 3. Cách biên dịch

Sử dụng lệnh:    g++ main.cpp -o sort.exe

---

## 4. Định dạng file input

File `input.txt` có dạng:  
  n  
  a1 a2 a3 ... an  
Trong đó:
- `n`: số lượng phần tử
- `a[i]`: các số nguyên

---

## 5. Các chế độ chạy chương trình

### 🔹 MODE `-a`: Chạy 1 thuật toán

**Command 1:**  
  ./sort.exe -a [algorithm] input.txt [output]  
Ví dụ:  
  ./sort.exe -a quick-sort input.txt -both

---

**Command 2:**  
  ./sort.exe -a [algorithm] [size] [data order] [output]  
Ví dụ:  
  ./sort.exe -a selection-sort 100 -rand -time

---

**Command 3:**  
  ./sort.exe -a [algorithm] [size] [output]  
Chạy với 4 loại dữ liệu:
- Random
- Sorted
- Reverse
- Nearly sorted  
Ví dụ:  
  ./sort.exe -a merge-sort 7000 -comp  

---

### 🔹 MODE `-c`: So sánh 2 thuật toán

**Command 4:**  
  ./sort.exe -c [algo1] [algo2] input.txt  
Ví dụ:  
  ./sort.exe -c heap-sort merge-sort input.txt  

---

**Command 5:**  
  ./sort.exe -c [algo1] [algo2] [size] [data order]  
Ví dụ:  
  ./sort.exe -c insertion-sort quick-sort 100000 -nsorted  

---

## 6. Tham số

###  Algorithm
- insertion-sort
- binary-insertion-sort
- selection-sort
- bubble-sort
- shaker-sort
- shell-sort
- heap-sort
- merge-sort
- quick-sort
- counting-sort
- radix-sort

---

###  Data order  
-rand : dữ liệu ngẫu nhiên  
-sorted : đã sắp xếp tăng  
-rev : giảm dần  
-nsorted : gần như đã sắp xếp  

---

###  Output  
-time : in thời gian chạy  
-comp : in số phép so sánh  
-both : in cả hai  

---

## 7. Output

- Kết quả được in ra màn hình  
- File `output.txt` chứa mảng sau khi sắp xếp  

---

## 8. Ghi chú

- Các thuật toán được cài đặt để đếm số lần so sánh  
- Thời gian đo bằng `clock()` trong C++  
- Một số thuật toán (Counting Sort, Radix Sort) yêu cầu dữ liệu không âm  

---

**END**
