Explain the output of the program `addressing.cc`

## Key Concepts

| Concept        | Explanation                                                                                                         |
| -------------- | ------------------------------------------------------------------------------------------------------------------- |
| `int v`        | A simple integer variable.                                                                                          |
| `int& r = v`   | A reference **alias** to `v`. `&r == &v`.                                                                           |
| `int* p = &v`  | A pointer pointing to `v`.                                                                                          |
| `int*& pr = p` | A **reference to a pointer**, meaning `pr` and `p` are aliases for the same pointer. Changing `pr` is changing `p`. |

In the function:

```cpp
void f(int v, int& r, int* p, int*& pr)
```

`v` is passed **by value** → copy of original `v`

`r` is a **reference** → directly refers to original `v`

`p` is a **copy** of a pointer (not a reference to pointer)

`pr` is a **reference to a pointer** → same as original pointer (`p` in `main()`)


| Parameter | Type    | What Is Passed                        | Meaning                                                         |
| --------: | ------- | ------------------------------------- | --------------------------------------------------------------- |
|       `v` | `int`   | Value of `v` (i.e., `0`)              | A **copy** of the integer. No link to original.                 |
|       `r` | `int&`  | Address of `v` (i.e., `&v`)           | A **reference**. Changes affect the original `v`.               |
|       `p` | `int*`  | Value of `p` (i.e., the address `&v`) | A **copy** of the pointer. The address it holds is passed.      |
|      `pr` | `int*&` | Address of `p` (i.e., `&p`)           | A **reference to the pointer** `p`. Changes to `pr` affect `p`. |
