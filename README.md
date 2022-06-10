# Echelon Forms

> Count and enumerate different types of echelon forms of a $m \times n$ matrix

Define a <ins>*leading entry*</ins> as the leftmost nonzero entry in a row.

A matrix is in <ins>*echelon form*</ins> if

1. all the zero rows are below nonzero rows, and
2. all the leading entries are to the right of the leading entries above them.

The Gaussian elimination reduces a matrix in two steps:

1. forward stage: matrix ⟶ echelon form
2. backward stage: echelon form ⟶ reduced echelon form

After the first stage, the positions of the leading entries are fixed. These positions are important, in that they determine the existence and uniqueness of the solution set corresponding to the linear system, among many other properties of the matrix.

From this perspective, we categorize all the entries in an echelon form in 3 categories:

1. `▉` - a leading entry
2. `0` - an entry to the left of a leading entry, whose value must be a zero
3. `*` - an entry to the right of a leading entry, whose value we don't care

Accordingly, we can classify the echelon forms. For example, there are 4 types of echelon forms for a $2 \times 2$ matrix

$$
\begin{equation*}
\begin{bmatrix}
▉ & * \\
0 & ▉
\end{bmatrix}
\text{,}
\begin{bmatrix}
▉ & *  \\
0 & 0
\end{bmatrix}
\text{,}
\begin{bmatrix}
0 & ▉ \\
0 & 0
\end{bmatrix}
\text{,}
\begin{bmatrix}
0 & 0 \\
0 & 0
\end{bmatrix}
\end{equation*}
$$

Questions are asked:

1. How many different types of echelon forms can an $m \times n$ matrix $\mathcal{A}$ have?
2. How to enumerate all different types of echelon forms using a computer program?

## Count - Answer to Question 1

> 1. How many different types of echelon forms can an $m \times n$ matrix $\mathcal{A}$ have?

The answer has an analytical form

$$
N(m, n) = \sum_{k=0}^{\min (m, n)} {n \choose k}
$$

where $N(m,n)$ stands for the number of different types of echelon forms for an $m \times n$ matrix, while ${n \choose k}$ is for $n$ choose $k$.

To see this, imagine we would like to pick $k$ positions to place $k$ leading entries for an $m \times n$ matrix in echelon form.

1. These $k$ leading entries must be placed in $k$ separate columns, because one column can have at most one leading entry, as required by echelon form condition 2.

2. These $k$ leading entries must be placed one by one from row $1$ to row $k$, because the rows without a leading entry are zero rows, and zero rows must be placed below nonzero rows, as required by echelon form condition 1.

Therefore, it's just choosing $k$ columns from $n$ columns, or ${n \choose k}$, to place $k$ leading entries in an echelon form.

With these $k$ leading entries settled, the type of the echelon form is determined -- in any given row, the entries to the left of a leading entry are forced zeros, and the entries to the right of a leading entry can have arbitrary values.

Finally, we can have $k = 0, 1, ..., \min(m, n)$ leading entries in an $m \times n$ matrix.

Summing them up, we arrive at the answer.

A C++ program to compute the result is at [`echelon1.cpp`](echelon1.cpp).

- Sample Run

```
Count different types of echelon forms of a m-by-n matrix.

Please enter m, n (press Q to quit): 5 8
There are 219 different types of echelon forms for a 5x8 matrix.
```

## Enumerate - Answer to Question 2

> 2. How to enumerate all different types of echelon forms using a computer program?

We will use backtracking techniques to generate the output.

The key is how to enumerate all the ${n \choose k}$ cases. All the rest is straightforward.

```
// e.g. 4 choose 2
1 2
1 3
1 4
2 3
2 4
3 4
```

A C++ program to compute the result is at [`echelon2.cpp`](echelon2.cpp).

- Sample Run

```
Enumerate different types of echelon forms of a m-by-n matrix.

Please enter m, n (press Q to quit): 3 4
0000
0000
0000

1***
0000
0000

01**
0000
0000

001*
0000
0000

0001
0000
0000

1***
01**
0000

1***
001*
0000

1***
0001
0000

01**
001*
0000

01**
0001
0000

001*
0001
0000

1***
01**
001*

1***
01**
0001

1***
001*
0001

01**
001*
0001

There are 15 different types of echelon forms for a 3x4 matrix.
```

## Misc

- [`test.cpp`](test.cpp) - test to make sure [`echelon2.cpp`](echelon2.cpp) agrees with [`echelon1.cpp`](echelon1.cpp), with `m + n` in `[2, 30]`
- [`makefile`](makefile) - makefile for [`echelon1.cpp`](echelon1.cpp) [`echelon2.cpp`](echelon2.cpp) and [`test.cpp`](test.cpp), using `g++`

## Reference

- [Classifying Row-Reduced Echelon Matrices](echelon.pdf), Venit & Bishop,  College Mathematics Journal, 1986
