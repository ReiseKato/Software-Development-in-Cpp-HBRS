- Make Rational the Coord type of Vector2D. Overload the (binary) comma operator – just a comma – to allow the following code to „extend“ a Coord value to a 2D vector:

```cpp
Vector2D::Coord x;
Vector2D::Coord y;
Vector2D v;
v = (x, y);
```

What is your opinion about this operator overload?

- Find and implement another uncommon but reasonable operator on vectors.
- What would happen if you overloaded the unary & operator? What if you made it private? Can you think of any purpose of doing so? (We will get back to this topic.)
- Overload the operator += for the class Vector2D so that its first argument is added to the second, and the first argument is returned. What is then the result of v1 += v2 += v3?
- Find some really abusive and confusing examples of operator overloading.

Make sure to remove all these examples from your code before continuing . . .


## Solution:

### Opinion on Overloading the Comma Operator

```cpp
Vector2D::Coord x(1, 2); // Rational(1, 2)
Vector2D::Coord y(3, 4); // Rational(3, 4)
Vector2D v;
v = (x, y); // Creates a Vector2D with x = Rational(1, 2), y = Rational(3, 4)
v.print();  // Outputs: Vector2D(1/2, 3/4)
```

While this implementation works, overloading the comma operator in this way is not recommended for the following reasons:

1. Unintuitive Behavior:

    The comma operator in C++ has a well-defined meaning: it evaluates the left-hand operand, discards its result, and then evaluates and returns the right-hand operand. Overloading it to create a Vector2D object changes its semantics, which can confuse readers of the code.

2. Readability:

    Using the comma operator to construct a Vector2D object is not intuitive. A developer reading v = (x, y); might not immediately understand that this creates a Vector2D object.

3. Better Alternatives:

    Instead of overloading the comma operator, you could use a named function or constructor, which is more explicit and easier to understand. For example:
This is clear and avoids any confusion about the behavior of the comma operator.

4. Code Maintainability:

    Overloading operators in unconventional ways can make the code harder to maintain, especially for developers unfamiliar with the custom behavior.


### Overloading unary & operator

Default gives the adress:

```cpp
Vector2D v;
Vector2D* p = &v;  // takes address of v
```

When overlaoading the unary `&` operator, it may not return the adress, but do something completely different defined in the custom function.

Let's say the function is private and returns the adress or whatever. This way, access to the adress from outside is being blocked. Unusal, but can prevent misuse.
