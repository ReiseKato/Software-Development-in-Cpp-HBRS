Provide a function norm2() for your Vector class(es), which computes the Euclidean norm (or 2-norm) of a vector `v` where, for a complex number `c` the value `~c` is its complex conjugate (which you implemented in class Complex).

For real numbers, the conjugate is the number itself.

Extend all your number (i.e., potential Vector2D::Coord) types by a corresponding (member or nonmember?) function conj(), so that the vector code can still be compiled for any choice of number type.

Remember that you need to link the math library in order to use std::sqrt.




To link the math library (libm) use the linkflag `lm`. In `Makefile` add `-lm` to `LNKLAGS`