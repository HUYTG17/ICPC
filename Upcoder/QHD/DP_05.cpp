Cho một xâu s gồm các ký tự số (mỗi ký tự nằm trong phạm vi '0' -> '9'). Mỗi số được tạo từ các ký tự trong phạm vi từ i đến j mà chia hết cho 2 thì được gọi là một số đẹp. Số đẹp được phép chứa các số 0 vô nghĩa ở đầu. Hãy tính tất cả các số đẹp trong phạm vi từ l đến r ( l <= i <= j <= r).
Input:
- Dòng 1 : Xâu s. (s.size() <= 2.105).
- Dòng 2: Một số nguyên dương q đại diện cho số truy vấn (1 <= q <= 2.105).
- Q dòng tiếp theo gồm một cặp số nguyên li, ri. (0 <= l <= r < s.size()).
Output:
Q số nguyên đại diện cho số lượng các số đẹp trong phạm vi từ li đến ri.
Ví dụ:

Input

Output

467364984

4

0 4

1 3

4 6

2 7

8 1 3 13 


