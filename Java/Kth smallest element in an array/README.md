# Selection of the kth smallest element in 1D array.

Program searches for and outputs an element that is the **kth smallest** in a **non-decreasing** array.
The search is performed by operations on a **Binary Search Tree**.

Time complexity: **O(n)**.

Space complexity: **O(h)** where `h` is a height of a tree.

First input variable is **how many data sets user will put in**. Second is the **array size followed by array's values**. Next, user inputs
how many `"kth smallest element place"` requests are supposed to be made. Lastly, he types in the `"kth smallest element places"` as many times, as he did input in the previous
variable. The output consists of `"kth smallest element place"` and the `"kth smallest element value"`. Also, if there is no 
`"kth smallest element value"` on the `"kth smallest element place"`, the program outputs correct answer.

Example input/output below.

### INPUT:
```
3
5
1 2 3 4 5 
3 
1 2 3
5 
5 3 4 4 3
5 
2 5 1 3 4
10
1 1 1 1 1 1 1 1 1 1
5
1 10 0 -1 11
```
### OUTPUT:
```
1 1 
2 2 
3 3 
2 3 
5 5
1 3 
3 4
4 4
1 1
10 1
0 brak
-1 brak
11 brak
```
