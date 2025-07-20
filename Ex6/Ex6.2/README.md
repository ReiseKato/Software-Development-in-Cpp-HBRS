Write a program to view and manipulate bits in values of builtin integral type.

Write functions that operate on an int value as a sequence of bits:

- bitOut takes a std::ostream and an int and writes the bits of the latter to the former.
- bitIn takes a std::istream and a reference to int and reads the bits of the latter from the former.
- get takes an int value and an unsigned value describing a bit offset (0 for the position of the bit representing 1) in the former. It returns a bool value representing the bit at the given position of the former.
- set takes an int value, an unsigned value describing a bit offset (0 for the position of the bit representing 1) in the former, and a bool value. The latter is written as a bit to the given position in the former, which is then returned.
- insL is equivalent to set, but inserts the bit value at the given position. The bit previously at that position and those to the left of it are shifted to the left, the first bit is lost.
- insR also inserts a bit value at the given position, but shifts to the right.
- delL and delR receive a position and delete the bit at that position. Bits are moved in from the left or from the right, correspondingly. Pass the bit to move in as the new first or last bit as a second argument. Which would be a reasonable default choice for either?

    Overload both functions by unary functions that merely take the position as argument and use the default choice for the bit to move in.

Write a test program that runs a loop and reads as input the operations to perform (e.g. by control characters) and the values to use. The program should thereby work as an interactive bit editor.

Generalize your solution to operate on any builtin type Type provided by a using declaration, instead of int.



# How to solve:

## `bitOut`:

Logic:

- 5 & 1

```text
0000 0101  (binary for 5)
0000 0001  (binary for 1)
---------
0000 0001  (result is 1)
```

- 2 & 1

```text
0000 0010  (binary for 2)
0000 0001  (binary for 1)
---------
0000 0000  (result is 0)
```

Shift bitwise to right and compare with bitwise `&` --> gives result whether first bit is 0 or 1, since every other bit will be 0 due to 1 having only one "positive" bit, which is the very first bit.

## `set`:

Idea:

Shift bits of 1 to the required position and do bitwise `or` operation to set the value at that position to 1 or negate the shifted 1 (keppeing all other values unchanged when doing bitwise `and` over the entire number) and do bitwise `and` operation.