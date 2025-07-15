After defining class `Rational`, change it in the following manner for a little experiment:

Provide a member function `add` that takes another rational number `other` as argument and returns `*this + other`.

Add separate declarations for `operator+` (you made it a global function, right?) and for `Rational`.

Consider/try to compile various permutations of:
- definition of `Rational`
- declaration of `Rational`
- definition of `operator+`
- declaration of `operator+`

Which of them are accepted by the compiler (i.e., are legal C++), which are not?

```cpp
Rational add(const Rational& other) const
```

- Pass by Reference, so we do not have to copy the object. Copying also means havind to call the constructor and deconstructor
- `const Rational& other` ensures that the other object will not be changed
- `const` at the end ensures that `this` object will not be changed
