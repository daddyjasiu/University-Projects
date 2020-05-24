# Recursive and iterative searching in 2D array.

Program searches for a **first indexes and last indexes of a given value in a 2D array** by using **both iterative and recursive** functions.

Time complexity of both functions: **O(n)**

Recursive function is **not using any loop** and iterative function is **not using any other function**.

First input variable is **how many data sets will user put in**. Then he types **number of rows and colmuns** of a 2D array followed by 
**non-decreasing values of the array** itself. Lastly he types in the **value he is looking for**. Program outputs **first and last indexes of
rows and columns** in both functions respectively. If number is **not present** in the array, program **outputs** that this has occured. Note that
the output language is **Polish**, but it does **not** change the logic behind the program.

### INPUT:
```
3
3 4
10 10 10 10
10 20 20 30
20 20 20 40
20 
3 4 
10 10 10 10
10 20 20 30
20 20 20 40
50
3 3
10 10 10
10 20 20
20 20 20 
10
```
### OUTPUT:
```
RekPier: 20 w (1,1)
RekOst: 20 w (2,2)
IterPier: 20 w (1,1)
IterOst: 20 w (2,2)
---
RekPier: nie ma 50
RekOst:nie ma 50
IterPier: nie ma 50
IterOst: nie ma 50
---
RekPier: 10 w (0,0)
RekOst: 10 w (1,0)
IterPier: 10 w (0,0)
IterOst: 10 w (1,0)
---
```
