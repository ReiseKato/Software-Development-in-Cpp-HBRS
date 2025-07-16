# Vector2D Header Inclusion and Preprocessing Experiment

## Purpose

This small project demonstrates how the C++ preprocessor works, how include guards protect header files from being processed multiple times, and how inconsistent definitions between translation units can cause problems at **link-time** or **runtime**.

---

## Files

- `Vector2D.hh` — Header file with include guards
- `Vector2D.cc` — Implementation of the `Vector2D` class
- `main.cpp` — A test file that uses the class
- `README.md` — Explanation of the results

---

## Steps and Observations

### 1. Preprocessing with `-E`

You can inspect the preprocessed output of each source file:

```bash
g++ -E main.cpp -o main.ii
g++ -E Vector2D.cc -o Vector2D.ii
```

This shows that:

- The contents of `Vector2D.hh` are copied into both `.ii` files.

- The full definition of the class appears in each compilation unit.

- The include guards (`#ifndef VECTOR2D_HH`) prevent it from appearing twice if included more than once.

### 2. Manually Replacing `#include`

You can try replacing:

```cpp
#include "Vector2D.hh"
```

with the full contents of the header file. The program will still compile and link successfully — as long as both copies match.

### 3. Modifying One Copy

If you change one copy, e.g., add a method in `Vector2D.cc`:

```cpp
void foo(); // added only in one place
```

But don't declare it in `main.cc`’s version of the class, then:

- You may get a compile-time error (e.g., no such method).

- If the class layout changes (e.g., extra data members), you can get link-time or even runtime errors (memory corruption or unexpected behavior).

- This shows the danger of inconsistent definitions.

---

## Key Learnings

| Concept            | What You Learned                                        |
| ------------------ | ------------------------------------------------------- |
| Preprocessor       | Replaces `#include` with actual content                 |
| Include guards     | Prevent duplicate definitions in the same file          |
| Link-time errors   | Caused by different class definitions across files      |
| Manual replacement | Useful to visualize what `#include` does                |
| Consistency        | Header files must be identical in all translation units |

---

## Conclusion

Using include guards and keeping header files consistent is crucial for correct behavior of C++ programs. The preprocessor is a text-substitution tool that can easily break your build if misused.