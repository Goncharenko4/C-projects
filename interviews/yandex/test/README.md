## Preparing for interview in Yandex

*Read this in other languages: [English](README.md), [Русский](README.ru.md).*

<b> [Task A. Stones and jewelry](./1_task.cpp): </b><br>

Two strings of lowercase Latin characters are given: string J and string S.
The characters included in the string J are "jewels", the characters included in the string S are "stones".
It is necessary to determine how many characters from S are "jewels" at the same time.
Simply put, you need to check how many characters from S are included in J.<br>

<br><b>Input format:</b><br>
The first two lines of the input file contain two strings of lowercase Latin characters:
string J and string S. The length of each one does not exceed 100 characters.

<br><b>Output format:</b><br>
The output file must contain a single number — the number of stones that are jewels.

<br><b>Input:</b><br>
```none
ab
aabbccd
```

<br><b>Output:</b><br>
```none
4
```

<br> <b> [Task B. Consecutive ones](./2_task.cpp): </b><br>

It is required to find the longest sequence of `1` in a binary vector and output its length.<br>
It is desirable to get a solution that works in linear time and at the same time passes through the input
array only once.<br>

<br><b>Input format:</b><br>
The first line of input file contains one number `n`, `n ≤ 10000`.
Each of the following `n` lines contains exactly one number — the next element of array.

<br><b>Output format:</b><br>
The output file must contain a single number — the length of the longest sequence of `1` in the input array.

<br><b>Input:</b><br>
```none
5
1
0
1
0
1
```

<br><b>Output:</b><br>
```none
1
```

<br> <b> [Task C. Removing duplicates](./3_task.cpp): </b><br>

An array of 32-bit integers ordered in non-decreasing order is given. It is required to remove all
repetitions from it.<br>
It is desirable to get a solution that does not read the input file entirely into memory, uses only
a constant amount of memory during operation.<br>

<br><b>Input format:</b><br>
The first line of input file contains one number `n`, `n ≤ 1000000`.
The next `n` lines contain numbers - array elements, one per line.
The numbers are sorted by non-decreasing.

<br><b>Output format:</b><br>
The output file must contain the following unique elements of the input array in ascending order.

## Example 1:
<br><b>Input:</b><br>
```none
5
2
4
8
8
8
```

<br><b>Output:</b><br>
```none
2
4
8
```

## Example 2:
<br><b>Input:</b><br>
```none
5
2
2
2
8
8
```

<br><b>Output:</b><br>
```none
2
8
```

<br> <b> [Task D. Generating bracket sequences](./4_task.cpp): </b><br>

Given an integer `n`. It is required to output all the correct bracket sequences of length `2 * n`,
ordered lexicographically (https://en.wikipedia.org/wiki/Lexicographic_order ).<br>
The problem uses only parentheses.<br>
It is desirable to get a solution that works in a time proportional to the total number of correct
bracket sequences in the answer, and at the same time uses the amount of memory proportional to `n`.<br>

<br><b>Input format:</b><br>
The single line of the input file contains an integer `n`, `0 ≤ n ≤ 11`

<br><b>Output format:</b><br>
The output file contains generated correct bracket sequences ordered lexicographically.

## Example 1:
<br><b>Input:</b><br>
```none
2
```

<br><b>Output:</b><br>
```none
(())
()()
```

## Example 2:
<br><b>Input:</b><br>
```none
3
```

<br><b>Output:</b><br>
```none
((()))
(()())
(())()
()(())
()()()
```

<br> <b> [Task E. Anagrams](./5_task.cpp): </b><br>

Two strings consisting of lowercase Latin letters are given. It is required to determine whether
these strings are anagrams, that is, whether they differ only in the order of the characters.<br>

<br><b>Input format:</b><br>
The input file contains two lines of lowercase Latin characters, each no longer than
`100,000` characters. The lines are separated by a newline character.

<br><b>Output format:</b><br>
The output file must contain one if the strings are anagrams, and zero otherwise.

## Example 1:
<br><b>Input:</b><br>
```none
qiu
iuq
```

<br><b>Output:</b><br>
```none
1
```

## Example 2:
<br><b>Input:</b><br>
```none
zprl
zprc
```

<br><b>Output:</b><br>
```none
0
```

<br> <b> [Task G. Interesting journey](./6_task.go): </b><br>

It's no secret that some programmers really like to travel. Well-known programmer Petya also loves
to travel, visit museums and see the sights of other cities.<br>
He prefers to use a car to move between cities. At the same time, it refuels only at stations
in cities, but not at stations along the way. Therefore, he very carefully chooses routes so that
the car does not stall on the road. And Petya is also a very important member of the team, so
he can't afford to travel for too long. He decided to write a program that would help him choose
the next trip. But since he has too many other tasks right now, he asked you to help him.<br>
The distance between two cities is calculated as the sum of the difference modules for each
of the coordinates. There are roads between all pairs of cities.<br>

<br><b>Input format:</b><br>
The first line of the input data contains the number of cities `n (2 ≤ n ≤ 1000)`.
In the following `n` lines, two integers are given: the coordinates of each city, not exceeding
modulo a billion. All cities are numbered with numbers from `1` to `n` in the order of entry
in the input data.<br>
The next line contains a positive integer `k`, not exceeding two billion, — the maximum distance
between cities that Petya can overcome without refueling the car.<br>
The last line contains two different numbers - the number of the city from where Petya is going,
and the number of the city where he is going.

<br><b>Output format:</b><br>
If there are paths that meet the conditions described above, then output the minimum number
of roads that you need to drive to get from the starting point of the route to the final one.
If the path does not exist, print `-1`.

## Example 1:
<br><b>Input:</b><br>
```none
7
0 0
0 2
2 2
0 -2
2 -2
2 -1
2 1
2
1 3
```

<br><b>Output:</b><br>
```none
2
```

## Example 2:
<br><b>Input:</b><br>
```none
4
0 0
1 0
0 1
1 1
2
1 4
```

<br><b>Output:</b><br>
```none
1
```

## Example 3:
<br><b>Input:</b><br>
```none
4
0 0
2 0
0 2
2 2
1
1 4
```

<br><b>Output:</b><br>
```none
-1
```
