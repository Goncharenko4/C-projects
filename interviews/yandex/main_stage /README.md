## Interview in Yandex

*Read this in other languages: [English](README.md), [Русский](README.ru.md).*

<b> [Task A. Cinema](./1_task.cpp): </b><br>

Search for a suitable place in the cinema.<br>
Find an empty seat with the greatest distance to the nearest occupied seats.<br>

<br><b>Input format:</b><br>
The first line of input file contains one number `n`, `n ≤ 10000`.
Each of the following `n` lines contains exactly one number - 0 or 1 (free or occupied space).

<br><b>Output format:</b><br>
The output file must contain a single number - the maximum length to the nearest occupied space.

<br><b>Input:</b><br>
```none
7
1
0
1
0
0
0
1
```

<br><b>Output:</b><br>
```none
2
```

<br> <b> [Task B. Consecutive ones](./2_task.cpp): </b><br>

It is required to find the longest sequence of `1` in a binary vector and output its length,
provided that one element must be deleted.<br>

<br><b>Input format:</b><br>
The first line of input file contains one number `n`, `n ≤ 10000`.
Each of the following `n` lines contains exactly one number - 0 or 1

<br><b>Output format:</b><br>
The output file must contain a single number — the length of the longest sequence of `1`
in the input array.

<br><b>Input:</b><br>
```none
8
0
1
0
1
1
0
1
1
```

<br><b>Output:</b><br>
```none
4
```

<br> <b> [Task C. Straight line of symmetry](./3_task.cpp): </b><br>

An arbitrary set of integer points is given. Is it possible to draw a vertical line that will be
a straight line of symmetry? <br>

<br><b>Input format:</b><br>
The first line of input file contains one number `n`, `n ≤ 1000000`.
On the next `n` lines there are pairs of numbers - coordinates of points, one per line.

<br><b>Output format:</b><br>
The output file should contain `Yes` if such a line can be drawn, and `No` otherwise.

<br><b>Input:</b><br>
```none
3
-5 7
5 7
0 2
```

<br><b>Output:</b><br>
```none
Yes
```

<br> <b> [Task D. Deleting repetitions](./4_task.cpp): </b><br>

The function template is given:<br>
```cpp
void remove(std::vector<int>&v, int val);
```
It is necessary to remove from the vector `v` all elements equal to `val`. 

<br> <b> [Task E. Stack](./5_task.cpp): </b><br>

It is necessary to implement the `Stack` class, with methods: `push()`, `pop()`, `max()` working on O(1).<br>
The `max()` method returns the current maximum in the stack.
