# Finding the max sum of elements in 2D array.

For non-empty array find its maximum subarray containing the **largest, non-negative sum**.

Time complexity: O(n<sup>3</sup>).
 
If every element of given input array is **negative**, then the array is **_"empty"_**.

First input variable is **how many sets of data will user want to type in**. Next two variables are respectively numbers of **rows** and **columns**. Indexes of the found sum have to be lexicographically the smallest.

The program outputs **`max_sum = <sum>, a[first_row...first_column][last_row...last_column]`**.

### INPUT: 
```
5
2 5 
1 1 -1 -1  0 
1 1 -1 -1  4 
2 5 
0 -1 -1  1  1 
4 -2 -2  1  1 
2 5 
0 -1 -1  4  0 
4 -2 -2  0  0 
2 5 
-1 -2 -3 -1 -2  
-1 -1 -1 -1 -5 
1 6 
-2 7 -4 8 -5 4
```
### OUTPUT:
```
max_sum = 4, a[1..1][4..4]
max_sum = 4, a[1..1][0..0] 
max_sum = 4, a[0..0][3..3]
empty 
max_sum = 11, a[0..0][1..3]
```
