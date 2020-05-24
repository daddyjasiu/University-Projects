# Find a number of numbers in a given range using binsearch.

Program if given a set of numbers and range outputs how many numbers are in that range.

Time complexity: algorithm is in **O(log n)** and counting inputs in array that are different from each other is in **O(n)**.

Space complexity: **O(1)**.

First input variable is **how many data sets user will put in**. Next, he inputs **size of an array** and **that many array elements**. Later he puts in **how many pairs (ranges) he will input** and lastly he types the **pairs themselves**. Program outputs **number of numbers in the given range** and at the end of each data set it shows **how many different numbers were there**.

### INPUT:
```
2 
12 
-1 1 2 2 2 3 5 5 7 7 9 9 12 
1 2   
2 2   
3 6  
2 1  
-1 10  
1 0  
4 6 
4 3
-1 9  
1 1 
4 4  
0 9 
10
1 1 1 1 1 1 1 1 1 1 
7 
1 2 
0 1 
1 1 
0 0 
2 2 
3 1 
-1 -1
```
### OUTPUT:
```
4 
3 
3 
0 
12
0 
2 
0 
12
1 
0 
11
7 
//end of data set 1
10
10
10
0 
0 
0 
0 
1
//end of data set 2
```
