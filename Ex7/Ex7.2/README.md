For your class Complex (or Rational), provide addition, subtraction, multiplication, and division as non-member functions, if you have not yet done so.

In a test program, create an array of function pointers to binary (non-member!) functions. Make sure that you can call the functions via that array.

Make a suggestion how this approach could be used to encode an expression formed of these operations, with literals or variables as leaves of the expression tree. (You might consider how a Polish notation expression parser would store its output.)

Make a suggestion how this approach could be used by a compiler writer to implement / optimize a `switch` statement.

Make a suggestion how this approach could be used by a compiler writer to implement virtual member functions – which are member functions that can be overwritten, like instance methods in Java.


# Solution/Thoughts

## Expression tree

**Task**: Make a suggestion how this approach could be used to encode an expression formed of these operations, with literals or variables as leaves of the expression tree. (You might consider how a Polish notation expression parser would store its output.)

Imagine a Polish Notation (prefix): + 3 * 4 2

This means: 3 + (4 * 2)

You can represent this with an array of function pointers and a stack of operands: {+, 3, *, 4, 2}

**Process**:

- If token is a number → push to operand stack
- If token is an operator → pop two operands, apply function, push result

## Compiler Implementation/Optimization for `switch`statement

**Task**: Make a suggestion how this approach could be used by a compiler writer to implement / optimize a `switch` statement.

Instead of using a switch:

```cpp
switch (op) {
    case '+': return add(a, b);
    case '-': return sub(a, b);
    // ...
}
```

Use a table:

```cpp
BinOp table[256];  // indexed by char

table['+'] = add;
table['-'] = sub;
table['*'] = mul;
table['/'] = divi;

int result = table[op](a, b);
```

- This is faster, especially with dense `case` values.
- This is how compilers often translate switch statements — into jump tables or dispatch tables.

## Simulation Virtual Functions in C++ with Function Pointers

**Task**: Make a suggestion how this approach could be used by a compiler writer to implement virtual member functions – which are member functions that can be overwritten, like instance methods in Java.

In C++, virtual functions work via vtable: a table of function pointers per class.

You can simulate this manually:

```cpp
struct Base {
    using VFun = void(*)();
    VFun sayHello;

    void call() { sayHello(); }
};

void helloA() { std::cout << "Hello from A\n"; }
void helloB() { std::cout << "Hello from B\n"; }

int main() {
    Base obj1 = { helloA };
    Base obj2 = { helloB };

    obj1.call(); // Hello from A
    obj2.call(); // Hello from B
}
```

This is exactly how virtual dispatch is done internally in C++.

# Summary

| Use Case                          | Benefit / Idea                                      |
| --------------------------------- | --------------------------------------------------- |
| Array of function pointers        | Simplifies logic, avoids `switch`, dynamic dispatch |
| Expression tree / Polish notation | Compact eval, extensible ops                        |
| Switch statement optimization     | Replaces branching with indexed lookup (jump table) |
| Virtual function simulation       | Simulates polymorphism via function tables          |
