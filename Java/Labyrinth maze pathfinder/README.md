# Labyrinth recursive and iterative pathfinder with steps.

Program **finds a way** between two given points in a _maze_ which is a 2D array. The array consists of `1's` and `0's` where `1` is a *wall* and
`0` is a *moving field*. Algorithm **avoids the walls** and **outputs steps taken** on the way by writing `N, E, S, W` which are of course respectively
`North, East, South, West`. If the way out **doesn't exist**, program outputs `i/r X`.

Iterative function uses **stack** to solve the problem and can have **only 1 while loop** with space complexity **O(1)**.

Recursive function **cannot have any loops** at all.

User inputs two variables which are **numbers of rows and columns** of our labyrinth. Then, he types **how many data sets (starting and ending
points coordinates) he wants to input**. Then, he puts in letter `"r"` or `"i"` according if he wants to use **recursive** or **iterative** way 
of finding the exit. Lastly the letter is followed by the **coords themselves**.

Example input/output below.

### INPUT:
```
5 5
1 1 1 0 0
0 0 0 0 1
1 1 0 1 1
0 1 0 0 1
0 0 0 1 0
12
r 0 3 0 1
r 0 0 4 4
r 4 0 4 4
r 3 1 4 4
r 4 0 4 0
r 2 0 3 3
i 0 3 0 1
i 0 0 4 4
i 4 0 4 4
i 3 1 4 4
i 4 0 4 0
i 2 0 3 3
```
### OUTPUT:
```
r E E S S S W W N
r E E N N N E N E
r X
r W N N E N E
r
r N N N E
i E E S S S W W N
i E E N N N E N E
i X
i W N N E N E
i
i N N N E
```
